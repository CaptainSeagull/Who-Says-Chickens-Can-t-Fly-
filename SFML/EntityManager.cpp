#include "EntityManager.h"

// Return a vector holding each entity
std::vector< std::shared_ptr<AbstractEntity> > EntityManager::getAllEntities() {
	std::vector< std::shared_ptr<AbstractEntity> > returnKey;

	for ( unsigned int i=0; i<dynamicGroup.size(); i++ )
		for ( unsigned int k=0; k<dynamicGroup.at(i)->entity.size(); k++ ) 
			returnKey.push_back( dynamicGroup.at(i)->entity.at(k) );

	for ( unsigned int i=0; i<staticGroup.size(); i++ )
		for ( unsigned int k=0; k<staticGroup.at(i)->entity.size(); k++ )
			returnKey.push_back( staticGroup.at(i)->entity.at(k) );

	for ( unsigned int i=0; i<particles->rocketSmoke.size(); i++ )
		returnKey.push_back( particles->rocketSmoke.at(i) );

	return returnKey;
}

// Update each entity
void EntityManager::update() {
	// Update every Dynamic Entity
	for ( unsigned int i=0; i<dynamicGroup.size(); i++ )
		for ( unsigned int k=0; k<dynamicGroup.at(i)->entity.size(); k++ )
			dynamicGroup.at(i)->entity.at(k)->update();

	// Update every Static Entity
	for ( unsigned int i=0; i<staticGroup.size(); i++ )
		for ( unsigned int k=0; k<staticGroup.at(i)->entity.size(); k++ )
			staticGroup.at(i)->entity.at(k)->update();
}

void EntityManager::resetExcluding( std::string excluding ) {
	// Reset every Dynamic Entity
	for ( unsigned int i=0; i<dynamicGroup.size(); i++ )
		if ( dynamicGroup.at(i)->name != excluding )
			for ( unsigned int k=0; k<dynamicGroup.at(i)->entity.size(); k++ )
				dynamicGroup.at(i)->entity.at(k)->reset();


	// Reset every Static Entity
	for ( unsigned int i=0; i<staticGroup.size(); i++ )
		if ( staticGroup.at(i)->name != excluding )
			for ( unsigned int k=0; k<staticGroup.at(i)->entity.size(); k++ )
				staticGroup.at(i)->entity.at(k)->reset();
}


//==================================================================================================================
// Dynamic Entity Methods
//==================================================================================================================

void EntityManager::setData() {
	update();
	
	for ( unsigned int i=0; i<dynamicGroup.size(); i++ ) {

		// This prevent a glitch which causes the player to become invisible
		// Not idea what the cause is... something to do with animation I think
		// Also has the same effects with Checkpoint objects... da fuck!?
		if ( ( dynamicGroup.at(i)->name == "Player" ) || ( dynamicGroup.at(i)->name == "Checkpoint" ) || ( dynamicGroup.at(i)->name == "Bullet" ) || ( dynamicGroup.at(i)->name == "Boss" ) )
			continue;

		// For each objects...
		for ( unsigned int k=0; k<dynamicGroup.at(i)->entity.size(); k++ ) {
		
			dynamicGroup.at(i)->entity.at(k)->setLayer( dynamicGroup.at(i)->groupLayer );

			dynamicGroup.at(i)->entity.at(k)->setSpeed( dynamicGroup.at(i)->speed );

			dynamicGroup.at(i)->entity.at(k)->setSize( dynamicGroup.at(i)->size );

			dynamicGroup.at(i)->entity.at(k)->setAcceleration( dynamicGroup.at(i)->acceleration );

			dynamicGroup.at(i)->entity.at(k)->setCollisionBoundry( dynamicGroup.at(i)->m_collisionBoxPos, dynamicGroup.at(i)->m_collisionBoxSize );

			// Add animations
			for ( unsigned int j=0; j<dynamicGroup.at(i)->animationName.size(); j++ ) {
				dynamicGroup.at(i)->entity.at(k)->addAnimation(
					dynamicGroup.at(i)->animationName.at(j),
					dynamicGroup.at(i)->animationFrames.at(j).x, dynamicGroup.at(i)->animationFrames.at(j).y,
					dynamicGroup.at(i)->animationSpeed.at(j)
				);
			}
		}
	}
}


// Return a vector holding each dynamic entity
std::vector< std::shared_ptr<DynamicEntity> > EntityManager::getAllDynamicEntities() {
	std::vector< std::shared_ptr<DynamicEntity> > returnKey;

	for ( unsigned int i=0; i<dynamicGroup.size(); i++ )
		for ( unsigned int k=0; k<dynamicGroup.at(i)->entity.size(); k++ ) 
			returnKey.push_back( dynamicGroup.at(i)->entity.at(k) );

	return returnKey;
}


