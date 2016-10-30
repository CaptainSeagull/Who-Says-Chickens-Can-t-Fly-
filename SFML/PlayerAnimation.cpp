#include "PlayerAnimation.h"

//===================================================================================================================================
// Update
//===================================================================================================================================

// The main update method
void PlayerAnimation::update( DynamicEntity* player, UserInput* userInput ) {
	
	if ( player->getCurrentAnimation() == "Dead" )
		return;
	
	if ( userInput->arrowUp() == true )
		arrowUp( player, userInput );
	
	else if ( userInput->released_arrowUp() == true )
		player->setAnimation( "UpToNeutral" );


	else if ( userInput->arrowDown() == true )
		arrowDown( player, userInput );

	else if ( userInput->released_arrowDown() == true )
		player->setAnimation( "DownToNeutral" );


	else
		noKey( player, userInput );


	neutralOnAnimationEnd( "UpToNeutral", player, userInput );
	neutralOnAnimationEnd( "DownToNeutral", player, userInput );
}


//===================================================================================================================================
// Specific Methods
//===================================================================================================================================

// For when the up key is held
void PlayerAnimation::arrowUp( DynamicEntity* player, UserInput* userInput ) {
	if ( player->getCurrentAnimation() != "Up" ) {

			player->setAnimation( "NeutralToUp" );
				if ( player->hasAnimationEnded( "NeutralToUp" ) == true )
					player->setAnimation( "Up" );
		} else
			player->setAnimation( "Up" );
}
		
// For when the down key is held
void PlayerAnimation::arrowDown( DynamicEntity* player, UserInput* userInput ) {
	if ( player->getCurrentAnimation() != "Down" ) {

		player->setAnimation( "NeutralToDown" );
			if ( player->hasAnimationEnded( "NeutralToDown" ) == true )
				player->setAnimation( "Down" );
	} else
		player->setAnimation( "Down" );
}

// For when no key is pressed
void PlayerAnimation::noKey( DynamicEntity* player, UserInput* userInput ) {
	if ( player->getCurrentAnimation() == "UpToNeutral" )
		player->setAnimation( "UpToNeutral" );
	else if ( player->getCurrentAnimation() == "DownToNeutral" )
		player->setAnimation( "DownToNeutral" );
	else
		player->setAnimation( "Neutral" );
}

// Once the animation is done set the animation to neutral
void PlayerAnimation::neutralOnAnimationEnd( std::string animationName, DynamicEntity* player, UserInput* userInput ) {
	if ( player->getCurrentAnimation() == animationName )
		if ( player->hasAnimationEnded( animationName ) == true )
			player->setAnimation( "Neutral" );
}