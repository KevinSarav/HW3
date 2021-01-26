#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Class.h"
#include <cstdlib>
#include <iomanip>
#ifndef Class
#define Class
using namespace std;

void total_time(stopwatch *watch, int size);
double total_days(stopwatch *watch, int size);

int main() {
	int size, inp = 1;
	string hr, min, sec;
	stopwatch *watch;
	int arry[3] = { 0 }; 

	cout << "Please enter how many times you would like to store: ";
	cin >> size;
	watch = new stopwatch[size];

	for (int i = 0; i < size; i++) {
		cout << "Please enter hour: ";
		cin >> hr;
		arry[0] = stoi(hr);
		cout << "Please enter minute: ";
		cin >> min;
		arry[1] = stoi(min);
		cout << "Please enter second: ";
		cin >> sec;
		arry[2] = stoi(sec);

		if (arry[0] < 0 || (arry[1] < 0 || arry[1] > 59) || (arry[2] < 0 || arry[2] > 59))
			watch[i] = stopwatch();
		else
			watch[i] = stopwatch(arry[0], arry[1], arry[2]);
	}

	do {
		cout <<
			"1) Print Times \n" <<
			"2) Print Total Time \n" <<
			"3) Print Days in Total Time \n" <<
			"0) Exit \n" <<
			"Please enter your selection: ";
		cin >> inp;

		switch (inp) {
		case 1: {
			for (int i = 0; i < size; i++) {
				cout << "Time " << i + 1 << " - ";
				watch[i].print_time();
			}
			break;
		}
		case 2: {
			total_time(watch, size);
			break;	
		}
		case 3: {
			cout << "Total Time in Days - " << fixed << setprecision(2) << total_days(watch, size) << endl;
			break;
		}
		case 0: {
			cout << "Terminating...";
			break;
		}
		default: {
			cout << "Invalid Selection - Please make another selection. \n";
			break;
		}
		}
	} while (inp != 0);
}

void total_time(stopwatch *watch, int size) {
	int totalHr = 0, totalMin = 0, totalSec = 0;

	for (int i = 0; i < size; i++) {
		totalHr += watch[i].get_hr();
		totalMin += watch[i].get_min();
		totalSec += watch[i].get_sec();
	}

	while (totalSec > 59) {
		totalSec -= 60;
		totalMin++;
	}

	while (totalMin > 59) {
		totalMin -= 60;
		totalHr++;
	}

	cout << "Total Time - " << totalHr << ":" << setw(2) << setfill('0') << totalMin
		<< ":" << setw(2) << setfill('0') << totalSec << endl;
}

double total_days(stopwatch *watch, int size) {
	double days = 0.00;

	for (int i = 0; i < size; i++) {
		days += watch[i].get_hr() / 24.0;
		days += watch[i].get_min() / 1440.0;
		days += watch[i].get_sec() / 86400.0;
	}

	return days;
}
#endif