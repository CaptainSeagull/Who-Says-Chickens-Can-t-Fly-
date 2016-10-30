// The header file
#include "PlayState.h"

//===============================================================================================================================================================
// Initialization, and
// Loading
//===============================================================================================================================================================

// Initialize the state
void PlayState::init() {	
	// Assign the state
	currentState = "PlayState";

	// Create the window
	window.create( getWindow() );

	// Initialize all the game managers
	if ( initializeManagers() == false )
		ErrorHandler::exitFatalError( "Managers Failed To Initialize" );


	// Initialize Entity Manager
	std::cout << '\n' << "Initializing Entity Manager";
	entities = std::auto_ptr<EntityManager> ( new EntityManager() );
	
	// Whether the game starts in construction view or not
	setConstruction( false );

	// The seed folder
	m_folderName = "data//PlayState//";

	// Call all Loading Methods
	load_levelData();
	load_textures();
	load_Sound();
	load_Player();
	load_PlayerDead();
	load_Bullets();
	load_group( "Block" );
	load_group( "BreakableBlock" );
	load_group( "Foreground" );
	load_EventObjects();
	load_Enemies();
	load_Camera();
	load_Background();
	load_Fonts();
	load_Score();
	load_Particles();
	load_Controllers();
	load_LevelEditor();

	// Play the sound
	soundManager->backgroundMusic.play();

	entities->reset();
	camera->setCentreX( entities->getDynamicEntity( "Player" ).back()->getCentre().x );

	if ( AbstractEntity::load == false )
		loadLevel( m_levelData.startingLevel );
	else
		load_saveGame();
}

