#pragma once

#include "AbstractState.h"

	class CreditsState: public AbstractState {
		private:
			// The text objects
			sf::Text title;
			std::vector<sf::Text> m_names;
			unsigned int m_noOfPeople = 2;

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
			CreditsState() { }

			// Empty Destructor
			~CreditsState() { }
	};