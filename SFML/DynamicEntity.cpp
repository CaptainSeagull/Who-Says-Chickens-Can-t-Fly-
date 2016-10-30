#include "DynamicEntity.h"

// Whether collision boxes are drawn or not
// Since this is a static data member, it is initialized outside the class
bool DynamicEntity::draw_collisionBoxes = false;


void DynamicEntity::init() {
	addAnimation( "Starting", 0, 0, 0.0f );
}

//================================================================================================================================================================================================================
// Rendering
//================================================================================================================================================================================================================

// Draw the Entity
void DynamicEntity::draw(sf::RenderTarget& target, sf::RenderStates states) const {		
	if ( ( m_destroyed == true ) || ( m_deleted == true ) || ( visible == false ) )
		return;

	// Draw the sprite
	target.draw( sprite, &texture );




	// Draw a collision box for the entity
	// If they're enabled
	if ( draw_collisionBoxes == true )
		target.draw( m_collisionBox );
}

// Set a texture onto the entity
void DynamicEntity::assignTexture( std::string texture ) {
	if ( exists() == false )
		return;

	// Set the size to the texture size if it hasn't already been manually set
	if ( size.x < 1.0f ) {
		size.x = (float) AbstractEntity::textureManager.getTexture( texture ).getSize().x;
		size.y = (float) AbstractEntity::textureManager.getTexture( texture ).getSize().y;
	}

	this->texture = textureManager.getTexture( texture );

	// create an array of 3 vertices that define a triangle primitive
	sprite.setPrimitiveType( sf::Quads );
	sprite.resize(4);

	// Assign the texture coordinates to the texture size
	sprite[0].texCoords = sf::Vector2f( 0.0f, 0.0f );
	sprite[1].texCoords = sf::Vector2f( size.x, 0.0f );
	sprite[2].texCoords = sf::Vector2f( size.x, size.y );
	sprite[3].texCoords = sf::Vector2f( 0.0f, size.y );
	
	// Set the sprite coordinates to the texture coordinates
	// PLUS the entity's position
	for ( unsigned int i=0; i<sprite.getVertexCount(); i++ )
		sprite[i].position = sprite[i].texCoords + getPosition();
}


//================================================================================================================================================================================================================
// Animation
//================================================================================================================================================================================================================

// Add a new animation sequence onto the Entity
void DynamicEntity::addAnimation( std::string key, float minFrame, float maxFrame, float animationSpeed ) {
	Animation temp;

	temp.key = key;
	temp.minFrame = minFrame;
	temp.maxFrame = maxFrame;
	temp.animationSpeed = animationSpeed;

	m_frame.push_back( temp );
}

// Increment the current animation frame
void DynamicEntity::incrementFrame() {
	if ( hasAnimation() == true ) {
		if ( m_currentFrame < m_frame.at( m_currentAnimation ).maxFrame ) {
			m_currentFrame += m_frame.at( m_currentAnimation ).animationSpeed * AbstractEntity::deltaTime.asSeconds();
			
			if ( m_currentFrame >= m_frame.at( m_currentAnimation ).maxFrame )
				m_currentFrame = m_frame.at( m_currentAnimation ).maxFrame;
		} else {
			m_currentFrame = m_frame.at( m_currentAnimation ).minFrame;
		}
	}

}

// Assign an animation for the entity
bool DynamicEntity::setAnimation( std::string key ) {
	// Only switch the animation if the current animation
	// does not equal the key
	if ( m_currentAnimationName == key )
		return true;

	// Find the animation and switch it
	for ( unsigned int i=0; i<m_frame.size(); i++ )
		if ( m_frame.at(i).key == key ) {
			m_currentAnimation = i;
			m_currentAnimationName = key;
			m_currentFrame = m_frame.at(i).minFrame;
			return true;
	}

	setAnimation( "Starting" );

	// Return false if the key was not found
	return false;
}

// Returns true or false based on whether the animation has ended
bool DynamicEntity::hasAnimationEnded( std::string key ) {
	for ( unsigned int i=0; i<m_frame.size(); i++ )
		if ( m_frame.at(i).key == key )
			if ( m_currentFrame >= m_frame.at(i).maxFrame-1 )
				return true;

	return false;
}



//================================================================================================================================================================================================================
// Updating
//================================================================================================================================================================================================================

// Update the entities logic
void DynamicEntity::update() {
	if ( getX() < 1.0f )
		return;
	
	if ( m_collisionBoxSize.x <= 1.0f ) {
		m_collisionBoxPos = sf::Vector2f( 0.0f, 0.0f );
		m_collisionBoxSize = getSize();
	}

	setSpriteData();
	incrementFrame();
	setupCollisionBoxes();
	m_currentlyOnscreen = true;
}

// Set sprite data before rendering
void DynamicEntity::setSpriteData() {	
	if ( exists() == false )
		return;

	float m = size.x * (int) m_currentFrame;

	sprite[0].texCoords = sf::Vector2f( 0.0f + m, 0.0f );
	sprite[1].texCoords = sf::Vector2f( size.x + m, 0.0f );
	sprite[2].texCoords = sf::Vector2f( size.x + m, size.y );
	sprite[3].texCoords = sf::Vector2f( 0.0f + m, size.y );
	
	// Set the sprite coordinates to the four corners of the entity
	// PLUS it's position
	for ( unsigned int i=0; i<sprite.getVertexCount(); i++ ) {
		sprite[0].position = sf::Vector2f( 0.0f, 0.0f ) + getPosition();
		sprite[1].position = sf::Vector2f( size.x, 0.0f ) + getPosition();
		sprite[2].position = sf::Vector2f( size.x, size.y ) + getPosition();
		sprite[3].position = sf::Vector2f( 0.0f, size.y ) + getPosition();
	}
}

