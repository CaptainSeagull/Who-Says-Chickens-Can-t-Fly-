#pragma once

#include "ErrorHandler.h"

#include "AbstractState.h"

#include "DefaultState.h"
#include "SplashScreenState.h"
#include "MainMenuState.h"
#include "PlayState.h"
#include "HighScoreState.h"
#include "CreditsState.h"

	// Stores all the states
	// And handles switching between them
	class StateManager {
		private:
			HWND window;
			
			// The current state which the user is on
			std::unique_ptr<AbstractState> currentState = nullptr;

			// This methods assigns the currentState to the new state
			void switchStates();

			sf::Clock clock;

		public:
			// Constructor, which gets the window for the state
			StateManager(HWND window)
				: window(window) {}

			// Destructor
			~StateManager();

			// Initialize the manager
			void init();

			// Run the GameLoop for each state
			void run();

			// Draw the state onscreen
			void render() { currentState->renderState(); }
	};