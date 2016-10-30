#include "LevelEditor.h"

//==========================================================================================================================================================================
// Rendering
//==========================================================================================================================================================================

// Render the side-bar
void LevelEditor::draw( sf::RenderWindow *window ) {
	window->draw( m_bar );

	for ( unsigned int i=0; i<button.size(); i++ )
		window->draw( *button.at(i) );

	window->draw( m_selected );
}


//==========================================================================================================================================================================
// Initialization
//==========================================================================================================================================================================

// Initialize object for construction-mode
void LevelEditor::init() {
	// Set the bar to the left
	m_bar.setFillColor( sf::Color::White );
	m_bar.setOutlineColor( sf::Color::Black );
	m_bar.setOutlineThickness( (float) atof( IOManager::readFile_txt( "data//ConstructionMode//data", "outline_thickness" ).c_str() ) );
	m_bar.setSize( sf::Vector2f( (float) atof( IOManager::readFile_txt( "data//ConstructionMode//data", "bar_width" ).c_str() ), 0.0f ) );
	
	// Set the selected/highlight feature
	m_selected.setFillColor( sf::Color::Transparent );
	m_selected.setOutlineColor( sf::Color::Red );
	m_selected.setOutlineThickness( m_bar.getOutlineThickness() );
	m_selected.setSize( m_bar.getSize() );

	// The distance between each button
	m_distanceBetweenElements = atoi( IOManager::readFile_txt( "data//ConstructionMode//data", "distance_between_elements" ).c_str() );

	m_buttonSize = sf::Vector2f( 32.0f, 32.0f );
}


//==========================================================================================================================================================================
// Level Construction
//==========================================================================================================================================================================

// Calls all the construction-mode methods
void LevelEditor::run( EntityManager* entities, UserInput* userInput, Renderer* renderer, sf::Vector2f mousePosition ) {
	// Save the mouse position
	this->m_mousePosition = mousePosition;


	// Select an Entity from the left bar
	if ( userInput->pressed_leftMouse() == true )
		if ( selectEntity( userInput ) == true )
			return;

	// End the function here if the group name's blank
	if ( m_groupName == "" )
		return;


	// if the left mouse button is pressed...
	// Either place the selected entity
	// Or output the stats of the clicked-on entity
	if ( userInput->pressed_leftMouse() == true ) {
		if ( placeEntity( entities, renderer ) == true )
			m_saved = false;
		else
			outputEntityStats( entities );
	} else if ( ( userInput->leftMouse() && ( userInput->shift() ) ) ) {
		placeEntity( entities, renderer );
		m_saved = false;
	}


	// If the user presses the spacebar
	// Then move all entites right of the mouse up by one
	// (one being the Level Placement size)
	if ( userInput->pressed_space() == true ) 
		moveEntitiesThatAreRightOfMouse( entities, true );


	// Delete a placed Entity
	// Right clicking on an entity will delete ANY entity, regardless of which is selected
	else if ( userInput->rightMouse() == true ) {
		deleteEntity( entities );
		m_saved = false;
	}


	if ( userInput->pressed_returnKey() == true )
		saveChanges( entities );
}

// Used for selecting an entity within the side-bar
bool LevelEditor::selectEntity( UserInput* userInput ) {
	if ( userInput->pressed_leftMouse() == true )
		for ( unsigned int i=0; i<button.size(); i++ )
			if ( button.at(i)->contains( m_mousePosition ) == true ) {
				// Get the name of the entity
				m_groupName = button.at(i)->getType();
				std::cout << '\n' << "Now Editing: " << m_groupName;
				
				// Get the maximum and minimun numbers for that entity
				m_max = atoi( IOManager::readFile_txt( m_currentState + "init//" + m_groupName + "//data", "max_number" ).c_str() );
				m_min = atoi( IOManager::readFile_txt( m_currentState + "init//" + m_groupName + "//data", "min_number" ).c_str() );

				//std::cout << '\n' << "Min: " << m_min;
				//std::cout << '\n' << "Max: " << m_max;

				// Set which button was pressed and highlight it
				m_currentlySelectedButtonsNumber = i;
				m_selected.setSize( sf::Vector2f( m_selected.getSize().x, button.at(i)->getYSize()+m_selected.getOutlineThickness() ) );

				return true;
			}

	return false;
}

