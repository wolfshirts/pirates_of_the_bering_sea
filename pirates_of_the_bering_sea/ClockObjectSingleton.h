#pragma once
#include<allegro5/allegro.h>
#include<string>
class ClockObjectSingleton
{
public:
	static ClockObjectSingleton* ClockInstance(); //on first instantiation always pass timer.
	std::string get_game_time();
	void update();

private:
	ClockObjectSingleton(); //no instantiation.
	ClockObjectSingleton(ClockObjectSingleton const&) {}; // copy constructor is private
	ClockObjectSingleton & operator=(ClockObjectSingleton const&) {};  // assignment operator is private
	static ClockObjectSingleton *m_pInstance;
	int hours = 9;
	uint64_t days = 0;
	int ticks = 0;
	int minutes = 0;
};

