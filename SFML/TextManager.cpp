#include "TextManager.h"


// Load a font from a file
bool TextManager::loadFont( std::string fontPath ) {
	Font f;
	if ( !f.ttf.loadFromFile( fontPath ) )
		return false;
	
	f.name = fontPath.substr( fontPath.find_last_of( '/' )+1, fontPath.size() );

	font.push_back( f );

	return true;
}

sf::Font TextManager::getFont( std::string font ) {
	for ( unsigned int i=0; i<this->font.size(); i++ )
		if ( font == this->font.at(i).name )
			return this->font.at(i).ttf;

	sf::Font blankFont;
	return blankFont;
}


// Generate a message based on a loaded font
bool TextManager::generateMessage( std::string message, std::string key, std::string font ) {
	// Find the font
	int k=-1;
	for ( unsigned int i=0; i<this->font.size(); i++ )
		if ( font == this->font.at(i).name )
			k = i;

	// Test whether the font was found or not
	if ( k == -1 )
		return false;

	// Create the text object
	Text t;
	t.messageAsString = message;
	t.index = this->index;
	t.message.setFont( this->font.at(k).ttf );
	t.message.setString( message );
	t.key = key;

	this->index++;

	text.push_back( t );

	return true;
}


// Set the position of a message
bool TextManager::setPosition( std::string key, sf::Vector2f position ) {
	for ( unsigned int i=0; i<text.size(); i++ )
		if ( text.at(i).key == key ) {
			if ( position.x == -1 )
				position.x = text.at(i).message.getPosition().x;
			if ( position.y == -1 )
				position.y = text.at(i).message.getPosition().y;

			text.at(i).message.setPosition( position );
			return true;
		}

	return false;
}


sf::Vector2f TextManager::getPosition( std::string key ) {
	for ( unsigned int i=0; i<text.size(); i++ )
		if ( text.at(i).key == key )
			return text.at(i).message.getPosition();

	return sf::Vector2f( 0.0f, 0.0f );
}


// Set the position of a message
bool TextManager::changeMessage( std::string key, std::string newMessage ) {
	for ( unsigned int i=0; i<text.size(); i++ )
		if ( text.at(i).key == key ) {
			text.at(i).message.setString( newMessage );
			text.at(i).messageAsString = newMessage;
			return true;
		}

	return false;
}

// Set the character size of a message
bool TextManager::setCharacterSize( std::string key, int characterSize ) {
	for ( unsigned int i=0; i<text.size(); i++ )
		if ( text.at(i).key == key ) {
			text.at(i).message.setCharacterSize( characterSize );
			return true;
		}

	return false;
}
	

// Set the colour of a message
bool TextManager::setColour( std::string key, const sf::Color &colour ) {
	for ( unsigned int i=0; i<text.size(); i++ )
		if ( text.at(i).key == key ) {
			text.at(i).message.setColor(colour);
			return true;
		}

	return false;
}

// Set the colour of a message
bool TextManager::setColour( std::string key, std::string colour ) {
	sf::Color sfColour;
	
	if ( Utility::equalsIgnoreCase( colour, "black" ) )
		sfColour = sf::Color::Black;
	else if ( Utility::equalsIgnoreCase( colour, "white" ) )
		sfColour = sf::Color::White;
	else if ( Utility::equalsIgnoreCase( colour, "red" ) )
		sfColour = sf::Color::Red;
	else if ( Utility::equalsIgnoreCase( colour, "green" ) )
		sfColour = sf::Color::Green;
	else if ( Utility::equalsIgnoreCase( colour, "blue" ) )
		sfColour = sf::Color::Blue;
	else if ( Utility::equalsIgnoreCase( colour, "yellow" ) )
		sfColour = sf::Color::Yellow;
	else if ( Utility::equalsIgnoreCase( colour, "magenta" ) )
		sfColour = sf::Color::Magenta;
	else if ( Utility::equalsIgnoreCase( colour, "cyan" ) )
		sfColour = sf::Color::Cyan;
	else if ( Utility::equalsIgnoreCase( colour, "transparent" ) )
		sfColour = sf::Color::Transparent;
	else
		return false;

	setColour( key, sfColour );

	return true;
}

// Set the stle of the message
bool TextManager::setStyle( std::string key, sf::Uint32 style ) {
	for ( unsigned int i=0; i<text.size(); i++ )
		if ( text.at(i).key == key ) {
			text.at(i).message.setStyle( style );
			return true;
		}

	return false;
}

void TextManager::setVisible( std::string key, bool visible ) {
	for ( unsigned int i=0; i<text.size(); i++ )
		if ( text.at(i).key == key )
			text.at(i).visible = visible;
}

sf::Text TextManager::getMessage( std::string key ) {
	sf::Text fail;
	for ( unsigned int i=0; i<text.size(); i++ )
		if ( text.at(i).key == key )
			if ( text.at(i).visible == true )
				return text.at(i).message;

	return fail;
}