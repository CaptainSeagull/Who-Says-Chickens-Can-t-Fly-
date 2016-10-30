#pragma once

// A class to handle game logic
#include "GameLogic.h"

// A class to renderer Entities
#include "Renderer.h"

// For editing Levels
#include "LevelEditor.h"


	// Stores all the controllers
	// Controllers do actions on Entities
	class Controllers  {
		public:
			//std::unique_ptr<PlayerControls> playerControls;
			std::unique_ptr<Renderer> renderer;
			std::unique_ptr<GameLogic> gameLogic;
			std::unique_ptr<LevelEditor> levelEditor;

			Controllers() { }
			~Controllers();

			bool init();
	};