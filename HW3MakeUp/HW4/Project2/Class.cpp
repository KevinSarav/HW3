#include <iostream>
#include "Class.h"
#include <iomanip>
#ifndef Class
#define Class
using namespace std;


stopwatch::stopwatch() {
	hour = 0;
	minute = 0;
	second = 0;
};

stopwatch::stopwatch(int hr, int min, int sec) {
	hour = hr;
	minute = min;
	second = sec;
};

int stopwatch::get_hr() {
	return hour;
}

int stopwatch::get_min() {
	return minute;
}

int stopwatch::get_sec() {
	return second;
}

void stopwatch::print_time() {
	cout << get_hr() << ":" << setw(2) << setfill('0') << get_min()
		<< ":" << setw(2) << setfill('0') << get_sec() << endl;
}
#endif