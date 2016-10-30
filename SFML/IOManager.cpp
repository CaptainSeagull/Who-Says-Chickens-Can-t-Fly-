// The Header File
#include "IOManager.h"

namespace IOManager {

	// Read in data from a .txt file
	// And return it as a string
	std::string readFile_txt( std::string fileName, std::string key ) {
		
		
		// Test the fileName isn't blank
		if ( ( fileName == "" ) || ( fileName.empty() ) ) {
			//std::cout << '\n' << "Empty Filename";
			return "\n";
		}

		// Test the key isn't blank
		if ( ( key == "" ) || ( key.empty() ) ) {
			//std::cout << '\n' << "Empty Key";
			return "\n";
		}
	
		// Change the filename to the correct format ( .txt )
		fileName = fileName + ".txt";

		// Stores the contents as a string
		std::string line = "";
		std::string dummy;
	
		// Open the file
		std::fstream myfile( fileName );

		// Test the file was opened correctly
		if ( !myfile.is_open() ) {
			//std::cout << '\n' << fileName + " Failed To Open";
			//std::cout << '\n' << "Key: " << key;
			return "\n";
		}
	
		// Reset the .txt's internal position for later use
		myfile.clear();
		myfile.seekg( 0, std::ios::beg );

		// Tests the text file hasn't reached the end
		while ( getline( myfile, dummy ) ) {
			// Make sure the dummy value isn't empty
			if ( dummy.empty() )
				continue;

			// Move to the next iteration of the loop
			// If the dummy isn't long enough to be the key
			if ( dummy.length() < key.length() )
				continue;

			// Make a test string
			// Is in identical format to the key
			std::string test = dummy.substr( 0, key.length() );
		
			// Test, and assign, the key if it's been found
			if ( test == key )
				line = dummy;
		}

		// Close the .txt file
		myfile.close();
	
		// Test if the key was found or not
		//if ( line == "" )
		//	std::cout << std::endl << key << " Could Not Be Found Within " << fileName << std::endl;

		// Delete the key from the string
		if ( line.length() + 2 >= key.length() )
			line = line.substr( key.length() + 2, line.length() );

		// If the line wasn't found within the .txt file
		// Make the return value '\n'
		if ( (line == "") || ( line.empty() ) )
			line = "\n";

		// Return the loaded string
		return line;
	}


	// Read in data from a .txt file
	// And return the result
	std::vector<std::string> readArrayFile_txt( std::string fileName, std::string key ) {
		std::vector<std::string> line;
		
		// Test the fileName isn't blank
		if ( ( fileName == "" ) || ( fileName.empty() ) ) {
			//std::cout << '\n' << "Empty Filename";
			return line;
		}

		// Test the key isn't blank
		if ( ( key == "" ) || ( key.empty() ) ) {
			//std::cout << '\n' << "Empty Key";
			return line;
		}
	
		// Change the filename to the correct format ( .txt )
		fileName = fileName + ".txt";

		// Stores the contents as a string
		std::string dummy;
	
		// Open the file
		std::fstream myfile( fileName );

		// Test the file was opened correctly
		if ( !myfile.is_open() ) {
			//std::cout << '\n' << fileName + " Failed To Open";
			//std::cout << '\n' << "Key: " << key;
			return line;
		}
	
		// Reset the .txt's internal position for later use
		myfile.clear();
		myfile.seekg( 0, std::ios::beg );


		// Store everything in the .txt file
		while ( getline( myfile, dummy ) ) {
			if ( dummy.empty() )
				continue;
			
			if ( dummy.at(0) == '#' )
				continue;

			// Move to the next iteration of the loop
			// If the dummy isn't long enough to be the key
			if ( dummy.length() < key.length() )
				continue;

			// Make a test string
			// Is in identical format to the key
			std::string test = dummy.substr( 0, key.length() );
		
			// Test, and assign, the key if it's been found
			if ( test == key ) {
				line.push_back( dummy );
				line.back() = line.back().substr( key.length()+2, line.back().length() );
			}
		}

		// Close the .txt file
		myfile.close();

		// Output the line
		//std::cout << '\n' << "Line Size: " << line.size() << '\n';
		//for ( unsigned int i=0; i<line.size(); i++ )
		//	std::cout << '\n' << key + ": " << line[i];


		return line;
	}

