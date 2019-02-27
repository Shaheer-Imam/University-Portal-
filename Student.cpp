#include "Student.h"
#include<string>
#include<iostream>
#include<conio.h>
#include<fstream>
using namespace std;



Student::Student()
{
}


Student::~Student()
{
}

bool Student::validate(string userName, string pass)
{
	string cName, cPass;
	ifstream fin1, fin2;
	fin1.open("Usernames Student.txt");
	fin2.open("Passwords Student.txt");
	while (!fin1.eof() || !fin2.eof())
	{
		getline(fin1, cName);
		getline(fin2, cPass);
		if (cName == userName && cPass == pass)
			return true;
	}
	return false;
}

void Student::showDetails(string userName)
{
	ui.clearArea(45, 13, 115, 11);
hello:
	string si, su, depart, c3, c4,c5,year;
	int i = 13, tag = 0, tag1 = 0;
	ifstream fin1, fin2,fin3;
	fin1.open("Usernames Student.txt");
	fin2.open("Department Student.txt");
	fin3.open("Year Student.txt");
	ui.gotoxy(45, 15);
	while (!fin1.eof()||!fin2.eof()||fin3.eof()) {
		getline(fin1, c3);
		getline(fin2, c4);
		getline(fin3, c5);
		if (userName == c3) {
			depart = c4;
			year = c5;
			tag1 = 1;
			ui.clearArea(45, 13, 115, 14);
			ifstream fin;
			fin.open("All Details "+depart+"\\STUDENT\\"+year+"\\all details.txt");
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
				break;
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

void Student::registerCourse(string userName)
{
	ui.clearArea(45, 13, 115, 11);
hello:
	string si, su, depart, c3, c4, c5, year;
	int i = 13, tag = 0, tag1 = 0,y;
	char choice;
	ifstream fin1, fin2, fin3;
	ofstream fout;
	fin1.open("Usernames Student.txt");
	fin2.open("Department Student.txt");
	fin3.open("Year Student.txt");
	ui.gotoxy(45, 15);
	while (!fin1.eof() || !fin2.eof() || fin3.eof()) {
		getline(fin1, c3);
		getline(fin2, c4);
		getline(fin3, c5);
		if (userName == c3) {
			depart = c4;
			year = c5;
			tag1 = 1;
			ui.clearArea(45, 13, 115, 14);
			break;
		}
	}
	//fin.open("Semester.txt");
	//getline(fin, c3);
	choice=Person::selectCourses(depart, year);
	if (year == "FIRST")y = 1;
	if (year == "SECOND")y = 2;
	if (year == "THIRD")y = 3;
	if (year == "FOURTH")y = 4;
	if (choice == 'y')
	{

		fout.open("Members Details\\" + userName + " course.txt", std::fstream::in | std::fstream::out | std::fstream::app);
		for (i = 0; i < 5; i++)
		{
			//if(choice[i]==1||choice[i]==2||choice[i]==3||choice[i]==4||choice[i]==5)
			fout << depart << "-" <<y<< Person::ran[i] << "\n";
		}
		fout << "***\n";
		fout.close();
	}	
	fin1.close();
	fin2.close();
	fin3.close();

}

void Student::viewAttendence(string userName)
{
	ifstream fin1,fin2;
	int i=0;
	string course, attendence;
	fin1.open("Members Details\\" + userName + " course.txt");
	fin2.open("Members Details\\" + userName + " attendence.txt");
	ui.clearArea(45, 13, 115, 14);
	while (!fin1.eof() || !fin2.eof())
	{
		getline(fin1, course);
		getline(fin2, attendence);
		if (course == "***"||i>5) break;
		else
		{
			i++;
			ui.gotoxy(45, i + 12);
			cout << "attendence for " << course<<" is " << attendence <<" %";
		}
	}
}