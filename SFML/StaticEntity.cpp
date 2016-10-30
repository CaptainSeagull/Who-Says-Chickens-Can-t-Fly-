#include "StaticEntity.h"

// For drawing the Entity
void StaticEntity::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	if ( m_deleted == false )
		target.draw( sprite );
}

// The update method
void StaticEntity::update() {
	setSpriteData();
	scroll();
}


// Assign a texture which can repeat itself
void StaticEntity::assignTexture( std::string texture, sf::Vector2u size, bool repeated ) { 			
	// Assign the texture
	this->texture = AbstractEntity::textureManager.getTexture( texture );

	if ( this->texture.getSize().x < 1 )
		std::cout << '\n' << "Error Loading: " << type << '[' << number << "]'s Texture!";

	// Set the texture to repeated
	this->m_repeated = repeated;
	this->texture.setRepeated( m_repeated );

	// Put the texture onto the sprite
	sprite.setTexture( this->texture );

	// Define the sprite's size
	this->m_size = size;
	sprite.setTextureRect (
		sf::IntRect (
			(int) getPosition().x,
			(int) getPosition().y,
			(int) getPosition().x + size.x * this->AbstractEntity::textureManager.getTexture( texture ).getSize().x,
			(int) getPosition().y + size.y * this->AbstractEntity::textureManager.getTexture( texture ).getSize().y
		)
	);
}

// Assign a texture which can repeat itself
void StaticEntity::assignTexture( sf::Texture texture, sf::Vector2u size ) { 			
	// Assign the texture
	this->texture = texture;

	// Set the texture to repeated
	this->texture.setRepeated(true);

	// Put the texture onto the sprite
	sprite.setTexture( this->texture );

	// Define the sprite's size
	this->m_size = size;
	sprite.setTextureRect (
		sf::IntRect (
			(int) getPosition().x,
			(int) getPosition().y,
			(int) getPosition().x + size.x * this->texture.getSize().x,
			(int) getPosition().y + size.y *this->texture.getSize().y
		)
	);
}

void StaticEntity::changeTexture( std::string newTexture ) {
	std::cout << '\n' << newTexture;
	
	// Assign the texture
	this->texture = AbstractEntity::textureManager.getTexture( newTexture );

	// Set the texture to repeated
	this->texture.setRepeated( true );

	// Put the texture onto the sprite
	sprite.setTexture( this->texture );

	// Define the sprite's size
	sprite.setTextureRect (
		sf::IntRect (
			(int) getPosition().x,
			(int) getPosition().y,
			(int) getPosition().x + m_size.x * this->AbstractEntity::textureManager.getTexture( newTexture ).getSize().x,
			(int) getPosition().y + m_size.y * this->AbstractEntity::textureManager.getTexture( newTexture ).getSize().y
		)
	);
}