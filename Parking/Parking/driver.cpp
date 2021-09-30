#include<iostream>
#include "driver.h"
#include "parkingareas.h"

using namespace std;

driver::driver(int _selected_zone, int _selected_time, string _name)
{
	selected_zone = _selected_zone;
	selected_time = _selected_time;
	name = _name;
}