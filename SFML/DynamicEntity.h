#pragma once

// SFML
#include <SFML\Graphics.hpp>

// The superclass
#include "AbstractEntity.h"

// The std::vector library
#include <vector>

	// Holds some animation details about a frame of the entity
	struct Animation {
		std::string key = "";
		float animationSpeed = 0.0f;
		float minFrame = 0.0f;
		float maxFrame = 0.0f;
	};

	// Dynamic Entities are placeable through the Level Editor
	class DynamicEntity: public AbstractEntity {
		private:			
			bool m_currentlyOnscreen = false;
			
			// The size of the object
			// For collision purposes
			sf::Vector2f size;
			
			// Stores the object's texture
			sf::Texture texture;
			sf::VertexArray sprite;

			// For collision boxes
			sf::Vector2f m_collisionBoxPos = sf::Vector2f( 0.0f, 0.0f );
			sf::Vector2f m_collisionBoxSize = sf::Vector2f( 0.0f, 0.0f );
			sf::VertexArray m_collisionBox;

			// Animation stuff
			std::vector<Animation> m_frame;
			unsigned int m_currentAnimation = 0;
			std::string m_currentAnimationName = "";
			float m_currentFrame = 0.0f;

			// Acceleration
			sf::Vector2f m_currentSpeed;
			sf::Vector2f m_acceleration = sf::Vector2f( 0.0f, 0.0f );
			sf::Vector2f m_friction = sf::Vector2f ( 0.0f, 0.0f );


						
			// Whether this is a temperary entity
			// Or a perminant one
			// Eg, can be placed in the level-editor
			bool m_temperary = false;

			//=====================================================================================================================
			// Private Methods
			//=====================================================================================================================

			// Draw the Entity
			void draw(sf::RenderTarget& target, sf::RenderStates states) const;


			// Increment the entities frame rate
			void incrementFrame();


		public:
			//=====================================================================================================================
			// Constructor and
			// Destructor
			//=====================================================================================================================

			// Default Constructor
			DynamicEntity() { }

			// Set the object's number and type
			DynamicEntity( int number, std::string type ) { this->number = number; this->type = type; }


			// Destructor
			~DynamicEntity() { }

			void init();


			//====================================================================================================================
			// Updating
			//=====================================================================================================================

			// Update data about the entity
			void update();


			//====================================================================================================================
			// Animation
			//=====================================================================================================================
			
			// Returns true or false
			// Based on whether the object is animated or not
			bool hasAnimation() { if ( m_frame.size() > 0 ) return true;  else return false; }

			// Add a new Animation to the entity
			void addAnimation( std::string key, float minFrame, float maxFrame, float animationSpeed );

			// Set the current Entity's Animation
			// Returns true if the key was a valid animation
			// Or false if the animation was not found
			bool setAnimation( std::string key );

			// Returns a std::string
			// With the name of the current animation
			std::string getCurrentAnimation() { return m_currentAnimationName; }

			// Returns true or false
			// Based on whether the current animation has ended
			bool hasAnimationEnded() { hasAnimationEnded( m_currentAnimationName ); }

			// Returns true or false
			// Based on whether the specific animation has ended
			bool hasAnimationEnded( std::string animation );

			float getCurrentFrame() { return m_currentFrame; }


			//=====================================================================================================================
			// Rendering
			//=====================================================================================================================

			// Assign a texture to the object
			// std::string texture is a string to textures key
			void assignTexture( std::string texture );

			// Assign a texture to the object
			// The object's type will be used as the key to get the texture
			void assignTexture () { assignTexture( type ); }

			// Set whether the entity is onscreen or not
			void setOnscreen( bool currentlyOnscreen ) { this->m_currentlyOnscreen = currentlyOnscreen; }

			// Return true or false
			// Based on whether the entity is currently onscreen
			bool getOnscreen() { return m_currentlyOnscreen; }

			// Whether the collision boxes should get drawn or not
			static bool draw_collisionBoxes;

			// Setup data about the entities collision box
			void setupCollisionBoxes();

			// Set data for the sprite before rendering it
			void setSpriteData();


			//=====================================================================================================================
			// Size
			//=====================================================================================================================

			// Return the size of the object's sprite
			sf::Vector2f getSize() { return size; }

			// Return the size of the object's sprite
			// In the x direction
			float getXSize() { return size.x; }

			// Return the size of the object's sprite
			// In the y direction
			float getYSize() { return size.y; }

			// Set the size of the Entity
			// Using two floats
			void setSize( float x, float y ) { this->size = sf::Vector2f( x, y ); }

			// Set the size of the Entity
			// Using sf::Vector2f
			void setSize( sf::Vector2f size ) { this->size = size; }


			//=====================================================================================================================
			// Collision Detection
			//=====================================================================================================================

			void setCollisionBoundry( sf::Vector2f pos, sf::Vector2f size ) { this->m_collisionBoxPos = pos; this->m_collisionBoxSize = size; }

			sf::Vector2f getCollisionBoxPos() { return getPosition() + m_collisionBoxPos; }

			sf::Vector2f getCollisionBoxSize() { return m_collisionBoxSize; }


			// Test whether two entity's overlap
			bool intersects( DynamicEntity* o ) ;


			// Test whether a point is within an Entity
			bool contains( sf::Vector2f point );

			// Test whether a point is within an Entity
			bool contains( float x, float y ) { return contains( sf::Vector2f( x, y ) ); }


			//=====================================================================================================================
			// Whether the object is temperary or not
			// Temperary objects are like bullets
			// Perminant are like blocks or enemies
			//=====================================================================================================================

			// Set whether the object is temperary or not
			void setTemperary( bool temperary ) { this->m_temperary = temperary; }

			// Return whether the object is temperary or not
			bool getTemperary() { return m_temperary; }


			//=====================================================================================================================
			// Acceleration
			//=====================================================================================================================

			// Set the acceleration-factor for the entity
			// As sf::Vector2f
			void setAcceleration( sf::Vector2f acceleration ) { this->m_acceleration = acceleration; }

			// Set the acceleration-factor for the entity
			// As two floats
			void setAcceleration( float x, float y ) { setAcceleration( sf::Vector2f( x, y ) ); }


			// Set the friction for the entity
			// As a sf::Vector2f
			void setFriction( sf::Vector2f friction ) { m_friction = friction; }

			// Set the friction for the entity
			// As two floats
			void setFriction( float x, float y ) { setFriction( sf::Vector2f( x, y ) ); }



			// Move the Entity's x
			// Based on an inputted acceleration
			void accelerateX( float acceleration );

			// Move the Entity's x
			// Based on it's acceleration
			void accelerateX() { accelerateX( m_acceleration.x ); }


			// Move the Entity's y
			// Based on an inputted acceleration
			void accelerateY ( float acceleration );

			// Move the Entity's y
			// Based on it's acceleration
			void accelerateY() { accelerateY ( m_acceleration.y ); }


			// Move the Entity's -x
			// Based on an inputted acceleration
			void accelerateNX( float acceleration );

			// Move the Entity's -x
			// Based on it's acceleration
			void accelerateNX() { accelerateNX( m_acceleration.x ); }


			// Move the Entity's -y
			// Based on an inputted acceleration
			void accelerateNY( float acceleration );

			// Move the Entity's -y
			// Based on it's acceleration
			void accelerateNY() { accelerateNY( m_acceleration.y ); }




			// Set the entity's current speed to zero
			void resetCurrentSpeed();

			// Set the entity's current horizontal speed to zero
			void resetCurrentHorSpeed();

			// Set the entity's current vertical speed to zero
			void resetCurrentVertSpeed();


			// Return the entity's current speed
			// As a sf::Vector2f
			sf::Vector2f getCurrentSpeed() { return this->m_currentSpeed; }

			// Return the entity's current x-speed
			// As a float
			float getCurrentXSpeed() { return this->m_currentSpeed.x; }

			// Return the entity's current y-speed
			// As a float
			float getCurrentYSpeed() { return this->m_currentSpeed.y; }
	};