#pragma once

#include <SFML\Graphics\RectangleShape.hpp>
#include <vector>

#include "EntityManager.h"
#include "UserInput.h"
#include "TextureManager.h"
#include "IOManager.h"
#include "Renderer.h"

	// The level editor
	class LevelEditor {
		private:
			//===============================================================================================================
			// Selection-Bar Stuff
			//===============================================================================================================
			
			std::vector < std::shared_ptr<DynamicEntity> > button;
			sf::RectangleShape m_bar;
			sf::RectangleShape m_selected;
			unsigned int m_distanceBetweenElements = 1;
			unsigned int m_currentlySelectedButtonsNumber;
			sf::Vector2f m_buttonSize;

			std::string m_currentState = "";
			unsigned int m_level = 0;
			unsigned int m_maxNoOfLevels = 0;

			//===============================================================================================================
			// Moouse, and
			// Camera Data
			//===============================================================================================================
			
			sf::Vector2f m_mousePosition;

			sf::Vector2f m_cameraPosition;
			sf::Vector2f m_cameraSize;

			// This is the placement grid
			sf::Vector2f m_grid;
		

			//===============================================================================================================
			// Entity Group Data
			//===============================================================================================================
			
			std::string m_groupName = "";

			// The maximum and minimum number of entities the group can have
			unsigned int m_max = 0;
			unsigned int m_min = 0;
		

			// Whether the State has been saved or not
			bool m_saved = true;

			std::string m_currentLevel = "";

			//===============================================================================================================
			// Private Methods
			//===============================================================================================================

			// Used when selecting an entity from the left-hand bar
			bool selectEntity( UserInput* userInput );

			// For Placing Entities
			bool placeEntity( EntityManager* entities, Renderer* renderer );

			// Output the entity's stats to the console
			void outputEntityStats( EntityManager* entities );

			// Move all entities, that are right of the mouse
			// bool right is whether to move them right or left
			void LevelEditor::moveEntitiesThatAreRightOfMouse( EntityManager* entities, bool right );

			// For Deleting Entities
			void deleteEntity( EntityManager* entities );

			
			// Save the changes for all groups
			// std::string levelName is the name of the current level
			void saveChanges( EntityManager* entities, std::string levelName );

			// Save the changes for all groups
			void saveChanges( EntityManager* entities );


		public:
			
			//===============================================================================================================
			// Constructor, and
			// Destructor
			//===============================================================================================================
			
			LevelEditor() { }
			~LevelEditor();


			//===============================================================================================================
			// Initializer Methods
			//===============================================================================================================

			// Initialize the class
			void init();

			// Add a new Button onto the right bar
			void addButton( std::string name, sf::Texture texture );

			// Set the name of the state current using the Level Editor
			void setCurrentState( std::string currentState ) { this->m_currentState = currentState; }

			// Set the name of the current level
			void setLevelData( std::string currentLevel ) { this->m_currentLevel = currentLevel; }


			//===============================================================================================================
			// Run Methods
			//===============================================================================================================

			// Should be called from the states Construction Method
			// Meaning this state handles all Level-Building stuff
			void run( EntityManager* entities, UserInput* userInput, Renderer* renderer, sf::Vector2f mousePosition );

			// Set the camera position and size
			void setCamera( sf::Vector2f cameraPosition, sf::Vector2f cameraSize ) { this->m_cameraPosition = cameraPosition; this->m_cameraSize = cameraSize; }


			// Should be called at the end of the state
			// This sets up data which will be rendered onscreen
			void setupDrawing();


			// Returns true or false
			// Based on whether the changes are saved or not
			bool areChangesSaved() { return m_saved; }

			// Draw Level-Editor Stuff onscreen
			void draw( sf::RenderWindow *window );

			
			//===============================================================================================================
			// Grid Methods
			//===============================================================================================================
			
			// Set the size of the placement grid
			// Using sf::Vector2f
			void setGrid( sf::Vector2f grid ) { this->m_grid = grid; }

			// Set the size of the placement grid
			// Using two floats
			void setGrid( float x, float y ) { this->m_grid = sf::Vector2f( x, y ); }

			// Return the placement grid
			// As sf::Vector2f
			sf::Vector2f getGrid() { return m_grid; }
	};