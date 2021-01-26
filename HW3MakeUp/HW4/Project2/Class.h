#pragma once
#include <string>
#include <iostream>
using namespace std;

class stopwatch {
	int hour;
	int minute;
	int second;

public:
	stopwatch();
	stopwatch(int hr, int min, int sec);
	int get_hr();
	int get_min();
	int get_sec();
	void print_time();
};