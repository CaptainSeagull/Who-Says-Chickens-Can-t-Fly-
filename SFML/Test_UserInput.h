#pragma once

#include "UserInput.h"

	class Test_UserInput {	
		private:
			void controlKeys( UserInput* userInput );

			void pressed_controlKeys( UserInput* userInput );
	
	
		public:
			Test_UserInput() { }
			~Test_UserInput() { }

			void run( UserInput* userInput );
	};