#pragma once

#include <SFML\Graphics.hpp>

class Timer {
	private:
		sf::Clock m_clock;
		sf::Time m_time;

	public:
		Timer() { }
		~Timer() { }

		void start() { m_clock.restart(); }

		float getTime() {
			m_time = m_clock.restart();
			return m_time.asSeconds();
		}
};