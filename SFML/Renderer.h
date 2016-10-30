#pragma once

// Smart Pointers
#include <memory>

#include "AbstractEntity.h"

#include "Camera.h"

#include "Timer.h"


	// Holds a group of AbstractEntities
	// All with the same Layer
	struct LayerGroup {		
		std::vector< std::shared_ptr<AbstractEntity> > entity;

		int layerNumber;

		~LayerGroup() {
			for ( unsigned int i=0; i<entity.size(); i++ )
				std::get_deleter<AbstractEntity>( entity.at(i) );
			entity.resize(0);
		}
	};


	// Handles the Rendering for Entities
	// Including making sure they're drawn on the correct layer
	class Renderer {
		private:
			// The largest layout number
			unsigned int largestLayer = 0;
			
			// Holds each entity in a different group
			// Based on their layout number
			std::vector< std::shared_ptr<LayerGroup> > layerGroup;

			Timer timer;


		public:
			Renderer() { }
			~Renderer();

			// Used to initlaize all Entities at the start of the game
			void initializeEntities( std::vector< std::shared_ptr<AbstractEntity> > entity );


			// Used to add a new Entity to the class
			void addEntity( std::shared_ptr<AbstractEntity> entity );

			// Render all entities onscreen
			// Based on their layout number
			void draw( sf::RenderWindow *window, Camera* camera );
	};