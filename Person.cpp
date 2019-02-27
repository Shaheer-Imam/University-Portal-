#include "Person.h"
#include<string>
#include"Data.h"
#include<iostream>
#include<conio.h>
using namespace std;



Person::Person()
{
}
string Person::checkDepart(string depart)
{
	int i;
	for (i = 0; i <= (sizeof(departs) / 8); i++)
	{
		if (departs[i] == depart)
			return depart;
	}
	return "NOT FOUND";
}

Data Person:: get()
{
	int m, c, d;
	string check;
	ui.gotoxy(45, 15); cout << "*Name: ";
	ui.gotoxy(105, 15); cout << "*Age: ";
	ui.gotoxy(45, 16); cout << "*Address: ";
	ui.gotoxy(105, 17); cout << "*Department: ";
	ui.gotoxy(105, 18); cout << "*Phone: ";
	ui.gotoxy(105, 19); cout << "*Email: ";
	ui.gotoxy(45, 19); cout << "Date of Birth(day/month/year): ";
	ui.gotoxy(80, 19); cout << "-";
	ui.gotoxy(84, 19); cout << "-";
	ui.gotoxy(52, 15); getline(cin, data.name);
	ui.gotoxy(111, 15); getline(cin, data.age);
	ui.gotoxy(55, 16); getline(cin, data.address);
	do {
		fflush(stdin);
		ui.gotoxy(118, 17); getline(cin, data.department);
		check = Person::checkDepart(data.department);
		if (check == "NOT FOUND")
		{
			ui.gotoxy(118, 17); cout << "Please enter correct department code";
			ui.delay(1000);
			ui.clearArea(118, 17, 40, 1);
		}
	} while (check == "NOT FOUND");
	ui.gotoxy(113, 18); getline(cin, data.phone);
	ui.gotoxy(113, 19); getline(cin, data.email);
	ui.gotoxy(78, 19); cin >> m;
	ui.gotoxy(82, 19); cin >> c;
	ui.gotoxy(85, 19); cin >> d;
	data.d_o_b.setDay(m);
	data.d_o_b.setMonth(c);
	data.d_o_b.setYear(d);
	return this->data;
}

char Person::selectCourses(string depart,string year)
{
	int y, i = 13;
	char choice;
	if (year == "FIRST")y = 1;
	if (year == "SECOND")y = 2;
	if (year == "THIRD")y = 3;
	if (year == "FOURTH")y = 4;
	for (i = 13; i < 18; i++)
	{
		ui.gotoxy(45, i); cout << i - 12 << ". " << depart << "-" << y << ran[i - 13];
	}
	ui.gotoxy(65, 22); cout << "press \'n\' to exit ";
	ui.gotoxy(65, 20); cout << "press \'y\' if you want to register courses";
	choice = _getche();
	return choice;
}


Person::~Person()
{
}
