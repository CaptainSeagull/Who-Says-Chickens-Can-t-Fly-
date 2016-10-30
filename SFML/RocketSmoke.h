#pragma once

#include "AbstractEntity.h"

#include <SFML\Graphics.hpp>

	class RocketSmoke: public AbstractEntity {
		private:
			// The maximum distance particles travel from their spawn point
			//int maxRedFlameDistance = 0;
			//int maxFireDistance = 0;
			int maxSmokeDistance = 0;

			// The current distance, for each particle, from the spawn point
			//std::vector<int> redFlameDistance;
			//std::vector<int> fireDistance;
			std::vector<int> smokeDistance;

			// The movement speed
			//float redFlameSpeed = 0.0f;
			//float fireSpeed = 0.0f;
			float smokeSpeed = 0.0f;

			// The particles themselves
			//sf::VertexArray redFlame;
			//sf::VertexArray	fire;
			sf::VertexArray smoke;

			// The size of the spawn area
			sf::Vector2f size;

			// Render all the particles onscreen
			void draw(sf::RenderTarget& target, sf::RenderStates states) const;

		public:
			//=====================================================================================================================
			// Constructor, and
			// Destructor
			//=====================================================================================================================
			
			RocketSmoke() { }
			~RocketSmoke() { }


			//=====================================================================================================================
			// Create, and
			// Update methods
			//=====================================================================================================================

			// Create the particles
			// noOfPatciels is how many particles are in this effect
			void create();

			// Update the movement,
			// and lifetime of each particles
			// And respawn any that have 'died'
			void update();


			//=====================================================================================================================
			// Spawn Area Size
			//=====================================================================================================================

			// Set the size of the particle spawn area
			// Using sf::Vector2f
			void setSize( sf::Vector2f size ) { this->size = size; }

			// Set the size of the particle spawn area
			// Using two floats
			void setSize( float x, float y ) { this->size = sf::Vector2f( x, y ); }

			// Set the x size of the particle spawn area
			void setXSize( float x ) { this->size.x = x; }

			// Set the y size of the particle spawn area
			void setYSize( float y ) { this->size.y = y; }


			// Return the size of the particle spawn area
			sf::Vector2f getSize() { return size; }

			// Return the x size of the particle spawn area
			float  getXSize() { return size.x; }

			// Return the y size of the particle spawn area
			float getYSize() { return size.y; }
	};