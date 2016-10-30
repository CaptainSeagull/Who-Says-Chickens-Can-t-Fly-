#include "UserInput.h"

// Tests whether a key is currently pressed or not
void UserInput::test() {
	// Show that the window hasn't been pressed yet
	windowCross = false;

	// Set all the key-presses to false
	for (int i=0; i<NUMBER_OF_ARROW_KEYS; i++)
		pressed_arrowKeys[i] = false;
	for (int i=0; i<NUMBER_OF_LETTER_KEYS; i++)
		pressed_letter[i] = false;
	for (int i=0; i<NUMBER_OF_NUMBER_KEYS; i++)
		pressed_num[i] = false;
	for ( int i=0; i<NUMBER_OF_MOUSE_BUTTONS; i++ )
		pressed_mouseButtons[i] = false;
	for (int i=0; i<NUMBER_OF_CONTROL_KEYS; i++)
		pressed_controlKeys[i] = false;

	// Set all the key-released to false
	for (int i=0; i<NUMBER_OF_ARROW_KEYS; i++)
		released_arrowKeys[i] = false;
	for (int i=0; i<NUMBER_OF_LETTER_KEYS; i++)
		released_letter[i] = false;
	for (int i=0; i<NUMBER_OF_NUMBER_KEYS; i++)
		released_num[i] = false;
	for ( int i=0; i<NUMBER_OF_MOUSE_BUTTONS; i++ )
		released_mouseButtons[i] = false;
	for (int i=0; i<NUMBER_OF_CONTROL_KEYS; i++)
		released_controlKeys[i] = false;

	// Test whether keys are held
	test_letters();
	test_arrowKeys();
	test_numberKeys();
	test_mouseButtons();
	test_controlKeys();


	// Test whether keys are pressed or not
	testPressed_letters();
	testPressed_arrowKeys();
	testPressed_numberKeys();
	testPressed_mouseButtons();
	testPressed_controlKeys();

	
	// Test whether keys are just released or not
	testReleased_letters();
	testReleased_arrowKeys();
	testReleased_numberKeys();
	testReleased_mouseButtons();
	testReleased_controlKeys();
}


//=======================================================================================
// To test whether a key is pressed or not
//=======================================================================================

void UserInput::test_letters() {
	// A
	if ( sf::Keyboard::isKeyPressed(sf::Keyboard::A) )
		letter[0] = true;
	else
		letter[0] = false;

	// B
	if ( sf::Keyboard::isKeyPressed(sf::Keyboard::B) )
		letter[1] = true;
	else
		letter[1] = false;

	// C
	if ( sf::Keyboard::isKeyPressed(sf::Keyboard::C) )
		letter[2] = true;
	else
		letter[2] = false;

	// D
	if ( sf::Keyboard::isKeyPressed(sf::Keyboard::D) )
		letter[3] = true;
	else
		letter[3] = false;

	// E
	if ( sf::Keyboard::isKeyPressed(sf::Keyboard::E) )
		letter[4] = true;
	else
		letter[4] = false;

	// F
	if ( sf::Keyboard::isKeyPressed(sf::Keyboard::F) )
		letter[5] = true;
	else
		letter[5] = false;

	// G
	if ( sf::Keyboard::isKeyPressed(sf::Keyboard::G) )
		letter[6] = true;
	else
		letter[6] = false;

	// H
	if ( sf::Keyboard::isKeyPressed(sf::Keyboard::H) )
		letter[7] = true;
	else
		letter[7] = false;

	// I
	if ( sf::Keyboard::isKeyPressed(sf::Keyboard::I) )
		letter[8] = true;
	else
		letter[8] = false;

	// J
	if ( sf::Keyboard::isKeyPressed(sf::Keyboard::J) )
		letter[9] = true;
	else
		letter[9] = false;

	// K
	if ( sf::Keyboard::isKeyPressed(sf::Keyboard::K) )
		letter[10] = true;
	else
		letter[10] = false;

	// L
	if ( sf::Keyboard::isKeyPressed(sf::Keyboard::L) )
		letter[11] = true;
	else
		letter[11] = false;

	// M
	if ( sf::Keyboard::isKeyPressed(sf::Keyboard::M) )
		letter[12] = true;
	else
		letter[12] = false;

	// N
	if ( sf::Keyboard::isKeyPressed(sf::Keyboard::N) )
		letter[13] = true;
	else
		letter[13] = false;

	// O
	if ( sf::Keyboard::isKeyPressed(sf::Keyboard::O) )
		letter[14] = true;
	else
		letter[14] = false;

	// P
	if ( sf::Keyboard::isKeyPressed(sf::Keyboard::P) )
		letter[15] = true;
	else
		letter[15] = false;

	// Q
	if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Q) )
		letter[16] = true;
	else
		letter[16] = false;

	// R
	if ( sf::Keyboard::isKeyPressed(sf::Keyboard::R) )
		letter[17] = true;
	else
		letter[17] = false;

	// S
	if ( sf::Keyboard::isKeyPressed(sf::Keyboard::S) )
		letter[18] = true;
	else
		letter[18] = false;

	// T
	if ( sf::Keyboard::isKeyPressed(sf::Keyboard::T) )
		letter[19] = true;
	else
		letter[19] = false;

	// U
	if ( sf::Keyboard::isKeyPressed(sf::Keyboard::U) )
		letter[20] = true;
	else
		letter[20] = false;

	// V
	if ( sf::Keyboard::isKeyPressed(sf::Keyboard::V) )
		letter[21] = true;
	else
		letter[21] = false;

	// W
	if ( sf::Keyboard::isKeyPressed(sf::Keyboard::W) )
		letter[22] = true;
	else
		letter[22] = false;

	// X
	if ( sf::Keyboard::isKeyPressed(sf::Keyboard::X) )
		letter[23] = true;
	else
		letter[23] = false;

	// Y
	if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Y) )
		letter[24] = true;
	else
		letter[24] = false;

	// Z
	if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Z) )
		letter[25] = true;
	else
		letter[25] = false;
}

void UserInput::test_arrowKeys() {
	// Up
	if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Up) )
		arrowKeys[0] = true;
	else
		arrowKeys[0] = false;
	
	// Right
	if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Right) )
		arrowKeys[1] = true;
	else
		arrowKeys[1] = false;

	// Down
	if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Down) )
		arrowKeys[2] = true;
	else
		arrowKeys[2] = false;

	// Left
	if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Left) )
		arrowKeys[3] = true;
	else
		arrowKeys[3] = false;
}

void UserInput::test_numberKeys() {
	// Zero
	if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Num0) )
		num[0] = true;
	else
		num[0] = false;

	// One
	if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Num1) )
		num[1] = true;
	else
		num[1] = false;

	// Two
	if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Num2) )
		num[2] = true;
	else
		num[2] = false;

	// Three
	if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Num3) )
		num[3] = true;
	else
		num[3] = false;

	// Four
	if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Num4) )
		num[4] = true;
	else
		num[4] = false;

	// Five
	if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Num5) )
		num[5] = true;
	else
		num[5] = false;

	// Six
	if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Num6) )
		num[6] = true;
	else
		num[6] = false;

	// Seven
	if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Num7) )
		num[7] = true;
	else
		num[7] = false;

	// Eight
	if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Num8) )
		num[8] = true;
	else
		num[8] = false;

	// Nine
	if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Num9) )
		num[9] = true;
	else
		num[9] = false;
}

void UserInput::test_mouseButtons() {
	// Left Mouse Button
	if ( sf::Mouse::isButtonPressed(sf::Mouse::Left) )
		mouseButtons[0] = true;
	else
		mouseButtons[0] = false;

	// Right Mouse Button
	if ( sf::Mouse::isButtonPressed(sf::Mouse::Right) )
		mouseButtons[1] = true;
	else
		mouseButtons[1] = false;

	// Middle Mouse Button
	if ( sf::Mouse::isButtonPressed(sf::Mouse::Middle) )
		mouseButtons[2] = true;
	else
		mouseButtons[2] = false;
}