// Create a new set of DynamicEntity's
void EntityManager::newDynamicGroup( std::string name, unsigned int groupLayer ) {	
	dynamicGroup.push_back( std::shared_ptr<DynamicGroup> ( new DynamicGroup() ) );

	dynamicGroup.back()->groupLayer = groupLayer;

	dynamicGroup.back()->name = name;

	dynamicGroup.back()->speed = sf::Vector2f( 0.0f, 0.0f );

	dynamicGroup.back()->size = sf::Vector2f( 0.0f, 0.0f );

	dynamicGroup.back()->acceleration = sf::Vector2f( 1.0f, 1.0f );
}

// A a new entity onto an exisiting DynamicEntity
bool EntityManager::addDynamicEntityToGroup( std::string name ) {
	// found stores whether the group has been found or not
	// And groupNo is the number the group is at
	bool found = false;
	unsigned int groupNo;
	
	// Find the dynamic entity group
	for ( unsigned int i=0; i<dynamicGroup.size(); i++ )
		if ( dynamicGroup[i]->name == name ) {
			groupNo = i;
			found = true;
		}

	// Return false if the group hasn't been found
	if ( found == false )
		return found;
			
	// Add a new Entity onto the group
	dynamicGroup.at( groupNo )->entity.push_back( std::shared_ptr<DynamicEntity> ( new DynamicEntity( dynamicGroup.at( groupNo )->number, name  ) ) );

	// Init method
	dynamicGroup.at( groupNo )->entity.back()->init();

	// Set the new entity's layer
	dynamicGroup.at( groupNo )->entity.back()->setLayer( dynamicGroup.at( groupNo )->groupLayer );

	// Set the new entity's speed
	dynamicGroup.at( groupNo )->entity.back()->setSpeed( dynamicGroup.at( groupNo )->speed );

	// Set the new entity's size
	dynamicGroup.at( groupNo )->entity.back()->setSize( dynamicGroup.at( groupNo )->size );

	// Set the new entity's acceleration
	dynamicGroup.at( groupNo )->entity.back()->setAcceleration( dynamicGroup.at( groupNo )->acceleration );

	// Set the new entity's Collision Box
	dynamicGroup.at( groupNo )->entity.back()->setCollisionBoundry( dynamicGroup.at( groupNo )->m_collisionBoxPos, dynamicGroup.at( groupNo )->m_collisionBoxSize );

	// Add animations
	for ( unsigned int k=0; k<dynamicGroup.at( groupNo )->animationName.size(); k++ ) {
		dynamicGroup.at( groupNo )->entity.back()->addAnimation(
			dynamicGroup.at( groupNo )->animationName.at(k),
			dynamicGroup.at( groupNo )->animationFrames.at(k).x, dynamicGroup.at( groupNo )->animationFrames.at(k).y,
			dynamicGroup.at( groupNo )->animationSpeed.at(k)
		);
	}

	// Set the starting animation to the default one
	if ( dynamicGroup.at( groupNo )->animationName.size() > 0 )
		dynamicGroup.at( groupNo )->entity.back()->setAnimation( dynamicGroup.at( groupNo )->animationName.at(0) );

	// Increment the number of entity's in the group by one
	dynamicGroup.at( groupNo )->number++;

	// Return true, showing everything worked nicely
	return true;
}

// Return the index for a DynamicEntity group
int EntityManager::getDynamicGroup( std::string name ) {
	for ( unsigned int i=0; i<dynamicGroup.size(); i++ )
		if ( dynamicGroup[i]->name == name )
			return i;

		return -1;
}

// Returns the names of each Dynamic Entity Group
std::vector<std::string> EntityManager::getAllDynamicGroupTypes() {
	std::vector<std::string> returnKey;

	for ( unsigned int i=0; i<dynamicGroup.size(); i++ )
		returnKey.push_back( dynamicGroup.at(i)->name );

	return returnKey;
}


// Test a collision between two entity groups
int EntityManager::collision( std::string group1, std::string group2 ) {
	// Get the two groups of entities
	int g1 = getDynamicGroup(group1);
	int g2 = getDynamicGroup(group2);

	// Test a collision between each entity in each group
	// And return the ID to the colliding entity for group1


	for ( unsigned int i=0; i<dynamicGroup[g1]->entity.size(); i++ )
		for ( unsigned int k=0; k<dynamicGroup[g2]->entity.size(); k++ )
			if ( ( dynamicGroup[g1]->entity.at(i)->exists() == true ) && ( ( dynamicGroup[g2]->entity.at(k)->exists() == true ) ) )
				if ( dynamicGroup.at(g1)->entity.at(i)->intersects( dynamicGroup.at(g2)->entity.at(k).get() ) )
					return i;

	// Return -1 on fail
	return -1;
}

