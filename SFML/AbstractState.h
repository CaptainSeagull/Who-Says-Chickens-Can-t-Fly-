#pragma once

// The Windows API
#include <Windows.h>

// Standard I/O and String Handelling
#include <iostream>
#include <string>

// Include SFML's Graphics library
#include "SFML\Graphics.hpp"

// Include the Texture Manager, so objects can be textured
#include "TextureManager.h"

// For reading in .txt files
#include "IOManager.h"

// For handling errors
#include "ErrorHandler.h"

// User Input Class
#include "UserInput.h"

// For outputting text
#include "TextManager.h"

#include "SoundManager.h"

// For Unique Pointer
#include <memory>

	// This is the base state which every state inherits from
	class AbstractState {
		private:
			// The window which everything is drawn on
			HWND MainWindow;


			// This is whether the state is in construction mode or not
			bool isConstruction = false;

			// Whether the game has been paused or not
			bool paused = false;


			// Handles SFML events
			sf::Event event;

			// Whether the window is in focus or not
			bool focus = true;

			// Whether the game was in focus or not in the last frame
			bool focus_previous = false;

			// Whether the state should be switched or not
			bool should_switchState = false;

		protected:
			//===============================================================================================================================================================================
			// Managers
			//===============================================================================================================================================================================			

			// Is used forn outputting text to the screen
			std::unique_ptr<TextManager> textManager;

			// Handles Music and Sound Effects
			std::unique_ptr<SoundManager> soundManager;

			// Handles User Input
			std::unique_ptr<UserInput> userInput;

			// Call this method to initialize all the game managers
			bool initializeManagers();


			//===============================================================================================================================================================================
			// State
			//===============================================================================================================================================================================
			
			// Should be set to the state's name during init()
			// But should not be touched again
			std::string currentState;
			

			// Reload the state
			void restart() { currentState = "Restart"; should_switchState = true; }


			//===============================================================================================================================================================================
			// Window
			//===============================================================================================================================================================================

			// Returns the window which everything is drawn on
			// Can only be called from a inherited class
			HWND getWindow() { std::cout << "\nHereeeeeeeeeeeeeeee!"; return MainWindow; }

			// The window which the state draws to
			sf::RenderWindow window;


			//===============================================================================================================================================================================
			// Construction Mode
			//===============================================================================================================================================================================

			// Set the mode to construction mode
			void setConstruction( bool construction ) { this->isConstruction = construction; }

			// Switch between construction and normal mode
			void toggleConstruction() { if ( isConstruction == true ) { isConstruction = false; } else { isConstruction = true; } }

			// Returns true or false
			// Based on whether construction mode is on or not
			bool getConstruction() { return isConstruction; }

			
			// This is whether the previous update-method was construction or play
			bool previous_construction = false;


			//===============================================================================================================================================================================
			// Virtual Methods
			// Unique to each subclass
			//===============================================================================================================================================================================

			// Initialize the state
			virtual void init() = 0;


			// Update the state
			// This is called for both gameplay and construction mode
			virtual void update( UserInput* userInput ) = 0;

			// Update the state's gameplay
			// This should control all the physics and keyboard presses
			virtual void updateGameplay( UserInput* userInput ) = 0;

			// For building the state when it's in construction mode
			virtual void updateConstruction( UserInput* userInput ) = 0;




			// Render the state onto a screen
			// The window to render to can be gotten using the getWindow() method
			virtual void render() = 0;

			// Render things to the screen
			// Which should ONLY get drawn in Gameplay and not Construction Mode
			virtual void renderGame() = 0;

			// Render thing to the screen
			// Which should ONLY get drawn in Construction Mode and not in Gameplay
			virtual void renderConstruction() = 0;

		public:
			//===============================================================================================================================================================================
			// Constructor, and
			// Destructor
			//===============================================================================================================================================================================
			
			// Empty Constructor	
			AbstractState() { }
				
			// Constructor, which deletes the Managers	
			virtual ~AbstractState();


			//===============================================================================================================================================================================
			// Initialization
			//===============================================================================================================================================================================

			// Setup some default information about the state
			// And call the init() state45
			void setUp( const HWND MainWindow );


			//===============================================================================================================================================================================
			// Updating Logic
			//===============================================================================================================================================================================

			// This holds the game loop for the state
			// Will call the update function first
			// Then clear the screen, render the state, and push it onto the screen
			void gameLoop();

			
			//===============================================================================================================================================================================
			// Rendering
			//===============================================================================================================================================================================

			// Draw the current state
			void renderState();


			//===============================================================================================================================================================================
			// States
			//===============================================================================================================================================================================

			// Returns what the current state is set to
			std::string getState() { return currentState; }

			// Returns true or false
			// Based on whether the current state should switch or not
			bool getSwitch() { return should_switchState; }

			// Should be called when you want to switch state
			void switchState( std::string state ) { currentState = state; should_switchState = true; }

			//====
			// Loading
			//==

			// Loading screen
			// Write a message telling the user what's being loaded
			void load( std::string objectBeingLoaded );
	};