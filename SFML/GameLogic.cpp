#include "GameLogic.h"

//======================================================================================================================================================================================================
// Initialize Details about the Game Logic
//======================================================================================================================================================================================================

// Intialization
void GameLogic::init( float shotTimer ) {
	playerShootingData = std::auto_ptr<ShootingData> ( new ShootingData() );
	playerShootingData->maxTimer = shotTimer;

	m_playerAnimation = std::auto_ptr<PlayerAnimation> ( new PlayerAnimation() );
}

// Initialize the keyboard controls
void GameLogic::initKeyboard( std::string up_key, std::string down_key, std::string right_key, std::string left_key ) {
	m_playerControls = std::auto_ptr<PlayerControls> ( new PlayerControls( up_key, down_key, right_key, left_key ) );
}

// Initialize the mouse controls
void GameLogic::initMouse( float speed ) {
	m_playerControls = std::auto_ptr<PlayerControls> ( new PlayerControls( speed ) );
}

// Add a new entity group onto the GameLogic
void GameLogic::addEnemyGroup( int shoots, float shotTimer ) {
	m_enemyGroupShoots.push_back( shoots );
	enemyShootingData.push_back( std::auto_ptr<EnemyGroupShooting> ( new EnemyGroupShooting() ) );
	enemyShootingData.back()->shotTimer = shotTimer;
	m_numberOfEnemyTypes++;
}


//======================================================================================================================================================================================================
// Changing Level
//======================================================================================================================================================================================================

// Call whenever the level's changed
int GameLogic::changeLevel() {
	int r = m_changeLevel;
	m_changeLevel = 0;
	//checkpointData.score = m_score;
	return r;
}

// Return true or false
// Based on whether the game should be saved or not
bool GameLogic::getSave() {
	// First the method copies the contents of m_save
	// Then it resets m_save to false
	// And finally it turns the copied contents of m_save
	
	bool temp = m_save;
	m_save = false;
	return temp;
}


//======================================================================================================================================================================================================
// Run Method
//======================================================================================================================================================================================================

// Handles the running of the game
void GameLogic::run( EntityManager* entities, Camera* camera, UserInput* userInput, sf::Vector2f mousePos ) {	

	//=================================================================================================================================================================================
	// Logic Stuff
	//=================================================================================================================================================================================

	// Check whether the game should be reset or not
	checkResetToCheckpoint( entities, camera );

	// Check what the scroling speed should be and assign it
	m_scrollingSpeed = checkScrollingSpeed( userInput );


	//=================================================================================================================================================================================
	// Collisions
	//=================================================================================================================================================================================

	// Handle collisions between the player and checkpoint objects
	collision_checkpoint(entities);

	// Limit the player's movement to the edge of the screen
	collision_playerCameraEdge(entities, camera);

	// Handle collisions between the player and blocks
	collision_playerBlock(entities);

	// Handle collisions between player and enemy
	collision_playerEnemy(entities);


	// Handle collisions between the player and enemy bullets
	collision_playerBullet(entities);

	// Handle collisions between enemy's and the player's bullets
	collision_enemyBullet(entities);

	// Handle collisions between bullets and blocks
	collision_bulletBlock(entities);

	// Handle collisions between bullets and breakable blocks
	collision_bulletBreakableBlock(entities);

	// Handle collisions between the player and breakable blocks
	collision_playerBreakableBlock(entities);


	//=================================================================================================================================================================================
	// Update all entities
	//=================================================================================================================================================================================

	// Allow User-Input to move the player
	m_playerControls->update(entities->getDynamicEntity("Player").back().get(), userInput, mousePos);

	// Update the players animation
	m_playerAnimation->update(entities->getDynamicEntity("Player").back().get(), userInput);

	// Make the player constantly move right
	entities->getDynamicEntity("Player").back()->moveX(m_scrollingSpeed);

	// Limit the player's movement to the edge of the screen
	collision_playerCameraEdge(entities, camera);

	// Set the camera's x position
	camera->setX(camera->getX() + m_scrollingSpeed * AbstractEntity::deltaTime.asSeconds());

	// Update enemies
	update_enemy1( entities, camera );
	update_enemy2( entities, camera );
	update_enemy3( entities, camera );
	update_enemy4( entities, camera );
	update_enemy5( entities, camera );
	update_enemy6( entities, camera );


	for ( unsigned int i=1; i<m_numberOfEnemyTypes+1; i++ ) {
		for ( unsigned int k=0; k<entities->getDynamicEntity( "Enemy" + std::to_string(i) ).size(); k++ )
			if ( entities->getDynamicEntity( "Enemy" + std::to_string(i) ).at(k)->hasAnimationEnded( "Death" ) == true ) {
				entities->getDynamicEntity( "Enemy" + std::to_string(i) ).at(k)->setAnimation( "Normal" );
				entities->getDynamicEntity( "Enemy" + std::to_string(i) ).at(k)->setDeleted( true );
			}
	}


	// Update bullets
	update_bullets( entities, camera );


	// Update the Foreground
	update_foreground( entities, camera );
	

	//=================================================================================================================================================================================
	// Particles
	//=================================================================================================================================================================================

	// Update the particals in the game
	// If the player is dead then make the particles jump offscreen
	if ( getPlayerDead() == false )
		entities->getRocketParticles().back()->setPosition( entities->getDynamicEntity( "Player" ).back()->getCentreX(), entities->getDynamicEntity( "Player" ).back()->getCentreY() );
	else
		entities->getRocketParticles().back()->setPosition( 0.0f, 0.0f );

	entities->getRocketParticles().back()->update();

	//=================================================================================================================================================================================
	// Update Entities
	//=================================================================================================================================================================================

	// Update each entity
	entities->update();
	
	
	//=================================================================================================================================================================================
	// Handle shooting
	//=================================================================================================================================================================================

	// Make the player shoot
	shooting_player( entities, userInput );

	// Make enemies shoot
	shooting_enemy( entities, camera );
}