	// Read in data from a .txt file
	// And set the result to the  std::vector<std::string> &arr  parameter
	void readArrayFile_txt( std::string fileName, std::string key, std::vector<std::string> &arr ) {		
		// Test the fileName isn't blank
		if ( ( fileName == "" ) || ( fileName.empty() ) ) {
			//std::cout << '\n' << "Empty Filename";
			return;
		}

		// Test the key isn't blank
		if ( ( key == "" ) || ( key.empty() ) ) {
			//std::cout << '\n' << "Empty Key";
			return;
		}
	
		// Change the filename to the correct format ( .txt )
		fileName = fileName + ".txt";

		// Stores the contents as a string
		std::string dummy;
	
		// Open the file
		std::fstream myfile( fileName );

		// Test the file was opened correctly
		if ( !myfile.is_open() ) {
			//std::cout << '\n' << fileName + " Failed To Open";
			//std::cout << '\n' << "Key: " << key;
			return;
		}
	
		// Reset the .txt's internal position for later use
		myfile.clear();
		myfile.seekg( 0, std::ios::beg );


		// Store everything in the .txt file
		while ( getline( myfile, dummy ) ) {
			if ( dummy.empty() )
				continue;
			
			if ( dummy.at(0) == '#' )
				continue;

			// Move to the next iteration of the loop
			// If the dummy isn't long enough to be the key
			if ( dummy.length() < key.length() )
				continue;

			// Make a test string
			// Is in identical format to the key
			std::string test = dummy.substr( 0, key.length() );
		
			// Test, and assign, the key if it's been found
			if ( test == key ) {
				arr.push_back( dummy );
				arr.back() = arr.back().substr( key.length()+2, arr.back().length() );
			}
		}

		// Close the .txt file
		myfile.close();

		// Output the line
		//std::cout << '\n' << "Line Size: " << arr.size() << '\n';
		//for ( unsigned int i=0; i<arr.size(); i++ )
		//	std::cout << '\n' << key + ": " << arr.at(i);
	}


	void readLevel_txt( std::string fileName, std::vector< std::string > &entityName, std::vector< sf::Vector2f > &position ) {
		// Test the fileName isn't blank
		if ( ( fileName == "" ) || ( fileName.empty() ) ) {
			//std::cout << '\n' << "Empty Filename";
			return;
		}
	
		// Change the filename to the correct format ( .txt )
		fileName = fileName + ".txt";

		// Stores the contents as a string
		std::string dummy;
	
		// Open the file
		std::fstream myfile( fileName );

		// Test the file was opened correctly
		if ( !myfile.is_open() ) {
			//std::cout << '\n' << fileName + " Failed To Open";
			//std::cout << '\n' << "Key: " << key;
			return;
		}
	
		// Reset the .txt's internal position for later use
		myfile.clear();
		myfile.seekg( 0, std::ios::beg );


		// Store everything in the .txt file
		while ( getline( myfile, dummy ) ) {
			

			if ( dummy.empty() )
				continue;
			
			if ( dummy.at(0) == '#' )
				continue;

			unsigned int p = 0;
			for ( unsigned int i=0; i<dummy.size(); i++ )
				if ( dummy.at(i) == ':' )
					p = i;

			std::string entityN = dummy.substr( 0, p );
			std::string entityD = dummy.substr( p+2, dummy.length() );


			//std::cout << "\n\nEntity: " << entityN;
			//std::cout << "\nData: " << entityD;

			entityName.push_back( entityN );
			position.push_back( Utility::StringToVector2f( entityD ) );
			//std::cout << '\n' << position.back().x << ' ' << position.back().y;
		}

		//std::cout << "\n\nentityName size: " << entityName.size();
		//std::cout << "\nposition size: " << position.size();

		// Close the .txt file
		myfile.close();

		// Output the line
		//std::cout << '\n' << "Line Size: " << arr.size() << '\n';
		//for ( unsigned int i=0; i<arr.size(); i++ )
		//	std::cout << '\n' << key + ": " << ar
	}

