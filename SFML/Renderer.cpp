#include "Renderer.h"

// Draw all game objects
void Renderer::draw( sf::RenderWindow *window, Camera* camera ) {
	// Draw each enemy
	// Filtering out Entities which are offscreen
	for ( unsigned int i=0; i<layerGroup.size(); i++ ) {
		for ( unsigned int k=0; k<layerGroup.at(i)->entity.size(); k++ ) {
			if ( layerGroup.at(i)->entity.at(k)->exists() == true ) {

				if  ( ( layerGroup.at(i)->entity.at(k)->getType() == "Background" )
				|| ( ( ( layerGroup.at(i)->entity.at(k)->getRightX() > camera->getX() ) && ( layerGroup.at(i)->entity.at(k)->getX() < camera->getX() + camera->getSize().x ) ) && layerGroup.at(i)->entity.at(k)->getPosition().x > 1.0f ) ) {
					window->draw( *layerGroup.at(i)->entity.at(k) );
					
					//if ( layerGroup.at(i)->entity.at(k)->getType() == "PlayerDead" )
					//	std::cout << '\n' << "Drawing PlayerDead";
				}
			}
		}
	}
}

// Initialize all game objecys
void Renderer::initializeEntities( std::vector< std::shared_ptr<AbstractEntity> > entity ) {	
	for ( unsigned int i=0; i<entity.size(); i++ )
		if ( largestLayer < entity.at(i)->getLayer() )
			largestLayer = entity.at(i)->getLayer();

	for ( unsigned int i=0; i<largestLayer+1; i++ ) {
		layerGroup.push_back( std::shared_ptr<LayerGroup> ( new LayerGroup() ) );
		layerGroup.back()->layerNumber = i;

		for ( unsigned int k=0; k<entity.size(); k++ )
			if ( entity.at(k)->getLayer() == layerGroup.back()->layerNumber )
				layerGroup.back()->entity.push_back( std::shared_ptr<AbstractEntity> ( entity.at(k) ) );
	}
}

// Add a new Entity to the renderer
void Renderer::addEntity( std::shared_ptr<AbstractEntity> entity ) {	
	// If the added Entity's Layer is bigger than the largest layer...
	// Then increase the largest layer to the current Entity's Layer
	if ( entity->getLayer() > largestLayer )
		for ( unsigned int i=largestLayer; i<entity->getLayer()+1; i++ ) {
			layerGroup.push_back( std::shared_ptr<LayerGroup> ( new LayerGroup() ) );
			layerGroup.back()->layerNumber = i;
		}

	// Add the Entity onto the Render Group
	layerGroup.at( entity->getLayer() )->entity.push_back( entity );
}

// The method destructor
Renderer::~Renderer() {
	for ( unsigned int i=0; i<layerGroup.size(); i++ )
		std::get_deleter<LayerGroup>( layerGroup.at(i) );
	layerGroup.resize(0);
}