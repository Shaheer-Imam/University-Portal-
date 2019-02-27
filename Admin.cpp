#include "Admin.h"
#include<iostream>
#include<conio.h>
#include<fstream>
using namespace std;


Admin::Admin()
{
}


Admin::~Admin()
{
}

string Admin::checkYear(string year)
{
	int i;
	for (i = 0; i <= (sizeof(year) / 8); i++)
	{
		if (Person:: years[i] == year)
			return year;
	}
	return "NOT FOUND";
}

void Admin:: registerStudent()
{
	string check;
	ui.clearArea(35, 13, 119, 15);
	ui.gotoxy(105, 16); cout << "*year:";
	ui.gotoxy(45, 17); cout << "*Board: ";
	ui.gotoxy(45, 18); cout << "*Roll no: ";
	data=Person::get();
	do {
		fflush(stdin);
		ui.gotoxy(112, 16); getline(cin, data.year);
		check = Admin::checkYear(data.year);
		if (check == "NOT FOUND")
		{
			ui.gotoxy(118, 17); cout << "Please enter correct year code";
			ui.delay(1000);
			ui.clearArea(112, 17, 40, 1);
		}
	} while (check == "NOT FOUND");
	ui.gotoxy(52, 17); getline(cin, data.board);
	ui.gotoxy(55, 18); getline(cin, data.roll_no);
	ui.clearArea(35, 13, 119, 15);
	string s, si;
	string c1, c2;

	bool tag;
	ofstream fout;
	ifstream fin;
	do {
	again:
		ui.gotoxy(45, 14); cout << "Enter a Unique Username: ";
		fflush(stdin);
		cin >> s;
		for (int i = 0; i<s.length(); i++) {
			if (s[i] == ' ') {
				ui.gotoxy(45, 15);
				cout << "Username Cannot contain a Space! Please try again without using space."; _getch();
				ui.clearArea(35, 13, 119, 15);
				goto again;
			}
		}
		fin.open("Usernames Student.txt", std::fstream::in | std::fstream::out | std::fstream::app);
		while (!fin.eof()) {
			fin >> si;
			if (si == s) {
				tag = false;
				break;
			}
			tag = true;
		}
		fin.close();
		if (tag == false) {
			ui.gotoxy(45, 15); cout << "Username is already Used. Please try a Different one.";
			_getch();
			ui.clearArea(35, 13, 119, 15);
		}
	} while (tag == false);

	fout.open("Usernames Student.txt", std::fstream::in | std::fstream::out | std::fstream::app);
	fout << s << "\n";
	fout.close();
	fout.open("Department Student.txt", std::fstream::in | std::fstream::out | std::fstream::app);
	fout << data.department << "\n";
	fout.close();
	fout.open("Year Student.txt", std::fstream::in | std::fstream::out | std::fstream::app);
	fout << data.year << "\n";
	fout.close();
	do {
		ui.gotoxy(45, 15); cout << "Enter your new Password: ";
		cin >> c1;
		if (c1.length()>15 || c1.length()<4) {
			ui.gotoxy(45, 16); cout << "Password's length should be in between 4 to 15 characters. "; _getch();
			ui.clearArea(35, 13, 119, 15);
		}
	} while (c1.length()>15 || c1.length()<4);
	do {
		ui.gotoxy(45, 16); cout << "Enter your Password again: ";
		cin >> c2;
		if (c1 != c2) {
			ui.gotoxy(45, 17); cout << "You Put wrong Password"; _getch();
			ui.clearArea(35, 13, 119, 15);
		}
	} while (c1 != c2);

	fout.open("Passwords Student.txt", std::fstream::in | std::fstream::out | std::fstream::app);
	fout << c1 << "\n";
	fout.close();
	fout.open("All Details " + data.department + "\\STUDENT\\"+data.year+"\\all details.txt", std::fstream::in | std::fstream::out | std::fstream::app);
	fout << s << "\n";
	fout << "\n" << data.name << "\'Details\n\n\nAge: " << data.age << "\nAddress: " << data.address << "\nYear: " << data.year << "\nBoard: " << data.board << "\nDepartment: " << data.department
		<< "\nRoll No: " << data.roll_no << "\nEmail : " << data.email << "\nContact: " << data.phone << "\n\n***\n\n";
	ofstream fm(("Members Details\\" + data.name + " Student.txt").c_str());
	fm << "\n" << data.name << "\'Details\n\n\nAge: " << data.age << "\nAddress: " << "\nYear: " << data.year << "\nDate of Birth : " << data.d_o_b << data.address << "\nBoard: " << data.board << "\nDepartment: " << data.department
		<< "\nRoll No: " << data.roll_no << "\nEmail : " << data.email << "\nContact: " << data.phone << "\n\n***\n\n";
	fout.close();
	fm.close();
}
void Admin::registerTeacher()
{
	string check;
	ui.clearArea(35, 13, 119, 15);
	ui.gotoxy(45, 17); cout << "*Course codes: ";
	ui.gotoxy(45, 18); cout << "*Designation: ";
	data=Person::get();
	ui.gotoxy(60, 17); getline(cin, data.courseCodes);
	ui.gotoxy(60, 18); getline(cin, data.designation);
	ui.clearArea(35, 13, 119, 15);
	string s, si;
	string c1, c2;

	bool tag;
	ofstream fout;
	ifstream fin;
	do {
	again:
		ui.gotoxy(45, 14); cout << "Enter a Unique Username: ";
		fflush(stdin);
		cin >> s;
		for (int i = 0; i<s.length(); i++) {
			if (s[i] == 32) {
				ui.gotoxy(45, 15);
				cout << "Username Cannot contain a Space! Please try again without using space."; _getch();
				ui.clearArea(35, 13, 119, 15);
				goto again;
			}
		}
		fin.open("Usernames Teacher.txt", std::fstream::in | std::fstream::out | std::fstream::app);
		while (!fin.eof()) {
			fin >> si;
			if (si == s) {
				tag = false;
				break;
			}
			tag = true;
		}
		fin.close();
		if (tag == false) {
			ui.gotoxy(45, 15); cout << "Username is already Used. Please try a Different one.";
			_getch();
			ui.clearArea(35, 13, 119, 15);
		}
	} while (tag == false);

	fout.open("Usernames Teacher.txt", std::fstream::in | std::fstream::out | std::fstream::app);
	fout << s<<"\n";
	fout.close();
	fout.open("Department Teacher.txt", std::fstream::in | std::fstream::out | std::fstream::app);
	fout << data.department << "\n";
	fout.close();
	do {
		ui.gotoxy(45, 15); cout << "Enter your new Password: ";
		cin >> c1;
		if (c1.length()>15 || c1.length()<4) {
			ui.gotoxy(45, 16); cout << "Password's length should be in between 4 to 15 characters. "; _getch();
			ui.clearArea(35, 13, 119, 15);
		}
	} while (c1.length()>15 || c1.length()<4);
	do {
		ui.gotoxy(45, 16); cout << "Enter your Password again: ";
		cin >> c2;
		if (c1 != c2) {
			ui.gotoxy(45, 17); cout << "You Put wrong Password"; _getch();
			ui.clearArea(35, 13, 119, 15);
		}
	} while (c1 != c2);

	fout.open("Passwords Teacher.txt", std::fstream::in | std::fstream::out | std::fstream::app);
	fout << c1 << "\n";
	fout.close();
	fout.open("All Details " + data.department + "\\TEACHER\\all details.txt", std::fstream::in | std::fstream::out | std::fstream::app);
	fout << s << "\n";
	fout << "\n" << data.name << "\'Details\n\n\nAge: " << data.age << "\nAddress: " << data.address  << "\nBoard: " << data.board << "\nDepartment: " << data.department
		<< "\nRoll No: " << data.roll_no << "\nEmail : " << data.email << "\nContact: " << data.phone << "\n\n***\n\n";
	ofstream fm(("Members Details\\" + data.name + " Teacher.txt").c_str());
	fm << "\n" << data.name << "\'Details\n\n\nAge: " << data.age << "\nAddress: " << "\nDate of Birth : " << data.d_o_b << data.address << "\nBoard: " << data.board << "\nDepartment: " << data.department
		<< "\nRoll No: " << data.roll_no << "\nEmail : " << data.email << "\nContact: " << data.phone << "\n\n***\n\n";
	fout.close();
	fm.close();
}
void Admin::viewStudent(string depart, string year)
{
	ui.clearArea(35, 13, 119, 15);
hello:
	string c3, c4, c5,si,su;
	string st[100];
	int i=0,j=0,k=13, tag = 0, tag1 = 0,sel;
	ifstream fin;
	fin.open("All Details " + depart + "\\STUDENT\\" + year + "\\all details.txt", std::fstream::in | std::fstream::out | std::fstream::app);
	ifstream fin1, fin2, fin3;
	fin1.open("Usernames Student.txt");
	fin2.open("Department Student.txt");
	fin3.open("Year Student.txt");
	ui.gotoxy(45, 15);
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
	ui.clearArea(35, 13, 119, 15);
	while (!fin.eof()) {
		do {
			fin >> si;
			if (si == st[sel-1]) {
				tag = 1;
				getline(fin, su);
				while (su != "***") {
					ui.gotoxy(45, ++k);
					cout << su << "\n";
					getline(fin, su);
				}
			}
			break;
		} while (si != st[sel-1]);
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
	fin1.close();
	fin2.close();
	fin3.close();
}

void Admin::setAttendence(string depart, string year)
{
	ui.clearArea(35, 13, 119, 15);
hello:
	string c3, c4, c5, si, su,at;
	string st[100];
	int i = 0, j = 0, k = 13, tag = 0, tag1 = 0, sel;
	ifstream fin;
	//fin.open("All Details " + depart + "\\STUDENT\\" + year + "\\all details.txt", std::fstream::in | std::fstream::out | std::fstream::app);
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
			fout << at<<"\n";
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