	// Replace the data stored at a key within a .txt file
	void write_txt( std::string fileName, std::string key, std::string data ) {
		// Test the fileName isn't blank
		if ( ( fileName == "" ) || ( fileName.empty() ) ) {
			//std::cout << '\n' << "Empty Filename";
			return;
		}

		// Do not write to file whose name is preceeded by 'const'
		//if ( ( fileName.substr(0, 5) == "const" ) || ( fileName.substr(0, 5) == "Const" ) ) {
		//	std::cout << '\n' << "Cannot Rewrite Const Files";
		//	return;
		//}

		// Test the key isn't blank
		if ( ( key == "" ) || ( key.empty() ) ) {
			std::cout << '\n' << "Empty Key";
			return;
		}

		// Test that data was passed into the function
		if ( ( data == "" ) || ( data.empty() ) ) {
			std::cout << '\n' << "Empty Data";
			return;
		}
	
		// Change the filename to the correct format ( .txt )
		fileName = fileName + ".txt";
	
		// Open the file
		std::fstream myfile( fileName );

		// Test the file was opened correctly
		if ( !myfile.is_open() ) {
			std::cout << '\n' << fileName + " Failed To Open";
			std::cout << '\n' << "Key: " << key;
			std::cout << '\n' << "Data: " << data;
			return;
		}
	
		// Reset the .txt's internal position for later use
		myfile.clear();
		myfile.seekg( 0, std::ios::beg );

		// This is a dummy string
		// Which temperarily stores data from the .txt file
		std::string dummy;

		// A vector to store all the contents of a .txt file
		std::vector<std::string> line;

		// Store everything in the .txt file
		while ( getline( myfile, dummy ) )
			line.push_back( dummy + '\n' );

		// OUTPUT
		//for ( unsigned int i=0; i<line.size(); i++ )
		//	std::cout << line[i];

		// Search through all the store data
		// And modify the one which matches the key
		bool trigger = false;
		for ( unsigned int i=0; i<line.size(); i++ )
			if ( line[i].substr(0, key.length()) == key ) {
				line[i] = key + ": " + data + '\n';
				trigger = true;
			}

		if ( trigger == false ) {
			line.push_back( key + ": " + data + '\n' );
		}

		// Reset the .txt's internal position
		myfile.clear();
		myfile.seekg( 0, std::ios::beg );

		// Output all the data back into the .txt file
		for ( unsigned int i=0; i<line.size(); i++ )
			myfile << line[i];
		
		// Close the .txt file
		myfile.close();


		// OUTPUT
		//std::cout << "\n\n";
		//for ( unsigned int i=0; i<line.size(); i++ )
		//	std::cout << line[i];
		//std::cout << "\n\n";
	}


	// Replace the data stored at a key within a .txt file
	void add_txt( std::string fileName, std::string key, std::string data ) {
		// Test the fileName isn't blank
		if ( ( fileName == "" ) || ( fileName.empty() ) ) {
			//std::cout << '\n' << "Empty Filename";
			return;
		}

		// Do not write to file whose name is preceeded by 'const'
		//if ( ( fileName.substr(0, 5) == "const" ) || ( fileName.substr(0, 5) == "Const" ) ) {
		//	std::cout << '\n' << "Cannot Rewrite Const Files";
		//	return;
		//}

		// Test the key isn't blank
		if ( ( key == "" ) || ( key.empty() ) ) {
			std::cout << '\n' << "Empty Key";
			return;
		}

		// Test that data was passed into the function
		if ( ( data == "" ) || ( data.empty() ) ) {
			std::cout << '\n' << "Empty Data";
			return;
		}
	
		// Change the filename to the correct format ( .txt )
		fileName = fileName + ".txt";
	
		// Open the file
		std::fstream myfile( fileName );

		// Test the file was opened correctly
		if ( !myfile.is_open() ) {
			std::cout << '\n' << fileName + " Failed To Open";
			std::cout << '\n' << "Key: " << key;
			std::cout << '\n' << "Data: " << data;
			return;
		}
	
		// Reset the .txt's internal position for later use
		myfile.clear();
		myfile.seekg( 0, std::ios::beg );

		// This is a dummy string
		// Which temperarily stores data from the .txt file
		std::string dummy;

		// A vector to store all the contents of a .txt file
		std::vector<std::string> line;

		// Store everything in the .txt file
		while ( getline( myfile, dummy ) )
			line.push_back( dummy + '\n' );

		// OUTPUT
		//for ( unsigned int i=0; i<line.size(); i++ )
		//	std::cout << line[i];

		// Add the new data onto the end of the .txt file
		line.push_back( key + ": " + data + '\n' );

		// Reset the .txt's internal position
		myfile.clear();
		myfile.seekg( 0, std::ios::beg );

		// Output all the data back into the .txt file
		for ( unsigned int i=0; i<line.size(); i++ )
			myfile << line[i];
		
		// Close the .txt file
		myfile.close();


		// OUTPUT
		//std::cout << "\n\n";
		//for ( unsigned int i=0; i<line.size(); i++ )
		//	std::cout << line[i];
		//std::cout << "\n\n";
	}

