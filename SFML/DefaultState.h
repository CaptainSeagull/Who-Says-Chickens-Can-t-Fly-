#pragma once

// The superclass
#include "AbstractState.h"


	// This is the first state tha the game points to
	// It points to whatever the user wants the first state to be
	// In it's init() method
	class DefaultState: public AbstractState {
		public:
			// Empty constructor
			DefaultState() { }

			// Empty destructor
			~DefaultState() { }


			// Initialized, which sets the state to another
			void init() { }

			void update( UserInput* userInput ) { }

			// Handles User Input
			// And moving objects
			void updateGameplay( UserInput* userInput ) { }

			// Used for constructing the level
			void updateConstruction( UserInput* userInput ) { }

			// Render all the objects to the screen
			void render() { }

			void renderGame() { }

			void renderConstruction() { }
	};