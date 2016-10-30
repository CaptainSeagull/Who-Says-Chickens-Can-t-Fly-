// Header File
#include "AbstractState.h"

// Setup the state before calling the init() method
void AbstractState::setUp( const HWND MainWindow ) {	
	// Assignt the main window
	this->MainWindow = MainWindow;

	// Enable V-Sync to limit the frame rate to the monitors refresh rate
	// To avoid screen tearing
	//window.setVerticalSyncEnabled(true);
	std::cout << '\n' << "V-Sync Enabled";

	init();
}

bool AbstractState::initializeManagers() {
	
	//=============================================================================================================================
	// Texture Manager
	//=============================================================================================================================
	std::cout << '\n' << "Initializing Texture Manager";
	load( "Texture Manager" );
	
	// Initialize the Texture Manager
	//textureManager =  std::auto_ptr<TextureManager> ( new TextureManager() );
	

	//=============================================================================================================================
	// Font and Text Manager
	//=============================================================================================================================
	std::cout << '\n' << "Initializing Font and Text Manager";
	load( "Text and Font Manager" );

	// Initialize the Text Manager
	textManager = std::auto_ptr<TextManager> ( new TextManager() );


	//=============================================================================================================================
	// UserInput
	//=============================================================================================================================
	std::cout << '\n' << "Initializing User Input";
	load( "User Input Manager" );

	// Initialize the User Input Manager
	userInput = std::auto_ptr<UserInput> ( new UserInput() );


	//=============================================================================================================================
	// Sound Manager
	//=============================================================================================================================
	std::cout << '\n' << "Initializing Sound Manager";
	load( "Sound Manager" );

	// Create the Sound Manager
	soundManager = std::auto_ptr<SoundManager> ( new SoundManager() );



	// Return true, indicating all the managers were loaded successfully
	return true;
}

// Holds the game loop for the state
void AbstractState::gameLoop() {	
	
	//=============================================================================================================================
	// Handle Game Events
	//=============================================================================================================================

	// While there are pending events...
	// Check the event type
	while ( window.pollEvent(event) ) {
		switch ( event.type ) {
			// Window not in focus
			case sf::Event::LostFocus:
				focus = false;
				break;

			// Window in focus
			case sf::Event::GainedFocus:
				focus = true;
				break;

			// Default
			default:
				break;
		}
	}
	

	// If the game is in focus
	// The stop updating the game logic
	// Effectively Pausing the game
	if ( focus == false ) {
		soundManager->backgroundMusic.pause();
		focus_previous = false;
		return;
	}

	// If the game has just came into focus...
	if ( focus_previous == false ) {
		soundManager->backgroundMusic.play();
	}
	

	//=============================================================================================================================
	// Test for User Input
	//=============================================================================================================================

	// Test which buttons are being pressed this frame
	userInput->test();

	// Allow the game to be paused and player
	if ( userInput->pressed_escape() == true ) {
		if ( paused == true )
			paused = false;
		else
			paused = true;
	}

	// Used for switching between the update
	// and construction modes
	if ( userInput->pressed_control() == true )
		toggleConstruction();


	//=============================================================================================================================
	// Update the state
	//=============================================================================================================================

	update( userInput.get() );

	// If the game isn't paused
	// Then either update the game logic
	// Or Level-Editor stuff
	if ( paused == false ) {
		if ( isConstruction == false ) {
			updateGameplay( userInput.get() );
			previous_construction = false;
		} else {
			updateConstruction( userInput.get() );
			previous_construction = true;
		}
	}

	// For the next iteration of the Game Loop
	// Tells the program that, in the previous loop, the game WAS in focus
	focus_previous = true;
}

// Clear the window
// Draw the state
// And push it onscreen
void AbstractState::renderState() {
	if ( focus == true ) {
		// Clear the window,
		window.clear();

		// Render the state
		render();

		if ( isConstruction == false )
			renderGame();
		else
			renderConstruction();

		// Display everything
		window.display();
	}
}


void AbstractState::load( std::string objectBeingLoaded ) {
	// All the variables
	static sf::Font font;
	static sf::Text text;
	static sf::Texture back;
	static sf::Sprite background;
	
	// If this is the first time calling the function
	static bool first = true;
	if ( first == true ) {
		// Load the font
		font.loadFromFile( "resources//fonts//sansation.ttf" );

		// Create the text
		text.setFont( font );
		text.setPosition( 156.0f, 408.0f );
		text.setStyle( sf::Text::Bold );

		// Load the background
		back.loadFromFile( "resources//textures//loading.png" );

		// Create the background
		background.setTexture( back );

		// Tell the program that the function has already been called
		first = false;
	}


	// Clear the screen
	window.clear();

	// Assign the text
	text.setString( objectBeingLoaded );

	// Draw everything
	window.draw( background );
	window.draw( text );

	// Draw everything
	window.display();
}


// Destructor
AbstractState::~AbstractState() {
	// Delete the managers
	userInput.get_deleter();
	textManager.get_deleter();
	soundManager.get_deleter();
}