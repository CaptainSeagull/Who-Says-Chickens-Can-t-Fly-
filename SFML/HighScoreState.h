#pragma once

#include "AbstractState.h"
#include "IOManager.h"


	class HighScoreState: public AbstractState {
		private:
			// The text objects
			sf::Text scores;
			sf::Text m_title;
			std::vector< std::string > m_everyone;

			// The font used in this state
			sf::Font font;

			bool m_getName = true;
			int m_userScore;


			// Private Methods

			// Initialize all the text for this state
			void init();

			void load_Title();
			void load_Scores();
			void load_UserScore();

			void sort();



			void update( UserInput* userInput );


			// Handles User Input
			// And moving objects
			void updateGameplay( UserInput* userInput ) { }

			// Used for constructing the level
			void updateConstruction( UserInput* userInput ) { }


			void updateGetName( UserInput* userInput );



			// Render all the objects to the screen
			void render();

			void renderGame() { }

			void renderConstruction() { }

		public:
			// Empty Constructor
			HighScoreState() { }

			// Empty Destructor
			~HighScoreState() { }
	};