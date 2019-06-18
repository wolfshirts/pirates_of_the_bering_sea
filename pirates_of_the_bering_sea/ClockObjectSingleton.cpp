#include<string>

#include "ClockObjectSingleton.h"


ClockObjectSingleton* ClockObjectSingleton::m_pInstance = nullptr; //static pointer to ensure only one instance of class.

ClockObjectSingleton* ClockObjectSingleton::ClockInstance()
{
	if (!m_pInstance)   // Only allow one instance of class to be generated.
		m_pInstance = new ClockObjectSingleton;
	return m_pInstance;
}

ClockObjectSingleton::ClockObjectSingleton() {
	
}

void ClockObjectSingleton::update() {
	//every 10 seconds = 1 minute
	ticks += 1;
	if (ticks == 600) {
		minutes += 1;
		ticks = 0;
	}
	if (minutes == 60) {
		hours += 1;
		minutes = 0;
	}
	if (hours == 24) {
		days += 1;
		hours = 0;
	}
}

std::string ClockObjectSingleton::get_game_time()
{
	std::string clockMinutes;
	std::string clockHours;
	if (minutes < 10) {
		clockMinutes = "0" + std::to_string(minutes);
	}
	else {
		clockMinutes = std::to_string(minutes);
	}

	if(hours < 10){
		clockHours = "0" + std::to_string(hours);
	}
	else {
		clockHours = std::to_string(hours);
	}
	return clockHours + ":" + clockMinutes;
}

std::string ClockObjectSingleton::get_game_day()
{
	return std::to_string(this->days);
}
