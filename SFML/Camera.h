#pragma once

#include <SFML/Graphics.hpp>

#include "AbstractEntity.h"

	// This is a class which controls the camera's position
	class Camera: public AbstractEntity {
		private:
			// How fast the object moves
			sf::Vector2f speed;

			// The zoom speed and default size
			sf::Vector2f m_zoomSpeed = sf::Vector2f( 0.0f, 0.0f );
			sf::Vector2f m_defaultSize = sf::Vector2f( 0.0f, 0.0f );

			// Collision Margins for the player
			float marginLeft = 0.0f;
			float marginRight = 0.0f;
			float marginBottom = 0.0f;
			float marginTop = 0.0f;

			// The current view
			sf::View view;

			// Sets the game's view to the camera's view
			virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const { target.setView(view); }

		public:
			//=====================================================================================================================
			// Constructor, and
			// Destructor
			//=====================================================================================================================
			
			// Default Constructor
			Camera() { }

			// Destructor
			~Camera() { std::cout << '\n' << "Deleting: Camera"; }

			void update() { }


			//=====================================================================================================================
			// View
			//=====================================================================================================================

			// Return the view
			// For putting in the window
			sf::View getView() { return view; }

			// Set the size of the view
			// Using sf::Vector2f
			void setSize( sf::Vector2f size ) { view.setSize( size ); }

			// Set the size of the view
			// Using two floats
			void setSize( float width, float height ) { view.setSize( sf::Vector2f( width, height ) ); }

			// Return the size of the view
			sf::Vector2f getSize() { return view.getSize(); }

			// Return a rectangle the same size as the camera view
			sf::RectangleShape getRectView();
			
			//=====================================================================================================================
			// The Margin
			// For the player
			//=====================================================================================================================

			void setMargins( float marginLeft, float marginRight, float marginTop, float marginBottom ) {
				this->marginLeft = marginLeft;
				this->marginRight = marginRight;
				this->marginTop = marginTop;
				this->marginBottom = marginBottom;
			}

			float getLeftMargin() { return getPosition().x + marginLeft; }

			float getRightMargin() { return ( getPosition().x + getSize().x ) - marginRight; }

			float getTopMargin() { return getPosition().y + marginTop; }

			float getBottomMargin() { return ( getPosition().y + getSize().y ) - marginBottom; }
			


			//=====================================================================================================================
			// Centre Position
			//=====================================================================================================================
			
			// Set the Camera's Centre Position as a sf::Vector2f
			void setCentre( sf::Vector2f position ) { view.setCenter( position ); }

			// Set the Camera's Centre Position as two floats
			void setCentre( float x, float y ) { view.setCenter( sf::Vector2f( x, y ) ); }

			// Set the Camera's Centre x Position
			void setCentreX( float x ) { view.setCenter( sf::Vector2f( x, view.getCenter().y ) ); }

			// Set the Camera's Centre y Position
			void setCentreY( float y ) { view.setCenter( sf::Vector2f( view.getCenter().x, y ) ); }

			// Return the Camera's current Centre Position as a sf::Vector2f
			sf::Vector2f getCentrePosition() { return view.getCenter(); }

			// Return the Camera's Centre x Position
			float getCentreX() { return view.getCenter().x; }

			// Return the Camera's Centre y osition
			float getCentreY() { return view.getCenter().y; }


			//=====================================================================================================================
			// Top-Left Position
			//=====================================================================================================================

			// Set the Camera's Top-Left Position as a sf::Vector2f
			void setPosition( sf::Vector2f position ) { view.setCenter( position + sf::Vector2f( view.getSize().x/2.0f, view.getSize().y/2.0f ) ); }

			// Set the Camera's Top-Left Position as two floats
			void setPosition( float x, float y ) { setPosition( sf::Vector2f( x, y ) ); }

			// Return the Camera's Top-Left Position as a sf::Vector2f
			sf::Vector2f getPosition() { return view.getCenter() - sf::Vector2f( view.getSize().x/2.0f, view.getSize().y/2.0f ); }

			// Return the Camera's Top-Left x Position
			float getX() { return getPosition().x; }

			// Return the Camera's Top-Left y Position
			float getY() { return getPosition().y; }

			// Set the Camera's Top-Left x Position
			void setX( float x ) { setPosition( x, getY() ); }

			// Set the Camera's Top-Left y Position
			void setY( float y ) { setPosition( getX(), y ); }

			//=====================================================================================================================
			// Movement
			//=====================================================================================================================
			
			// Move the object
			// Using sf::Vector2f
			void move( sf::Vector2f displacement ) { AbstractEntity::move( displacement ); }

			// Move the object
			// Using two floats
			void move( float x, float y ) { AbstractEntity::move( sf::Vector2f( x, y ) ); }

			// Move the x coordinate of the Camera
			void moveX( float x ) { AbstractEntity::move( x, 0.0f ); }

			// Move the y coordinate of the Camera
			void moveY( float y ) { AbstractEntity::move( 0.0f, y ); }


			// Move the Camera based on it's speed
			void move() { AbstractEntity::setPosition( getX() + speed.x, getY() + speed.y ); }

			// Move the Camera's x based on it's speed
			void moveX() { setX( speed.x * AbstractEntity::deltaTime.asSeconds() ); }

			// Move the Camera's y based on it's speed
			void moveY() { setX( -speed.x * AbstractEntity::deltaTime.asSeconds() ); }

			// Move the Camera backwards based on it's speed
			void moveNeg() { AbstractEntity::move( -speed ); }

			// Move the Camera backwards along the x plane
			// Based on it's speed
			void moveNegX() { AbstractEntity::move( sf::Vector2f( -speed.x, 0.0f ) ); }

			// Move the Camera backwards along the y plane
			// Based on it's speed
			void moveNegY() { AbstractEntity::move( sf::Vector2f( 0.0f, -speed.y ) ); }
			
			
			//=====================================================================================================================
			// Zooming
			//=====================================================================================================================
			
			void setZoomSpeed( sf::Vector2f zoomSpeed ) { this->m_zoomSpeed = zoomSpeed; }
			
			void zoom() { view.setSize( view.getSize() - m_zoomSpeed ); }

			void defaultZoom() { view.setSize( m_defaultSize ); }

			void setDefaultZoom() { m_defaultSize = view.getSize(); }

			void setDefaultZoom( sf::Vector2f defaultSize ) { m_defaultSize = defaultSize; }
	};