// Loading Methods
void PlayState::load_levelData() {
	// Load the list of levels
	IOManager::readArrayFile_txt( m_folderName + "init//levels//levelList", "level", m_levelData.levels.str );

	// Find out how many levels there are
	m_levelData.maxNoOfLevels = m_levelData.levels.str.size();

	// Load the starting level
	m_levelData.startingLevel = IOManager::readFile_txt( m_folderName + "init//levels//levelData", "starting_level" );
}
void PlayState::load_textures() {
	// Load the texture into the Texture Manager
	std::cout << '\n' << "Loading all Textures";
	load( "Loading Textures" );


	// Game Objects
	AbstractEntity::textureManager.addTexture( "resources//textures//player.png", "Player" );
	AbstractEntity::textureManager.addTexture("resources//textures//playerDead.png", "PlayerDead");
	AbstractEntity::textureManager.addTexture( "resources//textures//block.png", "Block" );
	AbstractEntity::textureManager.addTexture( "resources//textures//bullet.png", "Bullet" );
	AbstractEntity::textureManager.addTexture( "resources//textures//breakableBlock.png", "BreakableBlock" );

	AbstractEntity::textureManager.addTexture( "resources//textures//enemy1.png", "Enemy1" );
	AbstractEntity::textureManager.addTexture( "resources//textures//enemy2.png", "Enemy2" );
	AbstractEntity::textureManager.addTexture( "resources//textures//enemy3.png", "Enemy3" );
	AbstractEntity::textureManager.addTexture( "resources//textures//enemy4.png", "Enemy4" );
	AbstractEntity::textureManager.addTexture( "resources//textures//enemy5.png", "Enemy5" );
	AbstractEntity::textureManager.addTexture( "resources//textures//enemy6.png", "Enemy6" );

	AbstractEntity::textureManager.addTexture( "resources//textures//boss.png", "Boss" );

	// Backgrounds
	std::cout << '\n' << "Loading Backgrounds";
	for ( unsigned int i=0; i<m_levelData.maxNoOfLevels; i++ ) {
		AbstractEntity::textureManager.addTexture( "resources//textures//" + m_levelData.levels.str.at(i) + "//background0.png", m_levelData.levels.str.at(i) + "Background0" );
		AbstractEntity::textureManager.addTexture( "resources//textures//" + m_levelData.levels.str.at(i) + "//background1.png", m_levelData.levels.str.at(i) + "Background1" );
		AbstractEntity::textureManager.addTexture( "resources//textures//" + m_levelData.levels.str.at(i) + "//background2.png", m_levelData.levels.str.at(i) + "Background2" );
		AbstractEntity::textureManager.addTexture( "resources//textures//" + m_levelData.levels.str.at(i) + "//background3.png", m_levelData.levels.str.at(i) + "Background3" );
		AbstractEntity::textureManager.addTexture( "resources//textures//" + m_levelData.levels.str.at(i) + "//background4.png", m_levelData.levels.str.at(i) + "Background4" );
		AbstractEntity::textureManager.addTexture( "resources//textures//" + m_levelData.levels.str.at(i) + "//background5.png", m_levelData.levels.str.at(i) + "Background5" );
	}


	// Foregrounds
	AbstractEntity::textureManager.addTexture( "resources//textures//foreground.png", "Foreground" );

	// Construction Stuff
	AbstractEntity::textureManager.addTexture( "resources//textures//checkpoint.png", "Checkpoint" );
	AbstractEntity::textureManager.addTexture( "resources//textures//nextLevel.png", "NextLevel" );


	// Construction Mode
	AbstractEntity::textureManager.addTexture( "resources//textures//construction//block.png", "Construction Block" );
	AbstractEntity::textureManager.addTexture( "resources//textures//construction//breakableBlock.png", "Construction BreakableBlock" );
	AbstractEntity::textureManager.addTexture( "resources//textures//construction//player.png", "Construction Player" );
	AbstractEntity::textureManager.addTexture( "resources//textures//construction//foreground.png", "Construction Foreground" );
	AbstractEntity::textureManager.addTexture( "resources//textures//construction//checkpoint.png", "Construction Checkpoint" );
	AbstractEntity::textureManager.addTexture( "resources//textures//construction//nextLevel.png", "Construction NextLevel" );

	AbstractEntity::textureManager.addTexture( "resources//textures//construction//enemy1.png", "Construction Enemy1" );
	AbstractEntity::textureManager.addTexture( "resources//textures//construction//enemy2.png", "Construction Enemy2" );
	AbstractEntity::textureManager.addTexture( "resources//textures//construction//enemy3.png", "Construction Enemy3" );
	AbstractEntity::textureManager.addTexture( "resources//textures//construction//enemy4.png", "Construction Enemy4" );
	AbstractEntity::textureManager.addTexture( "resources//textures//construction//enemy5.png", "Construction Enemy5" );
	AbstractEntity::textureManager.addTexture( "resources//textures//construction//enemy6.png", "Construction Enemy6" );
	AbstractEntity::textureManager.addTexture( "resources//textures//construction//boss.png", "Construction Boss" );
}
void PlayState::load_Sound() {
	std::cout << '\n' << "Loading Audio Files";
	load( "Audio" );


	// load_ Background Music
	std::string trackName = IOManager::readFile_txt( m_folderName + "//init//data", "background_track" );
	std::cout << '\n' << trackName;
	if ( !soundManager->backgroundMusic.openFromFile( "resources//music//" + trackName ) )
		ErrorHandler::exitFatalError( "Failed To load_ Music" );

	
	// Play The Background Music
	soundManager->backgroundMusic.play();

	// Make the background music looped
	soundManager->backgroundMusic.setLoop( true );


	// load_ Sound Effects
	if ( !soundManager->loadSound( "resources//sounds//boom.wav", "boom" ) )
		ErrorHandler::exitFatalError( "Sound Failed To load_ Sound" );

	soundManager->backgroundMusic.stop();
}
void PlayState::load_Player() {
	std::cout << "\n" << "Initializing Player";
	load( "Player" );

	// Reset the .txt score file
	IOManager::write_txt( "data//HighScores//playerScore", "player_score", "0" );

	// Create the player
	entities->newDynamicGroup( "Player", atoi( IOManager::readFile_txt( m_folderName + "//init//Player//data", "layer" ).c_str() ) );
	entities->addDynamicEntityToGroup( "Player" );

	// Texture the player
	entities->getDynamicEntity( "Player" ).back()->assignTexture();


	// Set the speed
	entities->setDynamicGroupSpeed( "Player", Utility::StringToVector2f ( IOManager::readFile_txt( m_folderName + "//init//Player//speed", "speed" ) ) );

	// Set the acceleration
	entities->setDynamicGroupAcceleration( "Player",  Utility::StringToVector2f ( IOManager::readFile_txt( m_folderName + "//init//Player//speed", "acceleration" ) ) );
	entities->getDynamicEntity("Player").back()->setFriction( Utility::StringToVector2f(IOManager::readFile_txt(m_folderName + "//init//Player//speed", "friction") ) );

	// Set the size of the player
	entities->getDynamicEntity( "Player" ).back()->setSize( Utility::StringToVector2f( IOManager::readFile_txt( m_folderName + "//init//Player//data", "size"  ).c_str() ) );


	// Animation Stuff

	// Variables to hold animation data
	std::vector<std::string> aniName;
	std::vector<std::string> aniFrames;
	std::vector<std::string> aniSpeed;

	// Load in animation data
	IOManager::readArrayFile_txt( m_folderName + "//init//Player//animation", "animation", aniName );
	IOManager::readArrayFile_txt( m_folderName + "//init//Player//animation", "frames", aniFrames );
	IOManager::readArrayFile_txt( m_folderName + "//init//Player//animation", "speed", aniSpeed );

	// Set the player's animation speed
	for ( unsigned int i=0; i<aniName.size(); i++ ) {
		sf::Vector2f maxAndMin = Utility::StringToVector2f( aniFrames.at(i).c_str() );
		entities->getDynamicEntity( "Player" ).back()->addAnimation( aniName.at(i), maxAndMin.x, maxAndMin.y, (float) atof( aniSpeed.at(i).c_str() ) );
	}

	entities->getDynamicEntity( "Player" ).back()->setAnimation( "Neutral" );

	entities->setCollisionBox( "Player",
		Utility::StringToVector2f( IOManager::readFile_txt( m_folderName + "init//Player//data", "collision_box_position" ) ),
		Utility::StringToVector2f( IOManager::readFile_txt( m_folderName + "init//Player//data", "collision_box_size" ) )
	);

	//entities->getDynamicEntity( "Player" ).back()->setCollisionBoundry( sf::Vector2f( 50.0f, 50.0f ), sf::Vector2f ( 50.0f, 50.0f ) );

}
void PlayState::load_PlayerDead() {
	std::cout << "\n" << "Initializing PlayerDead Object";

	// The name of the group
	std::string groupName = "PlayerDead";

	// Create the player
	entities->newDynamicGroup( groupName, entities->getDynamicEntity( "Player" ).back()->getLayer() + 1 );
	entities->addDynamicEntityToGroup( groupName );

	// Texture the player
	entities->getDynamicEntity( groupName ).back()->assignTexture();


	// Set the position
	entities->getDynamicEntity( groupName ).back()->setPosition( entities->getDynamicEntity( "Player" ).back()->getPosition() );

	// Set the speed
	entities->setDynamicGroupSpeed(
		groupName,
		Utility::StringToVector2f( IOManager::readFile_txt(m_folderName + "//init//" + groupName + "//data", "speed") )
	);

	// Set the size of the player
	entities->setDynamicGroupSize(
		groupName,
		Utility::StringToVector2f( IOManager::readFile_txt(m_folderName + "//init//" + groupName + "//data", "size").c_str() )
	);



	// Animation Stuff

	// Variables to hold animation data
	std::vector<std::string> aniName;
	std::vector<std::string> aniFrames;
	std::vector<std::string> aniSpeed;

	// Load in animation data
	IOManager::readArrayFile_txt(m_folderName + "//init//" + groupName + "//animation", "animation", aniName);
	IOManager::readArrayFile_txt(m_folderName + "//init//" + groupName + "//animation", "frames", aniFrames);
	IOManager::readArrayFile_txt(m_folderName + "//init//" + groupName + "//animation", "speed", aniSpeed);

	// Set the player's animation speed
	for (unsigned int i = 0; i<aniName.size(); i++) {
		sf::Vector2f maxAndMin = Utility::StringToVector2f(aniFrames.at(i).c_str());
		entities->getDynamicEntity( groupName ).back()->addAnimation(aniName.at(i), maxAndMin.x, maxAndMin.y, (float)atof(aniSpeed.at(i).c_str()));
	}

	entities->getDynamicEntity( groupName ).back()->setAnimation( "Default" );

	entities->getDynamicEntity( groupName ).back()->setVisible( false );
	entities->getDynamicEntity( groupName ).back()->setDeleted( false );
	entities->getDynamicEntity( groupName ).back()->setDestroyed( false );
}
void PlayState::load_Bullets() {
	std::cout << '\n' << "Initializing Bullets";
	load( "Bullets" );

	std::string name = "Bullet";

	// Load in the bullet's speeds
	sf::Vector2f bulletSpeed = Utility::StringToVector2f( IOManager::readFile_txt( m_folderName + "//init//" + name + "//data", "bullet_speed" ).c_str() );
	
	// Create the group of bullets
	entities->newDynamicGroup( name, atoi( IOManager::readFile_txt( m_folderName + "//init//" + name + "//data", "depth" ).c_str() ) );


	// Animation Data
	std::vector<std::string> aniName;
	std::vector<std::string> aniFrames;
	std::vector<std::string> aniSpeed;
	IOManager::readArrayFile_txt( m_folderName + "//init//" + name + "//animation", "animation", aniName );
	IOManager::readArrayFile_txt( m_folderName + "//init//" + name + "//animation", "frames", aniFrames );
	IOManager::readArrayFile_txt( m_folderName + "//init//" + name + "//animation", "speed", aniSpeed );


	// For the maximum number of bullets allowed...
	unsigned int max_noOfBullets = atoi( IOManager::readFile_txt( m_folderName + "//init//" + name + "//data", "max_number_of_bullets" ).c_str() );
	for ( unsigned int i=0; i<max_noOfBullets; i++ ) {                      
		// Add a new Bullet onto the group
		entities->addDynamicEntityToGroup( name );

		// Set the initial coords for each level
		entities->getDynamicEntity( name ).back()->setInitialPosition ( 0.0f, 0.0f );

		// Texture the bullet
		entities->getDynamicEntity( name ).back()->assignTexture( name );

		// Assign the bullet's speed
		entities->getDynamicEntity( name ).back()->setSpeed( bulletSpeed );
		entities->getDynamicEntity( name ).back()->setAcceleration( bulletSpeed );

		// Set the size
		entities->getDynamicEntity( name ).back()->setSize( Utility::StringToVector2f( IOManager::readFile_txt( m_folderName + "//init//" + name + "//data", "size" ).c_str() ) );


		// Delete the bullet
		// This is so there's no bullets being created at random locations in ther game
		entities->getDynamicEntity( name ).back()->setDeleted( true );

		// Tell the game bullets are temperary objects
		entities->getDynamicEntity( name ).back()->setTemperary( true );

		// Set the Bullet animation data
		for ( unsigned int i=0; i<aniName.size(); i++ ) {
			sf::Vector2f maxAndMin = Utility::StringToVector2f( aniFrames.at(i).c_str() );
			entities->getDynamicEntity( name ).back()->addAnimation( aniName.at(i), maxAndMin.x, maxAndMin.y, (float) atof( aniSpeed.at(i).c_str() ) );
		}
	}
}
void PlayState::load_Enemies() {
	// Get the number of enemy types
	m_noOfEnemyTypes = atoi( IOManager::readFile_txt( m_folderName + "//init//data", "number_of_enemy_types" ).c_str() );

	// Load each enemy type
	for ( unsigned int i=1; i<m_noOfEnemyTypes+1; i++ ) {
		load_group( "Enemy" + std::to_string(i) );
	}
}
void PlayState::load_Camera() {
	std::cout << '\n' << "Initializing Camera";
	load( "Camera" );

	// Intialize the camera
	camera = std::auto_ptr<Camera> ( new Camera() );

	// How fast the user can scroll the game in construction mode
	camera->setSpeed( Utility::StringToVector2f ( IOManager::readFile_txt( m_folderName + "//construction//data", "scrolling_speed" ) ) );

	// Set the position and size of the camera from a .txt file
	camera->setSize( Utility::StringToVector2f ( IOManager::readFile_txt( m_folderName + "//init//camera", "size" ) ) );
	camera->setY( 0.0f );
	camera->setCentreX( entities->getDynamicEntity( "Player" ).back()->getPosition().x );

	// Set the margins for the player-camera collision
	camera->setMargins (
		(float) atof( IOManager::readFile_txt( m_folderName + "//init//camera", "margin_left" ).c_str() ),
		(float) atof( IOManager::readFile_txt( m_folderName + "//init//camera", "margin_right" ).c_str() ),
		(float) atof( IOManager::readFile_txt( m_folderName + "//init//camera", "margin_top" ).c_str() ),
		(float) atof( IOManager::readFile_txt( m_folderName + "//init//camera", "margin_bottom" ).c_str() )
	);

	camera->setDefaultZoom();
	camera->setZoomSpeed( sf::Vector2f( 0.1024f*3.0f, 0.0768f*3.0f ) );

	// Output the currently viewing size
	std::cout << ". Viewing Size: " << camera->getSize().x << " x " << camera->getSize().y;
}
void PlayState::load_Background() {
	std::cout << '\n' << "Initializing Background(s)";
	load( "Background" );

	m_numberOfBackgroundLayers = 6;

	// Create a new group to store the backgrounds
	entities->newStaticGroup( "Background" );

	// Load in how far tiled the background's are
	std::vector<std::string> tile;
	IOManager::readArrayFile_txt( m_folderName + "//init//Background//tiled", "tiled", tile );

	// Load in which layer each background's on
	std::vector<std::string> layer;
	IOManager::readArrayFile_txt( m_folderName + "//init//Background//layer", "layer", layer );
	
	// Load in the scrolling speed of each background
	std::vector<std::string> speed;
	IOManager::readArrayFile_txt( m_folderName + "//init//Background//speed", "speed", speed );

	// Create all the backgrounds
	for ( unsigned int i=0; i<m_numberOfBackgroundLayers; i++ ) {
		// Create the background
		entities->addStaticEntityToGroup( "Background" );

		// Set the background's texture
		//Level2Background0
		entities->getStaticEntity( "Background" ).back()->assignTexture(  m_levelData.levels.str.at( m_levelData.currentLevel ) + "Background" + std::to_string(i), Utility::StringToVector2u( tile.at(i).c_str() ), true );

		// Set which layer the background's drawn on
		entities->getStaticEntity( "Background" ).back()->setLayer( atoi( layer.at(i).c_str() ) );

		// Set the initial position
		//entities->getStaticEntity( "Background" ).back()->setNoOfLevels( m_maxNoOfLevels );
		entities->getStaticEntity( "Background" ).back()->setInitialPosition( sf::Vector2f( 0.0f, 0.0f ) );

		// Set the background's scrolling speed
		entities->getStaticEntity( "Background" ).back()->setScrollingSpeed( Utility::StringToVector2f( speed.at(i).c_str() ) );
	}
}
void PlayState::load_Fonts() {
	std::cout << '\n' << "Initializing Text";
	load( "Fonts and Text Messages" );

	// load a test Font
	if ( textManager->loadFont( "resources//fonts//sansation.ttf" ) == false )
		ErrorHandler::exitFatalError( "Font Failed To load" );
	else
		std::cout << '\n' << "Font Loaded: " << "sansation.ttf";


	// Generate a the Message
	if ( textManager->generateMessage( "Changes Not Saved!", "Not Saved", "sansation.ttf" ) == false )
		ErrorHandler::exitFatalError( "Not Saved Text Fail To Generate" );


	// Perform manipulations on a message
	if ( textManager->setColour( "Not Saved", sf::Color::Red ) == false )
		ErrorHandler::exitFatalError( "Text Colour Not Set" );

	// Where the text saying 'Data Not Saved' is
	m_notSavedPositionRelativeToCamera = Utility::StringToVector2f( IOManager::readFile_txt( m_folderName + "//construction//data", "not_saved_pos" ) );
}
void PlayState::load_Score() {
	std::cout << '\n' << "Initializing Score";
	load( "Score Data" );


	// Generate the Message
	if ( textManager->generateMessage( "Score: ", "Score", "sansation.ttf" ) == false )
		ErrorHandler::exitFatalError( "Score Text Fail To Generate" );

	// Set the colour
	if ( textManager->setColour( "Score", IOManager::readFile_txt( m_folderName + "init//data", "score_colour" ) ) == false )
		ErrorHandler::exitFatalError( "Score Text Not Coloured" );

	// Set the style
	if ( textManager->setStyle( "Score", sf::Text::Bold ) == false )
		ErrorHandler::exitFatalError( "Score Style Not Set" );


	// Where the text saying 'Data Not Saved' is
	m_scorePosRelativeToCamera = sf::Vector2f( Utility::StringToVector2f( IOManager::readFile_txt( m_folderName + "init//data", "score_pos" ) ) );
}
void PlayState::load_Particles() {
	std::cout << '\n' << "Initializing Particles";
	load( "Particle Effects" );

	// Create the particles
	entities->createParticles();
	
	// Create particles for the player
	entities->createRocketParticles( entities->getDynamicEntity( "Player" ).back()->getLayer() );
	entities->getRocketParticles().back()->setPosition( entities->getDynamicEntity( "Player" ).back()->getPosition() );
	entities->getRocketParticles().back()->setSize( 1.0f, 7.0f );
}
void PlayState::load_EventObjects() {
	// Load the checkpoints
	load_group( "Checkpoint" );

	// Load the object which take the player to the next level
	load_group( "NextLevel" );
}
void PlayState::load_Controllers() {
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
	// Game Logic
	//========================================================================================================================


	// Set the default enemy shot timer
	for ( unsigned int i=1; i<m_noOfEnemyTypes+1; i++ ) {
		int shoots = atoi( IOManager::readFile_txt( m_folderName + "//init//Enemy" + std::to_string(i) + "//shooting", "shoots" ).c_str() );		
		controllers->gameLogic->addEnemyGroup( shoots, (float) atof( IOManager::readFile_txt(m_folderName + "//init//Enemy" + std::to_string(i) + "//shooting", "shot_timer").c_str() ) );
	}


	// Initialize the game logic
	controllers->gameLogic->init( (float) atof( IOManager::readFile_txt( m_folderName + "//init//Player//shooting", "shot_timer" ).c_str() ) );

	// Load the control type
	std::string controlLayout = IOManager::readFile_txt( m_folderName + "//init//data", "controls" );

	// Load the keyboard layout
	if ( Utility::equalsIgnoreCase( controlLayout, "keyboard" ) ) {
		controllers->gameLogic->initKeyboard(
			IOManager::readFile_txt( m_folderName + "//init//Player//controls", "move_up" ),
			IOManager::readFile_txt( m_folderName + "//init//Player//controls", "move_down" ),
			IOManager::readFile_txt( m_folderName + "//init//Player//controls", "move_right" ),
			IOManager::readFile_txt( m_folderName + "//init//Player//controls", "move_left" )
		);

	// Or Load the mouse layout
	} else if ( Utility::equalsIgnoreCase( controlLayout, "mouse" ) ) {
		controllers->gameLogic->initMouse (
			(float) atof( IOManager::readFile_txt( m_folderName + "//init//Player//speed", "mouse_speed" ).c_str() )
		);

	// Error - Invalid Layout
	} else
		ErrorHandler::exitFatalError( "Controllers Fail To Initialize\nControl Type: " + controlLayout );

	// Output which layout was loaded
	std::cout << '\n' << "Control Layout: " << controlLayout;

	//========================================================================================================================
	// Load the renderer
	//========================================================================================================================

	// Load all the entities into the renderer
	controllers->renderer->initializeEntities( entities->getAllEntities() );


	//========================================================================================================================
	// Set the scrolling speed
	//========================================================================================================================

	// The window's scrolling speed
	float scrollingSpeed = (float) atof( IOManager::readFile_txt( m_folderName + "//init//data", "scrolling_speed" ).c_str() );
	float fastScrollingSpeed = (float) atof( IOManager::readFile_txt( m_folderName + "//init//data", "fast_scrolling_speed" ).c_str() );
	float slowScrollingSpeed = (float) atof( IOManager::readFile_txt( m_folderName + "//init//data", "slow_scrolling_speed" ).c_str() );

	// Test the scrolling speeds were loaded properly
	if ( ( scrollingSpeed < 0.1f ) || ( fastScrollingSpeed < 0.1f ) || ( slowScrollingSpeed < 0.1 ) )
		ErrorHandler::exitFatalError( "Scrolling Speeds Not Loaded Properly" );
	else {
		std::cout << '\n' << "Default Scrolling Speed Set To: " << scrollingSpeed;
		std::cout << '\n' << "Fast Scrolling Speed Set To: " << fastScrollingSpeed;
		std::cout << '\n' << "Slow Scrolling Speed Set To: " << slowScrollingSpeed;
	}

	// Set the scrolling speed
	controllers->gameLogic->setScrollingSpeeds( scrollingSpeed,  fastScrollingSpeed, slowScrollingSpeed );
}
void PlayState::load_LevelEditor() {
	std::cout << '\n' << "Initializing Level Editor";
	load( "Level Editor" );

	// Initialize the level editor
	controllers->levelEditor->init();

	// Load every button into the Level Editor from a .txt file
	for ( unsigned int i=0; i<IOManager::readArrayFile_txt( m_folderName + "//construction//buttons", "button").size(); i++ ) {
		controllers->levelEditor->addButton (
			IOManager::readArrayFile_txt( m_folderName + "//construction//buttons", "button").at(i),
			AbstractEntity::textureManager.getTexture( IOManager::readArrayFile_txt( m_folderName + "//construction//buttons", "button").at(i) )
		);
	}

	// Set the grid size
	controllers->levelEditor->setGrid( Utility::StringToVector2f( IOManager::readFile_txt( m_folderName + "//init//data", "grid" ) ) );

	// Output the placement grid size
	std::cout << '\n' << "Placement Grid Size: " << Utility::VectorToString( controllers->levelEditor->getGrid() );
}

