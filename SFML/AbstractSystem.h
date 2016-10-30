#pragma once

#include "Entity.h"

#include <memory>



	class AbstractSystem {
		protected:
			std::string m_systemName;
			
		public:
			AbstractSystem() { }
			~AbstractSystem() { }

			virtual void update( std::vector < std::shared_ptr<Entity> > entity ) = 0;

			void setSystemName( std::string systemName ) { this->m_systemName = systemName; }
			std::string getSystemName() { return m_systemName; }
	};