#include "HighScoreState.h"

//===============================================================================================================================================================
// Loading
//===============================================================================================================================================================

// Init method
void HighScoreState::init() {
	// Assign the state
	currentState = "HighScoreState";

	// Create the window
	window.create( getWindow() );

	// Initialize all the game managers
	if ( initializeManagers() == false )
		ErrorHandler::exitFatalError( "Managers Failed To Initialize" );

	// Load a font
	if ( !font.loadFromFile( "resources//fonts//sansation.ttf" ) )
		return exit(1);

	// Delete the save data
	// Since the player has just finished the game
	IOManager::write_txt( "data//PlayState//init//savedata", "level", "NULL" );
	IOManager::write_txt( "data//PlayState//init//savedata", "player_position", "NULL" );
	IOManager::write_txt( "data//PlayState//init//savedata", "score", "NULL" );


	// Load the objects
	load_Title();
	load_Scores();
	load_UserScore();
}

// Loading methods
void HighScoreState::load_Title() {
	m_title.setFont( font );
	m_title.setString( "Scoreboard!" );
	m_title.setCharacterSize( 50 );
	m_title.setPosition( 350.0f, 50.0f );
	m_title.setColor( sf::Color::White );
	m_title.setStyle( sf::Text::Bold );


	IOManager::readArrayFile_txt( "data//HighScores//scores", "Score", m_everyone );

	std::string test = "";
	for ( unsigned int i=0; i<10; i++ ) {
		test += m_everyone.at(i) + '\n';
	}
	scores.setString( test );
}
void HighScoreState::load_Scores() {
	scores.setFont( font );
	scores.setCharacterSize( 30 );
	scores.setPosition( 400.0f, 250.0f );
	scores.setColor( sf::Color::White );
	scores.setStyle( sf::Text::Bold );


	IOManager::readArrayFile_txt( "data//HighScores//scores", "Score", m_everyone );

	sort();

	IOManager::delete_txt( "data//HighScores//scores" );
	for ( unsigned int i=0; i<10; i++ ) {
		IOManager::add_txt( "data//HighScores//scores", "Score", m_everyone.at(i) );
		std::cout << '\n' << "Adding: " << m_everyone.at(i);
	}

	std::string test = "";
	for ( unsigned int i=0; i<10; i++ ) {
		test += m_everyone.at(i) + '\n';
	}
	scores.setString( test );
}
void HighScoreState::load_UserScore() {
	m_userScore = atoi( IOManager::readFile_txt( "data//HighScores//playerScore", "player_score" ).c_str() );
	std::cout << '\n' << "Player Score: " << m_userScore;
	std::cout << '\n' << m_everyone.back();

	int s = m_everyone.back().find_first_of( ' ' );

	if ( m_userScore > atoi( m_everyone.back().substr( s, m_everyone.back().size() ).c_str() ) )
		m_getName = true;
	else
		m_getName = false;
}



//===============================================================================================================================================================
// Update Methods
//===============================================================================================================================================================

// Update method
void HighScoreState::update( UserInput* userInput ) {	
	if ( m_getName == true )
		updateGetName( userInput );

	if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Space) ) 
		switchState( "CreditsState" );
}

// Get the User to Input their name
void HighScoreState::updateGetName( UserInput* userInput ) {
	while ( m_getName == true ) {
		std::string s;
		sf::RenderWindow hwindow( sf::VideoMode( 500, 200 ), "Enter Your Name!" );

		while( hwindow.isOpen() ) {
			userInput->test();

			//Event processing.
			sf::Event event;
			sf::Text t;
			t.setFont( font );
			t.setCharacterSize( 30 );
			t.setColor( sf::Color::White );

			while ( hwindow.pollEvent(event) ) {
				if ( event.type == sf::Event::Closed )
					hwindow.close();
				if ( event.type == sf::Event::TextEntered ) {
					if ( event.text.unicode < 128 ) {
						s.push_back( (char)event.text.unicode );
						if ( s.back() == '\b' ) {
							s.pop_back();
							if ( s.size() > 0 )
								s.pop_back();
						}
					}
				}
			}

			
			if ( userInput->pressed_returnKey() == true ) {
				s.pop_back();
				m_everyone.at(9) = s + ' ' + std::to_string( m_userScore );
				m_getName = false;

				sort();


				std::string test = "";
				for ( unsigned int i=0; i<10; i++ )
					test += m_everyone.at(i) + '\n';
				scores.setString( test );


				IOManager::delete_txt( "data//HighScores//scores" );

				for ( unsigned int i=0; i<10; i++ )
					IOManager::add_txt( "data//HighScores//scores", "Score", m_everyone.at(i) );
			

				return;
			}

			t.setString( s );
			hwindow.clear();
			hwindow.draw( t );
			hwindow.display();

		}
	}
}

// Sort the scores by rating of highest to lowest
void HighScoreState::sort() {
	int score[10];


	for ( unsigned int i=0; i<10; i++ ) {
		std::string k = m_everyone.at(i);
		int f = k.find_first_of( ' ' );
		score[i] = atoi( k.substr( f, k.size() ).c_str() );
	}

	// Specific Bubblesort
	for (int i=1; i < 10; i++)
		for (int k=10-1; k>=i; k--) {
			// Exchange the elements if they're out of order
			if ( score[k-1] < score[k]) {	

				int j = score[k-1];
				score[k-1] = score[k];
				score[k] = j;

				std::string p = m_everyone.at(k-1);
				m_everyone.at(k-1) = m_everyone.at(k);
				m_everyone.at(k) = p;

			}
		}
}


//===============================================================================================================================================================
// Rendering
//===============================================================================================================================================================

// Render method
void HighScoreState::render() {
	window.draw( scores );
	window.draw( m_title );
}