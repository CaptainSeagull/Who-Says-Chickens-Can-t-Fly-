#pragma once

#include <string>

	class AbstractComponent {
		protected:
			std::string m_name;
	
		public:
			AbstractComponent() { }
			~AbstractComponent() { }

			virtual void init() = 0;
			virtual void run() = 0;

			void setName( std::string name ) { this->m_name = name; }
			std::string getName() { return m_name; }
	};