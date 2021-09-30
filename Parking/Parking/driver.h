#include<iostream>
#include<list>
#ifndef DRIVER_H
#define DRIVER_H

using namespace std;

class driver
{
public:
	int selected_zone;
	int selected_time;
	string name;
	driver(int _selected_zone, int _selected_time, string _name);
};
#endif
