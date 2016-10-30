#pragma once

#include <string>

#include <vector>

#include <SFML/Graphics.hpp>

#include "ErrorHandler.h"

#include "Utility.h"

struct Font {
	sf::Font ttf;
	std::string name;
};

struct Text {
	sf::Text message;
	std::string messageAsString;
	std::string key;
	int index;
	bool visible = true;
};

	class TextManager {
		private:
			//====================================================================================================================================================
			// Holds the loaded Font and Messages
			//====================================================================================================================================================
			std::vector<Font> font;
			std::vector<Text> text;
			int index=0;


		public:
			//====================================================================================================================================================
			// Constructor, and
			// Destructor
			//====================================================================================================================================================
			TextManager() { }
			~TextManager() { std::cout << '\n' << "Deleting: Font and Text Manager"; }

			//====================================================================================================================================================
			// Loading Fonts
			//====================================================================================================================================================

			// Load a font from a .txt file
			// And save it's name for later use
			// The name will be the font name
			// Eg: resources//fonts//Ariel.ttf
			// will be saved as Ariel.ttf
			bool loadFont( std::string fontPath );

			sf::Font getFont( std::string font );


			//====================================================================================================================================================
			// Generate Messages
			//====================================================================================================================================================

			// Generate a message
			// The message is a standard std::string
			// The font is the name of the font saved
			// Eg: Ariel.ttf
			bool generateMessage( std::string message, std::string key, std::string font );


			//====================================================================================================================================================
			// Positions
			//====================================================================================================================================================

			// Set the position of a message
			// message is what the Outputted Message said
			// sf::Vector2f position is the new object's position
			bool setPosition( std::string key, sf::Vector2f position );
			
			// Set the position of a message
			// message is what the Outputted Message said
			// float x and y are the object's new position
			bool setPosition( std::string key, float x, float y ) { return setPosition( key, sf::Vector2f( x, y ) ); }

			// Set the x position of a message
			// message is what the Outputted Message said
			// float x is the object's new x coordinate
			// The y is unchanged
			bool setX( std::string key, float x ) { return setPosition( key, sf::Vector2f( x, -1 ) ); }

			// Set the y position of a message
			// message is what the Outputted Message said
			// float y is the object's new y coordinate
			// The x is unchanged
			bool setY( std::string key, float y ) { return setPosition( key, sf::Vector2f( -1, y ) ); }

			// Return the position of some text
			sf::Vector2f getPosition( std::string key );

			//====================================================================================================================================================
			// Character Size
			//====================================================================================================================================================

			// Set the character size of a message
			// std::string message is what the message said
			// int characterSize is the new Character Size
			bool setCharacterSize( std::string key, int characterSize );


			//====================================================================================================================================================
			// Colour
			//====================================================================================================================================================

			// Set the colour of a message
			// std::string message is what the message said
			// const sf::Color &colour is sf::Color
			// Eg: sf::Color::Red
			bool setColour( std::string key, const sf::Color &colour );

			// Set the colour of a message
			// std::string message is what the message said
			// std::string colour is the colour to set the message to
			// Case does not matter for the colour
			// Possible Colours are:
			// Black
			// White
			// Red
			// Green
			// Blue
			// Yellow
			// Magenta
			// Cyan
			// Transparent
			bool setColour( std::string key, std::string colour );

			//====================================================================================================================================================
			// Style
			// Bold, Underlines, Itallics
			//====================================================================================================================================================

			// Set the style of the message
			// std::string message is what the message said
			// sf::Uint32 style is the style to change the message to
			// Eg: sf::Text::Bold | sf::Text::Underlined
			bool setStyle( std::string key, sf::Uint32 style );


			//====================================================================================================================================================
			// Change the message
			//====================================================================================================================================================

			bool changeMessage( std::string key, std::string newMessage );


			//====================================================================================================================================================
			// Getting the Message
			//====================================================================================================================================================

			void setVisible( std::string key, bool visible );

			// Return the number of messages stored
			// As an Unsigned Integer
			unsigned int getNoOfMessages() { return text.size(); }

			// Return a message at a specific index
			sf::Text getMessage( unsigned int index ) { sf::Text fail; if ( text.at( index ).visible == true ) return text.at( index ).message; return fail; }

			// Return a message based on it's key
			sf::Text getMessage( std::string key );
	};