#pragma once

#include <iostream>

#include <SFML/Graphics.hpp>

#include <string>

namespace Utility {
	
	// The formula for converting degrees to radians
	const float DEGREES_TO_RADIANS = 0.017453293f;

	// Convert a string to a sf::Vector2f
	// The string must have a space inbetween the elements
	sf::Vector2f StringToVector2f( std::string strVector );

	// Convert a string to a sf::Vector2f
	// The string must have a space inbetween the elements
	sf::Vector2u StringToVector2u( std::string strVector );

	// Convert a sf::Vector2f to a string
	// The string will be in the format: x + ' ' + y
	std::string VectorToString( sf::Vector2f vec );


	// A standard bubblesort
	// Which sorts through integers
	// and arranges them from lowest to highest
	void bubbleSort( int *no, int size );


	// Tests whether two std::strings are equal
	// Ignoring their case
	bool equalsIgnoreCase( const std::string& a, const std::string& b );


	// Returns the distance between two points
	// Using two sf::Vector2f's
	float distance( sf::Vector2f a, sf::Vector2f b );

	// Returns the distance between two points
	// Using four floats
	// Each set of two is a point
	float distance( float a_x, float a_y, float b_x, float b_y );

	// Return the distance between two 1D points
	// Using two floats
	float distance( float p1, float p2 );
	

	// Returns a random float between two values
	float random( float min, float max );

	// Returns a random integer between two values
	int random( int min, int max );
}