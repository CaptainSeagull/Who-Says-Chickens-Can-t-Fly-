#include "CreditsState.h"

void CreditsState::init() {
	// Assign the state
	currentState = "CreditsState";

	// Create the window
	window.create( getWindow() );

	// Initialize all the game managers
	if ( initializeManagers() == false )
		ErrorHandler::exitFatalError( "Managers Failed To Initialize" );

	// Load a font
	if ( !font.loadFromFile("resources//fonts//sansation.ttf") )
		return exit(1);

	// Setup the font for the message
	title.setFont( font );
	title.setCharacterSize( 36 );
	title.setPosition( 200.0f, 100.0f );
	title.setColor( sf::Color::White );
	title.setStyle( sf::Text::Bold );
	title.setString( "Credits" );

	for ( unsigned int i=0; i<m_noOfPeople; i++ ) {
		sf::Text temp;
		m_names.push_back( temp );
		m_names.back().setCharacterSize( 24 );
		m_names.back().setFont( font );
		m_names.back().setColor( sf::Color::White );
		m_names.back().setPosition( 200.0f, title.getPosition().y + 50*(1+i) );
	}


	m_names.at(0).setString( "Programming - Jonathan Livingstone" );
	m_names.at(1).setString( "Art - Lauren Martin" );
}

void CreditsState::update( UserInput* userInput ) {
	if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Space) ) 
		switchState( "MainMenuState" );
}

void CreditsState::render() {
	// Render the message
	window.draw(title);

	// Draw the logo
	for ( unsigned int i=0; i<m_names.size(); i++ )
		window.draw( m_names.at(i) );
}