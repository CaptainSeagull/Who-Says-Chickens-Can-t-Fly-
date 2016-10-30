#include "ErrorHandler.h"

namespace ErrorHandler {

	// Output the name of the object created
	void successfullyCreated(std::string object) {
		std::cout << '\n' << "Successfully Created: " << object;
	}

	// Ouput a fatal error and quits the program
	void exitFatalError(std::string message) {
		std::cout << '\n' << '\n' << "Fatal Error: " << message;
		std::cout << '\n' << "Exiting Program Now";
		std::cout << '\n' << "Press Return to Quit";
		std::cin.get();
		exit(1);
	}

	// Output a warning, but continues running
	void warning(std::string message) {
		std::cout << '\n' << "Warning: " << message;
	}
} // namespace ErrorHandler