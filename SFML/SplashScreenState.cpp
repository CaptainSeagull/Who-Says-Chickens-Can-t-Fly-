#include "SplashScreenState.h"

void SplashScreenState::init() {
	// Assign the state
	currentState = "SplashScreenState";

	// Create the window
	window.create( getWindow() );

	// Initialize all the game managers
	if ( initializeManagers() == false )
		ErrorHandler::exitFatalError( "Managers Failed To Initialize" );

	// Load a font
	if ( !font.loadFromFile("resources//fonts//sansation.ttf") )
		return exit(1);

	// Setup the font for the message
	text.setFont( font );
	text.setCharacterSize( 20 );
	text.setPosition( 120.0f, 100.0f );
	text.setColor( sf::Color::White );
	text.setString( "A Game by Jonathan Livingstone and Lauren Martin" );

	// Setup the font for the placeholder logo
	logo.setFont(font);
	logo.setCharacterSize(40);
	logo.setPosition( 100.0f, 200.0f );
	logo.setColor( sf::Color::White );
	logo.setStyle( sf::Text::Bold | sf::Text::Underlined );
	logo.setString( "Who Says Chickens Can't Fly!?" );

	// Setup the 'Press Spce to Continue' text
	next.setFont(font);
	next.setCharacterSize(16);
	next.setPosition( 200.0f, 350.0f );
	next.setColor( sf::Color::White );
	next.setString("Press Space to Continue");
}

void SplashScreenState::update( UserInput* userInput ) {
	if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Space) ) 
		switchState( "MainMenuState" );
}

void SplashScreenState::render() {
	// Render the message
	window.draw(text);

	// Draw the logo
	window.draw(logo);

	// Draw the 'Press Space to Continue' text
	window.draw(next);
}