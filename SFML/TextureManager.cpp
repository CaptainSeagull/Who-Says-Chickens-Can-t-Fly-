#include "TextureManager.h"

bool TextureManager::addTexture( std::string fileName, std::string key ) {
	Tex tempTexture;

	// Load the texture in
	// And test it loaded properly
	if ( !tempTexture.texture.loadFromFile( fileName ) )
		return false;

	// Assign a key to the texture so it can be found
	tempTexture.key = key;
			
	// Push the texture onto the std::vector
	textures.push_back( tempTexture );

	return true;
}

			
// Find a texture
sf::Texture TextureManager::getTexture( std::string key ) {
	// Find the desired texture and return it
	for ( unsigned int i=0; i<textures.size(); i++ )
		if ( textures[i].key == key )
			return textures[i].texture;

	// Return an empty texture nothing was found
	sf::Texture fail;
	return fail;
}	