#pragma once

#include "AbstractState.h"

#include "EntityManager.h"

#include "Camera.h"

#include "Controllers.h"

#include "Utility.h"

	class MainMenuState: public AbstractState {
		private:
			// For the help screen
			// Whether it is currently displayed or not
			bool m_helpDisplayed = false;


			// The text objects
			sf::Text text, logo, next;

			// The font used in this state
			sf::Font font;

			// Holds all the buttons
			std::unique_ptr<EntityManager> buttons;

			// The camera
			std::unique_ptr<Camera> camera;

			
			// Stuff to control the game flow
			// Includes a GameLogic updater and a Renderer
			std::unique_ptr<Controllers> controllers;


			std::vector<std::string> m_buttonNames;
			std::vector<int> m_buttonHighlighted;


			// Private Methods

			// Initialize all the text for this state
			void init();

			void load_group(std::string name);


			void update( UserInput* userInput );

			// Handles User Input
			// And moving objects
			void updateGameplay( UserInput* userInput );

			// Used for constructing the level
			void updateConstruction( UserInput* userInput );

			// Render all the objects to the screen
			void render();

			void renderGame();

			void renderConstruction();

		public:
			// Empty Constructor
			MainMenuState() { }

			// Destructor
			~MainMenuState();

		private:
			void load_Textures();
			void load_Camera();
			void load_Buttons();
			void load_HelpScreen();
			void load_Controllers();
			void load_LevelEditor();
	};