#pragma once

#include "EntityManager.h"
#include "Camera.h"
#include "UserInput.h"

#include "PlayerControls.h"
#include "PlayerAnimation.h"

#include "ShootingData.h"

#include "Timer.h"

struct EnemyGroupShooting {
	std::vector< std::unique_ptr<ShootingData> > enemyShootingData;
	float shotTimer;
};

struct CheckpointData {
	bool m_checkpointSet = false;
	sf::Vector2f lastCheckpoint = sf::Vector2f( 0.0f, 0.0f );
	unsigned int score = 0;
};

	class GameLogic {
		private:

			Timer timer;

			// Allows the User to be moved with the keyboard
			std::unique_ptr<PlayerControls> m_playerControls;

			// For the player's animation
			std::unique_ptr<PlayerAnimation> m_playerAnimation;

			// Shooting data for the player
			std::unique_ptr<ShootingData> playerShootingData;
			std::vector< std::unique_ptr<EnemyGroupShooting> > enemyShootingData;

			// The scrolling speed of the window
			float m_scrollingSpeed = 0.0f;

			float m_defaultScrollingSpeed = 0.0f;
			float m_fastScrollingSpeed = 0.0f;
			float m_slowScrollingSpeed = 0.0f;


			// Whether the entities are being reset or not
			bool m_reset = false;

			unsigned int m_numberOfEnemyTypes = 0;
			std::vector<int> m_enemyGroupShoots;

			// The last saved checkpoint
			CheckpointData checkpointData;

			// The score
			unsigned int m_score = 0;

			// Is set to 1 if the current level should go up
			// -1 if it should go down
			// Or 0 if it should stay the same
			int m_changeLevel = 0;

			// Set to true if the game should save
			bool m_save = false;


			// Whether the player is alive or not
			bool m_playerDead = false;
			bool getPlayerDead() { return m_playerDead; }


		public:

			//======================================================================================================================================================================================================
			// Constructor, and
			// Destructor
			//======================================================================================================================================================================================================
			
			GameLogic() { }
			~GameLogic();


			//======================================================================================================================================================================================================
			// Initialization
			//======================================================================================================================================================================================================

			// Intialize the states logic
			void init( float shotTimer );

			// Intialize the keyboard
			void initKeyboard( std::string up_key, std::string down_key, std::string right_key, std::string left_key );

			// Initialize the mouse
			void initMouse( float speed );

			// Set how fast the game-screen should move
			void setScrollingSpeeds( float defaultScrollingSpeed, float fastScrollingSpeed, float slowScrollingSpeed ) {
				this->m_defaultScrollingSpeed = defaultScrollingSpeed;
				this->m_fastScrollingSpeed = fastScrollingSpeed;
				this->m_slowScrollingSpeed = slowScrollingSpeed;
			}


			//======================================================================================================================================================================================================
			// Run
			//======================================================================================================================================================================================================

			// Call this to handle all logic from the main-game
			void run( EntityManager* entities, Camera* camera, UserInput* userInput, sf::Vector2f mousePos );

			// Returns true or false
			// Based on whether the current state is going to be reset or not
			bool getReset() { return this->m_reset; }

			// Check which scrolling speed should be applied
			// Default, Fast or Slow
			float checkScrollingSpeed( UserInput* userInput );

			//======================================================================================================================================================================================================
			// Enemy Stuff
			//======================================================================================================================================================================================================

			// Set the enemy's shot timer
			void addEnemyGroup( int shoots, float shotTimer );

			
			//======================================================================================================================================================================================================
			// Score
			//======================================================================================================================================================================================================
	
			// Set the score
			// Using a unsigned integer
			void setScore( unsigned int score ) { this->m_score = score; }

			// Set the score
			// Using a std::string
			void setScore( std::string score ) { this->m_score = (unsigned int) atoi( score.c_str() ); }

			// Return the score
			// As a unsigned int
			unsigned int getScore() { return m_score; }

			// Return the score
			// As a std::string
			std::string getScoreAsString() { return std::to_string( m_score ); }


			//======================================================================================================================================================================================================
			// Saving
			//======================================================================================================================================================================================================


			// Call when you want to save the game
			void save() { m_save = true; }

			// Returns true if the game should be saved
			// Or false if it should not be saved
			// Once this method is called, save is automatically set to false
			bool getSave();


			//======================================================================================================================================================================================================
			// Level and Checkpoint data
			//======================================================================================================================================================================================================

			// Call this method when changing the level
			void levelChanged() { checkpointData.m_checkpointSet = false; }// m_reset = true; }

			void setCheckpoint( sf::Vector2f checkpoint) { this->checkpointData.lastCheckpoint = checkpoint; checkpointData.m_checkpointSet = true; }

			// Return 0 if the level should stay the same
			// -1 If the level should go down 1
			// Or 1 if the level should go up 1
			int changeLevel();


			// Private Methods
		private:
			//======================================================================================================================================================================================================
			// Logic Stuff
			//======================================================================================================================================================================================================

			// Test whether the game should be reset or not
			void checkResetToCheckpoint( EntityManager* entities, Camera* camera );

			// Call when the player is hit
			// This method resets the player back to the previous checkpoint
			void resetToCheckpoint() { m_reset = true; }
			
			
			//======================================================================================================================================================================================================
			// Update Logic
			//======================================================================================================================================================================================================
			
			// Update enemy1's movement
			void update_enemy1( EntityManager* entities, Camera* camera );

			// Update enemy2's movement
			void update_enemy2( EntityManager* entities, Camera* camera );

			// Update enemy3's movement
			void update_enemy3( EntityManager* entities, Camera* camera );

			// Update enemy4's movement
			void update_enemy4( EntityManager* entities, Camera* camera );

			// Update enemy5's movement
			void update_enemy5( EntityManager* entities, Camera* camera );

			// Update enemy6's movement
			void update_enemy6( EntityManager* entities, Camera* camera );

			// Update all bullet movement
			void update_bullets( EntityManager* entities, Camera* camera );

			// Update the Foreground movement
			void update_foreground( EntityManager* entities, Camera* camera );



			//======================================================================================================================================================================================================
			// Collisions
			//======================================================================================================================================================================================================
		
			// Handle collisions between
			// The player and checkpoints
			void collision_checkpoint( EntityManager* entities );

			// Handles the collision code
			// Between the player and camera edge
			void collision_playerCameraEdge( EntityManager* entities, Camera* camera );

			// Handle collisions betweeen
			// The Player and Blocks
			void collision_playerBlock( EntityManager* entities );

			// Handle collisions betweeen
			// The Player and Enemies
			void collision_playerEnemy( EntityManager* entities );

			// Handle collisions between
			// Enemies and Other Bullets
			void collision_enemyBullet( EntityManager* entities );

			// Handle collisions between
			// The Player and Enemy Bullets
			void collision_playerBullet( EntityManager* entities );

			// Handle collisions between
			// Bullets and Blocks
			void collision_bulletBlock( EntityManager* entities );

			// Handle collisions between
			// Bullets and Breakable Blocks
			void collision_bulletBreakableBlock( EntityManager* entities );

			// Handle collisions between
			// The Player and Breakable Blocks
			void collision_playerBreakableBlock( EntityManager* entities );


			//======================================================================================================================================================================================================
			// Shooting
			//======================================================================================================================================================================================================

			// Handles the players shooting
			void shooting_player( EntityManager* entities, UserInput* userInput );

			// Handles enemy shooting
			void shooting_enemy( EntityManager* entities, Camera* camera );
};