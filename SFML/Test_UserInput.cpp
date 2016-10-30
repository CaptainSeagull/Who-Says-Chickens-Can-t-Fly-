#include "Test_UserInput.h"


void Test_UserInput::run( UserInput* userInput ) {
	controlKeys( userInput );
	pressed_controlKeys( userInput );
}

void Test_UserInput::controlKeys( UserInput* userInput ) {
	if ( userInput->escape() == true )
		std::cout << '\n' << "Escape Key";
	
	if ( userInput->leftControl() == true )
		std::cout << '\n' << "Left Control";

	if ( userInput->leftShift() == true )
		std::cout << '\n' << "Left Shift";

	if ( userInput->leftAlt() == true )
		std::cout << '\n' << "Left Alt";

	if ( userInput->leftSystem() == true )
		std::cout << '\n' << "Left System";

	if ( userInput->rightControl() == true )
		std::cout << '\n' << "Right Control";

	if ( userInput->rightShift() == true )
		std::cout << '\n' << "Right Shift";

	if ( userInput->rightAlt() == true )
		std::cout << '\n' << "Right Alt";

	if ( userInput->rightSystem() == true )
		std::cout << '\n' << "Right System";

	if ( userInput->menu() == true )
		std::cout << '\n' << "Menu";

	if ( userInput->leftBracket() == true )
		std::cout << '\n' << "Left bracket";
	
	if ( userInput->rightBracket() == true )
		std::cout << '\n' << "Right Bracket";

	if ( userInput->semiColon() == true )
		std::cout << '\n' << "semiColon";

	if ( userInput->comma() == true )
		std::cout << '\n' << "Comma";

	if ( userInput->period() == true )
		std::cout << '\n' << "Period";

	if ( userInput->quote() == true )
		std::cout << '\n' << "Quote";

	if ( userInput->slash() == true )
		std::cout << '\n' << "slash";

	if ( userInput->backslash() == true )
		std::cout << '\n' << "backslash";

	if ( userInput->tilde() == true )
		std::cout << '\n' << "tilde";

	if ( userInput->equal() == true )
		std::cout << '\n' << "equal";

	if ( userInput->dash() == true )
		std::cout << '\n' << "dash";

	if ( userInput->space() == true )
		std::cout << '\n' << "space";

	if ( userInput->returnKey() == true )
		std::cout << '\n' << "return";

	if ( userInput->backSpace() == true )
		std::cout << '\n' << "Backspace";

	if ( userInput->tab() == true )
		std::cout << '\n' << "tab";

	if ( userInput->pageDown() == true )
		std::cout << '\n' << "page down";

	if ( userInput->pageUp() == true )
		std::cout << '\n' << "page up";

	if ( userInput->end() == true )
		std::cout << '\n' << "end";

	if ( userInput->home() == true )
		std::cout << '\n' << "home";
			
	if ( userInput->insert() == true )
		std::cout << '\n' << "Insert";

	if ( userInput->deleteKey() == true )
		std::cout << '\n' << "Delete Key";

	if ( userInput->add() == true )
		std::cout << '\n' << "add";

	if ( userInput->subtract() == true )
		std::cout << '\n' << "Subtract";

	if ( userInput->multiply() == true )
		std::cout << '\n' << "Multiply";

	if ( userInput->divide() == true )
		std::cout << '\n' << "Divide";

	if ( userInput->f1() == true )
		std::cout << '\n' << "f1";

	if ( userInput->f2() == true )
		std::cout << '\n' << "f2";

	if ( userInput->f3() == true )
		std::cout << '\n' << "f3";

	if ( userInput->f4() == true )
		std::cout << '\n' << "f4";

	if ( userInput->f5() == true )
		std::cout << '\n' << "f5";

	if ( userInput->f6() == true )
		std::cout << '\n' << "f6";

	if ( userInput->f7() == true )
		std::cout << '\n' << "f7";

	if ( userInput->f8() == true )
		std::cout << '\n' << "f8";

	if ( userInput->f9() == true )
		std::cout << '\n' << "f9";

	if ( userInput->f10() == true )
		std::cout << '\n' << "f10";

	if ( userInput->f11() == true )
		std::cout << '\n' << "f11";

	if ( userInput->f12() == true )
		std::cout << '\n' << "f12";

	if ( userInput->f13() == true )
		std::cout << '\n' << "f13";

	if ( userInput->f14() == true )
		std::cout << '\n' << "f14";

	if ( userInput->f15() == true )
		std::cout << '\n' << "f15";

	if ( userInput->control() == true )
		std::cout << '\n' << "Control";

	if ( userInput->shift() == true )
		std::cout << '\n' << "shift";

	if ( userInput->alt() == true )
		std::cout << '\n' << "alt";

	if ( userInput->system() == true )
		std::cout << '\n' << "System";
}

