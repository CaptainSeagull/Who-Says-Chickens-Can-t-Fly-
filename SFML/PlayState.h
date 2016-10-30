#pragma once

// The superclass
#include "AbstractState.h"

#include "Utility.h"

// For using the std::vector class
#include <Vector>

// The base class for all game objects
#include "AbstractEntity.h"

// Stores all the game entity's
#include "EntityManager.h"

// Entity's are Game Objects
#include "DynamicEntity.h"
#include "StaticEntity.h"

// The camera class
#include "Camera.h"

// For Smart Pointers
#include <memory>

#include "Controllers.h"

#include "LevelEditor.h"



	struct VectorOfStrings {
		std::vector< std::string > str;
	};

	struct LevelData {
		unsigned int maxNoOfLevels = 0;
		unsigned int currentLevel = 0;
		std::string startingLevel = "";
		std::string currentLevelAsString;
		VectorOfStrings levels;
	};

	// This is the main game state
	class PlayState: public AbstractState {
		private:
			// If this is set to false
			// The the update function will not be called
			bool updateLogic = false;

			// Holds all the Game Entities
			std::unique_ptr<EntityManager> entities;
			std::unique_ptr<Camera> camera;

			// Stuff to control the game flow
			// Includes a GameLogic updater and a Renderer
			std::unique_ptr<Controllers> controllers;

			unsigned int m_noOfEnemyTypes = 0;

			// Text Data
			sf::Vector2f m_notSavedPositionRelativeToCamera = sf::Vector2f( 0.0f, 0.0f );

			// The position on-screen the score's drawn at
			sf::Vector2f m_scorePosRelativeToCamera = sf::Vector2f( 0.0f, 0.0f );

			// The number of background layers
			unsigned int m_numberOfBackgroundLayers;

			// The 'seed' folder
			std::string m_folderName = "";

			// Level Stuff
			LevelData m_levelData;


			//=======================================================================================================================
			// Private Methods
			//=======================================================================================================================

			// Initialize the state
			// Is called in AbstractState's setUp() method
			void init();

			// Update Method
			// Upate from both Gameplay and Construction
			void update( UserInput* userInput );

			// Handles updating gameplay
			void updateGameplay( UserInput* userInput );

			// Handles updating Construction-Mode stuff
			void updateConstruction( UserInput* userInput );


			// Render all the objects to the screen
			void render();

			// Render Gameplay-specific object
			void renderGame();

			// Render Construction Mode-specfic object
			void renderConstruction();

			// Loading
			void load_levelData();
			void load_textures();
			void load_Sound();
			void load_Player();
			void load_PlayerDead();
			void load_Bullets();
			void load_Enemies();
			void load_Camera();
			void load_Background();
			void load_Fonts();
			void load_Score();
			void load_Particles();
			void load_EventObjects();
			void load_Controllers();
			void load_LevelEditor();

			void load_group( std::string name );

			void loadLevel( std::string level );

			void load_saveGame();
			void save_game();

		public:
			// Empty Constructor
			PlayState() { }

			// Destructor
			// Deletes all Entity's
			~PlayState();
	};