//======================================================================================================================================================================================================
// Logic Stuff
//======================================================================================================================================================================================================

// Test whether the game should be reset back to the last checkpoint or not
void GameLogic::checkResetToCheckpoint( EntityManager* entities, Camera* camera ) {
	
	
	// Set the checkpoint to the player's initial position if it's not already been set
	if ( checkpointData.m_checkpointSet == false ) {
		checkpointData.lastCheckpoint = entities->getDynamicEntity( "Player" ).back()->getInitialPosition();
		checkpointData.m_checkpointSet = true;
	}
	

	// Reset the game if it should be reset
	if ( m_reset == true ) {

		camera->zoom();

		if ( entities->getDynamicEntity( "Player" ).back()->getCurrentAnimation() != "Dead" ) {
			// Make the explosion visible and set it to the player's position
			entities->getDynamicEntity( "PlayerDead" ).back()->setVisible( true );
			entities->getDynamicEntity( "PlayerDead" ).back()->setPosition( entities->getDynamicEntity( "Player" ).back()->getPosition() );
			entities->getDynamicEntity( "PlayerDead" ).back()->setAnimation( "Exploading" );
		}

		// Change the player into a roasted chicken upon death
		m_playerDead = true;
		entities->getDynamicEntity( "Player" ).back()->setAnimation( "Dead" );
		entities->getDynamicEntity( "Player" ).back()->accelerateY();
		entities->getDynamicEntity( "Player" ).back()->accelerateY();


		// If the animation has finished then properly reset the game
		if ( entities->getDynamicEntity( "PlayerDead" ).back()->hasAnimationEnded( "Exploading" ) == true ) {
			entities->getDynamicEntity( "PlayerDead" ).back()->setAnimation( "ExploadingDone" );
			entities->getDynamicEntity( "PlayerDead" ).back()->setVisible( false );
		}

		if ( entities->getDynamicEntity( "PlayerDead" ).back()->hasAnimationEnded( "ExploadingDone" ) == true ) {
			m_reset = false;

			// Set PlayerDead's data to invisible
			entities->getDynamicEntity( "PlayerDead" ).back()->setAnimation( "Default" );
			entities->getDynamicEntity( "PlayerDead" ).back()->setVisible( false );

			// Reset every Entity
			entities->reset();


			// Reset the Player's data
			entities->getDynamicEntity( "Player" ).back()->setAnimation( "Neutral" );
			entities->getDynamicEntity( "Player" ).back()->setVisible( true );
			entities->getDynamicEntity( "Player" ).back()->setPosition( checkpointData.lastCheckpoint );
			m_playerDead = false;

			// Reset the camera
			camera->setCentreX( entities->getDynamicEntity( "Player" ).back()->getCentre().x );
			camera->defaultZoom();

			// Reset the score
			m_score = checkpointData.score;

			// Save the game
			save();

			// Delete all the currently created bullets
			for ( unsigned int i=0; i<entities->getDynamicEntity( "Bullet" ).size(); i++ )
				entities->getDynamicEntity( "Bullet" ).at(i)->setDeleted( true );
		}
	}
}

