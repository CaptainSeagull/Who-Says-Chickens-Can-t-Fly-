#include "Controllers.h"

bool Controllers::init() {
	// Load the game logic handles
	gameLogic = std::auto_ptr<GameLogic> ( new GameLogic() );

	// Load the game renderer
	renderer = std::auto_ptr<Renderer> ( new Renderer() );

	// Load the level editor
	levelEditor = std::auto_ptr<LevelEditor> ( new LevelEditor() );

	return true;
}



Controllers::~Controllers() {
	std::cout << '\n' << "Deleting: Controllers";

	gameLogic.get_deleter();
	renderer.get_deleter();
	levelEditor.get_deleter();
}