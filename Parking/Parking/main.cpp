#include <iostream>
#include <ctime>
#include <list>
#include "driver.h"
#include "parkingareas.h"


using namespace std;

//i used seconds as minutes for this simulation

int main()
{
	clock_t t;
	clock_t t1;
	clock_t t2;
	t = clock();
	t1 = clock();
	int current_hour = 10;
	//int current_hour = 8;
	double check;
	parkingareas orangezone(1, "orange", 80);
	parkingareas purplezone(2, "purple", 40);
	parkingareas bluezone(3, "blue", 20);
	driver alex(1, 15, "Alex");
	driver mihai(1, 30, "Mihai");
	driver alina(1, 60, "Alina");
	driver mihaela(1, 15, "Mihaela");
	driver dan(2, 45, "Dan");
	driver marius(3, 90, "Marius");
	driver maria(3, 180, "Maria");
	driver catalin(3, 105, "Catalin");
	orangezone.parklist.emplace_back(alex);
	orangezone.parklist.emplace_back(mihai);
	orangezone.parklist.emplace_back(alina);
	orangezone.parklist.emplace_back(mihaela);
	purplezone.parklist.emplace_back(dan);
	bluezone.parklist.emplace_back(marius);
	bluezone.parklist.emplace_back(maria);
	bluezone.parklist.emplace_back(catalin);
	cout << "Here you can see the details of the drivers who parked into the orange zone :" << endl;
	print(orangezone.parklist);
	for (orangezone.i = orangezone.parklist.begin(); orangezone.i != orangezone.parklist.end(); orangezone.i++)
	{
		cout << orangezone.i->name << " paid " << orangezone.calculate_payment(orangezone.i->selected_time, orangezone.zone_price, current_hour) << " coins " << endl;
	}

	cout << "Here you can see the details of the drivers who parked into the purple zone :" << endl;
	print(purplezone.parklist);
	for (purplezone.i = purplezone.parklist.begin(); purplezone.i != purplezone.parklist.end(); purplezone.i++)
	{
		cout << purplezone.i->name << " paid " << purplezone.calculate_payment(purplezone.i->selected_time, purplezone.zone_price, current_hour) << " coins " << endl;
	}

	cout << "Here you can see the details of the drivers who parked into the blue zone :" << endl;
	print(bluezone.parklist);
	for (bluezone.i = bluezone.parklist.begin(); bluezone.i != bluezone.parklist.end(); bluezone.i++)
	{
		cout << bluezone.i->name << " paid " << bluezone.calculate_payment(bluezone.i->selected_time, bluezone.zone_price, current_hour) << " coins " << endl;
	}
	take_enter();
	for (orangezone.i = orangezone.parklist.begin(); orangezone.i != orangezone.parklist.end(); orangezone.i++)
	{
		t2 = clock() - t1;
		check = ((double)t2) / CLOCKS_PER_SEC;
		if (orangezone.i->selected_time - check <= 10.1)
		{
			cout << "The driver " << orangezone.i->name << " has just 10 more minutes of the paid parking spot" << endl;
			cout << orangezone.i->name << " can extend the time with maximum " << (1 * 60) - orangezone.i->selected_time << " minutes " << endl;
		}
	}

	for (purplezone.i = purplezone.parklist.begin(); purplezone.i != purplezone.parklist.end(); purplezone.i++)
	{
		t2 = clock() - t1;
		check = ((double)t2) / CLOCKS_PER_SEC;
		if (purplezone.i->selected_time - check <= 10.1)
		{
			cout << "The driver " << purplezone.i->name << " has just 10 more minutes of the paid parking spot" << endl;
			cout << purplezone.i->name << " can extend the time with maximum " << (3 * 60) - purplezone.i->selected_time << " minutes " << endl;
		}
	}

	for (bluezone.i = bluezone.parklist.begin(); bluezone.i != bluezone.parklist.end(); bluezone.i++)
	{
		t2 = clock() - t1;
		check = ((double)t2) / CLOCKS_PER_SEC;
		if (bluezone.i->selected_time - check <= 10.1)
		{
			cout << "The driver " << bluezone.i->name << " has just 10 more minutes of the paid parking spot" << endl;
			cout << bluezone.i->name << " can extend the time with maximum" << (24 * 60) - bluezone.i->selected_time << " minutes " << endl;
		}

	}

	t = clock() - t;
	double time_taken = ((double)t) / CLOCKS_PER_SEC;
	cout << "The program took " << time_taken << " seconds to execute";
	return 0;
}