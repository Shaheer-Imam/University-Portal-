#include "Teacher.h"
#include<string>
#include<iostream>
#include<conio.h>
#include<fstream>
using namespace std;



Teacher::Teacher()
{
}


Teacher::~Teacher()
{
}
bool Teacher::validate(string userName, string pass)
{
	string cName, cPass;
	ifstream fin1, fin2;
	fin1.open("Usernames Teacher.txt");
	fin2.open("Passwords Teacher.txt");
	while (!fin1.eof() || !fin2.eof())
	{
		getline(fin1, cName);
		getline(fin2, cPass);
		if (cName == userName && cPass == pass)
			return true;
	}
	return false;
}

void Teacher::showDetails(string userName)
{
	ui.clearArea(45, 13, 115, 11);
hello:
	string si, su, depart, c3, c4, c5;
	int i = 13, tag = 0, tag1 = 0;
	ifstream fin1, fin2, fin3;
	fin1.open("Usernames Teacher.txt");
	fin2.open("Department Teacher.txt");
	ui.gotoxy(45, 15);
	while (!fin1.eof() || !fin2.eof()) {
		getline(fin1, c3);
		getline(fin2, c4);
		if (userName == c3) {
			depart = c4;
			tag1 = 1;
			ui.clearArea(45, 13, 115, 14);
			ifstream fin;
			fin.open("All Details " + depart + "\\TEACHER\\all details.txt");
			while (!fin.eof()) {
				do {
					fin >> si;
					if (si == userName) {
						tag = 1;
						getline(fin, su);
						while (su != "***") {
							ui.gotoxy(45, ++i);
							cout << su << "\n";
							getline(fin, su);
						}
					}
					break;
				} while (si != userName);
			}
			if (tag == 0) {
				goto hello;
			}
			else {
				fin.close();
				ui.gotoxy(45, 13);
				cout << "Press any key to go back.";
				_getch();
				ui.clearArea(45, 13, 115, 15);
			}
			fin.close();
		}
	}
	fin1.close();
	fin2.close();
	ui.gotoxy(45, ++i);
	cout << "press any key to continue";
	_getch();
}

void Teacher::setAttendence(string year,string userName)
{
	ui.clearArea(45, 13, 115, 11);
	int i = 0, tag = 0, tag1 = 0, j=0, sel, k=13;
hello:
	string si, su, c3, c4, c5,st[100],at,depart;
	ifstream fin1, fin2, fin3;
	ifstream fin;
	ofstream fout;
	fin1.open("Usernames Teacher.txt");
	fin2.open("Department Teacher.txt");
	ui.gotoxy(45, 15);
	while (!fin1.eof() || !fin2.eof())
	{
		j++;
		getline(fin1, c3);
		getline(fin2, c4);
		if (c3 == userName)
		{
			depart = c4;
		}
		if (j > 100) 
			break;
	}
	fin1.close();
	fin2.close();
	fin1.open("Usernames Student.txt");
	fin2.open("Department Student.txt");
	fin3.open("Year Student.txt");
	ui.gotoxy(45, 15);
	j = 0;
	while (!fin1.eof() || !fin2.eof() || fin3.eof()) {
		getline(fin1, c3);
		getline(fin2, c4);
		getline(fin3, c5);
		j++;
		if (c4 == depart && c5 == year)
		{
			st[i] = c3;
			tag1 = 1;
			ui.gotoxy(45, i + 15);
			cout << ++i << " . " << c3;
		}
		if (j >= 100) break;
	}
	ui.gotoxy(65, 25); cout << "Select student by number : ";
	cin >> sel;
	fin.open("Members Details\\" + st[sel - 1] + " course.txt");
	fout.open("Members Details\\" + st[sel - 1] + " attendence.txt", std::fstream::in | std::fstream::out | std::fstream::app);
	i = 0;
	ui.clearArea(35, 13, 119, 15);
	while (!fin.eof())
	{
		tag = 1;
		getline(fin, su);
		while (su != "***")
		{
			if (su == "***")
				break;
			ui.gotoxy(45, ++k);
			cout << "enter attendence for " << su << ": ";
			cin >> at;
			fout << at << "\n";
			getline(fin, su);
		}
		break;
	}
	if (tag == 0) {
		goto hello;
	}
	else {
		fin.close();
		ui.gotoxy(45, 13);
		cout << "Press any key to go back.";
		_getch();
		ui.clearArea(45, 13, 115, 15);
	}
	fout.close();
	fin.close();
	fin1.close();
	fin2.close();
	ui.gotoxy(45, ++i);
	cout << "press any key to continue";
	_getch();
}