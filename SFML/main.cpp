//============================================================================================
// Additional Dependancies
//============================================================================================

// Diffeent SFML library files must be included depending
// on whether it's running in Debug or Release Mode
// The format is:
// Debug:		sfml-xxx-d.lib
// Release:		sfml-xxx.lib

#ifdef _DEBUG
	// Include SFML libraries for debug mode
	#pragma comment( lib, "sfml-system-d.lib" )
	#pragma comment( lib, "sfml-window-d.lib" )
	#pragma comment( lib, "sfml-graphics-d.lib" ) 
	#pragma comment( lib, "sfml-network-d.lib" )
	#pragma comment( lib, "sfml-audio-d.lib" )
	#pragma comment( lib, "sfml-main-d.lib" )

	// Activate the console
	#pragma comment( linker, "/subsystem:\"console\" /entry:\"WinMainCRTStartup\"" )
#else
	// Include SFML libraries for release mode
	#pragma comment( lib, "sfml-system.lib" )
	#pragma comment( lib, "sfml-window.lib" )
	#pragma comment( lib, "sfml-graphics.lib" )
	#pragma comment( lib, "sfml-network.lib" )
	#pragma comment( lib, "sfml-audio.lib" )
	#pragma comment( lib, "sfml-main.lib" )

	#pragma comment( linker, "/subsystem:\"console\" /entry:\"WinMainCRTStartup\"" )
#endif


//============================================================================================
// Headers
//============================================================================================

// To use the windows API
#include <windows.h>

// Include the actual game
#include "GameContext.h"

// For handling .txt file input
#include "IOManager.h"


//============================================================================================
// Function called whenever one of the windows receives a message
//============================================================================================

LRESULT CALLBACK onEvent( HWND handle, UINT message, WPARAM wParam, LPARAM lParam ) {
	switch (message) {
		// Quit when the main window is closed
		case WM_CLOSE:
            PostQuitMessage(0);
            return 0;
			break;

		default:
			break;
	}

	return DefWindowProc(handle, message, wParam, lParam);
}


//============================================================================================
// Entry point of application
//
// \param Instance : Instance of the application
//
// \return Error code
//
//============================================================================================

// The program starting point
// Using SAL Annotations
INT WINAPI WinMain( _In_ HINSTANCE instance, _In_opt_ HINSTANCE, _In_ LPSTR, _In_ INT ) {
	// Define a class for the main window
	WNDCLASS windowClass;
	windowClass.style         = 0;
	windowClass.lpfnWndProc   = &onEvent;
	windowClass.cbClsExtra    = 0;
	windowClass.cbWndExtra    = 0;
	windowClass.hInstance     = instance;
	windowClass.hIcon         = NULL;
	windowClass.hCursor       = 0;
	windowClass.hbrBackground = reinterpret_cast<HBRUSH>(COLOR_BACKGROUND);
	windowClass.lpszMenuName  = NULL;
	windowClass.lpszClassName = TEXT( "SFML Engine" );
	RegisterClass(&windowClass);


	//====================================================================================================================================================
	// Setup some information about the window
	//====================================================================================================================================================

	// The window width
	std::string cWidth = IOManager::readFile_txt( "data//startup", "screenWidth" );
	if ( cWidth == "\n" )
		ErrorHandler::exitFatalError( "Screen Width not read from file" );

	// The window height
	std::string cHeight = IOManager::readFile_txt( "data//startup", "screenHeight" );
	if ( cHeight == "\n" )
		ErrorHandler::exitFatalError( "Screen Height Not Read From File Properly" );


	// Load the window title
	std::string strTitle = IOManager::readFile_txt( "data//startup", "screenTitle" );

	// Test the window title was loaded properly
	if ( strTitle == "\n" )
		strTitle = "Default";


	// Create a window
	HWND window = CreateWindow (
		TEXT("SFML Engine"),											// Window Handle
		std::wstring( strTitle.begin(), strTitle.end() ).c_str(),		// Window Title ( in the format std::wstring which is converted to LPWSTR )
		WS_SYSMENU | WS_VISIBLE | WS_MINIMIZEBOX,						// Window Features
		0, 0,															// Position
		atoi( cWidth.c_str() ), atoi( cHeight.c_str() ),				// Size
		NULL,															// Parent Window
		NULL,															// Handle to the menu window
		instance,														// A handle to the instance
		NULL
	);

	// Test the window was created properly
	if (window == NULL)
		ErrorHandler::exitFatalError( "Window Not Created Properly" );
	else {
		std::cout << '\n' << "Successfully Created: Main Window";
		std::cout << '\n' << "'" << strTitle << "' - Width: " << cWidth << "  Height: " << cHeight << '\n';
	}


	//============================================================================================
	// The game starts here
	//============================================================================================

	// Game Context is the actual game
	// The other parts were just setting up stuff
	GameContext *gameContext = nullptr;
	gameContext = new GameContext(window);

	// If the GameContext class was successfully created
	if ( gameContext != nullptr ) {
		// Initialize the game context class
		gameContext->init();

		// Holds the main game loop
		// Which updates the game and renders it to the screen
		gameContext->run();

		// Delete game context after use
		delete gameContext;
	
	// Or, if there was an error creating the class
	} else
		ErrorHandler::exitFatalError( "GameContext Class Failed To Initialize" );


	//============================================================================================
	// End of game stuff
	//============================================================================================

	// Destroy the main window ( all its child controls will also be destroyed )
	if ( DestroyWindow( window ) == false )
		ErrorHandler::exitFatalError( "HWND Window Failed To Be Destroyed" );

	// Unregister the window class
	UnregisterClass(TEXT("SFML Engine"), instance);


	// Stop the game imediately exiting
	// For testing purposes only
	std::cout << '\n' << "Game Successfully Destroyed!";
	std::cout << '\n' << "Press Return to Quit";
	std::cin.get();

	// Exit the program
	return EXIT_SUCCESS;
}