#include "GameContext.h"

// Initialize the object
void GameContext::init() {
	// Test the window was created properly
	if (window == nullptr)
		ErrorHandler::exitFatalError( "Window Failed to Initialize" );

	// Load the number of draw calls that can be skipped during slowdown
	m_drawSkip = atoi( IOManager::readFile_txt( "data//startup", "draw_calls_skipped_during_slowdown" ).c_str() );
	std::cout << '\n' << "Number of Draw Calls To Skip During Slowdown: " << m_drawSkip;


	//=================================================================================
	// State Manager
	//=================================================================================
	std::cout << '\n' << "Initializing State Manager";

	// Create the state manager
	stateManager = std::auto_ptr<StateManager> ( new StateManager( window ) );

	// Test the state manager was created properly
	if (stateManager == nullptr)
		ErrorHandler::exitFatalError( "State Manager Failed to Initialize" );

	// Initialize the state manager
	stateManager->init();

	// Tell the state that it has been initialized
	// So the run() method can now be called
	m_initialized = true;
}

// Holds the main game loop
void GameContext::run() {	
	// Make sure the state is initialized before continuing
	if ( m_initialized != true )
		ErrorHandler::exitFatalError( "State Not Yet Initialized" );
	
	
	// Loop until a WM_QUIT message is received
	MSG message;
	message.message = static_cast<UINT>(~WM_QUIT);

	// A variable for toggling drawing
	bool draw = true;

	// The game loop
	std::cout << '\n' << "Entering Game Loop";

	// Run the current states game loop
	// Until the user closes the program
	// This is the run() and display() methods, respectively
	// The run() method is called every frame
	// But the draw() method is called every second frame
	while (message.message != WM_QUIT) {
		if ( PeekMessage(&message, NULL, 0, 0, PM_REMOVE) ) {
			// If a message was waiting in the message queue, process it
			TranslateMessage(&message);
			DispatchMessage(&message);
		} else {
			// Update and render the game
			runAndDraw();
		}
	}
}

// Call the render and draw functions
void GameContext::runAndDraw() {
	// Set the deltatime for AbstractEntity
	AbstractEntity::deltaTime = clock.restart();

	// Call the Update method
	stateManager->run();

	// Call the Render method
	stateManager->render();
}

// Destructor
GameContext::~GameContext() {
	std::cout << '\n' << '\n' << "Deleting Game Context";

	// Delete the State Manager
	stateManager.get_deleter();
}