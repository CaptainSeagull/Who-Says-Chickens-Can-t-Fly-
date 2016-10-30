#pragma once

#include "AbstractState.h"

	class SplashScreenState: public AbstractState {
		private:
			// The text objects
			sf::Text text, logo, next;

			// The font used in this state
			sf::Font font;


			// Private Methods

			// Initialize all the text for this state
			void init();

			void update( UserInput* userInput );

			// Handles User Input
			// And moving objects
			void updateGameplay( UserInput* userInput ) { }

			// Used for constructing the level
			void updateConstruction( UserInput* userInput ) { }

			// Render all the objects to the screen
			void render();

			void renderGame() { }

			void renderConstruction() { }

		public:
			// Empty Constructor
			SplashScreenState() { }

			// Empty Destructor
			~SplashScreenState() { }
	};