// Get the current scrolling speed
float GameLogic::checkScrollingSpeed( UserInput* userInput ) {
	if ( userInput->z() == true )
		return m_slowScrollingSpeed;
	if ( userInput->x() == true )
		return m_fastScrollingSpeed;
	else
		return m_defaultScrollingSpeed;
}


//======================================================================================================================================================================================================
// Update Logic
//======================================================================================================================================================================================================

// Update each enemy's logic
void GameLogic::update_enemy1( EntityManager* entities, Camera* camera ) {
	// For each entity
	// Make it move once it's onscreen
	for ( unsigned int i=0; i<entities->getDynamicEntity( "Enemy1").size(); i++ )
		if ( entities->getDynamicEntity( "Enemy1" ).at(i)->onScreen( camera->getRectView() ) == true )
			if ( entities->getDynamicEntity( "Enemy1" ).at(i)->getCurrentAnimation() != "Death" )
				entities->getDynamicEntity( "Enemy1" ).at(i)->moveNX();

}
void GameLogic::update_enemy2( EntityManager* entities, Camera* camera ) {
	static std::vector<int> up;
	static float travelDistance = (float) atof( IOManager::readFile_txt( "data//PlayState//init//Enemy2//data", "vertical_travel_distance" ).c_str() );

	if ( up.size() < entities->getDynamicEntity( "Enemy2" ).size() ) {
		for ( unsigned int i=up.size(); i<entities->getDynamicEntity( "Enemy2" ).size(); i++ )
			up.push_back(0);
	}

	// For each entity
	// Make it move once it's onscreen
	for ( unsigned int i=0; i<entities->getDynamicEntity( "Enemy2" ).size(); i++ )
		if ( entities->getDynamicEntity( "Enemy2" ).at(i)->onScreen( camera->getRectView() ) == true )
			if ( entities->getDynamicEntity( "Enemy2" ).at(i)->getCurrentAnimation() != "Death" ) {
			
				entities->getDynamicEntity( "Enemy2" ).at(i)->moveNX();


				if ( Utility::distance( entities->getDynamicEntity( "Enemy2" ).at(i)->getInitialPosition().y, entities->getDynamicEntity( "Enemy2" ).at(i)->getPosition().y ) > travelDistance ) {
					if ( up.at(i) == 1 ) {
						up.at(i) = 0;
						entities->getDynamicEntity( "Enemy2" ).at(i)->setY( entities->getDynamicEntity( "Enemy2" ).at(i)->getInitialPosition().y - travelDistance+1.0f );
					} else {
						up.at(i) = 1;
						entities->getDynamicEntity( "Enemy2" ).at(i)->setY( entities->getDynamicEntity( "Enemy2" ).at(i)->getInitialPosition().y + travelDistance-1.0f );
					}
				}


				if ( up.at(i) == 1 )
					entities->getDynamicEntity( "Enemy2" ).at(i)->moveNY();
				else
					entities->getDynamicEntity( "Enemy2" ).at(i)->moveY();
			}

	// If the game is reset, then reset all enemy2's movement data
	if (m_reset == true) 
		for (unsigned int i=0; i<up.size(); i++)
			up.at(i) = 0;
}
void GameLogic::update_enemy3( EntityManager* entities, Camera* camera ){
	// For each entity
	// Make it move once it's onscreen
	for ( unsigned int i=0; i<entities->getDynamicEntity( "Enemy3").size(); i++ )
		if ( entities->getDynamicEntity( "Enemy3" ).at(i)->onScreen( camera->getRectView() ) == true )
			if ( entities->getDynamicEntity( "Enemy3" ).at(i)->getCurrentAnimation() != "Death" )
				entities->getDynamicEntity( "Enemy3" ).at(i)->moveNX();

	// Make the enemy bullet follow the player on the x-axis
	for ( unsigned int i=0; i<entities->getDynamicEntity( "Bullet" ).size(); i++ )
		if ( entities->getDynamicEntity( "Bullet" ).at(i)->getDeleted() == false ) {

			for ( unsigned int k=0; k<entities->getDynamicEntity( "Enemy3" ).size(); k++ )
				if ( entities->getDynamicEntity( "Bullet" ).at(i)->getType() == "Enemy3Bullet" + std::to_string(k) )
					entities->getDynamicEntity( "Bullet" ).at(i)->moveTowardsY( entities->getDynamicEntity( "Player" ).back()->getPosition().y, -entities->getDynamicEntity( "Bullet" ).at(i)->getSpeed().x / 5.0f );

		}
}
void GameLogic::update_enemy4( EntityManager* entities, Camera* camera ) {
	std::string enemyName = "Enemy4";

	// For each Enemy4
	// Make it move
	for ( unsigned int i=0; i<entities->getDynamicEntity( enemyName ).size(); i++ )
		if ( entities->getDynamicEntity( enemyName ).at(i)->onScreen( camera->getRectView() ) == true )
			if ( entities->getDynamicEntity( enemyName ).at(i)->getCurrentAnimation() != "Death" )
				entities->getDynamicEntity( enemyName ).at(i)->moveNX();
	
	// Make Enemy4's bullet shoot upwards
	for ( unsigned int i=0; i<entities->getDynamicEntity( "Bullet" ).size(); i++ )
		if ( entities->getDynamicEntity( "Bullet" ).at(i)->getDeleted() == false ) {

			for ( unsigned int k=0; k<entities->getDynamicEntity( enemyName ).size(); k++ )
				if ( entities->getDynamicEntity( "Bullet" ).at(i)->getType() == enemyName + "Bullet" + std::to_string(k) ) {
					entities->getDynamicEntity( "Bullet" ).at(i)->setX( entities->getDynamicEntity( enemyName ).at(k)->getCentre().x );
					entities->getDynamicEntity( "Bullet" ).at(i)->moveY();
					entities->getDynamicEntity( "Bullet" ).at(i)->setAnimation( "Up" );
				}
		}
}
void GameLogic::update_enemy5( EntityManager* entities, Camera* camera ) {
	std::string enemyName = "Enemy5";

	// For each Enemy4
	// Make it move
	for ( unsigned int i=0; i<entities->getDynamicEntity( enemyName ).size(); i++ )
		if ( entities->getDynamicEntity( enemyName ).at(i)->onScreen( camera->getRectView() ) == true )
			if ( entities->getDynamicEntity( enemyName ).at(i)->getCurrentAnimation() != "Death" )
				entities->getDynamicEntity( enemyName ).at(i)->moveNX();
	
	// Make Enemy4's bullet shoot upwards
	for ( unsigned int i=0; i<entities->getDynamicEntity( "Bullet" ).size(); i++ )
		if ( entities->getDynamicEntity( "Bullet" ).at(i)->getDeleted() == false ) {

			for ( unsigned int k=0; k<entities->getDynamicEntity( enemyName ).size(); k++ )
				if ( entities->getDynamicEntity( "Bullet" ).at(i)->getType() == enemyName + "Bullet" + std::to_string(k) ) {
					entities->getDynamicEntity( "Bullet" ).at(i)->setX( entities->getDynamicEntity( enemyName ).at(k)->getCentre().x );
					entities->getDynamicEntity( "Bullet" ).at(i)->moveNY();
					entities->getDynamicEntity( "Bullet" ).at(i)->setAnimation( "Down" );
				}
		}
}
void GameLogic::update_enemy6( EntityManager* entities, Camera* camera ) {
	// For each entity
	// Make it move once it's onscreen
	for ( unsigned int i=0; i<entities->getDynamicEntity( "Enemy6" ).size(); i++ )
		if ( entities->getDynamicEntity( "Enemy6" ).at(i)->onScreen( camera->getRectView() ) == true )
			if ( entities->getDynamicEntity( "Enemy6" ).at(i)->getCurrentAnimation() != "Death" )
				entities->getDynamicEntity( "Enemy6" ).at(i)->moveTowardsPoint( entities->getDynamicEntity( "Player" ).back()->getPosition() );
}