std::string EntityManager::collisionAsString( std::string group1, std::string group2 ) {
	// Get the two groups of entities
	int g1 = getDynamicGroup(group1);
	int g2 = getDynamicGroup(group2);

	// Test a collision between each entity in each group
	// And return the ID to the colliding entity for group1
	for ( unsigned int i=0; i<dynamicGroup[g1]->entity.size(); i++ )
		for ( unsigned int k=0; k<dynamicGroup[g2]->entity.size(); k++ )
			if ( dynamicGroup.at(g1)->entity.at(i)->intersects( dynamicGroup.at(g2)->entity.at(k).get() ) )
				return std::to_string(i) + ' ' + std::to_string(k);

	// Return -1 on fail
	return "";
}



// Test whether two objects, within the same group, collide
int EntityManager::collision( std::string group ) {
	// Get the two groups of entities
	int g = getDynamicGroup(group);

	// Test a collision between each entity in each group
	// And return the ID to the colliding entity
	// While making sure entity's don't collide with each other
	for ( unsigned int i=0; i<dynamicGroup[g]->entity.size(); i++ )
		for ( unsigned int k=0; k<dynamicGroup[g]->entity.size(); k++ )
			if ( i != k )
				if ( dynamicGroup[g]->entity[i]->circleIntersects( dynamicGroup[g]->entity[k].get() ) == true )
					return k;

	// Return -1 on fail
	return -1;
}

// Test whether a group of entities contain a point
int EntityManager::contains( std::string group, float x, float y) {
	// Get the two groups of entities
	int g = getDynamicGroup(group);

	// Test a collision between each entity in each group
	// And return the ID to the colliding entity for group1
	for ( unsigned int i=0; i<dynamicGroup[g]->entity.size(); i++ )
		if ( dynamicGroup[g]->entity[i]->contains( x, y ) )
			return i;

	// Return -1 on fail
	return -1;
}


// Test a collision between two entity groups
int EntityManager::circleCollision( std::string group1, std::string group2 ) {
	// Get the two groups of entities
	int g1 = getDynamicGroup(group1);
	int g2 = getDynamicGroup(group2);

	// Test a collision between each entity in each group
	// And return the ID to the colliding entity for group1
	for ( unsigned int i=0; i<dynamicGroup[g1]->entity.size(); i++ )
		for ( unsigned int k=0; k<dynamicGroup[g2]->entity.size(); k++ )
			if ( dynamicGroup.at(g1)->entity.at(i)->circleIntersects( dynamicGroup.at(g2)->entity.at(k).get() ) == true )
				return i;

	// Return -1 on fail
	return -1;
}

// Test whether two objects, within the same group, collide
int EntityManager::circleCollision( std::string group ) {
	// Get the two groups of entities
	int g = getDynamicGroup(group);

	// Test a collision between each entity in each group
	// And return the ID to the colliding entity for group1
	for ( unsigned int i=0; i<dynamicGroup[g]->entity.size(); i++ )
		for ( unsigned int k=0; k<dynamicGroup[g]->entity.size(); k++ )
			if ( i != k )
				if ( dynamicGroup[g]->entity[i]->circleIntersects( dynamicGroup[g]->entity[k].get() ) )
					return i;

	// Return -1 on fail
	return -1;
}

// Set a group's default speed
bool EntityManager::setDynamicGroupSpeed( std::string groupName, sf::Vector2f speed ) {
	for ( unsigned int i=0; i<dynamicGroup.size(); i++ )
		if ( dynamicGroup.at(i)->name == groupName ) {
			dynamicGroup.at(i)->speed = speed;
			for ( unsigned int k=0; k<dynamicGroup.at(i)->entity.size(); k++ )
				dynamicGroup.at(i)->entity.at(k)->setSpeed( speed );
			return true;
		}

	return false;
}

bool EntityManager::setDynamicGroupAcceleration( std::string groupName, sf::Vector2f acceleration ) {
	for ( unsigned int i=0; i<dynamicGroup.size(); i++ )
		if ( dynamicGroup.at(i)->name == groupName ) {
			dynamicGroup.at(i)->acceleration = acceleration;
			for ( unsigned int k=0; k<dynamicGroup.at(i)->entity.size(); k++ )
				dynamicGroup.at(i)->entity.at(k)->setAcceleration( acceleration );
			return true;
		}

	return false;
}


// Set a group's default size
bool EntityManager::setDynamicGroupSize( std::string groupName, sf::Vector2f size) {
	for ( unsigned int i=0; i<dynamicGroup.size(); i++ )
		if ( dynamicGroup.at(i)->name == groupName ) {
			dynamicGroup.at(i)->size = size;
			for ( unsigned int k=0; k<dynamicGroup.at(i)->entity.size(); k++ )
				dynamicGroup.at(i)->entity.at(k)->setSize( size );
			return true;
		}

	return false;
}

