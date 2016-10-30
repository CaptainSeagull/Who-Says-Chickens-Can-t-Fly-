#pragma once

// Standard IO / STD Strings
#include <iostream>
#include <string>

#include <SFML\System\Vector2.hpp>

// IO File stream
#include <fstream>

// Include Vector Arrays
#include <vector>

#include <ctype.h>

#include "Utility.h"

namespace IOManager {

	// Reads in data from a .txt file
	// And returns it as a std::string
	// fileName is the path to the .txt file to read
	// and gets converted from fileName to fileName.txt
	// key is the key within the file to find the data
	std::string readFile_txt( std::string fileName, std::string key );

	// Reads in data from a .txt file
	// And assigns it to the string data[]
	// fileName is the path to the .txt file to read
	// and gets converted from fileName to fileName.txt
	// key is the key within the file to find the data
	// data is the string to store the data
	std::vector<std::string> readArrayFile_txt( std::string fileName, std::string key );


	void readArrayFile_txt( std::string fileName, std::string key, std::vector<std::string> &arr );

	// Reads in data from a .txt file
	// which contains data for a level within the game
	// fileName is the path to the .txt file to read
	// and gets converted from fileName to fileName.txt
	// &entityName is a std::vector which will get populated with entity types
	// &position is a std::vector which will get populated with entity positions
	// &entityName and &position are interlocked, eg. entityName[1] = position[1]
	void readLevel_txt( std::string fileName, std::vector< std::string > &entityName, std::vector< sf::Vector2f > &position );

	// Output data to a .txt file
	// fileName is the path to the .txt file to read
	// and gets converted from fileName to fileName.txt
	// key is the key whose data should be replaced
	// If the key is not found, then a new key will be outputted
	// at the end of the .txt file
	// NOTE - Will not rewrite .txt file which begin 'Const'
	void write_txt( std::string fileName, std::string key, std::string data );

	// Output data to a .txt file
	// fileName is the path to the .txt file to read
	// and gets converted from fileName to fileName.txt
	// key is the key whose data should added at the end
	// If the key is not found, then a new key will be outputted
	// at the end of the .txt file
	// NOTE - Will not rewrite .txt file which begin 'Const'
	void add_txt( std::string fileName, std::string key, std::string data );
	

	void deleteLine_txt( std::string fileName, unsigned int lineNo );

	// Delete an entire .txt file
	// fileName is the path to the .txt file to deleted
	// and gets converted from fileName to fileName.txt
	// WARNING - Perminantly deletes .txt files without backups
	void delete_txt( std::string fileName );
};