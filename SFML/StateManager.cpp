#include "StateManager.h"

// Initialize the state
void StateManager::init() {
	currentState = std::auto_ptr<DefaultState> ( new DefaultState() );
	currentState->switchState( IOManager::readFile_txt( "data//startup", "startingState" ) ); 
}

// Check to see if the state need to be switched or not
// And initialized the state if it does
void StateManager::run() {
	// Check to see if the state should be switched
	
	if ( currentState->getSwitch() == true ) {
		// Assign currentState to the new state
		switchStates();

		// Initialize the new state
		currentState->setUp(window);

		// Output that the state has been successfully initialized
		std::cout << "\n" << currentState->getState() << " Successfully Initialized" << '\n';

	// Or if the state doesn't need to be switched
	} else {
		// Update the game logic
		currentState->gameLoop();
	}
}

// Switch states when is needed
void StateManager::switchStates() {	
	if ( currentState->getState() == "Restart" )
		return;

	// Output the state being initialized
	std::cout << '\n' << '\n' << "Initializing State: " << currentState->getState();
	
	// If getState() == PlayState then create the playState
	// and assign currentState to it
	if (currentState->getState() == "PlayState") {
		currentState = std::auto_ptr<PlayState> ( new PlayState() );
	}

	// If getState() == SplashScreenState then create the splashScreenState
	// and assign currentState to it
	else if (currentState->getState() == "SplashScreenState") {
		currentState = std::auto_ptr<SplashScreenState> ( new SplashScreenState() );
	}

	// if getState() == MainMenuState then create the mainMenuState
	// and assign the currentState to it
	else if ( currentState->getState() == "MainMenuState" ) {
		currentState = std::auto_ptr<MainMenuState> ( new MainMenuState() );
	}


	else if ( currentState->getState() == "CreditsState" ) {
		currentState = std::auto_ptr<CreditsState> ( new CreditsState() );
	}

	else if ( currentState->getState() == "HighScoreState" ) {
		currentState = std::auto_ptr<HighScoreState> ( new HighScoreState() );
	}

	// Report an error if the state was invalid
	else
		ErrorHandler::exitFatalError(currentState->getState() + " Is Not a Valid State");
}


// Destructor
// Deletes the current state
StateManager::~StateManager() {
	std::cout << '\n' << '\n' << "Deleting: State Manager";

	// Delete the state
	currentState.get_deleter();
}
