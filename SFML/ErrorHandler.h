#pragma once

#include <iostream>
#include <string>

	namespace ErrorHandler {

		// Output, to the console, the name of the object
		// which was just created
		void successfullyCreated(std::string object);

		// Call if there's anunrecoverable error
		// And this function will exit the program
		void exitFatalError(std::string message);

		// Output a warning to the console
		// But continue running the program despite it
		void warning(std::string message);
	
	} // namespace ErrorHandler