#include "SoundManager.h"

bool SoundManager::loadSound( std::string filename, std::string key) {
	Sound sound;
	if ( !sound.audio.loadFromFile( filename ) )
		return false;

	sound.key = key;

	this->m_sound.push_back( sound );

	return true;
}

void SoundManager::playSound( std::string key ) {
	for ( unsigned int i=0; i<m_sound.size(); i++ )
		if ( m_sound.at(i).key == key ) {
			m_play.setBuffer( m_sound.at(i).audio );
			m_play.play();
		}
}