// Used to place the currently-selected entity
bool LevelEditor::placeEntity( EntityManager* entities, Renderer* renderer ) {
	bool returnKey = false;
	
	// Exit the function early if the player's going to place two entity's ontop of each other
	for ( unsigned int i=0; i<entities->getDynamicEntity( m_groupName ).size(); i++ )
		if ( entities->getDynamicEntity( m_groupName ).at(i)->contains( m_mousePosition ) )
			return false;
	
	// If the number of entitie shasn't reached the max count yet...
	if ( entities->getDynamicEntity( m_groupName ).size() < m_max ) {


		// Add a block to the dynamicGroup and texture it 
		entities->addDynamicEntityToGroup( m_groupName );
		entities->getDynamicEntity( m_groupName ).back()->assignTexture();


		// Move the Entity to the mouse's position
		entities->getDynamicEntity( m_groupName ).back()->setPosition( m_mousePosition );

		// Snap the entity to a grid
		entities->getDynamicEntity( m_groupName ).back()->snapToGrid( m_grid );

		// Save the entity's starting position
		//entities->getDynamicEntity( m_groupName ).back()->setNoOfLevels( m_maxNoOfLevels );
		entities->getDynamicEntity( m_groupName ).back()->setInitialPosition( entities->getDynamicEntity( m_groupName ).back()->getPosition() );

		// Special Case for the Foreground
		if ( entities->getDynamicEntity( m_groupName ).back()->getType() == "Foreground" )
			entities->getDynamicEntity( m_groupName ).back()->setInitialPosition( sf::Vector2f( entities->getDynamicEntity( m_groupName ).back()->getInitialPosition().x, 0.0f ) );

		// Add the New Entity onto the Renderer
		renderer->addEntity( entities->getDynamicEntity( m_groupName ).back() );

		// Setup rendering information
		entities->getDynamicEntity( m_groupName ).back()->setSpriteData();

		//entities->getDynamicEntity( m_groupName ).back()->update();
	

		// Output position
		std::cout << "\n\n" << m_groupName << '[' << entities->getDynamicEntity( m_groupName ).back()->getNumber() << "].Position: " << entities->getDynamicEntity( m_groupName ).back()->getPositionAsString();


		return true;


	// If the Entity Group HAVE reached their max count...
	} else {
		// Move the Entity to the mouse's position
		entities->getDynamicEntity( m_groupName ).back()->setPosition( m_mousePosition );

		// Snap the entity to a grid
		entities->getDynamicEntity( m_groupName ).back()->snapToGrid( m_grid );

		// Save the entity's starting position
		entities->getDynamicEntity( m_groupName ).back()->setInitialPosition( entities->getDynamicEntity( m_groupName ).back()->getPosition() );


		// Setup rendering information
		entities->getDynamicEntity( m_groupName ).back()->setSpriteData();

		return true;
	}
}

// Output the clicked-on entities stats to the console
void LevelEditor::outputEntityStats( EntityManager* entities ) {
	// Find out if the user clicked on an entity
	for ( unsigned int i=0; i<entities->getAllDynamicEntities().size(); i++ )
		if ( entities->getAllDynamicEntities().at(i)->contains( m_mousePosition ) ) {
			std::cout << '\n' << '\n' << "Dynamic Entity Output";
			std::cout << '\n' << "Type: " << entities->getAllDynamicEntities().at(i)->getType() << '[' << entities->getAllDynamicEntities().at(i)->getNumber() << ']';
			std::cout << '\n' << "Position: " << entities->getAllDynamicEntities().at(i)->getPositionAsString();
			std::cout << '\n' << "Size: " << entities->getAllDynamicEntities().at(i)->getSize().x << ' ' << entities->getAllDynamicEntities().at(i)->getSize().y;
			std::cout << '\n' << "Current Animation: " << entities->getAllDynamicEntities().at(i)->getCurrentAnimation();
		}
}

// Moves all dynamic entities right of the mouse
void LevelEditor::moveEntitiesThatAreRightOfMouse( EntityManager* entities, bool right ) {
	if ( right == true ) {
		for ( unsigned int i=0; i<entities->getAllDynamicEntities().size(); i++ )
			if ( entities->getAllDynamicEntities().at(i)->getPosition().x > m_mousePosition.x ) {
				entities->getAllDynamicEntities().at(i)->setInitialPosition( entities->getAllDynamicEntities().at(i)->getPosition() + sf::Vector2f( m_grid.x, 0.0f ) );
				entities->getAllDynamicEntities().at(i)->setPosition( entities->getAllDynamicEntities().at(i)->getPosition() + sf::Vector2f( m_grid.x, 0.0f ) );
			}
	}

	if ( right == false ) {
		for ( unsigned int i=0; i<entities->getAllDynamicEntities().size(); i++ )
			if ( entities->getAllDynamicEntities().at(i)->getPosition().x > m_mousePosition.x ) {
				entities->getAllDynamicEntities().at(i)->setInitialPosition( entities->getAllDynamicEntities().at(i)->getPosition() - sf::Vector2f( m_grid.x, 0.0f ) );
				entities->getAllDynamicEntities().at(i)->setPosition( entities->getAllDynamicEntities().at(i)->getPosition() - sf::Vector2f( m_grid.x, 0.0f ) );
			}
	}

	entities->update();
}

// Used for selecting an entity within the level
void LevelEditor::deleteEntity( EntityManager* entities ) {
	// Holds the type of the entity going to be deleted
	// And it's number
	std::string groupTypeOfEntityToDelete = "";
	int numberOfEntityToDelete = -1;

	// Get the entity up for deletion
	for ( unsigned int i=0; i<entities->getAllEntities().size(); i++ )
		if ( entities->getAllEntities().at(i)->contains( m_mousePosition ) )
			if ( entities->getAllEntities().at(i)->getType() != "Player" ) {
				entities->getAllEntities().at(i)->setDestroyed( true );
				std::cout << '\n' << "Destroyed: " << entities->getAllEntities().at(i)->getType() << '[' << entities->getAllEntities().at(i)->getNumber() << ']';
			}
}

