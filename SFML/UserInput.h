#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

	class UserInput {
		private:			
			static const int NUMBER_OF_LETTER_KEYS = 26;
			static const int NUMBER_OF_NUMBER_KEYS = 10;
			static const int NUMBER_OF_ARROW_KEYS = 4;
			static const int NUMBER_OF_MOUSE_BUTTONS = 3;
			static const int NUMBER_OF_CONTROL_KEYS = 54;
			
			
			// If key is held
			bool letter[ NUMBER_OF_LETTER_KEYS ];
			bool num[ NUMBER_OF_NUMBER_KEYS ];
			bool arrowKeys[ NUMBER_OF_ARROW_KEYS ];
			bool mouseButtons[ NUMBER_OF_MOUSE_BUTTONS ];
			bool controlKeys[ NUMBER_OF_CONTROL_KEYS ];


			// If key is pressed
			bool pressed_letter[ NUMBER_OF_LETTER_KEYS ];
			bool pressed_num[ NUMBER_OF_NUMBER_KEYS ];
			bool pressed_arrowKeys[ NUMBER_OF_ARROW_KEYS ];
			bool pressed_mouseButtons[ NUMBER_OF_MOUSE_BUTTONS ];
			bool pressed_controlKeys[ NUMBER_OF_CONTROL_KEYS ];


			// If a key is released
			bool released_letter[ NUMBER_OF_LETTER_KEYS ];
			bool released_num[ NUMBER_OF_NUMBER_KEYS ];
			bool released_arrowKeys[ NUMBER_OF_ARROW_KEYS ];
			bool released_mouseButtons[ NUMBER_OF_MOUSE_BUTTONS ];
			bool released_controlKeys[ NUMBER_OF_CONTROL_KEYS ];


			// The cross for the window
			bool windowCross;

			// Testing the mouse position
			void testMousePosition();

			// For testing whether key is held
			void test_letters();
			void test_arrowKeys();
			void test_numberKeys();
			void test_mouseButtons();
			void test_controlKeys();


			// For testing whether a key is pressed
			void testPressed_letters();
			void testPressed_arrowKeys();
			void testPressed_numberKeys();
			void testPressed_mouseButtons();
			void testPressed_controlKeys();


			// For testing whether a key has just been released
			void testReleased_letters();
			void testReleased_arrowKeys();
			void testReleased_numberKeys();					/* TODO */
			void testReleased_mouseButtons();
			void testReleased_controlKeys();				/* TODO */

			// Test whether two strings are equal
			// Ignoring their case
			bool equalsIgnoreCase(const std::string& a, const std::string& b);

		public:
			// The constructor
			UserInput(){ }

			// The destructor
			~UserInput() { std::cout << std::endl << "Deleting: User Input Class"; }

			// For testing keyboard input
			// Tests whether every key has been pressed or held down
			void test();


			// Returns true if the cross has been pressed on the window
			bool cross() { return windowCross; }

			
			//========================================================================================================================
			// Getting User Input as String
			//========================================================================================================================

			// Returns true or false based on whether a key is held
			// The Inputted String is the key
			// Types
			// Arrow Keys: arrow_<key> eg. arrow_down
			// Numbers: 0 or Zero
			// Letters: a or A
			bool keyboard( std::string key );

			// Returns true or false based on whether a key is just pressed
			// The Inputted String is the key
			// Types
			// Arrow Keys: arrow_<key> eg. arrow_down
			// Numbers: 0 or Zero
			// Letters: a or A
			bool keyboard_pressed( std::string key );

			// Returns true or false based on whether a key was just released
			// The Inputted String is the key
			// Types
			// Arrow Keys: arrow_<key> eg. arrow_down
			// Numbers: 0 or Zero
			// Letters: a or A
			//bool keyboard_released( std::string key );


			// Returns the key being currently pressed
			// NOTE: If two keys are being pressed then
			// only one of them will be returned!
			std::string get_keypress();



			//=========================================================================================================================
			// Mouse
			//=========================================================================================================================

			bool leftMouse() { return mouseButtons[0]; }
			bool rightMouse() { return mouseButtons[1]; }
			bool middleMouse() { return mouseButtons[2]; }

			bool pressed_leftMouse() { return pressed_mouseButtons[0]; }
			bool pressed_rightMouse() { return pressed_mouseButtons[1]; }
			bool pressed_middleMouse() { return pressed_mouseButtons[2]; }

			bool released_leftMouse() { return released_mouseButtons[0]; }
			bool released_rightMouse() { return released_mouseButtons[1]; }
			bool released_middleMouse() { return released_mouseButtons[2]; }

			// Return the mouse coordinates in the game area
			// Required the current sf::RenderWindow
			sf::Vector2f mouse_getPixelCoords( sf::RenderWindow &window ) { return window.mapPixelToCoords( sf::Mouse::getPosition(window) ); }


			//=========================================================================================================================
			// Arrow Keys
			//=========================================================================================================================

			bool arrowUp() { return arrowKeys[0]; }
			bool arrowRight() { return arrowKeys[1]; }
			bool arrowDown() { return arrowKeys[2]; }
			bool arrowLeft() { return arrowKeys[3]; }
			
			bool pressed_arrowUp() { return pressed_arrowKeys[0]; }
			bool pressed_arrowRight() { return pressed_arrowKeys[1]; }
			bool pressed_arrowDown() { return pressed_arrowKeys[2]; }
			bool pressed_arrowLeft() { return pressed_arrowKeys[3]; }

			bool released_arrowUp() { return released_arrowKeys[0]; }
			bool released_arrowRight() { return released_arrowKeys[1]; }
			bool released_arrowDown() { return released_arrowKeys[2]; }
			bool released_arrowLeft() { return released_arrowKeys[3]; }


			//=========================================================================================================================
			// Numbers
			//=========================================================================================================================

			bool zero() { return num[0]; }
			bool one() { return num[1]; }
			bool two() { return num[2]; }
			bool three() { return num[3]; }
			bool four() { return num[4]; }
			bool five() { return num[5]; }
			bool six() { return num[6]; }
			bool seven() { return num[7]; }
			bool eight() { return num[8]; }
			bool nine() { return num[9]; }

			bool pressed_zero() { return pressed_num[0]; }
			bool pressed_one() { return pressed_num[1]; }
			bool pressed_two() { return pressed_num[2]; }
			bool pressed_three() { return pressed_num[3]; }
			bool pressed_four() { return pressed_num[4]; }
			bool pressed_five() { return pressed_num[5]; }
			bool pressed_six() { return pressed_num[6]; }
			bool pressed_seven() { return pressed_num[7]; }
			bool pressed_eight() { return pressed_num[8]; }
			bool pressed_nine() { return pressed_num[9]; }

			bool released_zero() { return released_num[0]; }
			bool released_one() { return released_num[1]; }
			bool released_two() { return released_num[2]; }
			bool released_three() { return released_num[3]; }
			bool released_four() { return released_num[4]; }
			bool released_five() { return released_num[5]; }
			bool released_six() { return released_num[6]; }
			bool released_seven() { return released_num[7]; }
			bool released_eight() { return released_num[8]; }
			bool released_nine() { return released_num[9]; }


			//=========================================================================================================================
			// Letters
			//=========================================================================================================================

			bool a() { return letter[0]; }
			bool b() { return letter[1]; }
			bool c() { return letter[2]; }
			bool d() { return letter[3]; }
			bool e() { return letter[4]; }
			bool f() { return letter[5]; }
			bool g() { return letter[6]; }
			bool h() { return letter[7]; }
			bool i() { return letter[8]; }
			bool j() { return letter[9]; }
			bool k() { return letter[10]; }
			bool l() { return letter[11]; }
			bool m() { return letter[12]; }
			bool n() { return letter[13]; }
			bool o() { return letter[14]; }
			bool p() { return letter[15]; }
			bool q() { return letter[16]; }
			bool r() { return letter[17]; }
			bool s() { return letter[18]; }
			bool t() { return letter[19]; }
			bool u() { return letter[20]; }
			bool v() { return letter[21]; }
			bool w() { return letter[22]; }
			bool x() { return letter[23]; }
			bool y() { return letter[24]; }
			bool z() { return letter[25]; }

			bool pressed_a() { return pressed_letter[0]; }
			bool pressed_b() { return pressed_letter[1]; }
			bool pressed_c() { return pressed_letter[2]; }
			bool pressed_d() { return pressed_letter[3]; }
			bool pressed_e() { return pressed_letter[4]; }
			bool pressed_f() { return pressed_letter[5]; }
			bool pressed_g() { return pressed_letter[6]; }
			bool pressed_h() { return pressed_letter[7]; }
			bool pressed_i() { return pressed_letter[8]; }
			bool pressed_j() { return pressed_letter[9]; }
			bool pressed_k() { return pressed_letter[10]; }
			bool pressed_l() { return pressed_letter[11]; }
			bool pressed_m() { return pressed_letter[12]; }
			bool pressed_n() { return pressed_letter[13]; }
			bool pressed_o() { return pressed_letter[14]; }
			bool pressed_p() { return pressed_letter[15]; }
			bool pressed_q() { return pressed_letter[16]; }
			bool pressed_r() { return pressed_letter[17]; }
			bool pressed_s() { return pressed_letter[18]; }
			bool pressed_t() { return pressed_letter[19]; }
			bool pressed_u() { return pressed_letter[20]; }
			bool pressed_v() { return pressed_letter[21]; }
			bool pressed_w() { return pressed_letter[22]; }
			bool pressed_x() { return pressed_letter[23]; }
			bool pressed_y() { return pressed_letter[24]; }
			bool pressed_z() { return pressed_letter[25]; }

			bool released_a() { return released_letter[0]; }
			bool released_b() { return released_letter[1]; }
			bool released_c() { return released_letter[2]; }
			bool released_d() { return released_letter[3]; }
			bool released_e() { return released_letter[4]; }
			bool released_f() { return released_letter[5]; }
			bool released_g() { return released_letter[6]; }
			bool released_h() { return released_letter[7]; }
			bool released_i() { return released_letter[8]; }
			bool released_j() { return released_letter[9]; }
			bool released_k() { return released_letter[10]; }
			bool released_l() { return released_letter[11]; }
			bool released_m() { return released_letter[12]; }
			bool released_n() { return released_letter[13]; }
			bool released_o() { return released_letter[14]; }
			bool released_p() { return released_letter[15]; }
			bool released_q() { return released_letter[16]; }
			bool released_r() { return released_letter[17]; }
			bool released_s() { return released_letter[18]; }
			bool released_t() { return released_letter[19]; }
			bool released_u() { return released_letter[20]; }
			bool released_v() { return released_letter[21]; }
			bool released_w() { return released_letter[22]; }
			bool released_x() { return released_letter[23]; }
			bool released_y() { return released_letter[24]; }
			bool released_z() { return released_letter[25]; }

			//=========================================================================================================================
			// Control Keys
			//=========================================================================================================================

			bool escape() { return controlKeys[0]; }
			bool leftControl() { return controlKeys[1]; }
			bool leftShift() { return controlKeys[2]; }
			bool leftAlt() { return controlKeys[3]; }
			bool leftSystem() { return controlKeys[4]; }
			bool rightControl() { return controlKeys[5]; }
			bool rightShift() { return controlKeys[6]; }
			bool rightAlt() { return controlKeys[7]; }
			bool rightSystem() { return controlKeys[8]; }
			bool menu() { return controlKeys[9]; }
			bool leftBracket() { return controlKeys[10]; }
			bool rightBracket() { return controlKeys[11]; }
			bool semiColon() { return controlKeys[12]; }
			bool comma() { return controlKeys[13]; }
			bool period() { return controlKeys[14]; }
			bool quote() { return controlKeys[15]; }
			bool slash() { return controlKeys[16]; }
			bool backslash() { return controlKeys[17]; }
			bool tilde() { return controlKeys[18]; }
			bool equal() { return controlKeys[19]; }
			bool dash() { return controlKeys[20]; }
			bool space() { return controlKeys[21]; }
			bool returnKey() { return controlKeys[22]; }
			bool backSpace() { return controlKeys[23]; }
			bool tab() { return controlKeys[24]; }
			bool pageDown() { return controlKeys[25]; }
			bool pageUp() { return controlKeys[26]; }
			bool end() { return controlKeys[27]; }
			bool home() { return controlKeys[28]; }
			bool insert() { return controlKeys[29]; }
			bool deleteKey() { return controlKeys[30]; }
			bool add() { return controlKeys[31]; }
			bool subtract() { return controlKeys[32]; }
			bool multiply() { return controlKeys[33]; }
			bool divide() { return controlKeys[34]; }
			bool f1() { return controlKeys[35]; }
			bool f2() { return controlKeys[36]; }
			bool f3() { return controlKeys[37]; }
			bool f4() { return controlKeys[38]; }
			bool f5() { return controlKeys[39]; }
			bool f6() { return controlKeys[40]; }
			bool f7() { return controlKeys[41]; }
			bool f8() { return controlKeys[42]; }
			bool f9() { return controlKeys[43]; }
			bool f10() { return controlKeys[44]; }
			bool f11() { return controlKeys[45]; }
			bool f12() { return controlKeys[46]; }
			bool f13() { return controlKeys[47]; }
			bool f14() { return controlKeys[48]; }
			bool f15() { return controlKeys[49]; }
			bool control() { return controlKeys[50]; }
			bool shift() { return controlKeys[51]; }
			bool alt() { return controlKeys[52]; }
			bool system() { return controlKeys[53]; }


			bool pressed_escape() { return pressed_controlKeys[0]; }
			bool pressed_leftControl() { return pressed_controlKeys[1]; }
			bool pressed_leftShift() { return pressed_controlKeys[2]; }
			bool pressed_leftAlt() { return pressed_controlKeys[3]; }
			bool pressed_leftSystem() { return pressed_controlKeys[4]; }
			bool pressed_rightControl() { return pressed_controlKeys[5]; }
			bool pressed_rightShift() { return pressed_controlKeys[6]; }
			bool pressed_rightAlt() { return pressed_controlKeys[7]; }
			bool pressed_rightSystem() { return pressed_controlKeys[8]; }
			bool pressed_menu() { return pressed_controlKeys[9]; }
			bool pressed_leftBracket() { return pressed_controlKeys[10]; }
			bool pressed_rightBracket() { return pressed_controlKeys[11]; }
			bool pressed_semiColon() { return pressed_controlKeys[12]; }
			bool pressed_comma() { return pressed_controlKeys[13]; }
			bool pressed_period() { return pressed_controlKeys[14]; }
			bool pressed_quote() { return pressed_controlKeys[15]; }
			bool pressed_slash() { return pressed_controlKeys[16]; }
			bool pressed_backslash() { return pressed_controlKeys[17]; }
			bool pressed_tilde() { return pressed_controlKeys[18]; }
			bool pressed_equal() { return pressed_controlKeys[19]; }
			bool pressed_dash() { return pressed_controlKeys[20]; }
			bool pressed_space() { return pressed_controlKeys[21]; }
			bool pressed_returnKey() { return pressed_controlKeys[22]; }
			bool pressed_backSpace() { return pressed_controlKeys[23]; }
			bool pressed_tab() { return pressed_controlKeys[24]; }
			bool pressed_pageDown() { return pressed_controlKeys[25]; }
			bool pressed_pageUp() { return pressed_controlKeys[26]; }
			bool pressed_end() { return pressed_controlKeys[27]; }
			bool pressed_home() { return pressed_controlKeys[28]; }
			bool pressed_insert() { return pressed_controlKeys[29]; }
			bool pressed_deleteKey() { return pressed_controlKeys[30]; }
			bool pressed_add() { return pressed_controlKeys[31]; }
			bool pressed_subtract() { return pressed_controlKeys[32]; }
			bool pressed_multiply() { return pressed_controlKeys[33]; }
			bool pressed_divide() { return pressed_controlKeys[34]; }
			bool pressed_f1() { return pressed_controlKeys[35]; }
			bool pressed_f2() { return pressed_controlKeys[36]; }
			bool pressed_f3() { return pressed_controlKeys[37]; }
			bool pressed_f4() { return pressed_controlKeys[38]; }
			bool pressed_f5() { return pressed_controlKeys[39]; }
			bool pressed_f6() { return pressed_controlKeys[40]; }
			bool pressed_f7() { return pressed_controlKeys[41]; }
			bool pressed_f8() { return pressed_controlKeys[42]; }
			bool pressed_f9() { return pressed_controlKeys[43]; }
			bool pressed_f10() { return pressed_controlKeys[44]; }
			bool pressed_f11() { return pressed_controlKeys[45]; }
			bool pressed_f12() { return pressed_controlKeys[46]; }
			bool pressed_f13() { return pressed_controlKeys[47]; }
			bool pressed_f14() { return pressed_controlKeys[48]; }
			bool pressed_f15() { return pressed_controlKeys[49]; }
			bool pressed_control() { return pressed_controlKeys[50]; }
			bool pressed_shift() { return pressed_controlKeys[51]; }
			bool pressed_alt() { return pressed_controlKeys[52]; }
			bool pressed_system() { return pressed_controlKeys[53]; }


			bool released_escape() { return released_controlKeys[0]; }
			bool released_leftControl() { return released_controlKeys[1]; }
			bool released_leftShift() { return released_controlKeys[2]; }
			bool released_leftAlt() { return released_controlKeys[3]; }
			bool released_leftSystem() { return released_controlKeys[4]; }
			bool released_rightControl() { return released_controlKeys[5]; }
			bool released_rightShift() { return released_controlKeys[6]; }
			bool released_rightAlt() { return released_controlKeys[7]; }
			bool released_rightSystem() { return released_controlKeys[8]; }
			bool released_menu() { return released_controlKeys[9]; }
			bool released_leftBracket() { return released_controlKeys[10]; }
			bool released_rightBracket() { return released_controlKeys[11]; }
			bool released_semiColon() { return released_controlKeys[12]; }
			bool released_comma() { return released_controlKeys[13]; }
			bool released_period() { return released_controlKeys[14]; }
			bool released_quote() { return released_controlKeys[15]; }
			bool released_slash() { return released_controlKeys[16]; }
			bool released_backslash() { return released_controlKeys[17]; }
			bool released_tilde() { return released_controlKeys[18]; }
			bool released_equal() { return released_controlKeys[19]; }
			bool released_dash() { return released_controlKeys[20]; }
			bool released_space() { return released_controlKeys[21]; }
			bool released_returnKey() { return released_controlKeys[22]; }
			bool released_backSpace() { return released_controlKeys[23]; }
			bool released_tab() { return released_controlKeys[24]; }
			bool released_pageDown() { return released_controlKeys[25]; }
			bool released_pageUp() { return released_controlKeys[26]; }
			bool released_end() { return released_controlKeys[27]; }
			bool released_home() { return released_controlKeys[28]; }
			bool released_insert() { return released_controlKeys[29]; }
			bool released_deleteKey() { return released_controlKeys[30]; }
			bool released_add() { return released_controlKeys[31]; }
			bool released_subtract() { return released_controlKeys[32]; }
			bool released_multiply() { return released_controlKeys[33]; }
			bool released_divide() { return released_controlKeys[34]; }
			bool released_f1() { return released_controlKeys[35]; }
			bool released_f2() { return released_controlKeys[36]; }
			bool released_f3() { return released_controlKeys[37]; }
			bool released_f4() { return released_controlKeys[38]; }
			bool released_f5() { return released_controlKeys[39]; }
			bool released_f6() { return released_controlKeys[40]; }
			bool released_f7() { return released_controlKeys[41]; }
			bool released_f8() { return released_controlKeys[42]; }
			bool released_f9() { return released_controlKeys[43]; }
			bool released_f10() { return released_controlKeys[44]; }
			bool released_f11() { return released_controlKeys[45]; }
			bool released_f12() { return released_controlKeys[46]; }
			bool released_f13() { return released_controlKeys[47]; }
			bool released_f14() { return released_controlKeys[48]; }
			bool released_f15() { return released_controlKeys[49]; }
			bool released_control() { return released_controlKeys[50]; }
			bool released_shift() { return released_controlKeys[51]; }
			bool released_alt() { return released_controlKeys[52]; }
			bool released_system() { return released_controlKeys[53]; }
	};