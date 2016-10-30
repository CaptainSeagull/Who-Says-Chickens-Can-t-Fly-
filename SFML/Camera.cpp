#include "Camera.h"

// Return a rectangle the same size as the camera view
sf::RectangleShape Camera::getRectView() {
	sf::RectangleShape rectangle;
	rectangle.setSize( view.getSize() );
	rectangle.setPosition( getPosition() );
	return rectangle;
}