void UserInput::test_controlKeys() {
	// 1 Escape
	if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Escape ) )
		controlKeys[0] = true;
	else
		controlKeys[0] = false;

	// 2 Left Control
	if ( sf::Keyboard::isKeyPressed( sf::Keyboard::LControl ) )
		controlKeys[1] = true;
	else
		controlKeys[1] = false;

	// 3 Left Shift
	if ( sf::Keyboard::isKeyPressed( sf::Keyboard::LShift ) )
		controlKeys[2] = true;
	else
		controlKeys[2] = false;

	// 4 Left Alt
	if ( sf::Keyboard::isKeyPressed( sf::Keyboard::LAlt ) )
		controlKeys[3] = true;
	else
		controlKeys[3] = false;

	// 5 Left System
	if ( sf::Keyboard::isKeyPressed( sf::Keyboard::LSystem ) )
		controlKeys[4] = true;
	else
		controlKeys[4] = false;

	// 6 Right Control
	if ( sf::Keyboard::isKeyPressed( sf::Keyboard::RControl ) )
		controlKeys[5] = true;
	else
		controlKeys[5] = false;

	// 7 Right Shift
	if ( sf::Keyboard::isKeyPressed( sf::Keyboard::RShift ) )
		controlKeys[6] = true;
	else
		controlKeys[6] = false;

	// 8 Right Alt
	if ( sf::Keyboard::isKeyPressed( sf::Keyboard::RAlt ) )
		controlKeys[7] = true;
	else
		controlKeys[7] = false;

	// 9 Right System
	if ( sf::Keyboard::isKeyPressed( sf::Keyboard::RSystem ) )
		controlKeys[8] = true;
	else
		controlKeys[8] = false;

	// 10 Menu
	if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Menu ) )
		controlKeys[9] = true;
	else
		controlKeys[9] = false;

	// 11 Left Bracket
	if ( sf::Keyboard::isKeyPressed( sf::Keyboard::LBracket ) )
		controlKeys[10] = true;
	else
		controlKeys[10] = false;

	// 12 Right Bracket
	if ( sf::Keyboard::isKeyPressed( sf::Keyboard::RBracket ) )
		controlKeys[11] = true;
	else
		controlKeys[11] = false;

	// 13 Semi Colon
	if ( sf::Keyboard::isKeyPressed( sf::Keyboard::SemiColon ) )
		controlKeys[12] = true;
	else
		controlKeys[12] = false;

	// 14 Comma
	if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Comma ) )
		controlKeys[13] = true;
	else
		controlKeys[13] = false;

	// 15 Period
	if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Period ) )
		controlKeys[14] = true;
	else
		controlKeys[14] = false;

	// 16 Quote
	if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Quote ) )
		controlKeys[15] = true;
	else
		controlKeys[15] = false;

	// 17 Slash
	if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Slash ) )
		controlKeys[16] = true;
	else
		controlKeys[16] = false;

	// 18 Backslash
	if ( sf::Keyboard::isKeyPressed( sf::Keyboard::BackSlash ) )
		controlKeys[17] = true;
	else
		controlKeys[17] = false;

	// 19 Tilde
	if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Tilde ) )
		controlKeys[18] = true;
	else
		controlKeys[18] = false;

	// 20 Equal
	if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Equal ) )
		controlKeys[19] = true;
	else
		controlKeys[19] = false;

	// 21 Dash
	if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Dash ) )
		controlKeys[20] = true;
	else
		controlKeys[20] = false;

	// 22 Space
	if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Space ) )
		controlKeys[21] = true;
	else
		controlKeys[21] = false;

	// 23 Return
	if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Return ) )
		controlKeys[22] = true;
	else
		controlKeys[22] = false;

	// 24 Backspace
	if ( sf::Keyboard::isKeyPressed( sf::Keyboard::BackSpace ) )
		controlKeys[23] = true;
	else
		controlKeys[23] = false;

	// 25 Tab
	if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Tab ) )
		controlKeys[24] = true;
	else
		controlKeys[24] = false;

	// 26 Page Down
	if ( sf::Keyboard::isKeyPressed( sf::Keyboard::PageDown ) )
		controlKeys[25] = true;
	else
		controlKeys[25] = false;

	// 27 Page Up
	if ( sf::Keyboard::isKeyPressed( sf::Keyboard::PageUp ) )
		controlKeys[26] = true;
	else
		controlKeys[26] = false;

	// 28 End
	if ( sf::Keyboard::isKeyPressed( sf::Keyboard::End ) )
		controlKeys[27] = true;
	else
		controlKeys[27] = false;

	// 29 Home
	if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Home ) )
		controlKeys[28] = true;
	else
		controlKeys[28] = false;

	// 30 Insert
	if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Insert ) )
		controlKeys[29] = true;
	else
		controlKeys[29] = false;

	// 31 Delete
	if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Delete ) )
		controlKeys[30] = true;
	else
		controlKeys[30] = false;

	// 32 Add
	if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Add ) )
		controlKeys[31] = true;
	else
		controlKeys[31] = false;

	// 33 Substract
	if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Subtract ) )
		controlKeys[32] = true;
	else
		controlKeys[32] = false;

	// 34 Multiply
	if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Multiply ) )
		controlKeys[33] = true;
	else
		controlKeys[33] = false;

	// 35 Divide
	if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Divide ) )
		controlKeys[34] = true;
	else
		controlKeys[34] = false;

	// 36 F1
	if ( sf::Keyboard::isKeyPressed( sf::Keyboard::F1 ) )
		controlKeys[35] = true;
	else
		controlKeys[35] = false;

	// 37 F2
	if ( sf::Keyboard::isKeyPressed( sf::Keyboard::F2 ) )
		controlKeys[36] = true;
	else
		controlKeys[36] = false;

	// 38 F3
	if ( sf::Keyboard::isKeyPressed( sf::Keyboard::F3 ) )
		controlKeys[37] = true;
	else
		controlKeys[37] = false;

	// 39 F4
	if ( sf::Keyboard::isKeyPressed( sf::Keyboard::F4 ) )
		controlKeys[38] = true;
	else
		controlKeys[38] = false;

	// 40 F5
	if ( sf::Keyboard::isKeyPressed( sf::Keyboard::F5 ) )
		controlKeys[39] = true;
	else
		controlKeys[39] = false;

	// 41 F6
	if ( sf::Keyboard::isKeyPressed( sf::Keyboard::F6 ) )
		controlKeys[40] = true;
	else
		controlKeys[40] = false;

	// 42 F7
	if ( sf::Keyboard::isKeyPressed( sf::Keyboard::F7 ) )
		controlKeys[41] = true;
	else
		controlKeys[41] = false;

	// 43 F8
	if ( sf::Keyboard::isKeyPressed( sf::Keyboard::F8 ) )
		controlKeys[42] = true;
	else
		controlKeys[42] = false;

	// 44 F9
	if ( sf::Keyboard::isKeyPressed( sf::Keyboard::F9 ) )
		controlKeys[43] = true;
	else
		controlKeys[43] = false;

	// 45 F10
	if ( sf::Keyboard::isKeyPressed( sf::Keyboard::F10 ) )
		controlKeys[44] = true;
	else
		controlKeys[44] = false;

	// 46 F11
	if ( sf::Keyboard::isKeyPressed( sf::Keyboard::F11 ) )
		controlKeys[45] = true;
	else
		controlKeys[45] = false;

	// 47 F12
	if ( sf::Keyboard::isKeyPressed( sf::Keyboard::F12 ) )
		controlKeys[46] = true;
	else
		controlKeys[46] = false;

	// 48 F13
	if ( sf::Keyboard::isKeyPressed( sf::Keyboard::F13 ) )
		controlKeys[47] = true;
	else
		controlKeys[47] = false;

	// 49
	if ( sf::Keyboard::isKeyPressed( sf::Keyboard::F14 ) )
		controlKeys[48] = true;
	else
		controlKeys[48] = false;

	// 50
	if ( sf::Keyboard::isKeyPressed( sf::Keyboard::F15 ) )
		controlKeys[49] = true;
	else
		controlKeys[49] = false;

	// 51 Control
	if ( ( sf::Keyboard::isKeyPressed( sf::Keyboard::RControl ) ) || ( sf::Keyboard::isKeyPressed( sf::Keyboard::LControl ) ) )
		controlKeys[50] = true;
	else
		controlKeys[50] = false;

	// 52 Shift
	if ( ( sf::Keyboard::isKeyPressed( sf::Keyboard::RShift ) ) || ( sf::Keyboard::isKeyPressed( sf::Keyboard::LShift ) ) )
		controlKeys[51] = true;
	else
		controlKeys[51] = false;

	// 53 Alt
	if ( ( sf::Keyboard::isKeyPressed( sf::Keyboard::RAlt ) ) || ( sf::Keyboard::isKeyPressed( sf::Keyboard::LAlt ) ) )
		controlKeys[52] = true;
	else
		controlKeys[52] = false;

	// 54
	if ( ( sf::Keyboard::isKeyPressed( sf::Keyboard::RSystem ) ) || ( sf::Keyboard::isKeyPressed( sf::Keyboard::LSystem ) ) )
		controlKeys[53] = true;
	else
		controlKeys[53] = false;
}


//====================================================================================================================================
// Used to test when a key is just pressed
//====================================================================================================================================