void PlayState::load_group( std::string name ) {
	std::cout << '\n' << "Initializing " << name;
	load( name );

	// Create the block group and set it's layer
	entities->newDynamicGroup( name, atoi( IOManager::readFile_txt( m_folderName + "init//" + name + "//data", "layer" ).c_str() )  );

	// Set the default speed of the enemies
	entities->setDynamicGroupSpeed( name, Utility::StringToVector2f( IOManager::readFile_txt( m_folderName + "//init//" + name + "//data", "speed" ).c_str() ) );

	// Set the entity size
	entities->setDynamicGroupSize( name, Utility::StringToVector2f( IOManager::readFile_txt( m_folderName + "//init//" + name + "//data", "size" ).c_str() ) );

	// Add one entity onto the group
	// and texture it
	entities->addDynamicEntityToGroup( name );
	entities->getDynamicEntity( name ).back()->assignTexture();

	
	// Animation Stuff

	// Variables to hold animation data
	std::vector<std::string> aniName;
	std::vector<std::string> aniFrames;
	std::vector<std::string> aniSpeed;

	// Load in animation data
	IOManager::readArrayFile_txt( m_folderName + "//init//" + name + "//animation", "animation", aniName );
	IOManager::readArrayFile_txt( m_folderName + "//init//" + name + "//animation", "frames", aniFrames );
	IOManager::readArrayFile_txt( m_folderName + "//init//" + name + "//animation", "speed", aniSpeed );


	entities->setCollisionBox( name,
		Utility::StringToVector2f( IOManager::readFile_txt( m_folderName + "init//" + name + "//data", "collision_box_position" ) ),
		Utility::StringToVector2f( IOManager::readFile_txt( m_folderName + "init//" + name + "//data", "collision_box_size" ) )
	);

	// Set the entity's animation speed
	for ( unsigned int i=0; i<aniName.size(); i++ ) {
		sf::Vector2f maxAndMin = Utility::StringToVector2f( aniFrames.at(i).c_str() );
		entities->addGroupAnimation( name, aniName.at(i), maxAndMin, (float) atof( aniSpeed.at(i).c_str() ) );
	}
}



