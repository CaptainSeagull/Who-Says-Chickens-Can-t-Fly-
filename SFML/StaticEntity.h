#pragma once

// The superclass
#include "AbstractEntity.h"

#include <SFML\Graphics.hpp>


// The std::vector library
#include <vector>

	// Used for static objects, which are objects that don't move
	class StaticEntity: public AbstractEntity {
		private:
			// Holds the objects texture
			sf::Sprite sprite;
			sf::Texture texture;

			// Whether the entity is on screen
			std::vector<int> onscreen;

			// Size, in x and y, of the tiled object
			// If the object is NOT tiled, this is 1 both ways
			sf::Vector2u m_size = sf::Vector2u( 1, 1 );

			// How fast the entity scrolls in each direction
			sf::Vector2f m_scrollingSpeed = sf::Vector2f( 0.0f, 0.0f );

			// Whether the texture is repeated or not
			bool m_repeated = true;

			// Draw the object
			virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

		public:
			//================================================================================
			// Constructors, and
			// Destructor
			//================================================================================

			// Default Constructor
			StaticEntity() { }

			// Set the object number
			StaticEntity( std::string type, int number ) { this->type = type; this->number = number; }


			// Destructor
			~StaticEntity() { }

			//====================================================================================================================
			// Updating
			//=====================================================================================================================

			// Set all the sprite data for the static entity
			// And make the entity scroll
			void update();


			//================================================================================
			// Create the tiled object
			// Can also create non-tiled object by setting x and y to 1
			//================================================================================

			// Assigns a texture to the entity
			// Texture is the sf::Texture which the object will use
			// And size is how much the object is tiled in the x and y directions
			// Repeated is whether the texture is repeated along or not
			void assignTexture( std::string texture, sf::Vector2u size, bool repeated );

			// Assigns a tiled texture to the object
			// Texture is a string to the key of the texture within the texture manager
			// And size is how much the object is tiled in the x and y directions
			// Repeated is whether the texture is repeated along or not
			void assignTexture( std::string texture, bool repeated ) { assignTexture( texture, m_size, repeated ); }

			// Assigns a tiled texture to the object
			// Size is how much the object is tiled in the x and y directions
			// Repeated is whether the texture is repeated along or not
			void assignTexture( sf::Vector2u size, bool repeated ) { assignTexture ( type, size, repeated ); }

			// Assigns a tiled texture to the object
			// Repeated is whether the texture is repeated along or not
			// The object's type will be used as the key for the texture
			void assignTexture( bool repeated ) { assignTexture( type, m_size, repeated ); }

			// Assigns a tiled texture to the object
			// The object's type will be used as the key for the texture
			void assignTexture() { assignTexture( type, m_size, false ); }

			// Assign a tiled texture to the object
			// Texture is the sf::Texture which the object will use
			void assignTexture ( sf::Texture, sf::Vector2u size );

			
			void changeTexture( std::string newTexture );

			//================================================================================
			// Scrolling
			//================================================================================

			// Set the scrolling speed of the object
			void setScrollingSpeed( sf::Vector2f scrollingSpeed ) { this->m_scrollingSpeed = scrollingSpeed; }

			// Make the object scroll
			void scroll() { setPosition( getPosition() - m_scrollingSpeed * AbstractEntity::deltaTime.asSeconds() ); }


			//================================================================================
			// Rendering
			//================================================================================

			// Setup data about the object for rendering
			void setSpriteData() { 	sprite.setPosition( sf::Vector2f( getPosition().x, getPosition().y ) ); }
	};