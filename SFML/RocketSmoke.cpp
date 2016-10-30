#include "RocketSmoke.h"
#include "RocketSmoke.h"

void RocketSmoke::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw( smoke );
	//target.draw( fire );
	//target.draw( redFlame );
}

		
void RocketSmoke::create() {
	//int noOfRedFlame = atoi( IOManager::readFile_txt( "data//PlayState//init//effects//rocketSmoke", "no_of_redflame_particles" ).c_str() );
	//int noOfYellowFlame =  atoi( IOManager::readFile_txt( "data//PlayState//init//effects//rocketSmoke", "no_of_yellowflame_particles" ).c_str() );
	int noOfSmoke =  atoi( IOManager::readFile_txt( "data//PlayState//init//effects//rocketSmoke", "no_of_smoke_particles" ).c_str() );
	
	/*
	// Setup red flame
	redFlame.setPrimitiveType( sf::Points );
	redFlame.resize( noOfRedFlame );


	for ( unsigned int i=0; i<redFlame.getVertexCount(); i++ ) {
		redFlame[i].color = sf::Color::Red;
		
		maxRedFlameDistance = atoi( IOManager::readFile_txt( "data//PlayState//init//effects//rocketSmoke", "max_redflame_distance" ).c_str() );

		redFlameSpeed = (float) atof( IOManager::readFile_txt( "data//PlayState//init//effects//rocketSmoke", "redflame_speed" ).c_str() );

		redFlameDistance.push_back( Utility::random( 0, maxRedFlameDistance ) );
	}
	
	// Setup fire
	fire.setPrimitiveType( sf::Points );
	fire.resize( noOfYellowFlame );

	for ( unsigned int i=0; i<fire.getVertexCount(); i++ ) {
		fire[i].color = sf::Color::Yellow;
		
		maxFireDistance = atoi( IOManager::readFile_txt( "data//PlayState//init//effects//rocketSmoke", "max_fire_distance" ).c_str() );

		fireSpeed = (float) atof( IOManager::readFile_txt( "data//PlayState//init//effects//rocketSmoke", "fire_speed" ).c_str() );

		fireDistance.push_back( Utility::random( 0, maxFireDistance ) );
	}
	*/

	// Setup smoke
	smoke.setPrimitiveType( sf::Points );
	smoke.resize( noOfSmoke );

	for ( unsigned int i=0; i<smoke.getVertexCount(); i++ ) {
		smoke[i].color = sf::Color::White;
		
		maxSmokeDistance = atoi( IOManager::readFile_txt( "data//PlayState//init//effects//rocketSmoke", "max_smoke_distance" ).c_str() );

		smokeSpeed = (float) atof( IOManager::readFile_txt( "data//PlayState//init//effects//rocketSmoke", "smoke_speed" ).c_str() );

		smokeDistance.push_back( Utility::random( 0, maxSmokeDistance ) );
	}
}

void RocketSmoke::update() {
	/*
	// Update Red fire
	for ( unsigned int i=0; i<redFlame.getVertexCount(); i++ ) {
		redFlame[i].position.x -= Utility::random( 0.0f, redFlameSpeed * AbstractEntity::deltaTime.asSeconds() );
		
		if ( Utility::distance( getPosition(), redFlame[i].position ) > redFlameDistance.at(i) ) {
			redFlameDistance.at(i) = Utility::random( 0, maxRedFlameDistance );
			redFlame[i].position = getPosition();
			redFlame[i].position.x += Utility::random( -size.x, size.x );
			redFlame[i].position.y += Utility::random( -size.y, size.y );
		}
	}
	
	// Update fire
	for ( unsigned int i=0; i<fire.getVertexCount(); i++ ) {
		fire[i].position.x -= Utility::random( 0.0f, fireSpeed * AbstractEntity::deltaTime.asSeconds() );
		
		if ( Utility::distance( getPosition(), fire[i].position ) > fireDistance.at(i) ) {
			fireDistance.at(i) = Utility::random( 0, maxFireDistance );
			fire[i].position = getPosition();
			fire[i].position.x += Utility::random( -size.x, size.x );
			fire[i].position.y += Utility::random( -size.y, size.y );
		}
	}
	*/

	// Update Smoke
	for ( unsigned int i=0; i<smoke.getVertexCount(); i++ ) {
		smoke[i].position.x -= Utility::random( 0.0f, smokeSpeed * AbstractEntity::deltaTime.asSeconds() );
		
		if ( Utility::distance( getPosition(), smoke[i].position ) > smokeDistance.at(i) ) {
			smokeDistance.at(i) = Utility::random( 0, maxSmokeDistance );
			smoke[i].position = getPosition();
			smoke[i].position.x += Utility::random( -size.x, size.x );
			smoke[i].position.y += Utility::random( -size.y, size.y );
		}
	}
}