//===============================================================================================================================================================
// Update and Construction Methods
//===============================================================================================================================================================

// Universal update method
void PlayState::update( UserInput* userInput ) {	
	// Used Z and X to change the current level
	if ( userInput->pressed_n() == true ) {
		m_levelData.currentLevel--;
		loadLevel( m_levelData.levels.str.at( m_levelData.currentLevel) );
	}
	else if ( userInput->pressed_m() == true ) {
		if ( m_levelData.currentLevel < m_levelData.maxNoOfLevels-1 ) {
			m_levelData.currentLevel++;
			loadLevel( m_levelData.levels.str.at( m_levelData.currentLevel) );
		} else {
			switchState( "HighScoreState" );
			IOManager::write_txt( "data//HighScores//playerScore", "player_score", std::to_string( controllers->gameLogic->getScore() ) );
		}
	}
	
	// Set the score's rendering
	textManager->changeMessage( "Score", "Score: " + std::to_string( controllers->gameLogic->getScore() ) );
	textManager->setPosition( "Score", m_scorePosRelativeToCamera + camera->getPosition() );
}

// For updating the game logic
void PlayState::updateGameplay( UserInput* userInput ) {		
	// This is used to fix a problem with a exponentially large deltaTime issue
	// Where deltaTime gets huge because of the long loading time
	if ( updateLogic == false ) {
		updateLogic = true;
		return;
	}

	// Stop updating logic briefly while the game is resetting
	if (controllers->gameLogic->getReset() == true)
		updateLogic = false;

	// Make the camera just to the player's position
	// if the previous frame was in construction mode
	if ( previous_construction == true )
		camera->setCentreX( entities->getDynamicEntity( "Player" ).back()->getX() );

	// Handle game logic
	controllers->gameLogic->run( entities.get(), camera.get(), userInput, userInput->mouse_getPixelCoords( window ) );


	// Set Level-Control Objects to invisible during Gameplay
	textManager->setVisible("Not Saved", false);
	for ( unsigned int i=0; i<entities->getDynamicEntity( "Checkpoint" ).size(); i++ )
		entities->getDynamicEntity( "Checkpoint" ).at(i)->setVisible(false);
	for ( unsigned int i=0; i<entities->getDynamicEntity( "NextLevel" ).size(); i++ )
		entities->getDynamicEntity( "NextLevel" ).at(i)->setVisible(false);


	// Saving!
	if ( ( userInput->pressed_s() == true ) || ( controllers->gameLogic->getSave() == true ) )
		save_game();



	// Manually Changing Level
		
	// Used Z and X to change the current level
	if ( entities->collision( "Player", "NextLevel" ) != -1 ) {
		if ( m_levelData.currentLevel < m_levelData.maxNoOfLevels-1 ) {
			m_levelData.currentLevel++;
			loadLevel( m_levelData.levels.str.at( m_levelData.currentLevel) );
		} else {
			switchState( "HighScoreState" );
			IOManager::write_txt( "data//HighScores//playerScore", "player_score", std::to_string( controllers->gameLogic->getScore() ) );
		}
	}
}

