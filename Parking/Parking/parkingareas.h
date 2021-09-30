#include<iostream>
#include<list>
#include "driver.h"
#ifndef PARKINGAREAS_H
#define PARKINGAREAS_H

using namespace std;

class parkingareas
{
public:
	list<driver> parklist;
	list<driver>::iterator i;
	int areaid;
	string color;
	int zone_price;
	parkingareas(int _areaid, string _color, int _zone_price);
	int calculate_payment(int time, int zone_price, int current_hour);
};
void print(list<driver> const& parklist);
void take_enter();
#endif