// Update bullets
void GameLogic::update_bullets( EntityManager* entities, Camera* camera ) {
	// Handle moving bullets
	for ( unsigned int i=0; i<entities->getDynamicEntity( "Bullet" ).size(); i++ )
		if ( entities->getDynamicEntity( "Bullet" ).at(i)->exists() == true ) {
			entities->getDynamicEntity( "Bullet" ).at(i)->moveX( m_scrollingSpeed );
			entities->getDynamicEntity( "Bullet" ).at(i)->moveX();

			if ( entities->getDynamicEntity( "Bullet" ).at(i)->onScreen( camera->getRectView() ) == false )
				entities->getDynamicEntity( "Bullet" ).at(i)->setDeleted( true );

		} else
			entities->getDynamicEntity( "Bullet" ).at(i)->setPosition( 0.0f, 0.0f );



}

// Update Foreground
void GameLogic::update_foreground( EntityManager* entities, Camera* camera ) {
	// Handle moving foreground
	for ( unsigned int i=0; i<entities->getDynamicEntity( "Foreground" ).size(); i++ )
		if ( entities->getDynamicEntity( "Foreground" ).at(i)->onScreen( camera->getRectView() ) == true )
			entities->getDynamicEntity( "Foreground" ).at(i)->moveX();	
}