// For creating the state
void PlayState::updateConstruction( UserInput* userInput ) {
	// Reset all objects ( except the player ) if the previous frame was NOT in construction mode
	// Then set the camera to the player's position
	if ( previous_construction == false ) {
		entities->reset();

		// Initialize all the entities sprite data
		for ( unsigned int i=0; i<entities->getAllDynamicEntities().size(); i++ )
			entities->getAllDynamicEntities().at(i)->setSpriteData();
	}

	// Move the camera
	if ( userInput->arrowLeft() == true )
		if ( userInput->shift() == false )
			camera->setCentreX( camera->getCentreX() - camera->getSpeed().x * AbstractEntity::deltaTime.asSeconds() );
		else
			camera->setCentreX( camera->getCentreX() - camera->getSpeed().x * AbstractEntity::deltaTime.asSeconds() * 2 );
	if ( userInput->arrowRight() == true )
		if ( userInput->shift() == false )
			camera->setCentreX( camera->getCentreX() + camera->getSpeed().x * AbstractEntity::deltaTime.asSeconds() );
		else
			camera->setCentreX( camera->getCentreX() + camera->getSpeed().x * AbstractEntity::deltaTime.asSeconds() * 2 );
	
	// Set data
	controllers->levelEditor->setCurrentState( m_folderName );
	controllers->levelEditor->setLevelData( m_levelData.levels.str.at( m_levelData.currentLevel ) );

	// Call the Level-Construction Code
	controllers->levelEditor->run( entities.get(), userInput, controllers->renderer.get(), userInput->mouse_getPixelCoords( window ) );


	// Setup information for the level-editor
	controllers->levelEditor->setCamera( camera->getPosition(), camera->getSize() );
	controllers->levelEditor->setupDrawing();

	// Output the "Changes Not Saved" Text if the Level hasn't been saved
	if ( controllers->levelEditor->areChangesSaved() == false ) {
		textManager->setPosition( "Not Saved", camera->getPosition() + m_notSavedPositionRelativeToCamera );
		textManager->setVisible( "Not Saved", true );
	} else
		textManager->setVisible( "Not Saved", false );

	// Set Level-Control Objects to Visible During Level-Construction
	for ( unsigned int i=0; i<entities->getDynamicEntity( "Checkpoint" ).size(); i++ )
		entities->getDynamicEntity( "Checkpoint" ).at(i)->setVisible(true);
	for ( unsigned int i=0; i<entities->getDynamicEntity( "NextLevel" ).size(); i++ )
		entities->getDynamicEntity( "NextLevel" ).at(i)->setVisible(true);
}



