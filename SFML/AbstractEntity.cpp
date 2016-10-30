#include "AbstractEntity.h"

// Define the static variable DeltaTime
// Which is used to control the game's speed
sf::Time AbstractEntity::deltaTime = sf::milliseconds(0);

// Define the static member Texture Manager
TextureManager AbstractEntity::textureManager = TextureManager();

bool AbstractEntity::load = false;


//====================================================================================================================================================================
// Snap to Grid
//====================================================================================================================================================================

// Lock the entity onto a grid
void AbstractEntity::snapToGrid( sf::Vector2f grid, sf::Vector2f maxSize ) {
	if ( exists() == false )
		return;
	
	// Make the coordinates within the limit
	// If they're outside it
	if ( getX() > maxSize.x )
		setX( maxSize.x-grid.x );
	if ( getY() > maxSize.y )
		setY( maxSize.y-grid.y );


	// Lock the entity onto the x grid
	for ( float x=0; x<maxSize.x; x+=grid.x )
		if ( getX()-x <= grid.x ) {
			setX(x);
			break;
		}
				
	// Lock the entity onto the y grid
	for ( float y=0.0f; y<maxSize.y; y+=grid.y )
		if ( getY()-y <= grid.y ) {
			setY(y);
			break;
		} 
}


//====================================================================================================================================================================
// Collision Detection
//====================================================================================================================================================================

// Test whether two entity's overlap based on a square
bool AbstractEntity::intersects( AbstractEntity* o ) {
	if ( exists() == false )
		return false;
		
	if ( ( getPosition().x + getSize().x >= o->getPosition().x ) && ( o->getPosition().x + o->getXSize() >= getPosition().x ) )
		if ( ( getPosition().y + getSize().y >= o->getPosition().y ) && ( o->getPosition().y + o->getYSize() >= getPosition().y ) )
			return true;

	return false;
}

// Test whether two entity's overlap based on a circle
bool AbstractEntity::circleIntersects( AbstractEntity* o ) {
	if ( exists() == false )
		return false;
	
	if ( sqrt( pow( getCentreX()-o->getCentreX(), 2 ) + pow( getCentreY()-o->getCentreY(), 2 ) ) < ( getXSize()+o->getXSize()) /2 )
		return true;

	return false;
}

// Test whether a point is within an Entity
bool AbstractEntity::contains( sf::Vector2f point ) {
	if ( exists() == false )
		return false;
	
	if ( ( getPosition().x + getXSize() >= point.x ) && ( point.x >= getPosition().x ) )
		if ( ( getPosition().y + getYSize() >= point.y ) && ( point.y >= getPosition().y ) )
			return true;

	return false;
}


// Test whether the entity is onscreen
bool AbstractEntity::onScreen( sf::RectangleShape screen ) {
	if ( exists() == false )
		return false;
	
	if ( ( getPosition().x + getSize().x >= screen.getPosition().x ) && ( screen.getPosition().x + screen.getSize().x >= getPosition().x ) )
		if ( ( getPosition().y + getSize().y >= screen.getPosition().y ) && ( screen.getPosition().y + screen.getSize().y >= getPosition().y ) )
			return true;

	return false;
}


//====================================================================================================================================================================
// Move towards Point
//====================================================================================================================================================================

// Move towards a point
void AbstractEntity::moveTowardsPoint( sf::Vector2f point, float speed ) {
	// If the object does not contain the following point
	// Then move the object towards said point
	if ( contains( point ) == false ) {
		point -= getSize() / 2.0f;
		move ( 
			speed * sin( 0.017453293f * ( ( atan2( getY() - point.y, getX() - point.x ) * 180.0f / 3.14159265359f ) + 270.0f ) ),
			speed * cos( 0.017453293f * ( ( atan2( getY() - point.y, getX() - point.x ) * 180.0f / 3.14159265359f ) + 90.0f ) )
		);
	}
}

//====================================================================================================================================================================
// Rotation
//====================================================================================================================================================================

void AbstractEntity::rotateTowardsPoint( sf::Vector2f point ) {
	if ( exists() == false )
		return;

	float m = ( point.y - getPosition().y ) / ( point.x - getPosition().x );

	float angle = atan(m);


	setRotation( angle );
}



//====================================================================================================================================================================
// Reset the Entity's stats
//====================================================================================================================================================================

// Reset the entity's stats
void AbstractEntity::reset() {
	sf::Transformable::setPosition( m_initialPos );
	m_deleted = false;
}