void UserInput::testPressed_letters() {
	static bool previous_letter[ NUMBER_OF_LETTER_KEYS ];
	
	// A
	if ( sf::Keyboard::isKeyPressed(sf::Keyboard::A) ) {
		if ( previous_letter[0] == false )
			pressed_letter[0] = true;
		previous_letter[0] = true;
	} else {
		pressed_letter[0] = false;
		previous_letter[0] = false;
	}

	// B
	if ( sf::Keyboard::isKeyPressed(sf::Keyboard::B) ) {
		if ( previous_letter[1] == false )
			pressed_letter[1] = true;
		previous_letter[1] = true;
	} else {
		pressed_letter[1] = false;
		previous_letter[1] = false;
	}

	// C
	if ( sf::Keyboard::isKeyPressed(sf::Keyboard::C) ) {
		if ( previous_letter[2] == false )
			pressed_letter[2] = true;
		previous_letter[2] = true;
	} else {
		pressed_letter[2] = false;
		previous_letter[2] = false;
	}

	// D
	if ( sf::Keyboard::isKeyPressed(sf::Keyboard::D) ) {
		if ( previous_letter[3] == false )
			pressed_letter[3] = true;
		previous_letter[3] = true;
	} else {
		pressed_letter[3] = false;
		previous_letter[3] = false;
	}

	// E
	if ( sf::Keyboard::isKeyPressed(sf::Keyboard::E) ) {
		if ( previous_letter[4] == false )
			pressed_letter[4] = true;
		previous_letter[4] = true;
	} else {
		letter[4] = false;
		previous_letter[4] = false;
	}

	// F
	if ( sf::Keyboard::isKeyPressed(sf::Keyboard::F) ) {
		if ( previous_letter[5] == false )
			pressed_letter[5] = true;
		previous_letter[5] = true;
	} else {
		pressed_letter[5] = false;
		previous_letter[5] = false;
	}

	// G
	if ( sf::Keyboard::isKeyPressed(sf::Keyboard::G) ) {
		if ( previous_letter[6] == false )
			pressed_letter[6] = true;
		previous_letter[6] = true;
	} else {
		pressed_letter[6] = false;
		previous_letter[6] = false;
	}

	// H
	if ( sf::Keyboard::isKeyPressed(sf::Keyboard::H) ) {
		if ( previous_letter[7] == false )
			pressed_letter[7] = true;
		previous_letter[7] = true;
	} else {
		pressed_letter[7] = false;
		previous_letter[7] = false;
	}

	// I
	if ( sf::Keyboard::isKeyPressed(sf::Keyboard::I) ) {
		if ( previous_letter[8] == false )
			pressed_letter[8] = true;
		previous_letter[8] = true;
	} else {
		pressed_letter[8] = false;
		previous_letter[8] = false;
	}

	// J
	if ( sf::Keyboard::isKeyPressed(sf::Keyboard::J) ) {
		if ( previous_letter[9] == false )
			pressed_letter[9] = true;
		previous_letter[9] = true;
	} else {
		pressed_letter[9] = false;
		previous_letter[9] = false;
	}

	// K
	if ( sf::Keyboard::isKeyPressed(sf::Keyboard::K) ) {
		if ( previous_letter[10] == false )
			pressed_letter[10] = true;
		previous_letter[10] = true;
	} else {
		pressed_letter[10] = false;
		previous_letter[10] = false;
	}

	// L
	if ( sf::Keyboard::isKeyPressed(sf::Keyboard::L) ) {
		if ( previous_letter[11] == false )
			pressed_letter[11] = true;
		previous_letter[11] = true;
	} else {
		pressed_letter[11] = false;
		previous_letter[11] = false;
	}

	// M
	if ( sf::Keyboard::isKeyPressed(sf::Keyboard::M) ) {
		if ( previous_letter[12] == false )
			pressed_letter[12] = true;
		previous_letter[12] = true;
	} else {
		pressed_letter[12] = false;
		previous_letter[12] = false;
	}

	// N
	if ( sf::Keyboard::isKeyPressed(sf::Keyboard::N) ) {
		if ( previous_letter[13] == false )
			pressed_letter[13] = true;
		previous_letter[13] = true;
	} else {
		letter[13] = false;
		previous_letter[13] = false;
	}

	// O
	if ( sf::Keyboard::isKeyPressed(sf::Keyboard::O) ) {
		if ( previous_letter[14] == false )
			pressed_letter[14] = true;
		previous_letter[14] = true;
	} else {
		letter[14] = false;
		previous_letter[14] = false;
	}

	// P
	if ( sf::Keyboard::isKeyPressed(sf::Keyboard::P) ) {
		if ( previous_letter[15] == false )
			pressed_letter[15] = true;
		previous_letter[15] = true;
	} else {
		letter[15] = false;
		previous_letter[15] = false;
	}

	// Q
	if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Q) ) {
		if ( previous_letter[16] == false )
			pressed_letter[16] = true;
		previous_letter[16] = true;
	} else {
		letter[16] = false;
		previous_letter[16] = false;
	}

	// R
	if ( sf::Keyboard::isKeyPressed(sf::Keyboard::R) ) {
		if ( previous_letter[17] == false )
			pressed_letter[17] = true;
		previous_letter[17] = true;
	} else {
		letter[17] = false;
		previous_letter[17] = false;
	}

	// S
	if ( sf::Keyboard::isKeyPressed(sf::Keyboard::S) ) {
		if ( previous_letter[18] == false )
			pressed_letter[18] = true;
		previous_letter[18] = true;
	} else {
		letter[18] = false;
		previous_letter[18] = false;
	}

	// T
	if ( sf::Keyboard::isKeyPressed(sf::Keyboard::T) ) {
		if ( previous_letter[19] == false )
			pressed_letter[19] = true;
		previous_letter[19] = true;
	} else {
		letter[19] = false;
		previous_letter[19] = false;
	}

	// U
	if ( sf::Keyboard::isKeyPressed(sf::Keyboard::U) ) {
		if ( previous_letter[20] == false )
			pressed_letter[20] = true;
		previous_letter[20] = true;
	} else {
		letter[20] = false;
		previous_letter[20] = false;
	}

	// V
	if ( sf::Keyboard::isKeyPressed(sf::Keyboard::V) ) {
		if ( previous_letter[21] == false )
			pressed_letter[21] = true;
		previous_letter[21] = true;
	} else {
		letter[21] = false;
		previous_letter[21] = false;
	}

	// W
	if ( sf::Keyboard::isKeyPressed(sf::Keyboard::W) ) {
		if ( previous_letter[22] == false )
			pressed_letter[22] = true;
		previous_letter[22] = true;
	} else {
		letter[22] = false;
		previous_letter[22] = false;
	}

	// X
	if ( sf::Keyboard::isKeyPressed(sf::Keyboard::X) ) {
		if ( previous_letter[23] == false )
			pressed_letter[23] = true;
		previous_letter[23] = true;
	} else {
		letter[23] = false;
		previous_letter[23] = false;
	}

	// Y
	if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Y) ) {
		if ( previous_letter[24] == false )
			pressed_letter[24] = true;
		previous_letter[24] = true;
	} else {
		letter[24] = false;
		previous_letter[24] = false;
	}

	// Z
	if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Z) ) {
		if ( previous_letter[25] == false )
			pressed_letter[25] = true;
		previous_letter[25] = true;
	} else {
		letter[25] = false;
		previous_letter[25] = false;
	}
}

void UserInput::testPressed_arrowKeys() {
	static bool previous_arrowKey[ NUMBER_OF_ARROW_KEYS ];
	
	// Up
	if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Up) ) {
		if ( previous_arrowKey[0] == false )
			pressed_arrowKeys[0] = true;
		previous_arrowKey[0] = true;
	} else {
		pressed_arrowKeys[0] = false;
		previous_arrowKey[0] = false;
	}

	// Right
	if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Right) ) {
		if ( previous_arrowKey[1] == false )
			pressed_arrowKeys[1] = true;
		previous_arrowKey[1] = true;
	} else {
		pressed_arrowKeys[1] = false;
		previous_arrowKey[1] = false;
	}

	// Down
	if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Down) ) {
		if ( previous_arrowKey[2] == false )
			pressed_arrowKeys[2] = true;
		previous_arrowKey[2] = true;
	} else {
		pressed_arrowKeys[2] = false;
		previous_arrowKey[2] = false;
	}

	// Left
	if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Left) ) {
		if ( previous_arrowKey[3] == false )
			pressed_arrowKeys[3] = true;
		previous_arrowKey[3] = true;
	} else {
		pressed_arrowKeys[3] = false;
		previous_arrowKey[3] = false;
	}
}

void UserInput::testPressed_numberKeys() {
	static bool previous_num[ NUMBER_OF_NUMBER_KEYS ];
	
	// Zero
	if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Num0) ) {
		if ( previous_num[0] == false )
			pressed_num[0] = true;
		previous_num[0] = true;
	} else {
		pressed_num[0] = false;
		previous_num[0] = false;
	}

	// One
	if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Num1) ) {
		if ( previous_num[1] == false )
			pressed_num[1] = true;
		previous_num[1] = true;
	} else {
		pressed_num[1] = false;
		previous_num[1] = false;
	}

	// Two
	if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Num2) ) {
		if ( previous_num[2] == false )
			pressed_num[2] = true;
		previous_num[2] = true;
	} else {
		pressed_num[2] = false;
		previous_num[2] = false;
	}

	// Three
	if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Num3) ) {
		if ( previous_num[3] == false )
			pressed_num[3] = true;
		previous_num[3] = true;
	} else {
		pressed_num[3] = false;
		previous_num[3] = false;
	}

	// Four
	if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Num4) ) {
		if ( previous_num[4] == false )
			pressed_num[4] = true;
		previous_num[4] = true;
	} else {
		pressed_num[4] = false;
		previous_num[4] = false;
	}

	// Five
	if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Num5) ) {
		if ( previous_num[5] == false )
			pressed_num[5] = true;
		previous_num[5] = true;
	} else {
		pressed_num[5] = false;
		previous_num[5] = false;
	}

	// Six
	if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Num6) ) {
		if ( previous_num[6] == false )
			pressed_num[6] = true;
		previous_num[6] = true;
	} else {
		pressed_num[6] = false;
		previous_num[6] = false;
	}

	// Seven
	if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Num7) ) {
		if ( previous_num[7] == false )
			pressed_num[7] = true;
		previous_num[7] = true;
	} else {
		pressed_num[7] = false;
		previous_num[7] = false;
	}

	// Eight
	if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Num8) ) {
		if ( previous_num[8] == false )
			pressed_num[8] = true;
		previous_num[8] = true;
	} else {
		pressed_num[8] = false;
		previous_num[8] = false;
	}

	// Nine
	if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Num9) ) {
		if ( previous_num[9] == false )
			pressed_num[9] = true;
		previous_num[9] = true;
	} else {
		pressed_num[9] = false;
		previous_num[9] = false;
	}
}

void UserInput::testPressed_mouseButtons() {
	static bool previous_mouseButtons[ NUMBER_OF_MOUSE_BUTTONS ];

	// Left
	if ( sf::Mouse::isButtonPressed(sf::Mouse::Left) ) {
		if ( previous_mouseButtons[0] == false )
			pressed_mouseButtons[0] = true;
		previous_mouseButtons[0] = true;
	} else {
		pressed_mouseButtons[0] = false;
		previous_mouseButtons[0] = false;
	}
	// Right
	if ( sf::Mouse::isButtonPressed(sf::Mouse::Right) ) {
		if ( previous_mouseButtons[1] == false )
			pressed_mouseButtons[1] = true;
		previous_mouseButtons[1] = true;
	} else {
		pressed_mouseButtons[1] = false;
		previous_mouseButtons[1] = false;
	}

	// Up
	if ( sf::Mouse::isButtonPressed(sf::Mouse::Middle) ) {
		if ( previous_mouseButtons[2] == false )
			pressed_mouseButtons[2] = true;
		previous_mouseButtons[2] = true;
	} else {
		pressed_mouseButtons[2] = false;
		previous_mouseButtons[2] = false;
	}
	
}

