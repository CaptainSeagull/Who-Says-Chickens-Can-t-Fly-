#pragma once

#include <SFML/Audio.hpp>

#include <iostream>

#include <string>

#include <vector>

#include <memory>

// Sounds are short files, like a gunshot
struct Sound {
	sf::SoundBuffer audio;
	std::string key;
};

	class SoundManager {
		private:
			std::vector<Sound> m_sound;
			sf::Sound m_play;
	
		public:
			SoundManager() { }
			~SoundManager() { std::cout << '\n' << "Deleting: Sound Manager"; }

			//=====================================================================================================
			// The background music
			//=====================================================================================================

			sf::Music backgroundMusic;


			//=====================================================================================================
			// Sound Effects
			//=====================================================================================================

			bool loadSound( std::string filename, std::string key );

			void playSound( std::string key );
	};