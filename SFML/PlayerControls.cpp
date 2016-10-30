#include "PlayerControls.h"

void PlayerControls::update( DynamicEntity* player, UserInput* userInput, sf::Vector2f mousePos ) {
	
	if ( player->getCurrentAnimation() == "Dead" )
		return;

	m_anyKeyPressed = sf::Vector2i( 0, 0 );

	if ( m_keyboard == true ) {
		moveLeft( player, userInput );
		moveRight( player, userInput );
		moveUp( player, userInput );
		moveDown( player, userInput );
	} else
		mouse( player, mousePos );

	if ( m_anyKeyPressed.x == 0 ) {
		player->resetCurrentHorSpeed();
		m_lastDirection.x = 0;
	}
	

	if ( m_anyKeyPressed.y == 0 ) {
		player->resetCurrentVertSpeed();
		m_lastDirection.y = 0;
	}
}

void PlayerControls::moveLeft( DynamicEntity* player, UserInput* userInput ) { 
	if ( userInput->keyboard( m_left ) ) {
		if ( m_lastDirection.x != -1 )
			player->resetCurrentHorSpeed();
		m_lastDirection.x = -1;

		m_anyKeyPressed.x = 1;

		player->accelerateNX();
	}
}
void PlayerControls::moveRight( DynamicEntity* player, UserInput* userInput ) {
	if ( userInput->keyboard( m_right ) ) {
		if ( m_lastDirection.x != 1 )
			player->resetCurrentHorSpeed();
		m_lastDirection.x = 1;

		m_anyKeyPressed.x = 1;

		player->accelerateX();
	}
}
void PlayerControls::moveUp( DynamicEntity* player, UserInput* userInput ) {
	if ( userInput->keyboard( m_up ) ) {
		if ( m_lastDirection.y != -1 )
			player->resetCurrentHorSpeed();
		m_lastDirection.y = -1;

		m_anyKeyPressed.y = 1;

		player->accelerateNY();
	}
}
void PlayerControls::moveDown( DynamicEntity* player, UserInput* userInput ) {
	if ( userInput->keyboard( m_down ) ) {
		if ( m_lastDirection.y != 1 )
			player->resetCurrentHorSpeed();
		m_lastDirection.y = 1;

		m_anyKeyPressed.y = 1;

		player->accelerateY();
	}
}

void PlayerControls::mouse( DynamicEntity* player, sf::Vector2f mousePos ) {
	player->moveTowardsPoint( mousePos, m_playerMouseSpeed );
}