void UserInput::testPressed_controlKeys() {
	static bool previous_controlKey[ NUMBER_OF_CONTROL_KEYS ];

	// 0 Escape
	if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) ) {
		if ( previous_controlKey[0] == false )
			pressed_controlKeys[0] = true;
		previous_controlKey[0] = true;
	} else {
		pressed_controlKeys[0] = false;
		previous_controlKey[0] = false;
	}

	// 1 Left Control
	if ( sf::Keyboard::isKeyPressed(sf::Keyboard::LControl) ) {
		if ( previous_controlKey[1] == false )
			pressed_controlKeys[1] = true;
		previous_controlKey[1] = true;
	} else {
		pressed_controlKeys[1] = false;
		previous_controlKey[1] = false;
	}

	// 2 Left Shift
	if ( sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) ) {
		if ( previous_controlKey[2] == false )
			pressed_controlKeys[2] = true;
		previous_controlKey[2] = true;
	} else {
		pressed_controlKeys[2] = false;
		previous_controlKey[2] = false;
	}

	// 3 Left Alt
	if ( sf::Keyboard::isKeyPressed(sf::Keyboard::LAlt) ) {
		if ( previous_controlKey[3] == false )
			pressed_controlKeys[3] = true;
		previous_controlKey[3] = true;
	} else {
		pressed_controlKeys[3] = false;
		previous_controlKey[3] = false;
	}

	// 4 Left System
	if ( sf::Keyboard::isKeyPressed(sf::Keyboard::LSystem) ) {
		if ( previous_controlKey[4] == false )
			pressed_controlKeys[4] = true;
		previous_controlKey[4] = true;
	} else {
		pressed_controlKeys[4] = false;
		previous_controlKey[4] = false;
	}

	// 5 Right Control
	if ( sf::Keyboard::isKeyPressed(sf::Keyboard::RControl) ) {
		if ( previous_controlKey[5] == false )
			pressed_controlKeys[5] = true;
		previous_controlKey[5] = true;
	} else {
		pressed_controlKeys[5] = false;
		previous_controlKey[5] = false;
	}

	// 6 Right Shift
	if ( sf::Keyboard::isKeyPressed(sf::Keyboard::RShift) ) {
		if ( previous_controlKey[6] == false )
			pressed_controlKeys[6] = true;
		previous_controlKey[6] = true;
	} else {
		pressed_controlKeys[6] = false;
		previous_controlKey[6] = false;
	}

	// 7 Right Alt
	if ( sf::Keyboard::isKeyPressed(sf::Keyboard::RAlt) ) {
		if ( previous_controlKey[7] == false )
			pressed_controlKeys[7] = true;
		previous_controlKey[7] = true;
	} else {
		pressed_controlKeys[7] = false;
		previous_controlKey[7] = false;
	}

	// 8 Right System
	if ( sf::Keyboard::isKeyPressed(sf::Keyboard::RSystem) ) {
		if ( previous_controlKey[8] == false )
			pressed_controlKeys[8] = true;
		previous_controlKey[8] = true;
	} else {
		pressed_controlKeys[8] = false;
		previous_controlKey[8] = false;
	}

	// 9 Menu
	if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Menu) ) {
		if ( previous_controlKey[9] == false )
			pressed_controlKeys[9] = true;
		previous_controlKey[9] = true;
	} else {
		pressed_controlKeys[9] = false;
		previous_controlKey[9] = false;
	}

	// 10 Left Bracket
	if ( sf::Keyboard::isKeyPressed(sf::Keyboard::LBracket) ) {
		if ( previous_controlKey[10] == false )
			pressed_controlKeys[10] = true;
		previous_controlKey[10] = true;
	} else {
		pressed_controlKeys[10] = false;
		previous_controlKey[10] = false;
	}

	// 11 Right Bracket
	if ( sf::Keyboard::isKeyPressed(sf::Keyboard::RBracket) ) {
		if ( previous_controlKey[11] == false )
			pressed_controlKeys[11] = true;
		previous_controlKey[11] = true;
	} else {
		pressed_controlKeys[11] = false;
		previous_controlKey[11] = false;
	}

	// 12 Semi Colon
	if ( sf::Keyboard::isKeyPressed(sf::Keyboard::SemiColon) ) {
		if ( previous_controlKey[12] == false )
			pressed_controlKeys[12] = true;
		previous_controlKey[12] = true;
	} else {
		pressed_controlKeys[12] = false;
		previous_controlKey[12] = false;
	}

	// 13 Comma
	if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Comma) ) {
		if ( previous_controlKey[13] == false )
			pressed_controlKeys[13] = true;
		previous_controlKey[13] = true;
	} else {
		pressed_controlKeys[13] = false;
		previous_controlKey[13] = false;
	}

	// 14 Period
	if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Period) ) {
		if ( previous_controlKey[14] == false )
			pressed_controlKeys[14] = true;
		previous_controlKey[14] = true;
	} else {
		pressed_controlKeys[14] = false;
		previous_controlKey[14] = false;
	}

	// 15 Quote
	if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Quote) ) {
		if ( previous_controlKey[15] == false )
			pressed_controlKeys[15] = true;
		previous_controlKey[15] = true;
	} else {
		pressed_controlKeys[15] = false;
		previous_controlKey[15] = false;
	}

	// 16 Slash
	if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Slash) ) {
		if ( previous_controlKey[16] == false )
			pressed_controlKeys[16] = true;
		previous_controlKey[16] = true;
	} else {
		pressed_controlKeys[16] = false;
		previous_controlKey[16] = false;
	}

	// 17 Backslash
	if ( sf::Keyboard::isKeyPressed(sf::Keyboard::BackSlash) ) {
		if ( previous_controlKey[17] == false )
			pressed_controlKeys[17] = true;
		previous_controlKey[17] = true;
	} else {
		pressed_controlKeys[17] = false;
		previous_controlKey[17] = false;
	}

	// 18 Tilde
	if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Tilde) ) {
		if ( previous_controlKey[18] == false )
			pressed_controlKeys[18] = true;
		previous_controlKey[18] = true;
	} else {
		pressed_controlKeys[18] = false;
		previous_controlKey[18] = false;
	}

	// 19 Equals
	if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Equal) ) {
		if ( previous_controlKey[19] == false )
			pressed_controlKeys[19] = true;
		previous_controlKey[19] = true;
	} else {
		pressed_controlKeys[19] = false;
		previous_controlKey[19] = false;
	}

	// 20 Dash
	if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Dash) ) {
		if ( previous_controlKey[20] == false )
			pressed_controlKeys[20] = true;
		previous_controlKey[20] = true;
	} else {
		pressed_controlKeys[20] = false;
		previous_controlKey[20] = false;
	}

	// 21 Space
	if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Space) ) {
		if ( previous_controlKey[21] == false )
			pressed_controlKeys[21] = true;
		previous_controlKey[21] = true;
	} else {
		pressed_controlKeys[21] = false;
		previous_controlKey[21] = false;
	}

	// 22 Return
	if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Return) ) {
		if ( previous_controlKey[22] == false )
			pressed_controlKeys[22] = true;
		previous_controlKey[22] = true;
	} else {
		pressed_controlKeys[22] = false;
		previous_controlKey[22] = false;
	}

	// 23 Backspace
	if ( sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace) ) {
		if ( previous_controlKey[23] == false )
			pressed_controlKeys[23] = true;
		previous_controlKey[23] = true;
	} else {
		pressed_controlKeys[23] = false;
		previous_controlKey[23] = false;
	}

	// 24 Tab
	if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Tab) ) {
		if ( previous_controlKey[24] == false )
			pressed_controlKeys[24] = true;
		previous_controlKey[24] = true;
	} else {
		pressed_controlKeys[24] = false;
		previous_controlKey[24] = false;
	}

	// 25 Page Down
	if ( sf::Keyboard::isKeyPressed(sf::Keyboard::PageDown) ) {
		if ( previous_controlKey[25] == false )
			pressed_controlKeys[25] = true;
		previous_controlKey[25] = true;
	} else {
		pressed_controlKeys[25] = false;
		previous_controlKey[25] = false;
	}

	// 26 Page Up
	if ( sf::Keyboard::isKeyPressed(sf::Keyboard::PageUp) ) {
		if ( previous_controlKey[26] == false )
			pressed_controlKeys[26] = true;
		previous_controlKey[26] = true;
	} else {
		pressed_controlKeys[26] = false;
		previous_controlKey[26] = false;
	}

	// 27 End
	if ( sf::Keyboard::isKeyPressed(sf::Keyboard::End) ) {
		if ( previous_controlKey[27] == false )
			pressed_controlKeys[27] = true;
		previous_controlKey[27] = true;
	} else {
		pressed_controlKeys[27] = false;
		previous_controlKey[27] = false;
	}

	// 28 Home
	if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Home) ) {
		if ( previous_controlKey[28] == false )
			pressed_controlKeys[28] = true;
		previous_controlKey[28] = true;
	} else {
		pressed_controlKeys[28] = false;
		previous_controlKey[28] = false;
	}

	// 29 Insert
	if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Insert) ) {
		if ( previous_controlKey[29] == false )
			pressed_controlKeys[29] = true;
		previous_controlKey[29] = true;
	} else {
		pressed_controlKeys[29] = false;
		previous_controlKey[29] = false;
	}

	// 30 Delete
	if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Delete) ) {
		if ( previous_controlKey[30] == false )
			pressed_controlKeys[30] = true;
		previous_controlKey[30] = true;
	} else {
		pressed_controlKeys[30] = false;
		previous_controlKey[30] = false;
	}

	// 31 Add
	if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Add) ) {
		if ( previous_controlKey[31] == false )
			pressed_controlKeys[31] = true;
		previous_controlKey[31] = true;
	} else {
		pressed_controlKeys[31] = false;
		previous_controlKey[31] = false;
	}

	// 32 Subtract
	if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Subtract) ) {
		if ( previous_controlKey[32] == false )
			pressed_controlKeys[32] = true;
		previous_controlKey[32] = true;
	} else {
		pressed_controlKeys[32] = false;
		previous_controlKey[32] = false;
	}

	// 33 Multiply
	if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Multiply) ) {
		if ( previous_controlKey[33] == false )
			pressed_controlKeys[33] = true;
		previous_controlKey[33] = true;
	} else {
		pressed_controlKeys[33] = false;
		previous_controlKey[33] = false;
	}

	// 34 Divide
	if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Divide) ) {
		if ( previous_controlKey[34] == false )
			pressed_controlKeys[34] = true;
		previous_controlKey[34] = true;
	} else {
		pressed_controlKeys[34] = false;
		previous_controlKey[34] = false;
	}

	// 35 F1
	if ( sf::Keyboard::isKeyPressed(sf::Keyboard::F1) ) {
		if ( previous_controlKey[35] == false )
			pressed_controlKeys[35] = true;
		previous_controlKey[35] = true;
	} else {
		pressed_controlKeys[35] = false;
		previous_controlKey[35] = false;
	}

	// 36 F2
	if ( sf::Keyboard::isKeyPressed(sf::Keyboard::F2) ) {
		if ( previous_controlKey[36] == false )
			pressed_controlKeys[36] = true;
		previous_controlKey[36] = true;
	} else {
		pressed_controlKeys[36] = false;
		previous_controlKey[36] = false;
	}

	// 37 F3
	if ( sf::Keyboard::isKeyPressed(sf::Keyboard::F3) ) {
		if ( previous_controlKey[37] == false )
			pressed_controlKeys[37] = true;
		previous_controlKey[37] = true;
	} else {
		pressed_controlKeys[37] = false;
		previous_controlKey[37] = false;
	}

	// 38 F4
	if ( sf::Keyboard::isKeyPressed(sf::Keyboard::F4) ) {
		if ( previous_controlKey[38] == false )
			pressed_controlKeys[38] = true;
		previous_controlKey[38] = true;
	} else {
		pressed_controlKeys[38] = false;
		previous_controlKey[38] = false;
	}

	// 39 F5
	if ( sf::Keyboard::isKeyPressed(sf::Keyboard::F5) ) {
		if ( previous_controlKey[39] == false )
			pressed_controlKeys[39] = true;
		previous_controlKey[39] = true;
	} else {
		pressed_controlKeys[39] = false;
		previous_controlKey[39] = false;
	}

	// 40 F6
	if ( sf::Keyboard::isKeyPressed(sf::Keyboard::F6) ) {
		if ( previous_controlKey[40] == false )
			pressed_controlKeys[40] = true;
		previous_controlKey[40] = true;
	} else {
		pressed_controlKeys[40] = false;
		previous_controlKey[40] = false;
	}

	// 41 F7
	if ( sf::Keyboard::isKeyPressed(sf::Keyboard::F7) ) {
		if ( previous_controlKey[41] == false )
			pressed_controlKeys[41] = true;
		previous_controlKey[41] = true;
	} else {
		pressed_controlKeys[41] = false;
		previous_controlKey[41] = false;
	}

	// 42 F8
	if ( sf::Keyboard::isKeyPressed(sf::Keyboard::F8) ) {
		if ( previous_controlKey[42] == false )
			pressed_controlKeys[42] = true;
		previous_controlKey[42] = true;
	} else {
		pressed_controlKeys[42] = false;
		previous_controlKey[42] = false;
	}

	// 43 F9
	if ( sf::Keyboard::isKeyPressed(sf::Keyboard::F9) ) {
		if ( previous_controlKey[43] == false )
			pressed_controlKeys[43] = true;
		previous_controlKey[43] = true;
	} else {
		pressed_controlKeys[43] = false;
		previous_controlKey[43] = false;
	}

	// 44 F10
	if ( sf::Keyboard::isKeyPressed(sf::Keyboard::F10) ) {
		if ( previous_controlKey[44] == false )
			pressed_controlKeys[44] = true;
		previous_controlKey[44] = true;
	} else {
		pressed_controlKeys[44] = false;
		previous_controlKey[44] = false;
	}

	// 45 F11
	if ( sf::Keyboard::isKeyPressed(sf::Keyboard::F11) ) {
		if ( previous_controlKey[45] == false )
			pressed_controlKeys[45] = true;
		previous_controlKey[45] = true;
	} else {
		pressed_controlKeys[45] = false;
		previous_controlKey[45] = false;
	}

	// 46 F12
	if ( sf::Keyboard::isKeyPressed(sf::Keyboard::F12) ) {
		if ( previous_controlKey[46] == false )
			pressed_controlKeys[46] = true;
		previous_controlKey[46] = true;
	} else {
		pressed_controlKeys[46] = false;
		previous_controlKey[46] = false;
	}

	// 47 F13
	if ( sf::Keyboard::isKeyPressed(sf::Keyboard::F13) ) {
		if ( previous_controlKey[47] == false )
			pressed_controlKeys[47] = true;
		previous_controlKey[47] = true;
	} else {
		pressed_controlKeys[47] = false;
		previous_controlKey[47] = false;
	}

	// 48 F14
	if ( sf::Keyboard::isKeyPressed(sf::Keyboard::F14) ) {
		if ( previous_controlKey[48] == false )
			pressed_controlKeys[48] = true;
		previous_controlKey[48] = true;
	} else {
		pressed_controlKeys[48] = false;
		previous_controlKey[48] = false;
	}

	// 49 F15
	if ( sf::Keyboard::isKeyPressed(sf::Keyboard::F15) ) {
		if ( previous_controlKey[49] == false )
			pressed_controlKeys[49] = true;
		previous_controlKey[49] = true;
	} else {
		pressed_controlKeys[49] = false;
		previous_controlKey[49] = false;
	}

	// Right and Left Control keys
	if ( ( pressed_leftControl() == true ) || ( pressed_rightControl() == true ) )
		pressed_controlKeys[50] = true;
	else
		pressed_controlKeys[50] = false;

	// Right and Left Shift Keys
	if ( ( pressed_leftShift() == true ) || ( pressed_rightShift() == true ) )
		pressed_controlKeys[51] = true;
	else
		pressed_controlKeys[51] = false;

	// Left and Right Alt Keys
	if ( ( pressed_leftAlt() == true ) || ( pressed_rightAlt() == true ) )
		pressed_controlKeys[52] = true;
	else
		pressed_controlKeys[52] = false;

	// Left and Right System Keys
	if ( ( pressed_leftSystem() == true ) || ( pressed_rightSystem() == true ) )
		pressed_controlKeys[53] = true;
	else
		pressed_controlKeys[53] = false;
}



