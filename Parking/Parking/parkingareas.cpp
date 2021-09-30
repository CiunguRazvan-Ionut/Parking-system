#include<iostream>
#include "driver.h"
#include "parkingareas.h"

parkingareas::parkingareas(int _areaid, string _color, int _zone_price)
{
	areaid = _areaid;
	color = _color;
	zone_price = _zone_price;
}

int parkingareas::calculate_payment(int time, int zone_price, int current_hour)
{
	if (current_hour >= 9 && current_hour <= 12)
	{
		zone_price = zone_price * 2;
	}
	int hour = 60, minutes = 15;
	int full_hours = 0, quarter_hours = 0;
	int total_payment = 0, hours_payment, quarter_hours_payment;
	int quarter_price = 0, quarter_time = 0;
	if (time > hour)
	{
		full_hours = time / hour;
		quarter_hours = time % minutes;
		hours_payment = full_hours * zone_price;
		quarter_hours_payment = quarter_hours * zone_price;
		total_payment = hours_payment + quarter_hours_payment;
	}
	else
	{
		quarter_price = zone_price / 4;
		quarter_time = time / 15;
		total_payment = quarter_time * quarter_price;
	}
	return total_payment;
}

void take_enter()
{
	cout << "Press enter to check if the parking time is going to end for some drivers" << endl;
	while (1) {
		if (getchar())
			break;
	}
}

void print(list<driver> const& parklist)
{
	for (auto const& i : parklist)
	{
		cout << "The name of the driver is " << i.name << " and paid for " << i.selected_time << " minutes" << endl;
	}
}