// Save the changes for all entities
void LevelEditor::saveChanges( EntityManager* entities ) {
	
	IOManager::delete_txt( m_currentState + "init//levels//" + m_currentLevel );

	for ( unsigned int i=0; i<entities->getAllDynamicEntities().size(); i++ )
		if ( entities->getAllDynamicEntities().at(i)->getDestroyed() == false )
			if ( entities->getAllDynamicEntities().at(i)->getPosition().x > 1.0f )
				IOManager::add_txt( m_currentState + "init//levels//" + m_currentLevel, entities->getAllDynamicEntities().at(i)->getType(), entities->getAllDynamicEntities().at(i)->getInitialPositionAsString() );
	

	// Output that changes have been saved
	std::cout << '\n' << '\n' << "Changes Saved!";
	m_saved = true;
}

// Save the changes for all entities
void LevelEditor::saveChanges( EntityManager* entities, std::string levelName ) {
	
	IOManager::delete_txt( m_currentState + "init//levels//" + levelName );

	for ( unsigned int i=0; i<entities->getAllDynamicEntities().size(); i++ )
		if ( entities->getAllDynamicEntities().at(i)->getDestroyed() == false )
			if ( entities->getAllDynamicEntities().at(i)->getPosition().x > 1.0f )
				IOManager::add_txt( m_currentState + "init//levels//" + levelName, entities->getAllDynamicEntities().at(i)->getType(), entities->getAllDynamicEntities().at(i)->getInitialPositionAsString() );
	

	// Output that changes have been saved
	std::cout << '\n' << '\n' << "Changes Saved!";
	m_saved = true;
}


//==========================================================================================================================================================================
// Construction Buttons
//==========================================================================================================================================================================

// Add a new button onto the entities
void LevelEditor::addButton( std::string name, sf::Texture texture ) {
	// Add a new button to the vector
	// And texture it
	button.push_back( std::shared_ptr<DynamicEntity> ( new DynamicEntity( button.size(), name ) )  );
	button.back()->assignTexture( "Construction " + button.back()->getType() );

	// Set the size of the button
	// And make it's animation static
	button.back()->setSize( m_buttonSize );
	button.back()->addAnimation( "Normal", 0.0f, 0.0f, 0.0f );

	// If this is the first button then set it to the top right corner
	if ( button.size() == 1 ) {
		
		// Set the inital position
		button.back()->setPosition( 0.0f, 0.0f );

		// Make this first button the one that's currently selected
		m_groupName = button.back()->getType();
		m_currentlySelectedButtonsNumber = 0;
	
		// Store the maximum and minium data
		// For the currently selected group
		m_max = atoi( IOManager::readFile_txt( m_currentState + "//init//" + m_groupName + "//data", "max_number" ).c_str() );
		m_min = atoi( IOManager::readFile_txt( m_currentState + "//init//" + m_groupName + "//data", "min_number" ).c_str() );

		// Set the outline size
		// For the highlight object 
		m_selected.setSize( sf::Vector2f( m_selected.getSize().x, button.back()->getYSize()+m_selected.getOutlineThickness() ) );

	// If it is the second button then set it to underneath the previous button
	} else
		button.back()->setPosition( 0.0f, ( button.end()[-2]->getY() + button.end()[-2]->getSize().y ) + m_distanceBetweenElements );

}

// Setup rendering information for construction mode
void LevelEditor::setupDrawing() {
	// Set the button positions and size
	// Relative to the camera
	m_bar.setPosition( sf::Vector2f( m_cameraPosition.x+m_bar.getOutlineThickness(), m_cameraPosition.y + m_bar.getOutlineThickness() ) );
	m_bar.setSize( sf::Vector2f( m_bar.getSize().x, m_cameraSize.y - m_bar.getOutlineThickness()*2 ) );

	// Update each button
	for ( unsigned int i=0; i<button.size(); i++ ) {
		button.at(i)->setX( m_bar.getPosition().x + m_bar.getOutlineThickness() );
		button.at(i)->update();
	}

	// Set the highlight object to the button current highlighted
	// Must be placed AFTER the buttons to provide a smoother look
	m_selected.setPosition( button.at( m_currentlySelectedButtonsNumber )->getPosition() - sf::Vector2f( m_selected.getOutlineThickness(),  m_selected.getOutlineThickness() ) );
}


//==========================================================================================================================================================================
// Destructor
//==========================================================================================================================================================================

// Destructor
LevelEditor::~LevelEditor() {
	std::cout << '\n' << "Deleting: Level Editor";

	// Delete all the buttons
	for ( unsigned int i=0; i<button.size(); i++ )
		std::get_deleter<DynamicGroup>( button.at(i) );
	button.resize(0);
}