//======================================================================================================================================================================================================
// Collisions
//======================================================================================================================================================================================================


// Collisions between the Player and Checkpoint objects
void GameLogic::collision_checkpoint( EntityManager* entities ) {

	// When the player touches a 'checkpoint'
	// Save the player's position as the last checkpoint
	int c = entities->collision( "Checkpoint", "Player" );
	if ( c > -1 ) {
		checkpointData.lastCheckpoint = entities->getDynamicEntity( "Player" ).back()->getPosition();
		checkpointData.score = m_score;
		save();
	}
}


// Lock the player onscreen
void GameLogic::collision_playerCameraEdge( EntityManager* entities, Camera* camera ) {
	if ( getPlayerDead() == true )
		return;
	
	if ( entities->getDynamicEntity( "Player" ).back()->getX() <= camera->getLeftMargin() )
		entities->getDynamicEntity( "Player" ).back()->setX( camera->getLeftMargin() );

	else if ( entities->getDynamicEntity( "Player" ).back()->getX() >= camera->getRightMargin() )
		entities->getDynamicEntity( "Player" ).back()->setX( camera->getRightMargin() );

	if ( entities->getDynamicEntity( "Player" ).back()->getY() <= camera->getTopMargin() )
		entities->getDynamicEntity( "Player" ).back()->setY( camera-> getTopMargin() );

	else if ( entities->getDynamicEntity( "Player" ).back()->getY() >= camera->getBottomMargin() )
		entities->getDynamicEntity( "Player" ).back()->setY( camera->getBottomMargin() );
}

// Collisions between the player and block
void GameLogic::collision_playerBlock( EntityManager* entities ) {
	int c = entities->collision( "Block", "Player" );
	if ( c > -1 )
		resetToCheckpoint();
}

// Collisions between the player and enemies
void GameLogic::collision_playerEnemy( EntityManager* entities ) {
	int c = -1;
	for ( unsigned int i=1; i<m_numberOfEnemyTypes+1; i++ ) {
		c = entities->collision( "Enemy" + std::to_string(i), "Player" );

		if ( c > -1 )
			if ( entities->getDynamicEntity( "Enemy" + std::to_string(i) ).at(c)->getCurrentAnimation() != "Death" )
				resetToCheckpoint();
	}
}

// Collisions between the Enemy and other Bullets
void GameLogic::collision_enemyBullet( EntityManager* entities ) {
	std::string c = "";
	for ( unsigned int i=1; i<m_numberOfEnemyTypes+1; i++ )  {
		std::string str_i = std::to_string(i);

		c = entities->collisionAsString( "Enemy" + str_i, "Bullet" );

		if ( c != "" ) {
			unsigned int space = c.find(' ');
			unsigned int enemyNumber = atoi( c.substr( 0, space ).c_str() );
			unsigned int bulletNumber = atoi( c.substr( space+1, c.size() ).c_str() );

			if ( entities->getDynamicEntity( "Enemy" + str_i ).at( enemyNumber )->getCurrentAnimation() != "Death" ) {

				if ( entities->getDynamicEntity( "Bullet" ).at( bulletNumber )->getType() != "Enemy" + str_i + "Bullet" + std::to_string( enemyNumber ) ) { 
				
					if ( entities->getDynamicEntity( "Bullet" ).at( bulletNumber )->getType() == "PlayerBullet" )
						if ( ( entities->getDynamicEntity( "Bullet" ).at( bulletNumber )->exists() == true ) && ( ( entities->getDynamicEntity( "Enemy" + str_i ).at( enemyNumber )->exists() == true ) ) )
							m_score += 100;


					//entities->getDynamicEntity( "Enemy" + str_i ).at( enemyNumber )->setDeleted( true );
					entities->getDynamicEntity( "Enemy" + str_i ).at( enemyNumber )->setAnimation( "Death" );
					entities->getDynamicEntity( "Bullet" ).at( bulletNumber )->setDeleted( true );
				}
			}
		}
	}
}