//====================================================================================================================================
// Used to test when a key is just pressed
//====================================================================================================================================


void UserInput::testReleased_letters() {
	static bool previous_letter[ NUMBER_OF_LETTER_KEYS ];
	
	// A
	if ( sf::Keyboard::isKeyPressed(sf::Keyboard::A) )
		previous_letter[0] = true;
	else {
		if ( previous_letter[0] == true )
			released_letter[0] = true;
		previous_letter[0] = false;
	}
	
	// B
	if ( sf::Keyboard::isKeyPressed(sf::Keyboard::B) )
		previous_letter[1] = true;
	else {
		if ( previous_letter[1] == true )
			released_letter[1] = true;
		previous_letter[1] = false;
	}

	// C
	if ( sf::Keyboard::isKeyPressed(sf::Keyboard::C) )
		previous_letter[2] = true;
	else {
		if ( previous_letter[2] == true )
			released_letter[2] = true;
		previous_letter[2] = false;
	}

	// D
	if ( sf::Keyboard::isKeyPressed(sf::Keyboard::D) )
		previous_letter[3] = true;
	else {
		if ( previous_letter[3] == true )
			released_letter[3] = true;
		previous_letter[3] = false;
	}

	// E
	if ( sf::Keyboard::isKeyPressed(sf::Keyboard::E) )
		previous_letter[4] = true;
	else {
		if ( previous_letter[4] == true )
			released_letter[4] = true;
		previous_letter[4] = false;
	}

	// F
	if ( sf::Keyboard::isKeyPressed(sf::Keyboard::F) )
		previous_letter[5] = true;
	else {
		if ( previous_letter[5] == true )
			released_letter[5] = true;
		previous_letter[5] = false;
	}

	// G
	if ( sf::Keyboard::isKeyPressed(sf::Keyboard::G) )
		previous_letter[6] = true;
	else {
		if ( previous_letter[6] == true )
			released_letter[6] = true;
		previous_letter[6] = false;
	}

	// H
	if ( sf::Keyboard::isKeyPressed(sf::Keyboard::H) )
		previous_letter[7] = true;
	else {
		if ( previous_letter[7] == true )
			released_letter[7] = true;
		previous_letter[7] = false;
	}

	// I
	if ( sf::Keyboard::isKeyPressed(sf::Keyboard::I) )
		previous_letter[8] = true;
	else {
		if ( previous_letter[8] == true )
			released_letter[8] = true;
		previous_letter[8] = false;
	}

	// J
	if ( sf::Keyboard::isKeyPressed(sf::Keyboard::J) )
		previous_letter[9] = true;
	else {
		if ( previous_letter[9] == true )
			released_letter[9] = true;
		previous_letter[9] = false;
	}

	// K
	if ( sf::Keyboard::isKeyPressed(sf::Keyboard::K) )
		previous_letter[10] = true;
	else {
		if ( previous_letter[10] == true )
			released_letter[10] = true;
		previous_letter[10] = false;
	}

	// L
	if ( sf::Keyboard::isKeyPressed(sf::Keyboard::L) )
		previous_letter[11] = true;
	else {
		if ( previous_letter[11] == true )
			released_letter[11] = true;
		previous_letter[11] = false;
	}

	// M
	if ( sf::Keyboard::isKeyPressed(sf::Keyboard::M) )
		previous_letter[12] = true;
	else {
		if ( previous_letter[12] == true )
			released_letter[12] = true;
		previous_letter[12] = false;
	}

	// N
	if ( sf::Keyboard::isKeyPressed(sf::Keyboard::N) )
		previous_letter[13] = true;
	else {
		if ( previous_letter[13] == true )
			released_letter[13] = true;
		previous_letter[13] = false;
	}

	// O
	if ( sf::Keyboard::isKeyPressed(sf::Keyboard::O) )
		previous_letter[14] = true;
	else {
		if ( previous_letter[14] == true )
			released_letter[14] = true;
		previous_letter[14] = false;
	}

	// P
	if ( sf::Keyboard::isKeyPressed(sf::Keyboard::P) )
		previous_letter[15] = true;
	else {
		if ( previous_letter[15] == true )
			released_letter[15] = true;
		previous_letter[15] = false;
	}

	// Q
	if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Q) )
		previous_letter[16] = true;
	else {
		if ( previous_letter[16] == true )
			released_letter[16] = true;
		previous_letter[16] = false;
	}

	// R
	if ( sf::Keyboard::isKeyPressed(sf::Keyboard::R) )
		previous_letter[17] = true;
	else {
		if ( previous_letter[17] == true )
			released_letter[17] = true;
		previous_letter[17] = false;
	}

	// S
	if ( sf::Keyboard::isKeyPressed(sf::Keyboard::S) )
		previous_letter[18] = true;
	else {
		if ( previous_letter[18] == true )
			released_letter[18] = true;
		previous_letter[18] = false;
	}

	// T
	if ( sf::Keyboard::isKeyPressed(sf::Keyboard::T) )
		previous_letter[19] = true;
	else {
		if ( previous_letter[19] == true )
			released_letter[19] = true;
		previous_letter[19] = false;
	}

	// U
	if ( sf::Keyboard::isKeyPressed(sf::Keyboard::U) )
		previous_letter[20] = true;
	else {
		if ( previous_letter[20] == true )
			released_letter[20] = true;
		previous_letter[20] = false;
	}

	// V
	if ( sf::Keyboard::isKeyPressed(sf::Keyboard::V) )
		previous_letter[21] = true;
	else {
		if ( previous_letter[21] == true )
			released_letter[21] = true;
		previous_letter[21] = false;
	}

	// W
	if ( sf::Keyboard::isKeyPressed(sf::Keyboard::W) )
		previous_letter[22] = true;
	else {
		if ( previous_letter[22] == true )
			released_letter[22] = true;
		previous_letter[22] = false;
	}

	// X
	if ( sf::Keyboard::isKeyPressed(sf::Keyboard::X) )
		previous_letter[23] = true;
	else {
		if ( previous_letter[23] == true )
			released_letter[23] = true;
		previous_letter[23] = false;
	}

	// Y
	if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Y) )
		previous_letter[24] = true;
	else {
		if ( previous_letter[24] == true )
			released_letter[24] = true;
		previous_letter[24] = false;
	}

	// Z
	if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Z) )
		previous_letter[25] = true;
	else {
		if ( previous_letter[25] == true )
			released_letter[25] = true;
		previous_letter[25] = false;
	}
}

