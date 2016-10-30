#include "MainMenuState.h"

//================================================================================================================================================
// Initialization, and
// Loading
//================================================================================================================================================

void MainMenuState::init() {
	// Assign the state
	currentState = "MainMenuState";

	// Create the window
	window.create( getWindow() );

	// Initialize all the game managers
	if ( initializeManagers() == false )
		ErrorHandler::exitFatalError( "Managers Failed To Initialize" );

	buttons = std::auto_ptr<EntityManager> ( new EntityManager() );
	buttons->createParticles();

	load_Textures();
	load_Camera();
	load_Buttons();
	load_HelpScreen();
	load_Controllers();
	load_LevelEditor();
}

void MainMenuState::load_Textures() {
	// Load the texture into the Texture Manager
	std::cout << '\n' << "Loading Main Menu Textures";
	load( "Loading Textures" );


	AbstractEntity::textureManager.addTexture( "resources//textures//mainMenu//play.png", "Play" );
	AbstractEntity::textureManager.addTexture( "resources//textures//mainMenu//howToPlay.png", "HowToPlay" );
	AbstractEntity::textureManager.addTexture( "resources//textures//mainMenu//load.png", "Load" );
	AbstractEntity::textureManager.addTexture( "resources//textures//mainMenu//quit.png", "Quit" );
	AbstractEntity::textureManager.addTexture( "resources//textures//mainMenu//title.png", "Title" );

	AbstractEntity::textureManager.addTexture( "resources//textures//construction//play.png", "Construction Play" );
	AbstractEntity::textureManager.addTexture( "resources//textures//construction//howToPlay.png", "Construction HowToPlay" );
	AbstractEntity::textureManager.addTexture( "resources//textures//construction//load.png", "Construction Load" );
	AbstractEntity::textureManager.addTexture( "resources//textures//construction//quit.png", "Construction Quit" );
	AbstractEntity::textureManager.addTexture( "resources//textures//construction//title.png", "Construction Title" );


	AbstractEntity::textureManager.addTexture( "resources//textures//mainMenu//helpScreen.png", "HelpScreen" );
}
void MainMenuState::load_Camera() {
	std::cout << '\n' << "Initializing Camera";
	load( "Camera" );

	// Intialize the camera
	camera = std::auto_ptr<Camera> ( new Camera() );


	// Set the position and size of the camera from a .txt file
	//camera->setSize( Utility::StringToVector2f ( IOManager::readFile_txt( "data//MainMenu//init//camera", "size" ) ) );
	camera->setSize( 800.0f, 600.0f );
	camera->setPosition( 0.0f, 0.0f );
}
void MainMenuState::load_Buttons() {
	
	IOManager::readArrayFile_txt( "data//MainMenuState//init//Buttons", "button", m_buttonNames );

	for ( unsigned int i=0; i<m_buttonNames.size(); i++ ) {
		load_group( m_buttonNames.at(i) );

		if (buttons->getDynamicEntity(m_buttonNames.at(i)).back()->getType() != "Title") {
			buttons->getDynamicEntity(m_buttonNames.at(i)).back()->setSize(sf::Vector2f(256.0, 64.0f));
			buttons->getDynamicEntity(m_buttonNames.at(i)).back()->addAnimation("Unselected", 0, 0, 0);
			buttons->getDynamicEntity(m_buttonNames.at(i)).back()->addAnimation("Selected", 1, 1, 0);
		}
	}

	buttons->update();
}
void MainMenuState::load_HelpScreen() {
	std::cout << '\n' << "Loading: Help Screen";
	load( "How To Play Screen" );

	buttons->newDynamicGroup( "HelpScreen" );
	buttons->addDynamicEntityToGroup( "HelpScreen" );
	buttons->getDynamicEntity( "HelpScreen" ).back()->assignTexture();
	buttons->getDynamicEntity( "HelpScreen" ).back()->setInitialPosition( 0.0f, 0.0f );
	buttons->getDynamicEntity( "HelpScreen" ).back()->setPosition( 0.0f, 0.0f );
	buttons->getDynamicEntity( "HelpScreen" ).back()->setVisible( false );
	buttons->getDynamicEntity( "HelpScreen" ).back()->setSize( 1024.0f, 768.0f );

	buttons->update();
}
void MainMenuState::load_Controllers() {
	std::cout << '\n' << "Initializing Control Manager";
	load( "Game Controllers" );


	//========================================================================================================================
	// Load All Controllers
	//========================================================================================================================

	// Initialize the controller class
	controllers = std::auto_ptr<Controllers> ( new Controllers() );

	// Initialize the classes it holds
	if ( controllers->init() == false )
		ErrorHandler::exitFatalError( "Controller Manager Failed To Initialize" );


	//========================================================================================================================
	// Load the renderer
	//========================================================================================================================

	// Load all the entities into the renderer
	controllers->renderer->initializeEntities( buttons->getAllEntities() );

}
void MainMenuState::load_LevelEditor() {
	std::cout << '\n' << "Initializing Level Editor";
	load( "Level Editor" );

	// Initialize the level editor
	controllers->levelEditor->init();

	// Load every button into the Level Editor from a .txt file
	for ( unsigned int i=0; i<IOManager::readArrayFile_txt( "data//MainMenuState//construction//buttons", "button").size(); i++ ) {
		controllers->levelEditor->addButton (
			IOManager::readArrayFile_txt( "data//MainMenuState//construction//buttons", "button").at(i),
			AbstractEntity::textureManager.getTexture( IOManager::readArrayFile_txt( "data//MainMenuState//construction//buttons", "button").at(i) )
		);
	}

	// Set the grid size
	controllers->levelEditor->setGrid( Utility::StringToVector2f( IOManager::readFile_txt( "data//MainMenuState//init//data", "grid" ) ) );

	// Output the placement grid size
	std::cout << '\n' << "Placement Grid Size: " << Utility::VectorToString( controllers->levelEditor->getGrid() );
}

