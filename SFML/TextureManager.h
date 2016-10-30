#pragma once

#include <SFML\Graphics.hpp>

#include <vector>

#include <string>

#include <iostream>

// A struct which stores a texture and a tag for the texture
struct Tex {
	sf::Texture texture;
	std::string key;
};

	class TextureManager {
		private:
			// A vector which stores all the textures as a Tex struct
			std::vector<Tex> textures;
	
		public:
			TextureManager() { }
			~TextureManager() { std::cout << '\n' << "Deleting: Texture Manager"; }

			// Add a texture to the manager
			bool addTexture( std::string fileName, std::string key );

			
			// Get a texture from the manager by searching for a 'key'
			// Which was assigned to the texture
			// Returns an empty texture upon failure
			sf::Texture getTexture( std::string key );	
	};