// Collisions between the Player and Enemy Bullets
void GameLogic::collision_playerBullet( EntityManager* entities ) {
	int c = entities->collision( "Bullet", "Player" );

	if ( c > -1 )
		if ( entities->getDynamicEntity( "Bullet" ).at(c)->getType() != "PlayerBullet" ) {
			resetToCheckpoint();

			for ( unsigned int i=0; i<entities->getDynamicEntity( "Bullet" ).size(); i++ )
				entities->getDynamicEntity( "Bullet" ).at(i)->setDeleted( true );
		}
}

// Collisions between Bullets and Blocks
void GameLogic::collision_bulletBlock( EntityManager* entities ) {
	int c = entities->collision( "Bullet", "Block" );

	if ( c > -1 )
		entities->getDynamicEntity( "Bullet" ).at( c )->setDeleted( true );
}

// Collisions between Bullets and Breakable Blocks
void GameLogic::collision_bulletBreakableBlock( EntityManager* entities ) {
	std::string c = "";

	c = entities->collisionAsString( "BreakableBlock", "Bullet" );

	if ( c != "" ) {
		unsigned int space = c.find(' ');
		unsigned int breakableBlockNumber = atoi( c.substr( 0, space ).c_str() );
		unsigned int bulletNumber = atoi( c.substr( space+1, c.size() ).c_str() );

		entities->getDynamicEntity( "BreakableBlock" ).at( breakableBlockNumber )->setDeleted( true );
		entities->getDynamicEntity( "Bullet" ).at( bulletNumber )->setDeleted( true );
	}
}

// Collisions between the Player and Breakable Blocks
void GameLogic::collision_playerBreakableBlock( EntityManager* entities ) {
	int c = entities->collision( "BreakableBlock", "Player" );
	if ( c > -1 )
		resetToCheckpoint();
}


//======================================================================================================================================================================================================
// Shooting
//======================================================================================================================================================================================================

// Handle the player's shooting
void GameLogic::shooting_player( EntityManager* entities, UserInput* userInput ) {
	// Handle creating a bullet
	sf::Vector2f playerPos = entities->getDynamicEntity( "Player" ).back()->getCentre();

	if ( userInput->space() == true ) {
		if ( playerShootingData->canShoot == true ) {
			for ( unsigned int i=0; i<entities->getDynamicEntity( "Bullet" ).size(); i++ ) {
				if ( entities->getDynamicEntity( "Bullet" ).at(i)->getDeleted() == true ) {
					entities->getDynamicEntity( "Bullet" ).at(i)->setDeleted( false );
					entities->getDynamicEntity( "Bullet" ).at(i)->setPosition( playerPos - sf::Vector2f( -10.0f, 17.0f ) );
					entities->getDynamicEntity( "Bullet" ).at(i)->resetCurrentSpeed();
					if ( entities->getDynamicEntity( "Bullet" ).at(i)->getSpeed().x < 0 )
						entities->getDynamicEntity( "Bullet" ).at(i)->setSpeed( -entities->getDynamicEntity( "Bullet" ).at(i)->getSpeed() );
					entities->getDynamicEntity( "Bullet" ).at(i)->setType( "PlayerBullet" );
					entities->getDynamicEntity( "Bullet" ).at(i)->setAnimation( "Right" );
					playerShootingData->canShoot = false;
					playerShootingData->shotTimer = 0.0f;
					break;
				}
			}
		}
	}

	// Handle the time inbetween shots
	if ( playerShootingData->canShoot == false ) {
		playerShootingData->shotTimer += AbstractEntity::deltaTime.asSeconds();
		if ( playerShootingData->shotTimer > playerShootingData->maxTimer )
			playerShootingData->canShoot = true;
	}
}