void UserInput::testReleased_arrowKeys() {
	static bool previous_arrowKey[ NUMBER_OF_ARROW_KEYS ];
	
	// Up
	if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Up) )
		previous_arrowKey[0] = true;
	else {
		if ( previous_arrowKey[0] == true )
			released_arrowKeys[0] = true;
		previous_arrowKey[0] = false;
	}

	// Right
	if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Right) )
		previous_arrowKey[1] = true;
	else {
		if ( previous_arrowKey[1] == true )
			released_arrowKeys[1] = true;
		previous_arrowKey[1] = false;
	}

	// Down
	if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Down) )
		previous_arrowKey[2] = true;
	else {
		if ( previous_arrowKey[2] == true )
			released_arrowKeys[2] = true;
		previous_arrowKey[2] = false;
	}

	// Left
	if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Left) )
		previous_arrowKey[3] = true;
	else {
		if ( previous_arrowKey[3] == true )
			released_arrowKeys[3] = true;
		previous_arrowKey[3] = false;
	}
}

void UserInput::testReleased_numberKeys() {
	static bool previous_num[ NUMBER_OF_NUMBER_KEYS ];
	
	// Zero
	if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Num0) )
		previous_num[0] = true;
	else {
		if ( previous_num[0] == true )
			released_num[0] = true;
		previous_num[0] = false;
	}
}

void UserInput::testReleased_mouseButtons() {
	static bool previous_mouseButtons[ NUMBER_OF_MOUSE_BUTTONS ];

	// Left Mouse Button
	if ( sf::Mouse::isButtonPressed(sf::Mouse::Left) )
		previous_mouseButtons[0] = true;
	else {
		if ( previous_mouseButtons[0] == true )
			released_mouseButtons[0] = true;
		previous_mouseButtons[0] = false;
	}

	// Right Mouse Button
	if ( sf::Mouse::isButtonPressed(sf::Mouse::Right) )
		previous_mouseButtons[1] = true;
	else {
		if ( previous_mouseButtons[1] == true )
			released_mouseButtons[1] = true;
		previous_mouseButtons[1] = false;
	}

	// Middle Mouse Button
	if ( sf::Mouse::isButtonPressed(sf::Mouse::Middle) )
		previous_mouseButtons[2] = true;
	else {
		if ( previous_mouseButtons[2] == true )
			released_mouseButtons[2] = true;
		previous_mouseButtons[2] = false;
	}
}

void UserInput::testReleased_controlKeys() {
	static bool previous_controlKey[ NUMBER_OF_CONTROL_KEYS ];

	// 0 Escape
	if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) )
		previous_controlKey[0] = true;
	else {
		if ( previous_controlKey[0] == true )
			released_controlKeys[0] = true;
		previous_controlKey[0] = false;
	}

	// 0 Escape
	// 1 Left Control
	// 2 Left Shift
	// 3 Left Alt
	// 4 Left System
	// 5 Right Control
	// 6 Right Shift
	// 7 Right Alt
	// 8 Right System
	// 9 Menu
	// 10 Left Bracket
	// 11 Right Bracket
	// 12 Semi Colon
	// 13 Comma
	// 14 Period
	// 15 Quote
	// 16 Slash
	// 17 Backslash
	// 18 Tilde
	// 19 Equals
	// 20 Dash
	// 21 Space
	// 22 Return
	// 23 Backspace
	// 24 Tab
	// 25 Page Down
	// 26 Page Up
	// 27 End
	// 28 Home
	// 29 Insert
	// 30 Delete
	// 31 Add
	// 32 Subtract
	// 33 Multiply
	// 34 Divide
	// 35 F1
	// 36 F2
	// 37 F3
	// 38 F4
	// 39 F5
	// 40 F6
	// 41 F7
	// 42 F8
	// 43 F9
	// 44 F10
	// 45 F11
	// 46 F12
	// 47 F13
	// 48 F14
	// 49 F15
}

//====================================================================================================================================
// Test Keys based on std::strings
//====================================================================================================================================

bool UserInput::equalsIgnoreCase(const std::string& a, const std::string& b) {
	
	if ( a.size() != b.size() )
		return false;

	unsigned int sz = a.size();
	if  (b.size() != sz )
		return false;
	for ( unsigned int i = 0; i < sz; ++i )
		if ( tolower(a[i]) != tolower(b[i]) )
			return false;
	return true;
}

// Return whether a key is held
bool UserInput::keyboard( std::string key ) {

	// Arrow Keys
	if ( equalsIgnoreCase( key, "arrow_up" ) )
		return arrowKeys[0];
	if ( equalsIgnoreCase( key, "arrow_right") )
		return arrowKeys[1];
	if ( equalsIgnoreCase( key, "arrow_down" ) )
		return arrowKeys[2];
	if ( equalsIgnoreCase( key, "arrow_left" ) )
		return arrowKeys[3];

	// Number Keys
	if ( ( equalsIgnoreCase( key, "zero" ) ) || ( equalsIgnoreCase( key, "0" ) ) )
		return num[0];
	if ( ( equalsIgnoreCase( key, "one" ) ) || ( equalsIgnoreCase( key, "1" ) ) )
		return num[1];
	if ( ( equalsIgnoreCase( key, "two" ) ) || ( equalsIgnoreCase( key, "2" ) ) )
		return num[2];
	if ( ( equalsIgnoreCase( key, "three" ) ) || ( equalsIgnoreCase( key, "3" ) ) )
		return num[3];
	if ( ( equalsIgnoreCase( key, "four" ) ) || ( equalsIgnoreCase( key, "4" ) ) )
		return num[4];
	if ( ( equalsIgnoreCase( key, "five" ) ) || ( equalsIgnoreCase( key, "5" ) ) )
		return num[5];
	if ( ( equalsIgnoreCase( key, "six" ) ) || ( equalsIgnoreCase( key, "6" ) ) )
		return num[6];
	if ( ( equalsIgnoreCase( key, "seven" ) ) || ( equalsIgnoreCase( key, "7" ) ) )
		return num[7];
	if ( ( equalsIgnoreCase( key, "eight" ) ) || ( equalsIgnoreCase( key, "8" ) ) )
		return num[8];
	if ( ( equalsIgnoreCase( key, "nine" ) ) || ( equalsIgnoreCase( key, "9" ) ) )
		return num[9];

	// Letters
	if ( equalsIgnoreCase( key, "a" ) )
		return letter[0];
	if ( equalsIgnoreCase( key, "b" ) )
		return letter[1];
	if ( equalsIgnoreCase( key, "c" ) )
		return letter[2];
	if ( equalsIgnoreCase( key, "d" ) )
		return letter[3];
	if ( equalsIgnoreCase( key, "e" ) )
		return letter[4];
	if ( equalsIgnoreCase( key, "f" ) )
		return letter[5];
	if ( equalsIgnoreCase( key, "g" ) )
		return letter[6];
	if ( equalsIgnoreCase( key, "h" ) )
		return letter[7];
	if ( equalsIgnoreCase( key, "i" ) )
		return letter[8];
	if ( equalsIgnoreCase( key, "j" ) )
		return letter[9];
	if ( equalsIgnoreCase( key, "k" ) )
		return letter[10];
	if ( equalsIgnoreCase( key, "l" ) )
		return letter[11];
	if ( equalsIgnoreCase( key, "m" ) )
		return letter[12];
	if ( equalsIgnoreCase( key, "n" ) )
		return letter[13];
	if ( equalsIgnoreCase( key, "o" ) )
		return letter[14];
	if ( equalsIgnoreCase( key, "p" ) )
		return letter[15];
	if ( equalsIgnoreCase( key, "q" ) )
		return letter[16];
	if ( equalsIgnoreCase( key, "r" ) )
		return letter[17];
	if ( equalsIgnoreCase( key, "s" ) )
		return letter[18];
	if ( equalsIgnoreCase( key, "t" ) )
		return letter[19];
	if ( equalsIgnoreCase( key, "u" ) )
		return letter[20];
	if ( equalsIgnoreCase( key, "v" ) )
		return letter[21];
	if ( equalsIgnoreCase( key, "w" ) )
		return letter[22];
	if ( equalsIgnoreCase( key, "x" ) )
		return letter[23];
	if ( equalsIgnoreCase( key, "y" ) )
		return letter[24];
	if ( equalsIgnoreCase( key, "z" ) )
		return letter[25];

	// Control Keys
	if ( ( equalsIgnoreCase( key, "escape" ) ) || ( equalsIgnoreCase( key, "esc" ) ) )
		return controlKeys[0];
	if ( ( equalsIgnoreCase( key, "left_control" ) ) || ( equalsIgnoreCase( key, "left_ctrl" ) ) )
		return controlKeys[1];
	if ( equalsIgnoreCase( key, "left_shift" ) )
		return controlKeys[2];
	if ( equalsIgnoreCase( key, "left_alt" ) )
		return controlKeys[3];
	if ( equalsIgnoreCase( key, "left_system" ) )
		return controlKeys[4];
	if ( ( equalsIgnoreCase( key, "right_control" ) ) || ( equalsIgnoreCase( key, "right_ctrl" ) ) )
		return controlKeys[5];
	if ( equalsIgnoreCase( key, "right_shift" ) )
		return controlKeys[6];
	if ( equalsIgnoreCase( key, "right_alt" ) )
		return controlKeys[7];
	if ( equalsIgnoreCase( key, "right_system" ) )
		return controlKeys[8];
	if ( equalsIgnoreCase( key, "menu" ) )
		return controlKeys[9];

	if ( ( equalsIgnoreCase( key, "left_bracket" ) ) || ( equalsIgnoreCase( key, "{" ) ) )
		return controlKeys[10];
	if ( ( equalsIgnoreCase( key, "right_bracket" ) ) || ( equalsIgnoreCase( key, "}" ) ) )
		return controlKeys[11];
	if ( ( equalsIgnoreCase( key, "semi_colon" ) ) || ( equalsIgnoreCase( key, ";" ) ) )
		return controlKeys[12];
	if ( ( equalsIgnoreCase( key, "comma" ) ) || ( equalsIgnoreCase( key, "," ) ) )
		return controlKeys[13];
	if ( ( equalsIgnoreCase( key, "period" ) ) || ( equalsIgnoreCase( key, "." ) ) )
		return controlKeys[14];
	if ( ( equalsIgnoreCase( key, "quote" ) ) || ( equalsIgnoreCase( key, "'" ) ) )
		return controlKeys[15];
	if ( ( equalsIgnoreCase( key, "slash" ) ) || ( equalsIgnoreCase( key, "/" ) ) || ( equalsIgnoreCase( key, "divide" ) ) )
		return controlKeys[16];
	if ( equalsIgnoreCase( key, "backslash" ) )
		return controlKeys[17];
	if ( ( equalsIgnoreCase( key, "tilde" ) ) || ( equalsIgnoreCase( key, "~" ) ) )
		return controlKeys[18];
	if ( ( equalsIgnoreCase( key, "equal" ) ) || ( equalsIgnoreCase( key, "=" ) ) )
		return controlKeys[19];

	if ( equalsIgnoreCase( key, "dash" ) )
		return controlKeys[20];
	if ( equalsIgnoreCase( key, "space" ) )
		return controlKeys[21];
	if ( equalsIgnoreCase( key, "return" ) )
		return controlKeys[22];
	if ( equalsIgnoreCase( key, "backspace" ) )
		return controlKeys[23];
	if ( equalsIgnoreCase( key, "tab" ) )
		return controlKeys[24];
	if ( equalsIgnoreCase( key, "page_down" ) )
		return controlKeys[25];
	if ( equalsIgnoreCase( key, "page_up" ) )
		return controlKeys[26];
	if ( equalsIgnoreCase( key, "end" ) )
		return controlKeys[27];
	if ( equalsIgnoreCase( key, "home" ) )
		return controlKeys[28];
	if ( equalsIgnoreCase( key, "insert" ) )
		return controlKeys[29];
	if ( equalsIgnoreCase( key, "delete" ) )
		return controlKeys[30];

	if ( ( equalsIgnoreCase( key, "add" ) ) || ( equalsIgnoreCase( key, "+" ) ) )
		return controlKeys[31];
	if ( ( equalsIgnoreCase( key, "subtract" ) ) || ( equalsIgnoreCase( key, "-" ) ) )
		return controlKeys[32];
	if ( ( equalsIgnoreCase( key, "multiply" ) ) || ( equalsIgnoreCase( key, "*" ) ) || ( equalsIgnoreCase( key, "star" ) ) )
		return controlKeys[33];

	if ( equalsIgnoreCase( key, "f1" ) )
		return controlKeys[35];
	if ( equalsIgnoreCase( key, "f2" ) )
		return controlKeys[36];
	if ( equalsIgnoreCase( key, "f3" ) )
		return controlKeys[37];
	if ( equalsIgnoreCase( key, "f4" ) )
		return controlKeys[38];
	if ( equalsIgnoreCase( key, "f5" ) )
		return controlKeys[39];
	if ( equalsIgnoreCase( key, "f6" ) )
		return controlKeys[40];
	if ( equalsIgnoreCase( key, "f7" ) )
		return controlKeys[41];
	if ( equalsIgnoreCase( key, "f8" ) )
		return controlKeys[42];
	if ( equalsIgnoreCase( key, "f9" ) )
		return controlKeys[43];
	if ( equalsIgnoreCase( key, "f10" ) )
		return controlKeys[44];
	if ( equalsIgnoreCase( key, "f11" ) )
		return controlKeys[45];
	if ( equalsIgnoreCase( key, "f12" ) )
		return controlKeys[46];
	if ( equalsIgnoreCase( key, "f13" ) )
		return controlKeys[47];
	if ( equalsIgnoreCase( key, "f14" ) )
		return controlKeys[48];
	if ( equalsIgnoreCase( key, "f15" ) )
		return controlKeys[49];

	if ( ( equalsIgnoreCase( key, "control" ) ) || ( equalsIgnoreCase( key, "ctrl" ) ) )
		return controlKeys[50];
	if ( equalsIgnoreCase( key, "shift" ) )
		return controlKeys[51];
	if ( equalsIgnoreCase( key, "alt" ) )
		return controlKeys[52];
	if ( equalsIgnoreCase( key, "system" ) )
		return controlKeys[53];

	// Returns false if no key was detected
	std::cout << '\n' << "Key: " << key << " does not match any Key!";
	return false;
}