//===============================================================================================================================================================
// Rendering
//===============================================================================================================================================================

// Draw the state
void PlayState::render() {	
	// Camera things 'n stuff
	window.draw( *camera );
	
	
	// Pass the camera's view into the Entities
	// To test whether they're on screen or not
	entities->setRectView( camera->getRectView() );
	
	// Draw all game entities
	controllers->renderer->draw( &window, camera.get() );

	// Draw text messages
	for ( unsigned int i=0; i<textManager->getNoOfMessages(); i++ )
		window.draw( textManager->getMessage( i ) );

	
}

// Draw Gameplay-specific stuff
void PlayState::renderGame() {

}

// Draw Construction Mode-specific stuff
void PlayState::renderConstruction() {	
	controllers->levelEditor->draw( &window );
}



//==============================================================================================================================================================
// Level Systems
//===============================================================================================================================================================

// Load in a level
void PlayState::loadLevel( std::string level ) {
	// Loading Screen
	load( "Level: " + level );
	std::cout << '\n' << "Loading: " << level;

	// Set the current level number
	for ( unsigned int i=0; i<m_levelData.maxNoOfLevels; i++ )
		if ( m_levelData.levels.str.at(i) == level )
			m_levelData.currentLevel = i;
	
	// Destroy all entities so they can be recreated from scratch
	for ( unsigned int i=0; i<entities->getAllDynamicEntities().size(); i++ )
		entities->getAllDynamicEntities().at(i)->setDestroyed( true );

	// Set the pathname for the level
	m_levelData.currentLevelAsString = level;
	level = m_folderName + "init//levels//" + level;

	// Two variables to store entity's data
	std::vector< std::string > entityData;
	std::vector< sf::Vector2f > levelData;

	// Load in all the level data
	IOManager::readLevel_txt( level, entityData, levelData );

	// For each piece of data loaded in...
	unsigned int k=0;
	std::string group = "";
	for ( unsigned int i=0; i<entityData.size(); i++, k++ ) {

		// Skip Bullet for the level-loading process
		std::size_t test = entityData.at(i).find( "Bullet" );
		if ( test != std::string::npos )
			continue;


		// If the group's changed, reset everything
		static std::string group = entityData.at(i);
		if ( group != entityData.at(i) ) {
			group = entityData.at(i);
			k=0;
		}

		// If k is greater than the group size
		// Add to the group size
		if ( k >= entities->getDynamicEntity( group ).size() )
			entities->addDynamicEntityToGroup( group );


		// Position the entity
		entities->getDynamicEntity( group ).at(k)->setInitialPosition( levelData.at(i) );

		// Texture the entity
		entities->getDynamicEntity( group ).at(k)->assignTexture();

		// Add the entity to the controller
		controllers->renderer->addEntity( entities->getDynamicEntity( group ).at(k) );

		// Tell the game the entity isn't destroyed
		entities->getDynamicEntity( group ).at(k)->setDestroyed( false );
	}

	// Reset all the entity's to their newly loaded positions
	// And set the camera to the player's position
	entities->reset();
	camera->setCentreX( entities->getDynamicEntity( "Player" ).back()->getCentre().x );
	controllers->gameLogic->levelChanged();

	// Create the backgrounds for this level
	for ( unsigned i=0; i<m_numberOfBackgroundLayers; i++ ) {

		// Background's tiles are reloaded, to avoid a glitch where backgrounds aren't tiled
		// This will be removed later, and added to the EntityManager
		std::vector<std::string> tile;
		IOManager::readArrayFile_txt(m_folderName + "//init//Background//tiled", "tiled", tile);
		
		// Texture the background
		entities->getStaticEntity("Background").at(i)->assignTexture(m_levelData.levels.str.at(m_levelData.currentLevel) + "Background" + std::to_string(i), Utility::StringToVector2u(tile.at(i).c_str()), true);
	}

	// Player Dead Animation
	entities->getDynamicEntity( "PlayerDead" ).back()->setDestroyed( false );

	// Re-create the destroyed bullets
	for ( unsigned int i=0; i<entities->getDynamicEntity( "Bullet" ).size(); i++ ) {
		entities->getDynamicEntity( "Bullet" ).at(i)->setDestroyed( false );
		entities->getDynamicEntity( "Bullet" ).at(i)->setDeleted( true );
	}

	for ( unsigned int i=1; i<m_noOfEnemyTypes+1; i++ )
		for ( unsigned int k=0; k<entities->getDynamicEntity( "Enemy" + std::to_string(i) ).size(); k++ )
			entities->getDynamicEntity( "Enemy" + std::to_string(i) ).at(k)->setAnimation( "Normal" );

	// Set data for every entity
	entities->setData();
}