	// Delete a line within a .txt file
	void deleteLine_txt( std::string fileName, unsigned int lineNo ) {		
		// Test the fileName isn't blank
		if ( ( fileName == "" ) || ( fileName.empty() ) ) {
			//std::cout << '\n' << "Empty Filename";
			return;
		}

		// Do not write to file whose name is preceeded by 'const'
		//if ( ( fileName.substr(0, 5) == "const" ) || ( fileName.substr(0, 5) == "Const" ) ) {
		//	std::cout << '\n' << "Cannot Rewrite Const Files";
		//	return;
		//}
	
		// Change the filename to the correct format ( .txt )
		fileName = fileName + ".txt";
	
		// Open the file
		std::fstream myfile( fileName );

		// Test the file was opened correctly
		if ( !myfile.is_open() ) {
			//std::cout << '\n' << fileName + " Failed To Open";
			return;
		}
	
		// Reset the .txt's internal position for later use
		myfile.clear();
		myfile.seekg( 0, std::ios::beg );

		// This is a dummy string
		// Which temperarily stores data from the .txt file
		std::string dummy;

		// A vector to store all the contents of a .txt file
		std::vector<std::string> line;

		std::cout << "\n\n";
		// Store everything in the .txt file
		while ( getline( myfile, dummy ) ) {
			if ( dummy.empty() == true )
				continue;
			
			if ( dummy.at(0) == '#' )
				continue;

			if ( !dummy.empty() )
				line.push_back( dummy + '\n' );
		}

		// Test the line wasn't too large
		if ( lineNo > line.size() ) {
			std::cout << '\n' << "Line Number Larger than .txt Size";
			std::cout << '\n' << "Filename: " << fileName;
			std::cout << '\n' << "No of Elements in File: " << line.size();
			std::cout << '\n' << "Desired Line: " << lineNo;
			return;
		}


		std::string emptyLine;
		for ( int i=0; i<2; i++ )
			emptyLine = emptyLine + ' ';
		emptyLine = emptyLine + '\n';

		line[lineNo] = emptyLine;

		for ( unsigned int i=0; i<emptyLine.size(); i++ )
			line.push_back(emptyLine);

		// OUTPUT
		//std::cout << "\n\nNo of Elements: " << line.size() << '\n';
		//for ( unsigned int i=0; i<line.size(); i++ )
		//	std::cout << line[i] << '\n';

		// Reset the .txt's internal position
		myfile.clear();
		myfile.seekg( 0, std::ios::beg );

		
		std::cout << "\n\n\n";
		for ( unsigned int i=0; i<line.size(); i++ ) {
			myfile << line.at(i);
			std::cout << line.at(i);
		}


		
		// Close the .txt file
		myfile.close();


		// OUTPUT
		//std::cout << "\n\n";
		//for ( unsigned int i=0; i<line.size(); i++ )
		//	std::cout << line[i];
		//std::cout << "\n\n";
	}

	// Delete a line within a .txt file
	void delete_txt( std::string fileName ) {		
		fileName = fileName + ".txt";
		
		// Test the fileName isn't blank
		if ( ( fileName == "" ) || ( fileName.empty() ) ) {
			//std::cout << '\n' << "Empty Filename";
			return;
		}

		if( remove( fileName.c_str() ) != 0 ) {
			perror( "Error deleting file" );
			std::cout << "File: " << fileName;
		}



		std::ofstream myfile;
		myfile.open (fileName);
		myfile.close();
	}

} // Namespace IOManager