#pragma once

// SFML
#include <SFML\Graphics\Drawable.hpp>
#include <SFML\Graphics\Transformable.hpp>

#include "AbstractComponent.h"

#include <memory>

#include <vector>

	// The AbstractEntity class
	// Which most other class inherit from
	class Entity: public sf::Drawable, public sf::Transformable {
		private:
			std::vector < std::unique_ptr<AbstractComponent> > m_component;
			std::string type;

		public:
			Entity() { }
			~Entity() { }

			void addComponent( std::unique_ptr<AbstractComponent> component ) {
				this->m_component.push_back( std::move( component ) );
			}

			bool hasComponent( std::string componentName ) {
				for ( unsigned int i=0; i<m_component.size(); i++ ) {
					if ( m_component.at(i)->getName() == componentName ) {
						return true;
					}
				}

				return false;
			}

	};
	/*
		protected:
			//=====================================================================================================================
			// Entity Data
			//=====================================================================================================================
			
			// Whether the entity will be drawn or not
			bool visible = true;

			// The number of the entity within a group
			unsigned int number;

			// The type of entity
			std::string type;

			// Holds the entity's speed
			sf::Vector2f speed;

			// Whether the entity is onscreen or not
			bool onscreen = true;

			// The layer the entity is on
			unsigned int layer = 0;

			// Whether the entity is deleted or not
			bool m_deleted = false;


		public:
			//=====================================================================================================================
			// Constructor and
			// Destructor
			//=====================================================================================================================

			// Constructor
			Entity() { }

			// Virtual Destructor
			virtual ~Entity() { }

			// Delta time is the time taken to complete the entire game loop
			// And is multiplied onto any movement to give the effect of slow movement
			static sf::Time deltaTime;

			// This is the texture manager
			static TextureManager textureManager;

			//=====================================================================================================================
			// Entity Type,
			// and Number
			//=====================================================================================================================

			// Return the entity type
			// As a std::string
			std::string getType() { return type; }

			// Return the entities number within their group
			unsigned int getNumber() { return number; }


			//=====================================================================================================================
			// Deleted
			//=====================================================================================================================

			void setDeleted( bool deleted ) { this->m_deleted = deleted; }

			bool getDeleted() { return m_deleted; }


			//=====================================================================================================================
			// Rendering
			//=====================================================================================================================

			void setLayer( unsigned int layer ) { this->layer = layer; }

			unsigned int getLayer() { return layer; }

			virtual void setSpriteData() { }


			// Set whether the entity should be drawn or not
			// True means it will be drawn
			// False means it will not be drawn
			void setVisible(bool visible) { this->visible = visible; }

			// Toggle the visibility of the entity
			// So, true = false
			// and false = true
			void toggleVisible() { if (visible == true) visible = false;  else visible = true; }

			// Return whether the Entity will be drawn or not
			bool getVisible() { return visible; }


			//=====================================================================================================================
			// Set the origin
			//=====================================================================================================================

			// Set the x origin of the Entity
			void setXOrigin( float x_origin ) { setOrigin( sf::Vector2f( x_origin, getOrigin().y ) ); }

			// Set the y origin of the Entity
			void setYOrigin( float y_origin ) { setOrigin( sf::Vector2f( getOrigin().x, y_origin ) ); }

			// Return the x origin of the Entity
			float getXOrigin() { return getOrigin().x; }

			// Return the y origin of the Entity
			float getYOrigin() { return getOrigin().y; }


			//=====================================================================================================================
			// Speed
			//=====================================================================================================================
			
			// Set the speed of the Entity as a sf::Vector2f
			void setSpeed( sf::Vector2f speed ) { this->speed = speed; }

			// Set the speed of the Entity as x and y floats
			void setSpeed( float x_speed, float y_speed ) { this->speed = sf::Vector2f( x_speed, y_speed ); }

			// Set the speed of the Entity
			// This just assigns the parameter to both the x and y speeds
			void setSpeed( float speed ) { this->speed = sf::Vector2f( speed, speed ); }

			// Set the speed of the x parameter
			void setXSpeed( float x_speed ) { this->speed.x = x_speed; }

			// Set the speed of the y parameter
			void setYSpeed( float y_speed ) { this->speed.y = y_speed; }


			// Return the object's speed as a sf::Vector2f
			sf::Vector2f getSpeed() { return speed; }

			// Return the x speed of the Entity
			float getXSpeed() { return speed.x; }

			// Return the y speed of the Entity
			float getYSpeed() { return speed.y; }


			//=====================================================================================================================
			// Position
			//=====================================================================================================================

			// Set the position of an Entity
			// Overwritting it's pervious position
			// Using a sf::Vector2f
			void setPosition( sf::Vector2f position ) { sf::Transformable::setPosition( position ); }

			// Set the position of an Entity
			// Overwritting it's pervious position
			// Using a two floats
			void setPosition( float x_position, float y_position ) { sf::Transformable::setPosition( x_position, y_position ); }
			
			// Set the position of an Entity
			// Overwritting it's pervious position
			// Using a std::string
			// NOTE - Format must be: x + ' ' + y
			void setPosition( std::string position ) { sf::Transformable::setPosition( Utility::StringToVector2f(position) ); }

			// Set the Entity's x position
			void setX( float x ) { sf::Transformable::setPosition( sf::Vector2f( x, getPosition().y ) ); }

			// Set the Entity's y position
			void setY( float y ) { sf::Transformable::setPosition( sf::Vector2f( getPosition().x, y ) ); }

			// Return the Entity's current position
			// As a std::string
			// In the format: x + " " + y
			std::string getPositionAsString() { return std::to_string( getPosition().x ) + " " + std::to_string( getPosition().y ); }

			// Return the Entity's x position
			float getX() { return getPosition().x; }

			// Return the Entity's y position
			float getY() { return getPosition().y; }


			//=====================================================================================================================
			// Centre Position
			//=====================================================================================================================

			// Set the centre position of an Entity
			// Overwritting it's pervious position
			// Using a sf::Vector2f
			void setCentre( sf::Vector2f position ) { sf::Transformable::setPosition( position - ( getSize()/2.0f ) ); }

			// Set the centre position of an Entity
			// Overwritting it's pervious position
			// Using a two floats
			void setCentre( float x_position, float y_position ) { sf::Transformable::setPosition( x_position - ( getSize().x/2.0f ), y_position - ( getSize().y/2.0f ) ); }
			
			// Set the centre position of an Entity
			// Overwritting it's pervious position
			// Using a std::string
			// NOTE - Format must be: x + ' ' + y
			void setCentre( std::string position ) { sf::Transformable::setPosition( Utility::StringToVector2f(position) - ( getSize()/2.0f ) ); }

			// Set the Entity's centre x position
			void setCentreX( float x ) { sf::Transformable::setPosition( sf::Vector2f( x-getSize().x, getPosition().y ) ); }

			// Set the Entity's centre y position
			void setCentreY( float y ) { sf::Transformable::setPosition( sf::Vector2f( getPosition().x, y-getSize().y ) ); }
			
			// Return the Entity's centre position
			sf::Vector2f getCentre() { return sf::Transformable::getPosition() + ( getSize()/2.0f ); }
			
			// Return the Entity's current centre
			// As a std::string
			// In the format: x + " " + y
			std::string getCentreAsString() { return std::to_string( getCentre().x ) + " " + std::to_string( getCentre().y ); }

			// Return the Entity's centre x position
			float getCentreX() { return getCentre().x; }

			// Return the Entity's centre y position
			float getCentreY() { return getCentre().y; }


			//=====================================================================================================================
			// Movement
			//=====================================================================================================================

			void move( sf::Vector2f displacement ) { Transformable::move( displacement*deltaTime.asSeconds() ); }

			void move( float x, float y ) { Transformable::move( sf::Vector2f( x, y ) * deltaTime.asSeconds() ); }

			// Move the x coordinate of the Entity
			void moveX( float x ) { Transformable::move( x*deltaTime.asSeconds(), 0.0f ); }

			// Move the y coordinate of the Entity
			void moveY( float y ) { Transformable::move( sf::Vector2f( 0.0f, y*deltaTime.asSeconds() ) ); }


			// Move the Entity based on it's speed
			void move() { Transformable::move( speed*deltaTime.asSeconds() ); }

			// Move the Entity's x based on it's speed
			void moveX() { Transformable::move( sf::Vector2f( speed.x*deltaTime.asSeconds(), 0.0f ) ); }

			// Move the Entity's y based on it's speed
			void moveY() { Transformable::move( sf::Vector2f( 0.0f, speed.y*deltaTime.asSeconds() ) ); }


			// Move the Entity based on it's speed
			void moveN() { Transformable::move( -speed*deltaTime.asSeconds() ); }

			// Move the Entity's x based on it's speed
			void moveNX() { Transformable::move( sf::Vector2f( -speed.x*deltaTime.asSeconds(), 0.0f ) ); }

			// Move the Entity's y based on it's speed
			void moveNY() { Transformable::move( sf::Vector2f( 0.0f, -speed.y*deltaTime.asSeconds() ) ); }


			//=====================================================================================================================
			// Snap to Grid
			//=====================================================================================================================

			// Snap the Entity onto a grid specified
			// sf::Vector2f grid: The size of the grid spaces
			// sf::Vector2f maxSize: The Maximum size to assign to
			void snapToGrid( sf::Vector2f grid, sf::Vector2f maxSize );

			// Snap the Entity onto a grid specified
			// sf::Vector2f grid: The size of the grid spaces
			void snapToGrid( sf::Vector2f grid ) { snapToGrid( grid, sf::Vector2f( (float) LONG_MAX, (float) LONG_MAX ) ); }
			
			// Snap the Entity onto a grid specified
			// float grid_x and grid_y: The size of the grid spaces
			void snapToGrid( float grid_x, float grid_y ) { snapToGrid( sf::Vector2f( grid_x, grid_y ), sf::Vector2f( (float) LONG_MAX, (float) LONG_MAX ) ); }

			// Snap the Entity onto a grid specified
			// float grid: How large the grid spaces
			void snapToGrid( float grid ) { snapToGrid( sf::Vector2f( grid, grid ), sf::Vector2f( (float) LONG_MAX, (float) LONG_MAX ) ); }
			
			// Snap the Entity onto a grid specified
			// sf::Vector2f grid: The size of the grid spaces
			// float max_x and maxY: The Maximum size to assign to
			void snapToGrid( sf::Vector2f grid, float max_x, float max_y ) { snapToGrid( grid, sf::Vector2f( max_x, max_y ) ); }

			// Snap the Entity onto a grid specified
			// float grid_x and grid_y: The size of the grid spaces
			// sf::Vector2f maxSize: The Maximum size to assign to
			void snapToGrid( float grid_x, float grid_y, sf::Vector2f maxSize ) { snapToGrid( sf::Vector2f( grid_x, grid_y ), maxSize ); }

			// Snap the Entity onto a grid specified
			// float grid_x and grid_y: The size of the grid spaces
			// float max_x and max_y: The Maximum size to assign to
			void snapToGrid( float grid_x, float grid_y, float max_x, float max_y ) { snapToGrid( sf::Vector2f (grid_x, grid_y ), sf::Vector2f( max_x, max_y ) ); }

			// Snap the Entity onto a grid specified
			// float grid: How large the grid spaces
			void snapToGrid( float grid, sf::Vector2f maxSize ) { snapToGrid( sf::Vector2f( grid, grid ), maxSize ); }


			//=====================================================================================================================
			// Scale
			//=====================================================================================================================

			// Set the x scale of the Entity
			void setXScale( float x_scale ) { setScale( sf::Vector2f( x_scale, getScale().y ) ); }

			// Set the y scale of the Entity
			void setYScale( float y_scale ) { setScale( sf::Vector2f( getScale().x, y_scale ) ); }

			// Return the x scale of the Entity
			float getXScale() { return getScale().x; }

			// Return the y scale of the Entity
			float getYScale() { return getScale().y; }

			
			//=====================================================================================================================
			// Size
			//=====================================================================================================================

			// Return the size of the object
			virtual sf::Vector2f getSize() { return getScale(); }

			// Return the size of the object's sprite
			// In the x direction
			virtual float getXSize() { return getScale().x; }

			// Return the size of the object's sprite
			// In the y direction
			virtual float getYSize() { return getScale().y; }
			

			//=====================================================================================================================
			// Distance to Point
			//=====================================================================================================================

			// Return the distance between the entity and a point
			// The point is a sf::Vector2f
			float distanceToPoint( sf::Vector2f point ) { return sqrt( pow( getPosition().x + (getSize().x/2) - point.x, 2 ) + pow( getPosition().y + (getSize().y/2) - point.y, 2 ) ); }


			// Return the distance between the entity and a point
			// The point is two floats
			float distanceToPoint( float x, float y ) { return distanceToPoint( sf::Vector2f( x, y ) );}

			// Return true if the entity is smaller
			// than a specificied distance to a point
			// And false if it's larger
			// The point is a sf::Vector2f
			// The distance is a float
			bool distanceToPoint( sf::Vector2f point, float distance ) { if ( distanceToPoint( point ) < distance ) return true;  else return false; }

			// Return true if the entity is smaller
			// than a specificied distance to a point
			// And false if it's larger
			// The point is two floats
			// The distance is a float
			bool distanceToPoint( float x, float y, float distance ) { return distanceToPoint( sf::Vector2f( x, y ), distance ); }

			
			//=====================================================================================================================
			// Collision Detection
			//=====================================================================================================================

			// Test whether two entity's overlap
			bool intersects( Entity* o ) ;

			// Test whether two entity's overlap
			bool circleIntersects( Entity* o );

			// Test whether a point is within an Entity
			virtual bool contains( sf::Vector2f point );

			// Test whether a point is within an Entity
			virtual bool contains( float x, float y ) { return contains( sf::Vector2f( x, y ) ); }

			// Returns whether the entity is on screen
			bool onScreen( sf::RectangleShape screen );

			
			//=====================================================================================================================
			// Move towards point
			//=====================================================================================================================

			// Move the object towarda a point
			// Based on a speed
			void moveTowardsPoint( sf::Vector2f point, float speed );

			// Move the object towarda a point
			// Based on a speed
			void moveTowardsPoint( float x, float y, float speed ) { moveTowardsPoint( sf::Vector2f( x, y ), speed ); }
	};
	*/