// Load save-game data
void PlayState::load_saveGame() {	
	// Read in the data
	std::string level = IOManager::readFile_txt( m_folderName + "init//savedata", "level" );
	std::string pos = IOManager::readFile_txt( m_folderName + "init//savedata", "player_position" );
	std::string score = IOManager::readFile_txt( m_folderName + "init//savedata", "score" );

	// Make sure none of the data's empty
	if ( ( level == "NULL" ) || ( pos == "NULL" ) || ( score == "NULL" ) ) {
		std::cout << '\n' << '\n' << "No Save Data Found";
		return;
	}

	// Load the level
	loadLevel( level );
	
	// Set the player position and checkpoint position
	entities->getDynamicEntity( "Player" ).back()->setPosition( pos );
	controllers->gameLogic->setCheckpoint( entities->getDynamicEntity( "Player" ).back()->getPosition() );
	camera->setCentreX( entities->getDynamicEntity( "Player" ).back()->getPosition().x );


	// Set the score
	controllers->gameLogic->setScore( score );

	// Tell the game that it has been successfully loaded
	AbstractEntity::load = false;
	std::cout << '\n' << '\n' << "Level " << level << " Loaded!";
	std::cout << '\n' << "Player.Position: " << entities->getDynamicEntity( "Player" ).back()->getPositionAsString();
	std::cout << '\n' << "Score: " << score;
	std::cout << '\n';
}

// Save game data to a .txt file
void PlayState::save_game() {
	// Output the Level Name, Player Position, and Current Score to the savegame.txt file
	IOManager::write_txt( m_folderName + "init//savedata", "level", m_levelData.currentLevelAsString );
	IOManager::write_txt( m_folderName + "init//savedata", "player_position", entities->getDynamicEntity( "Player" ).back()->getPositionAsString() );
	IOManager::write_txt( m_folderName + "init//savedata", "score", controllers->gameLogic->getScoreAsString() );

	// Output, to the console, the data that was saved
	std::cout << '\n' << '\n' << "Data Saved!";
	std::cout << '\n' << "Level: " << m_levelData.currentLevelAsString;
	std::cout << '\n' << "Player.Position: " << entities->getDynamicEntity( "Player" ).back()->getPositionAsString();
	std::cout << '\n' << "Score: " << controllers->gameLogic->getScore();
	std::cout << '\n';
}



//===============================================================================================================================================================
// Destructor
//===============================================================================================================================================================

// Destructor
PlayState::~PlayState() {
	std::cout << '\n' << "Deleting: PlayState";

	// Call the delete method for everything
	camera.get_deleter();
	controllers.get_deleter();
	entities.get_deleter();
}