void MainMenuState::load_group(std::string name) {
	std::cout << '\n' << "Initializing " << name;
	load(name);

	std::string folderName = "data//MainMenuState//";

	// Create the block group and set it's layer
	buttons->newDynamicGroup( name, atoi( IOManager::readFile_txt( folderName + "init//" + name + "//data", "layer").c_str() ) );

	// Set the default speed of the enemies
	buttons->setDynamicGroupSpeed(name, Utility::StringToVector2f(IOManager::readFile_txt(folderName + "//init//" + name + "//data", "speed").c_str()));

	// Set the entity size
	buttons->setDynamicGroupSize(name, Utility::StringToVector2f(IOManager::readFile_txt(folderName + "//init//" + name + "//data", "size").c_str()));

	// Add one entity onto the group
	// and texture it
	buttons->addDynamicEntityToGroup(name);
	buttons->getDynamicEntity(name).back()->assignTexture();


	// Animation Stuff

	// Variables to hold animation data
	std::vector<std::string> aniName;
	std::vector<std::string> aniFrames;
	std::vector<std::string> aniSpeed;

	// Load in animation data
	IOManager::readArrayFile_txt(folderName + "//init//" + name + "//animation", "animation", aniName);
	IOManager::readArrayFile_txt(folderName + "//init//" + name + "//animation", "frames", aniFrames);
	IOManager::readArrayFile_txt(folderName + "//init//" + name + "//animation", "speed", aniSpeed);


	buttons->setCollisionBox( name, sf::Vector2f( 0.0f, 0.0f ), buttons->getDynamicEntity( name ).back()->getSize() );

	// Set the entity's animation speed
	for (unsigned int i = 0; i<aniName.size(); i++) {
		sf::Vector2f maxAndMin = Utility::StringToVector2f(aniFrames.at(i).c_str());
		buttons->addGroupAnimation(name, aniName.at(i), maxAndMin, (float)atof(aniSpeed.at(i).c_str()));
	}


	buttons->getDynamicEntity( name ).back()->setInitialPosition(
		Utility::StringToVector2f( IOManager::readFile_txt( folderName + "//init//levels//level", name ) )
	);

	buttons->getDynamicEntity( name ).back()->setPosition( buttons->getDynamicEntity( name ).back()->getInitialPosition() );
}