void Test_UserInput::pressed_controlKeys( UserInput* userInput ) {
	if ( userInput->pressed_escape() == true )
		std::cout << '\n' << "Pressed Escape Key";
	
	if ( userInput->pressed_leftControl() == true )
		std::cout << '\n' << "Pressed Left Control";

	if ( userInput->pressed_leftShift() == true )
		std::cout << '\n' << "Pressed Left Shift";

	if ( userInput->pressed_leftAlt() == true )
		std::cout << '\n' << "Pressed Left Alt";

	if ( userInput->pressed_leftSystem() == true )
		std::cout << '\n' << "Pressed Left System";

	if ( userInput->pressed_rightControl() == true )
		std::cout << '\n' << "Pressed Right Control";

	if ( userInput->pressed_rightShift() == true )
		std::cout << '\n' << "Pressed Right Shift";

	if ( userInput->pressed_rightAlt() == true )
		std::cout << '\n' << "Pressed Right Alt";

	if ( userInput->pressed_rightSystem() == true )
		std::cout << '\n' << "Pressed Right System";

	if ( userInput->pressed_menu() == true )
		std::cout << '\n' << "Pressed Menu";

	if ( userInput->pressed_leftBracket() == true )
		std::cout << '\n' << "Pressed Left bracket";
	
	if ( userInput->pressed_rightBracket() == true )
		std::cout << '\n' << "Pressed Right Bracket";

	if ( userInput->pressed_semiColon() == true )
		std::cout << '\n' << "Pressed semiColon";

	if ( userInput->pressed_comma() == true )
		std::cout << '\n' << "Pressed Comma";

	if ( userInput->pressed_period() == true )
		std::cout << '\n' << "Pressed Period";

	if ( userInput->pressed_quote() == true )
		std::cout << '\n' << "Pressed Quote";

	if ( userInput->pressed_slash() == true )
		std::cout << '\n' << "Pressed slash";

	if ( userInput->pressed_backslash() == true )
		std::cout << '\n' << "Pressed backslash";

	if ( userInput->pressed_tilde() == true )
		std::cout << '\n' << "Pressed tilde";

	if ( userInput->pressed_equal() == true )
		std::cout << '\n' << "Pressed equal";

	if ( userInput->pressed_dash() == true )
		std::cout << '\n' << "Pressed dash";

	if ( userInput->pressed_space() == true )
		std::cout << '\n' << "Pressed space";

	if ( userInput->pressed_returnKey() == true )
		std::cout << '\n' << "Pressed return";

	if ( userInput->pressed_backSpace() == true )
		std::cout << '\n' << "Pressed Backspace";

	if ( userInput->pressed_tab() == true )
		std::cout << '\n' << "Pressed tab";

	if ( userInput->pressed_pageDown() == true )
		std::cout << '\n' << "Pressed page down";

	if ( userInput->pressed_pageUp() == true )
		std::cout << '\n' << "Pressed page up";

	if ( userInput->pressed_end() == true )
		std::cout << '\n' << "Pressed end";

	if ( userInput->pressed_home() == true )
		std::cout << '\n' << "Pressed home";
			
	if ( userInput->pressed_insert() == true )
		std::cout << '\n' << "Pressed Insert";

	if ( userInput->pressed_deleteKey() == true )
		std::cout << '\n' << "Pressed Delete Key";

	if ( userInput->pressed_add() == true )
		std::cout << '\n' << "Pressed add";

	if ( userInput->pressed_subtract() == true )
		std::cout << '\n' << "Pressed Subtract";

	if ( userInput->pressed_multiply() == true )
		std::cout << '\n' << "Pressed Multiply";

	if ( userInput->pressed_divide() == true )
		std::cout << '\n' << "Pressed Divide";

	if ( userInput->pressed_f1() == true )
		std::cout << '\n' << "Pressed f1";

	if ( userInput->pressed_f2() == true )
		std::cout << '\n' << "Pressed f2";

	if ( userInput->pressed_f3() == true )
		std::cout << '\n' << "Pressed f3";

	if ( userInput->pressed_f4() == true )
		std::cout << '\n' << "Pressed f4";

	if ( userInput->pressed_f5() == true )
		std::cout << '\n' << "Pressed f5";

	if ( userInput->pressed_f6() == true )
		std::cout << '\n' << "Pressed f6";

	if ( userInput->pressed_f7() == true )
		std::cout << '\n' << "Pressed f7";

	if ( userInput->pressed_f8() == true )
		std::cout << '\n' << "Pressed f8";

	if ( userInput->pressed_f9() == true )
		std::cout << '\n' << "Pressed f9";

	if ( userInput->pressed_f10() == true )
		std::cout << '\n' << "Pressed f10";

	if ( userInput->pressed_f11() == true )
		std::cout << '\n' << "Pressed f11";

	if ( userInput->pressed_f12() == true )
		std::cout << '\n' << "Pressed f12";

	if ( userInput->pressed_f13() == true )
		std::cout << '\n' << "Pressed f13";

	if ( userInput->pressed_f14() == true )
		std::cout << '\n' << "Pressed f14";

	if ( userInput->pressed_f15() == true )
		std::cout << '\n' << "Pressed f15";

	if ( userInput->pressed_control() == true )
		std::cout << '\n' << "Pressed Control";

	if ( userInput->pressed_shift() == true )
		std::cout << '\n' << "Pressed shift";

	if ( userInput->pressed_alt() == true )
		std::cout << '\n' << "Pressed alt";

	if ( userInput->pressed_system() == true )
		std::cout << '\n' << "Pressed System";
}