#pragma once

#include <SFML\Graphics.hpp>

#include <memory>

#include "UserInput.h"

#include "DynamicEntity.h"

	class PlayerControls {
		private:
			// Whether movement is mouse or keyboard
			bool m_keyboard = false;
			float m_playerMouseSpeed = 600.0f;

			// Whether any of the keys were pressed this time or not
			sf::Vector2i m_lastDirection;

			sf::Vector2i m_anyKeyPressed;
			
			// The keys for movement
			std::string m_up = "";
			std::string m_down = "";
			std::string m_left = "";
			std::string m_right = "";
			
			// Keyboard controls
			void moveLeft( DynamicEntity* player, UserInput* userInput );
			void moveRight( DynamicEntity* player, UserInput* userInput );
			void moveUp( DynamicEntity* player, UserInput* userInput );
			void moveDown( DynamicEntity* player, UserInput* userInput );

			void mouse( DynamicEntity* player, sf::Vector2f mousePos );
	
		public:
			// For Mouse
			PlayerControls( float playerMouseSpeed )
				: m_playerMouseSpeed( playerMouseSpeed ), m_keyboard( false ) {}

			// For keybiard
			PlayerControls( std::string upKey, std::string downKey, std::string rightKey, std::string leftKey )
				: m_up( upKey ), m_down( downKey ), m_left( leftKey ), m_right( rightKey ), m_keyboard( true ) {}
			~PlayerControls() { std::cout << '\n' << "Deleting: Player Controls"; }

			void update( DynamicEntity* player, UserInput* userInput, sf::Vector2f mousePos );

			// Set to true to enable keyboard movement
			// Or false to enable mouse movement
			void setKeyboard( bool keyboard ) { this->m_keyboard = keyboard; }
	};