// Return whether a key was pressed
bool UserInput::keyboard_pressed( std::string key ) {

	// Arrow Keys
	if ( equalsIgnoreCase( key, "arrow_up" ) )
		return pressed_arrowKeys[0];
	if ( equalsIgnoreCase( key, "arrow_right") )
		return pressed_arrowKeys[1];
	if ( equalsIgnoreCase( key, "arrow_down" ) )
		return pressed_arrowKeys[2];
	if ( equalsIgnoreCase( key, "arrow_left" ) )
		return pressed_arrowKeys[3];

	// Number Keys
	if ( ( equalsIgnoreCase( key, "zero" ) ) || ( equalsIgnoreCase( key, "0" ) ) )
		return pressed_num[0];
	if ( ( equalsIgnoreCase( key, "one" ) ) || ( equalsIgnoreCase( key, "1" ) ) )
		return pressed_num[1];
	if ( ( equalsIgnoreCase( key, "two" ) ) || ( equalsIgnoreCase( key, "2" ) ) )
		return pressed_num[2];
	if ( ( equalsIgnoreCase( key, "three" ) ) || ( equalsIgnoreCase( key, "3" ) ) )
		return pressed_num[3];
	if ( ( equalsIgnoreCase( key, "four" ) ) || ( equalsIgnoreCase( key, "4" ) ) )
		return pressed_num[4];
	if ( ( equalsIgnoreCase( key, "five" ) ) || ( equalsIgnoreCase( key, "5" ) ) )
		return pressed_num[5];
	if ( ( equalsIgnoreCase( key, "six" ) ) || ( equalsIgnoreCase( key, "6" ) ) )
		return pressed_num[6];
	if ( ( equalsIgnoreCase( key, "seven" ) ) || ( equalsIgnoreCase( key, "7" ) ) )
		return pressed_num[7];
	if ( ( equalsIgnoreCase( key, "eight" ) ) || ( equalsIgnoreCase( key, "8" ) ) )
		return pressed_num[8];
	if ( ( equalsIgnoreCase( key, "nine" ) ) || ( equalsIgnoreCase( key, "9" ) ) )
		return pressed_num[9];

	// Letters
	if ( equalsIgnoreCase( key, "a" ) )
		return pressed_letter[0];
	if ( equalsIgnoreCase( key, "b" ) )
		return pressed_letter[1];
	if ( equalsIgnoreCase( key, "c" ) )
		return pressed_letter[2];
	if ( equalsIgnoreCase( key, "d" ) )
		return pressed_letter[3];
	if ( equalsIgnoreCase( key, "e" ) )
		return pressed_letter[4];
	if ( equalsIgnoreCase( key, "f" ) )
		return pressed_letter[5];
	if ( equalsIgnoreCase( key, "g" ) )
		return pressed_letter[6];
	if ( equalsIgnoreCase( key, "h" ) )
		return pressed_letter[7];
	if ( equalsIgnoreCase( key, "i" ) )
		return pressed_letter[8];
	if ( equalsIgnoreCase( key, "j" ) )
		return pressed_letter[9];
	if ( equalsIgnoreCase( key, "k" ) )
		return pressed_letter[10];
	if ( equalsIgnoreCase( key, "l" ) )
		return pressed_letter[11];
	if ( equalsIgnoreCase( key, "m" ) )
		return pressed_letter[12];
	if ( equalsIgnoreCase( key, "n" ) )
		return pressed_letter[13];
	if ( equalsIgnoreCase( key, "o" ) )
		return pressed_letter[14];
	if ( equalsIgnoreCase( key, "p" ) )
		return pressed_letter[15];
	if ( equalsIgnoreCase( key, "q" ) )
		return pressed_letter[16];
	if ( equalsIgnoreCase( key, "r" ) )
		return pressed_letter[17];
	if ( equalsIgnoreCase( key, "s" ) )
		return pressed_letter[18];
	if ( equalsIgnoreCase( key, "t" ) )
		return pressed_letter[19];
	if ( equalsIgnoreCase( key, "u" ) )
		return pressed_letter[20];
	if ( equalsIgnoreCase( key, "v" ) )
		return pressed_letter[21];
	if ( equalsIgnoreCase( key, "w" ) )
		return pressed_letter[22];
	if ( equalsIgnoreCase( key, "x" ) )
		return pressed_letter[23];
	if ( equalsIgnoreCase( key, "y" ) )
		return pressed_letter[24];
	if ( equalsIgnoreCase( key, "z" ) )
		return pressed_letter[25];

	// Control Keys
	if ( ( equalsIgnoreCase( key, "escape" ) ) || ( equalsIgnoreCase( key, "esc" ) ) )
		return pressed_controlKeys[0];
	if ( ( equalsIgnoreCase( key, "left_control" ) ) || ( equalsIgnoreCase( key, "left_ctrl" ) ) )
		return pressed_controlKeys[1];
	if ( equalsIgnoreCase( key, "left_shift" ) )
		return pressed_controlKeys[2];
	if ( equalsIgnoreCase( key, "left_alt" ) )
		return pressed_controlKeys[3];
	if ( equalsIgnoreCase( key, "left_system" ) )
		return pressed_controlKeys[4];
	if ( ( equalsIgnoreCase( key, "right_control" ) ) || ( equalsIgnoreCase( key, "right_ctrl" ) ) )
		return pressed_controlKeys[5];
	if ( equalsIgnoreCase( key, "right_shift" ) )
		return pressed_controlKeys[6];
	if ( equalsIgnoreCase( key, "right_alt" ) )
		return pressed_controlKeys[7];
	if ( equalsIgnoreCase( key, "right_system" ) )
		return pressed_controlKeys[8];
	if ( equalsIgnoreCase( key, "menu" ) )
		return pressed_controlKeys[9];

	if ( ( equalsIgnoreCase( key, "left_bracket" ) ) || ( equalsIgnoreCase( key, "{" ) ) )
		return pressed_controlKeys[10];
	if ( ( equalsIgnoreCase( key, "right_bracket" ) ) || ( equalsIgnoreCase( key, "}" ) ) )
		return pressed_controlKeys[11];
	if ( ( equalsIgnoreCase( key, "semi_colon" ) ) || ( equalsIgnoreCase( key, ";" ) ) )
		return pressed_controlKeys[12];
	if ( ( equalsIgnoreCase( key, "comma" ) ) || ( equalsIgnoreCase( key, "," ) ) )
		return pressed_controlKeys[13];
	if ( ( equalsIgnoreCase( key, "period" ) ) || ( equalsIgnoreCase( key, "." ) ) )
		return pressed_controlKeys[14];
	if ( ( equalsIgnoreCase( key, "quote" ) ) || ( equalsIgnoreCase( key, "'" ) ) )
		return pressed_controlKeys[15];
	if ( ( equalsIgnoreCase( key, "slash" ) ) || ( equalsIgnoreCase( key, "/" ) ) || ( equalsIgnoreCase( key, "divide" ) ) )
		return pressed_controlKeys[16];
	if ( equalsIgnoreCase( key, "backslash" ) )
		return pressed_controlKeys[17];
	if ( ( equalsIgnoreCase( key, "tilde" ) ) || ( equalsIgnoreCase( key, "~" ) ) )
		return pressed_controlKeys[18];
	if ( ( equalsIgnoreCase( key, "equal" ) ) || ( equalsIgnoreCase( key, "=" ) ) )
		return pressed_controlKeys[19];

	if ( equalsIgnoreCase( key, "dash" ) )
		return pressed_controlKeys[20];
	if ( equalsIgnoreCase( key, "space" ) )
		return pressed_controlKeys[21];
	if ( equalsIgnoreCase( key, "return" ) )
		return pressed_controlKeys[22];
	if ( equalsIgnoreCase( key, "backspace" ) )
		return pressed_controlKeys[23];
	if ( equalsIgnoreCase( key, "tab" ) )
		return pressed_controlKeys[24];
	if ( equalsIgnoreCase( key, "page_down" ) )
		return pressed_controlKeys[25];
	if ( equalsIgnoreCase( key, "page_up" ) )
		return pressed_controlKeys[26];
	if ( equalsIgnoreCase( key, "end" ) )
		return pressed_controlKeys[27];
	if ( equalsIgnoreCase( key, "home" ) )
		return pressed_controlKeys[28];
	if ( equalsIgnoreCase( key, "insert" ) )
		return pressed_controlKeys[29];
	if ( equalsIgnoreCase( key, "delete" ) )
		return pressed_controlKeys[30];

	if ( ( equalsIgnoreCase( key, "add" ) ) || ( equalsIgnoreCase( key, "+" ) ) )
		return pressed_controlKeys[31];
	if ( ( equalsIgnoreCase( key, "subtract" ) ) || ( equalsIgnoreCase( key, "-" ) ) )
		return pressed_controlKeys[32];
	if ( ( equalsIgnoreCase( key, "multiply" ) ) || ( equalsIgnoreCase( key, "*" ) ) || ( equalsIgnoreCase( key, "star" ) ) )
		return pressed_controlKeys[33];

	if ( equalsIgnoreCase( key, "f1" ) )
		return pressed_controlKeys[35];
	if ( equalsIgnoreCase( key, "f2" ) )
		return pressed_controlKeys[36];
	if ( equalsIgnoreCase( key, "f3" ) )
		return pressed_controlKeys[37];
	if ( equalsIgnoreCase( key, "f4" ) )
		return pressed_controlKeys[38];
	if ( equalsIgnoreCase( key, "f5" ) )
		return pressed_controlKeys[39];
	if ( equalsIgnoreCase( key, "f6" ) )
		return pressed_controlKeys[40];
	if ( equalsIgnoreCase( key, "f7" ) )
		return pressed_controlKeys[41];
	if ( equalsIgnoreCase( key, "f8" ) )
		return pressed_controlKeys[42];
	if ( equalsIgnoreCase( key, "f9" ) )
		return pressed_controlKeys[43];
	if ( equalsIgnoreCase( key, "f10" ) )
		return pressed_controlKeys[44];
	if ( equalsIgnoreCase( key, "f11" ) )
		return pressed_controlKeys[45];
	if ( equalsIgnoreCase( key, "f12" ) )
		return pressed_controlKeys[46];
	if ( equalsIgnoreCase( key, "f13" ) )
		return pressed_controlKeys[47];
	if ( equalsIgnoreCase( key, "f14" ) )
		return pressed_controlKeys[48];
	if ( equalsIgnoreCase( key, "f15" ) )
		return pressed_controlKeys[49];

	if ( ( equalsIgnoreCase( key, "control" ) ) || ( equalsIgnoreCase( key, "ctrl" ) ) )
		return pressed_controlKeys[50];
	if ( equalsIgnoreCase( key, "shift" ) )
		return pressed_controlKeys[51];
	if ( equalsIgnoreCase( key, "alt" ) )
		return pressed_controlKeys[52];
	if ( equalsIgnoreCase( key, "system" ) )
		return pressed_controlKeys[53];

	// Returns false if no key was detected
	std::cout << '\n' << "Key: " << key << " does not match any Key!";
	return false;
}


