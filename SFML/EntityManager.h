#pragma once

// Standard Input/Output stream
#include <iostream>

// STD Strings
#include <string>

// The vector library
#include <vector>

// Dynamic and static entity's
#include "DynamicEntity.h"
#include "StaticEntity.h"
#include "RocketSmoke.h"

// For using Smart Pointers
#include <memory>

	// Holds a group of dynamic entity's, all with the game name
	// Eg, a group of blocks
	struct DynamicGroup {
		std::vector < std::shared_ptr<DynamicEntity> > entity;
		std::string name;
		int number = 0;
		unsigned int groupLayer = 0;
		sf::Vector2f speed;
		sf::Vector2f acceleration;
		sf::Vector2f size;

		sf::Vector2f m_collisionBoxPos;
		sf::Vector2f m_collisionBoxSize;

		// Animation Stuff
		std::vector< std::string > animationName;
		std::vector< sf::Vector2f > animationFrames;
		std::vector< float > animationSpeed;

		~DynamicGroup() {
			std::cout << '\n' << "Deleting: Dynamic Entities: " << name;
			for ( unsigned int i=0; i<entity.size(); i++ )
				std::get_deleter<DynamicEntity>( entity.at(i) );
			entity.resize(0);
		}
	};

	// Holds a group of static entity's, all with the same name
	// Eg, a group of trees
	struct StaticGroup {
		std::vector < std::shared_ptr<StaticEntity> > entity;
		std::string name;
		int number = 0;

		~StaticGroup() {
			std::cout << '\n' << "Deleting: Static Entities: " << name;
			for ( unsigned int i=0; i<entity.size(); i++ )
				std::get_deleter<StaticEntity>( entity.at(i) );
			entity.resize(0);
		}
	};

	// Holds all the Particle Group
	// Including:
	// Rocket Smoke
	struct Particles {
		std::vector < std::shared_ptr<RocketSmoke> > rocketSmoke;

		~Particles() {
			std::cout << '\n' << "Deleting: Smoke Particles";

			for ( unsigned int i=0; i<rocketSmoke.size(); i++ )
				std::get_deleter<RocketSmoke> ( rocketSmoke.at(i) );
			rocketSmoke.resize(0);
		}
	};



	// A manager to store all the entity's as seperate groups
	// Eg, all blocks are a group, all backgrounds are a group
	class EntityManager {
		private:
			sf::RectangleShape rectView;
			
			//==============================================================================================
			// The Entity Groups
			//==============================================================================================
			
			// Each element stores a group of entities
			std::vector< std::shared_ptr<DynamicGroup> > dynamicGroup;
			std::vector< std::shared_ptr<StaticGroup> > staticGroup;

			// The particles
			std::shared_ptr<Particles> particles;

		public:

			//==============================================================================================
			// Constructors, and
			// Destructors
			//==============================================================================================

			// Default Constructor
			EntityManager() { }

			// Destructor
			// Which deletes both vectors
			~EntityManager();

			// Returns a vector holding EVERY Entity
			std::vector< std::shared_ptr<AbstractEntity> > getAllEntities();

			// Calls the update method for each entity
			void update();

			// Reset all entities to their origional position
			void reset() { resetExcluding( "" ); }

			// Reset all entities to their origional position
			// Excluding a single group
			void resetExcluding( std::string excluding );


			//==============================================================================================
			// For rendering
			//==============================================================================================

			// Set the view size
			// sf::RectangleShape rectView is the view size which can be gotten from the camera
			void setRectView( sf::RectangleShape rectView ) { this->rectView = rectView; }


			//==============================================================================================
			// Dynamic Entity Methods
			//==============================================================================================
			
			// Set all the data for Dynamic Entities again
			void setData();

			// Returns a vector holding every Dynamic Entity
			std::vector< std::shared_ptr<DynamicEntity> > getAllDynamicEntities();

			// Return how many DynamicGrous there are
			unsigned int getNoOfDynamicGroups() { return dynamicGroup.size(); }

			// Returns the number of elements in a single DynamicGroup
			unsigned int getDynamicGroupSize( int groupNumber ) { return dynamicGroup[groupNumber]->entity.size(); }

			// Returns the number of elements in a single DynamicGroup
			unsigned int getDynamicGroupSize( std::string group ) { return getDynamicEntity( group ).size(); }

			// Create a new set of DynamicEntity's
			void newDynamicGroup( std::string name, unsigned int groupLayer );

			// Create a new set of DynamicEntity's
			void newDynamicGroup( std::string name ) { newDynamicGroup( name, 0 ); }

			// Add a new DynamicEntity onto an exisiting DynamicGroup
			bool addDynamicEntityToGroup( std::string name );

			// Returns a vector pointing to a group of DynamicEntities
			std::vector< std::shared_ptr<DynamicEntity> > getDynamicEntity( std::string group ) { return dynamicGroup[ getDynamicGroup(group) ]->entity; }

			// Returns a vecot pointing to a group of DynamicEntities
			std::vector< std::shared_ptr<DynamicEntity> > getDynamicEntity( unsigned int groupNumber ) { return dynamicGroup[ groupNumber ]->entity; }

			// Return the index for a DynamicEntity group
			// Returns -1 on fail
			int getDynamicGroup( std::string name );

			// Return a vector which holds the name of each dynamicGroup
			std::vector<std::string> getAllDynamicGroupTypes();

			// Test a collision between two Entity Groups
			// Tests a collision between each entity in each group
			// And returns the ID to the colliding entity for group1
			// Returns -1 if no collision
			int collision( std::string group1, std::string group2 );

			// Test a any collisions occur within the same Entity Group
			// Tests a collision between each entity in the group
			// And returns the ID to the colliding entity
			// Returns -1 if no collision
			int collision( std::string group );

			// Tests whether two entity's collide
			// And returns the index of each entity
			// as a single std::string
			// in the format: index + ' ' + index
			// eg, "2 5"
			std::string collisionAsString( std::string group1, std::string group2 );

			// Test whether a group of entities contain a point
			// Using two floats
			// Returns the ID to the first entity in the group the point's overlapping
			// Returns -1 if no entity contains the point
			int contains( std::string group, float x, float y);

			// Test whether a group of entities contain a point
			// Using sf::Vector2f
			// Returns the ID to the first entity in the group the point's overlapping
			// Returns -1 if no entity contains the point
			int contains( std::string group, sf::Vector2f pos ) { return contains( group, pos.x, pos.y ); }

			// Test a collision between two Entity Groups
			// Tests a collision between each entity in each group
			// And returns the ID to the colliding entity for group1
			// Returns -1 if no collision
			int circleCollision( std::string group1, std::string group2 );

			// Test a any collisions occur within the same Entity Group
			// Tests a collision between each entity in the group
			// And returns the ID to the colliding entity
			// Returns -1 if no collision
			int circleCollision( std::string group );

			// Set the default speed for a DynamicGroup
			// Return true if speed was set, or
			// false if it was not set
			// std::string groupName is the name of the group
			// sf::Vector2f speed is the default speed to set
			bool setDynamicGroupSpeed( std::string groupName, sf::Vector2f speed );

			// Set the default acceleration for a DynamicGroup
			// Return true if the acceleration was set, or
			// false if it was not set
			// std::string groupName is the name of the group
			// sf::Vector2f acceleration is the default acceleration to set
			bool setDynamicGroupAcceleration( std::string groupName, sf::Vector2f acceleration );

			// Set the default size for a DynamicGroup
			// Return true if the size was set, or
			// false if it was not set
			// std::string groupName is the name of the group
			// sf::Vector2f size is the default size to set
			bool setDynamicGroupSize( std::string groupName, sf::Vector2f size );


			bool addGroupAnimation( std::string groupName, std::string animationName, sf::Vector2f frames, float speed );

			bool setCollisionBox( std::string groupName, sf::Vector2f collisionBoxPos, sf::Vector2f collisionBoxSize );


			// Moves every dynamic entity
			// float displacement is how much to move each entity horitontally
			void moveAllDynamicEntities( float displacement ) { moveAllDynamicEntities( displacement, "" ); }

			// Moves every dynamic entity EXCEPT one group
			// float displacement is how much to move each entity horitontally
			// std::string excludingGroup is the ONE group which should not move
			void moveAllDynamicEntities( float displacement, std::string excludingGroup );


			//==============================================================================================
			// Static Entity Methods
			//==============================================================================================

			// Returns how many StaticGroups there are
			unsigned int getNoOfStaticGroups() { return staticGroup.size(); }

			// Returns the number of elements in a single StaticGroup
			unsigned int getStaticGroupSize( int groupNumber ) { return staticGroup[groupNumber]->entity.size(); }

			// Create a new set of StaticEntity's
			void newStaticGroup( std::string name );

			// Add an existing StaticEntity onto an exisiting StaticGroup
			bool addStaticEntityToGroup( std::string name, StaticEntity* o );

			// Add a new StaticEntity onto an existing StaticGroup
			bool addStaticEntityToGroup( std::string name );


			// Returns a vector pointing to a group of StaticEntities
			std::vector< std::shared_ptr<StaticEntity> > getStaticEntity( std::string group ) { return staticGroup[ getStaticGroup(group) ]->entity; }
			
			// Returns a vector pointing to a group of StaticEntities
			std::vector< std::shared_ptr<StaticEntity> > getStaticEntity( unsigned int groupNumber ) { return staticGroup[ groupNumber ]->entity; }


			// Return the index for a StaticEntity group
			// Returns -1 on fail
			int getStaticGroup( std::string name );


			//==============================================================================================
			// Particle Methods
			//==============================================================================================

			// Creates all the particles in the game
			// Must be called before any work is done on particles
			void createParticles();

			// Returns true if particles successfully created
			// And false otherwise
			bool createRocketParticles( unsigned int layer );

			// Access the vector of rocket particles
			std::vector< std::shared_ptr<RocketSmoke> > getRocketParticles();

	};