#pragma once

#include <SFML\Graphics.hpp>

#include <memory>
#include <string>

#include "UserInput.h"

#include "DynamicEntity.h"

	class PlayerAnimation {
		private:
			void arrowUp( DynamicEntity* player, UserInput* userInput );
			void arrowDown( DynamicEntity* player, UserInput* userInput );
			void noKey( DynamicEntity* player, UserInput* userInput );

			void neutralOnAnimationEnd( std::string animationName, DynamicEntity* player, UserInput* userInput );


		public:
			PlayerAnimation() { }
			
			~PlayerAnimation() { "Deleting: Player Controls"; }

			void update( DynamicEntity* player, UserInput* userInput );

	};