std::string UserInput::get_keypress() {
	// Arrow Keys
	if ( arrowKeys[0] == true )
		return "arrow_up";
	if ( arrowKeys[1] == true )
		return "arrow_right";
	if ( arrowKeys[2] == true )
		return "arrow_down";
	if ( arrowKeys[3] == true )
		return "arrow_left";

	// Number Keys
	if ( num[0] == true )
		return "0";
	if ( num[1] == true )
		return "1";
	if ( num[2] == true )
		return "2";
	if ( num[3] == true )
		return "3";
	if ( num[4] == true )
		return "4";
	if ( num[5] == true )
		return "5";
	if ( num[6] == true )
		return "6";
	if ( num[7] == true )
		return "7";
	if ( num[8] == true )
		return "8";
	if ( num[9] == true )
		return "9";

	// letters
	if ( letter[0] == true )
		return "a";
	if ( letter[1] == true )
		return "b";
	if ( letter[2] == true )
		return "c";
	if ( letter[3] == true )
		return "d";
	if ( letter[4] == true )
		return "e";
	if ( letter[5] == true )
		return "f";
	if ( letter[6] == true )
		return "g";
	if ( letter[7] == true )
		return "h";
	if ( letter[8] == true )
		return "i";
	if ( letter[9] == true )
		return "j";
	if ( letter[10] == true )
		return "k";
	if ( letter[11] == true )
		return "l";
	if ( letter[12] == true )
		return "m";
	if ( letter[13] == true )
		return "n";
	if ( letter[14] == true )
		return "o";
	if ( letter[15] == true )
		return "p";
	if ( letter[16] == true )
		return "q";
	if ( letter[17] == true )
		return "r";
	if ( letter[18] == true )
		return "s";
	if ( letter[19] == true )
		return "t";
	if ( letter[20] == true )
		return "u";
	if ( letter[21] == true )
		return "v";
	if ( letter[22] == true )
		return "w";
	if ( letter[23] == true )
		return "x";
	if ( letter[24] == true )
		return "y";
	if ( letter[25] == true )
		return "z";

	// Control Keys
	if ( controlKeys[0] == true )
		return "escape";
	if ( ( controlKeys[1] == true ) && ( controlKeys[5] == false ) )
		return "left_ctrl";
	if ( ( controlKeys[2] == true ) && ( controlKeys[6] == false ) )
		return "left_shift";
	if ( ( controlKeys[3] == true ) && ( controlKeys[7] == false ) )
		return "left_alt";
	if ( ( controlKeys[4] == true ) && ( controlKeys[8] == false ) )
		return "left_system";
	if ( ( controlKeys[5] == true ) && ( controlKeys[1] == false ) )
		return "right_ctrl";
	if ( ( controlKeys[6] == true ) && ( controlKeys[2] == false ) )
		return "right_shift";
	if ( ( controlKeys[7] == true ) && ( controlKeys[3] == false ) )
		return "right_alt";
	if ( ( controlKeys[8] == true ) && ( controlKeys[4] == false ) )
		return "right_system";

	if ( controlKeys[9] == true )
		return "menu";

	if ( controlKeys[10] == true )
		return "{";
	if ( controlKeys[11] == true )
		return "}";
	if ( controlKeys[12] == true )
		return ";";
	if ( controlKeys[13] == true )
		return ",";
	if ( controlKeys[14] == true )
		return ".";
	if ( controlKeys[15] == true )
		return "'";
	if ( controlKeys[16] == true )
		return "/";
	if ( controlKeys[17] == true )
		return "backslash";
	if ( controlKeys[18] == true )
		return "~";
	if ( controlKeys[19] == true )
		return "=";
	if ( controlKeys[20] == true )
		return "dash";
	if ( controlKeys[21] == true )
		return "space";
	if ( controlKeys[22] == true )
		return "return";
	if ( controlKeys[23] == true )
		return "backspace";
	if ( controlKeys[24] == true )
		return "tab";
	if ( controlKeys[25] == true )
		return "page_down";
	if ( controlKeys[26] == true )
		return "page_up";
	if ( controlKeys[27] == true )
		return "end";
	if ( controlKeys[28] == true )
		return "home";
	if ( controlKeys[29] == true )
		return "insert";
	if ( controlKeys[30] == true )
		return "delete";

	if ( controlKeys[31] == true )
		return "+";
	if ( controlKeys[32] == true )
		return "-";
	if ( controlKeys[33] == true )
		return "*";
	
	if ( controlKeys[35] == true )
		return "f1";
	if ( controlKeys[36] == true )
		return "f2";
	if ( controlKeys[37] == true )
		return "f3";
	if ( controlKeys[38] == true )
		return "f4";
	if ( controlKeys[39] == true )
		return "f5";
	if ( controlKeys[40] == true )
		return "f6";
	if ( controlKeys[41] == true )
		return "f7";
	if ( controlKeys[42] == true )
		return "f8";
	if ( controlKeys[43] == true )
		return "f9";
	if ( controlKeys[44] == true )
		return "f10";
	if ( controlKeys[45] == true )
		return "f11";
	if ( controlKeys[46] == true )
		return "f12";
	if ( controlKeys[47] == true )
		return "f13";
	if ( controlKeys[48] == true )
		return "f14";
	if ( controlKeys[49] == true )
		return "f15";

	if ( controlKeys[50] == true )
		return "ctrl";
	if ( controlKeys[51] == true )
		return "shift";
	if ( controlKeys[52] == true )
		return "alt";
	if ( controlKeys[53] == true )
		return "system";

	return " ";
}