// Handle enemy's shooting
void GameLogic::shooting_enemy( EntityManager* entities, Camera* camera ) {	
	// For each enemy group...
	for ( unsigned int j=0; j<m_numberOfEnemyTypes; j++ ) {
		std::string str_j = std::to_string(j+1);
		
		// If the current group of enemy's don't shoot...
		// then move onto the next group
		if ( m_enemyGroupShoots.at(j) == 0 )
			continue;

		// Add a shooting object onto any enemies which don't already have one
		if ( enemyShootingData.at(j)->enemyShootingData.size() < entities->getDynamicEntity( "Enemy" + str_j ).size() ) {
			for ( unsigned int i=enemyShootingData.at(j)->enemyShootingData.size(); i<entities->getDynamicEntity( "Enemy" + str_j ).size(); i++ ) {
				
				enemyShootingData.at(j)->enemyShootingData.push_back( std::auto_ptr<ShootingData> ( new ShootingData() ) );
				enemyShootingData.at(j)->enemyShootingData.back()->maxTimer = enemyShootingData.at(j)->shotTimer;
			}
		}


		//=========================================================================================================================================================
		// Handle creating a bullet
		//=========================================================================================================================================================

		// For each enemy...
		for ( unsigned int k=0; k<entities->getDynamicEntity( "Enemy" + str_j ).size(); k++ ) {

			// If the enemy exists and is currently on the screen...
			if ( entities->getDynamicEntity( "Enemy" + str_j ).at(k)->exists() == true )// && ( entities->getDynamicEntity( "Enemy" + str_j ).at(k)->onScreen( camera->getRectView() ) == true ) ) {
				if ( entities->getDynamicEntity( "Enemy" + str_j ).at(k)->getCurrentAnimation() != "Death" ) {


					// Make the enemy shoot if they're ready...
					if ( enemyShootingData.at(j)->enemyShootingData.at(k)->canShoot == true ) {
						for ( unsigned int i=0; i<entities->getDynamicEntity( "Bullet" ).size(); i++ ) {
							if ( entities->getDynamicEntity( "Bullet" ).at(i)->getDeleted() == true ) {
								// Enemy + 'enemytype' + Bullet + 'Number with type'
								entities->getDynamicEntity( "Bullet" ).at(i)->setType( "Enemy" + str_j + "Bullet" + std::to_string(k) );
								entities->getDynamicEntity( "Bullet" ).at(i)->setDeleted( false );
								entities->getDynamicEntity( "Bullet" ).at(i)->setCentre( entities->getDynamicEntity( "Enemy" + str_j ).at(k)->getCentre() );
								entities->getDynamicEntity( "Bullet" ).at(i)->resetCurrentSpeed();
								if ( entities->getDynamicEntity( "Bullet" ).at(i)->getSpeed().x > 0 )
									entities->getDynamicEntity( "Bullet" ).at(i)->setSpeed( -entities->getDynamicEntity( "Bullet" ).at(i)->getSpeed() );
								entities->getDynamicEntity( "Bullet" ).at(i)->setAnimation( "Left" );
								enemyShootingData.at(j)->enemyShootingData.at(k)->shotTimer = 0.0f;
								enemyShootingData.at(j)->enemyShootingData.at(k)->canShoot = false;
								break;
							}
						}
					}

					// Handle the time inbetween shots
					if ( enemyShootingData.at(j)->enemyShootingData.at(k)->canShoot == false ) {
						enemyShootingData.at(j)->enemyShootingData.at(k)->shotTimer += AbstractEntity::deltaTime.asSeconds();
						if ( enemyShootingData.at(j)->enemyShootingData.at(k)->shotTimer > enemyShootingData.at(j)->enemyShootingData.at(k)->maxTimer )
							enemyShootingData.at(j)->enemyShootingData.at(k)->canShoot = true;
					}


				}
		}
	}
}


//======================================================================================================================================================================================================
// Destructor
//======================================================================================================================================================================================================

// Destructor
GameLogic::~GameLogic() {
	m_playerControls.get_deleter();
	playerShootingData.get_deleter();
}