bool EntityManager::addGroupAnimation( std::string groupName, std::string animationName, sf::Vector2f frames, float speed ) {
	for ( unsigned int i=0; i<dynamicGroup.size(); i++ )
		if ( dynamicGroup.at(i)->name == groupName ) {

			dynamicGroup.at(i)->animationName.push_back( animationName );
			dynamicGroup.at(i)->animationFrames.push_back( frames );
			dynamicGroup.at(i)->animationSpeed.push_back( speed );

			for ( unsigned int k=0; k<dynamicGroup.at(i)->entity.size(); k++ )
				dynamicGroup.at(i)->entity.at(k)->addAnimation( animationName, frames.x, frames.y, speed );

			return true;
		}

	return false;
}

bool EntityManager::setCollisionBox( std::string groupName, sf::Vector2f collisionBoxPos, sf::Vector2f collisionBoxSize ) {
	for ( unsigned int i=0; i<dynamicGroup.size(); i++ )
		if ( dynamicGroup.at(i)->name == groupName ) {
			dynamicGroup.at(i)->m_collisionBoxPos = collisionBoxPos;
			dynamicGroup.at(i)->m_collisionBoxSize = collisionBoxSize;

			for ( unsigned int k=0; k<dynamicGroup.at(i)->entity.size(); k++ )
				dynamicGroup.at(i)->entity.at(k)->setCollisionBoundry( collisionBoxPos, collisionBoxSize );

			return true;
		}

	return false;
}


void EntityManager::moveAllDynamicEntities( float displacement, std::string excludingGroup ) {
	for ( unsigned int i=0; i<dynamicGroup.size(); i++ )
		for ( unsigned int k=0; k<dynamicGroup.at(i)->entity.size(); k++ )
			if ( dynamicGroup.at(i)->entity.at(k)->getType() != excludingGroup )
				dynamicGroup.at(i)->entity.at(k)->moveX( displacement );
}

//==================================================================================================================
// Static Entity Methods
//==================================================================================================================

// Create a new set of StaticEntity's
void EntityManager::newStaticGroup( std::string name ) {	
	staticGroup.push_back( std::shared_ptr<StaticGroup> ( new StaticGroup() ) );

	staticGroup.back()->name = name;
}


// Add a new StaticEntity onto a specific group
bool EntityManager::addStaticEntityToGroup( std::string name ) {
	for ( unsigned int i=0; i<staticGroup.size(); i++ )
		if ( staticGroup[i]->name == name ) {
			staticGroup[i]->entity.push_back( std::shared_ptr<StaticEntity> ( new StaticEntity( name, staticGroup[i]->number ) ) );
			staticGroup[i]->number++;
			return true;
		}

	return false;
}

// Return the index for a StaticEntity group
int EntityManager::getStaticGroup( std::string name ) {
	for ( unsigned int i=0; i<staticGroup.size(); i++ )
		if ( staticGroup[i]->name == name )
			return i;

		return -1;
}


//==================================================================================================================
// Particle Methods
//==================================================================================================================

void EntityManager::createParticles() {
	particles = std::shared_ptr<Particles> ( new Particles() );
}

// Returns true if particles successfully created
// And false otherwise
bool EntityManager::createRocketParticles( unsigned int layer ) {								
	// If the particles have been initialized
	if ( particles != nullptr ) {
		particles->rocketSmoke.push_back( std::shared_ptr<RocketSmoke> ( new RocketSmoke() ) );
		particles->rocketSmoke.back()->setLayer( layer );
		particles->rocketSmoke.back()->create();

		return true;
	}

	// Return false if they haven't
	return false;
}

// Access the vector of rocket particles
std::vector< std::shared_ptr<RocketSmoke> > EntityManager::getRocketParticles() {				
	// Return a pointer to the rocket particles if they've been initialized
	if ( particles != nullptr )
		return particles->rocketSmoke;

	// Or a pointer to an empty vector on failure
	else {
		std::vector < std::shared_ptr<RocketSmoke> > fail;
		return fail;
	}
}


//==================================================================================================================
// Destructor
//==================================================================================================================
EntityManager::~EntityManager() {
	std::cout << '\n' << '\n' << "Deleting: Entity Manager";

	// Delete Dynamic Entities
	for ( unsigned int i=0; i<dynamicGroup.size(); i++ )
		std::get_deleter<DynamicGroup>( dynamicGroup.at(i) );
	dynamicGroup.resize(0);

	// Delete Static Entities
	for ( unsigned int i=0; i<staticGroup.size(); i++ )
		std::get_deleter<StaticGroup>( staticGroup.at(i) );
	staticGroup.resize(0);

	// Delete Particles
	std::get_deleter<Particles> ( particles );
}