// Setup the collision boxes to be drawn
void DynamicEntity::setupCollisionBoxes() {
	if ( draw_collisionBoxes == true ) {
		m_collisionBox.resize(4);
		m_collisionBox.setPrimitiveType( sf::Quads );

		m_collisionBox[0].color = sf::Color::Black;
		m_collisionBox[1].color = sf::Color::Black;
		m_collisionBox[2].color = sf::Color::Black;
		m_collisionBox[3].color = sf::Color::Black;

		m_collisionBox[0].position = getCollisionBoxPos();
		m_collisionBox[1].position = sf::Vector2f( getCollisionBoxPos().x + m_collisionBoxSize.x, getCollisionBoxPos().y );
		m_collisionBox[2].position = getCollisionBoxPos() + m_collisionBoxSize;
		m_collisionBox[3].position = sf::Vector2f( getCollisionBoxPos().x, getCollisionBoxPos().y + m_collisionBoxSize.y );
	}
}


//================================================================================================================================================================================================================
// Collision Detection
//================================================================================================================================================================================================================

// Test whether a point is within the entity
bool DynamicEntity::contains( sf::Vector2f point ) {
	if ( exists() == false )
		return false;
	
	sf::Vector2f p = getPosition() + m_collisionBoxPos;
	
	if ( ( p.x + m_collisionBoxSize.x >= point.x ) && ( point.x >= p.x ) )
		if ( ( p.y + m_collisionBoxSize.y >= point.y ) && ( point.y >= p.y ) )
			return true;

	return false;
}

// Test whether two entity's overlap based on a square
bool DynamicEntity::intersects( DynamicEntity* o ) {
	if ( exists() == false )
		return false;
		
	if ( ( getCollisionBoxPos().x + getCollisionBoxSize().x >= o->getCollisionBoxPos().x ) && ( o->getCollisionBoxPos().x + o->getCollisionBoxSize().x >= getCollisionBoxPos().x ) )
		if ( ( getCollisionBoxPos().y + getCollisionBoxSize().y >= o->getCollisionBoxPos().y ) && ( o->getCollisionBoxPos().y + o->getCollisionBoxSize().y >= getCollisionBoxPos().y ) )
			return true;

	return false;
}



//================================================================================================================================================================================================================
// Movement
//================================================================================================================================================================================================================

// Move the Entity's x
void DynamicEntity::accelerateX( float acceleration ) {	
	m_currentSpeed.x += AbstractEntity::deltaTime.asSeconds() * (( ( 1 * speed.x ) - m_currentSpeed.x ) * acceleration );
	Transformable::move( sf::Vector2f( m_currentSpeed.x*deltaTime.asSeconds(), 0.0f ) );
}

// Move the Entity's y
void DynamicEntity::accelerateY( float acceleration ) {
	m_currentSpeed.y += AbstractEntity::deltaTime.asSeconds() * ( ( ( 1 * speed.y ) - m_currentSpeed.y ) * acceleration );
	Transformable::move( sf::Vector2f( 0.0f, m_currentSpeed.y*deltaTime.asSeconds() ) );
}

// Move the Entity's -x
void DynamicEntity::accelerateNX( float acceleration ) {
	m_currentSpeed.x += AbstractEntity::deltaTime.asSeconds()  * ( ( ( -1 * speed.x ) - m_currentSpeed.x ) * acceleration );
	Transformable::move( sf::Vector2f( m_currentSpeed.x*deltaTime.asSeconds(), 0.0f ) );
}

// Move the Entity's -y
void DynamicEntity::accelerateNY( float acceleration ) {
	m_currentSpeed.y += AbstractEntity::deltaTime.asSeconds() * ( ( ( -1 * speed.y ) - m_currentSpeed.y ) * acceleration );
	Transformable::move( sf::Vector2f( 0.0f, m_currentSpeed.y*deltaTime.asSeconds() ) );
}

// Set the entity's current speed to zero
void DynamicEntity::resetCurrentSpeed() {
	resetCurrentHorSpeed();
	resetCurrentVertSpeed();
}

// Set the entity's current horizontal speed to zero
void DynamicEntity::resetCurrentHorSpeed() {
	if ( m_currentSpeed.x > 1.0f )
		accelerateNX( m_friction.x );
	else if ( m_currentSpeed.x < -1.0f )
		accelerateX( m_friction.x );
	else
		m_currentSpeed.x = 0.0f;
}

// Set the entity's current vertical speed to zero
void DynamicEntity::resetCurrentVertSpeed() {
	if ( m_currentSpeed.y > 1.0f )
		accelerateNY( m_friction.y );
	else if ( m_currentSpeed.y < -1.0f )
		accelerateY( m_friction.y );
	else
		m_currentSpeed.y = 0.0f;
}