//================================================================================================================================================
// Updating, and
// Construction
//================================================================================================================================================

void MainMenuState::update( UserInput* userInput ) {
	buttons->update();
}


void MainMenuState::updateGameplay( UserInput* userInput ) {
	// Make the buttons highlight/darken depending on whether the mouse is over them
	for ( unsigned int i=0; i<buttons->getAllDynamicEntities().size(); i++ ) {
			buttons->getAllDynamicEntities().at(i)->setAnimation( "Unselected" );
		
		if ( buttons->getAllDynamicEntities().at(i)->contains( userInput->mouse_getPixelCoords( window ) ) )
			buttons->getAllDynamicEntities().at(i)->setAnimation( "Selected" );
	}


	// Make clicking on buttons actually do something
	if ( m_helpDisplayed == false ) {
		for ( unsigned int i=0; i<buttons->getAllDynamicEntities().size(); i++ )
			buttons->getAllDynamicEntities().at(i)->setVisible( true );
		buttons->getDynamicEntity( "HelpScreen" ).back()->setVisible( false );


		if ( userInput->leftMouse() == true ) {
			if ( buttons->getDynamicEntity( "Play" ).back()->contains( userInput->mouse_getPixelCoords( window ) ) ) {
				switchState( "PlayState" );
				AbstractEntity::load = false;
			} else if ( buttons->getDynamicEntity( "Quit" ).back()->contains( userInput->mouse_getPixelCoords( window ) ) ) {
				exit(0);
			} else if ( buttons->getDynamicEntity( "HowToPlay" ).back()->contains( userInput->mouse_getPixelCoords( window ) ) ) {
				m_helpDisplayed = true;
			} else if ( buttons->getDynamicEntity( "Load" ).back()->contains( userInput->mouse_getPixelCoords( window ) ) ) {
				switchState( "PlayState" );
				AbstractEntity::load = true;
			}
		}
	}


	// If the 'How To Play' screen is displayed
	// Then disable the user from selecting buttons
	if ( m_helpDisplayed == true ) {
		for ( unsigned int i=0; i<buttons->getAllDynamicEntities().size(); i++ )
			buttons->getAllDynamicEntities().at(i)->setVisible( false );
		buttons->getDynamicEntity( "HelpScreen" ).back()->setVisible( true );


		if ( userInput->pressed_returnKey() == true )
			m_helpDisplayed = false;
	}
}

void MainMenuState::updateConstruction( UserInput* userInput ) {
	// Reset all objects ( except the player ) if the previous frame was NOT in construction mode
	// Then set the camera to the player's position
	if ( previous_construction == false )
		buttons->reset();

	
	// Call the Level-Construction Code
	controllers->levelEditor->run( buttons.get(), userInput, controllers->renderer.get(), userInput->mouse_getPixelCoords( window ) );

	controllers->levelEditor->setCurrentState( "data//MainMenuState//" );
	controllers->levelEditor->setLevelData( "level" );

	// Setup information for the level-editor
	controllers->levelEditor->setCamera( camera->getPosition(), camera->getSize() );
	controllers->levelEditor->setupDrawing();
}


//================================================================================================================================================
// Rendering
//================================================================================================================================================

void MainMenuState::render() {
	window.draw( *camera );
	
	controllers->renderer->draw( &window, camera.get() );
	window.draw( *buttons->getDynamicEntity( "HelpScreen" ).back() );
}


void MainMenuState::renderGame() {
	// Do nothing
}

void MainMenuState::renderConstruction() {
	controllers->levelEditor->draw( &window );
}


//================================================================================================================================================
// Destructor
//================================================================================================================================================

MainMenuState::~MainMenuState() {
	buttons.get_deleter();
}