#pragma once

// Used to changed stattes
#include "StateManager.h"

// Used for outputting errors and warnings
#include "ErrorHandler.h"

// For Smart Pointers
#include <memory>

	// This is the main game class
	// Which is called from WinMain()
	class GameContext {
		private:
			// The window, which is passed into the function in the constructor
			HWND window = nullptr;

			// The game states
			std::unique_ptr<StateManager> stateManager;

			// For Frame Limiting
			sf::Clock clock;

			// Whether the init() function has been called or not
			bool m_initialized = false;

			// The number of draw calls that can be skipped when the game slows down
			unsigned int m_drawSkip = 0;


		public:
			// Constructors
			// Gets the window from the WinMain() method
			GameContext( const HWND window)
				: window(window) {}

			// Destructor
			// Deletes the managers
			~GameContext();

			// Initialize all objects within GameContext
			void init();

			// Handles the main program loop
			// And must be called AFTER init()
			void run();

			// Handes Updating and Rendering the State
			void runAndDraw();
	};