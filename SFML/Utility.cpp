#include "Utility.h"

namespace Utility {

	//==============================================================================================
	// String to Vectors
	//==============================================================================================

	// Convert a string to a Vector2f
	sf::Vector2f StringToVector2f( std::string strVector ) {
		int s = strVector.find(' ');
		return sf::Vector2f( (float) atof( strVector.substr( 0, s ).c_str() ), (float) atof( strVector.substr( s+1, strVector.size() ).c_str() ) );
	}

	// Convert a string to a Vector2u
	sf::Vector2u StringToVector2u( std::string strVector ) {
		sf::Vector2f i = Utility::StringToVector2f( strVector );
		return sf::Vector2u( (int) i.x, (int) i.y );
	}

	//==============================================================================================
	// Vector to String
	//==============================================================================================

	// Convert a sf::Vector2f as a string
	std::string VectorToString( sf::Vector2f vec ) {
		return std::to_string( vec.x ) + ' ' + std::to_string( vec.y );
	}

	//==============================================================================================
	// Bubblesort
	//==============================================================================================

	// Perform a bublesort on an array
	void bubbleSort( int *no, int size ) {
		for (int i=1; i < size; i++)
			for (int k=size-1; k>=i; k--) {
				// Exchange the elements if they're out of order
				if ( no[k-1] < no[k]) {	
					int j = no[k-1];
					no[k-1] = no[k];
					no[k] = j;
				}
			}
	}


	//==============================================================================================
	// Equals, ignore case
	//==============================================================================================

	// Tests whether two strings are equal
	bool equalsIgnoreCase(const std::string& a, const std::string& b) {
		unsigned int sz = a.size();
		if  (b.size() != sz )
			return false;
		for ( unsigned int i = 0; i < sz; ++i )
			if ( tolower(a[i]) != tolower(b[i]) )
				return false;
		return true;
	}


	//==============================================================================================
	// Distance Fomula
	//==============================================================================================

	float distance( sf::Vector2f a, sf::Vector2f b ) {
		return sqrt( pow( a.x-b.x, 2 ) + pow( a.y-b.y, 2 ) );
	}

	float distance( float a_x, float a_y, float b_x, float b_y ) {
		return distance( sf::Vector2f( a_x, a_y ), sf::Vector2f( b_x, b_y ) );
	}

	float distance ( float p1, float p2 ) {
		return distance( sf::Vector2f( p1, 0.0f ), sf::Vector2f( p2, 0.0f ) );
	}


	//==============================================================================================
	// Random
	//==============================================================================================

	// Returns a random float between two values
	float random( float min, float max ) {
	
		// Only call the srand() function the first time random() is called
		static bool first = true;
		if ( first == true ) {
			srand( (unsigned int) time(NULL) );
			first = false;
		}
	
		// Return a random float between two values
		return min + static_cast  <float> ( rand() ) / ( static_cast <float> (RAND_MAX/(max-min)) );
	}

	// Returns a random integer between two values
	int random( int min, int max ) {
		static bool first = true;

		if ( first == true ) {
			srand( (unsigned int) time(NULL) );
			first = false;
		}

		return min + ( rand() / ( RAND_MAX/(max-min) ) );
	}

} // namespace Utility