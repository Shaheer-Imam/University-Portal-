#include<string>
#include<iostream>
#include"UI.h"
#include<conio.h>
#include"Admin.h"
#include"Student.h"
#include"Teacher.h"

using namespace std;

UI ui;
Admin admin;
Student st;
Teacher teach;

const char* entry = "FCIT";
const char* admin1 = "Imam";
const char* admin2 = "Akram";
const char* admin3 = "Qadir";
const char* admin4 = "Asad";


void menu();
void menuAdmin();
string selectDepartment();
string selectYear();
void adminPassword();
bool password(string);
void menuStudent();
void menuTeacher();
void login();
void exit_menu();


int main()
{
	system("mode con: cols=200 lines=80");
	HWND hWnd = GetConsoleWindow();
	ShowWindow(hWnd, SW_SHOWMAXIMIZED);
	ui.gotoxy(70, 2);
	cout << "Starting Time Of Program";
	ui.gotoxy(70, 4);
	ui.t();
	menu();
	system("pause");
}

void menu()
{
	ui.printSquareBox('|', 30, 160, 5, 7);
	ui.gotoxy(25, 12); ui.printLineSlowly('|', 49, 5);
	ui.gotoxy(74, 12); ui.printStringSlowly("WELCOME TO NED PORTAL", 5);
	ui.gotoxy(95, 12); ui.printLineSlowly('|', 49, 5);
	ui.gotoxy(45, 14); cout << "1. FOR STUDENTS";
	ui.gotoxy(45, 15); cout << "2. FOR TEACHER";
	ui.gotoxy(45, 16); cout << "3. FOR ADMIN";
	ui.gotoxy(45, 17); cout << "4. EXIT ";
	ui.gotoxy(45, 19); cout << "ENTER CHOICE: ";
	char ch='z';
	ch = _getch();
	switch (ch)
	{
	case '1':
		menuStudent();
		break;
	case '2':
		menuTeacher();
		break;
	case '3':
		adminPassword();
		break;
	case '4':
		exit(0);
		break;
	default:
		ui.gotoxy(57, 20); cout << "WRONG ENTRY. ";
		getchar();
		menu();
	}

}

void adminPassword()
{
	ui.printSquareBox('|', 30, 160, 5, 7);
	ui.gotoxy(25, 12); ui.printLineSlowly('|', 49, 5);
	ui.gotoxy(78, 12); ui.printStringSlowly("ADMIN SECTION", 5);
	ui.gotoxy(95, 12); ui.printLineSlowly('|', 49, 5);
	password("ENTER PASSWORD TO UNLOCK DETAILS (OFFICE USE) : ");
	ui.gotoxy(45, 13); cout << "Press any key to Start or Backspace to go Back";
	menuAdmin();
}

void menuAdmin()
{
	char choice='z';
	string depart,year;
	ui.clearArea(35, 13, 119, 15);
	ui.gotoxy(45, 14); cout << "1. REGISTER STUDENT";
	ui.gotoxy(45, 15); cout << "2. REGISTER TEACHER";
	ui.gotoxy(45, 16); cout << "3. VIEW STUDENT INFO";
	ui.gotoxy(45, 17); cout << "4. Set Atendence";
	ui.gotoxy(45, 18); cout << "5. EXIT";
	ui.gotoxy(45, 19); cout << "backspace to go back ";
	ui.gotoxy(45, 21); cout << "ENTER CHOICE: ";
	choice = _getch();
	switch (choice)
	{
	case '1':
		admin.registerStudent();
		menuAdmin();
		break;
	case '2':
		admin.registerTeacher();
		menuAdmin();
		break;
	case '3':
		depart = selectDepartment();
		year = selectYear();
		admin.viewStudent(depart, year);
		break;
	case '4':
		depart = selectDepartment();
		year = selectYear();
		admin.setAttendence(depart, year);
		break;
	case'5':
		exit_menu();
		break;
	case 8:
		menu();
		break;
	default:
		cout << "wrong choice";
		ui.delay(7);
		menuAdmin();
		break;
	}
}
bool password(string s) {

	char ch='z', incrementer = 'A';
	int i = 0;
	char* pass = new char[20];
	ui.gotoxy(60, 13); cout << "                                            ";
	ui.gotoxy(45, 16); cout << "                                                                   ";
	ui.gotoxy(45, 13);
	string str = s;
	cout << s;
	ch = _getch();
	while (ch != 13) {
		if (ch == 8) {
			if (i != 0) {
				cout << "\b \b";
				i--;
			}
		}
		if (ch != 13 && ch != 8) {
			pass[i] = ch;
			_putch('*');
			i++;
		}
		ch = _getch();
	}
	pass[i] = '\0';
	if (str == "ENTER PASSWORD: ") {
		if (strcmp(pass, entry) == 0) {
			ui.gotoxy(45, 16);
			cout << "CORRECT PASSWORD.";
			ui.gotoxy(45, 17);
			cout << "Press Any Key To Continue.";
			_getch();
			return true;
		}
		else {
			ui.gotoxy(45, 16);
			cout << "WRONG PASSWORD. ";
			ch = _getch();
			if (ch == 27) {
				exit_menu();
			}
			password(s);
		}
	}
	else {
		if (strcmp(pass, admin1) == 0 || strcmp(pass, admin2) == 0 || strcmp(pass, admin3) == 0 || strcmp(pass, admin4) == 0) {
			login();
			ui.gotoxy(35, 16);
			cout << "ACCESSED TO Mr. " << pass;
			ui.gotoxy(45, 17);
			cout << "Press Any Key To Continue.";
			_getch();
			return true;
		}
		else {
			login();
			ui.gotoxy(45, 16);
			cout << "INVALID USERNAME. If You are not an Employee Please Press Backspace.";
			ch = _getch();
			if (ch == 8) {
				menu();
			}
			else if (ch == 27) {
				exit_menu();
			}
			password(s);
		}
	}
}

void menuStudent()
{
	string userName, pass;
	ui.printSquareBox('|', 30, 160, 5, 7);
	ui.gotoxy(25, 12); ui.printLineSlowly('|', 49, 5);
	ui.gotoxy(78, 12); ui.printStringSlowly("STUDENT SECTION", 5);
	ui.gotoxy(95, 12); ui.printLineSlowly('|', 49, 5);
	ui.gotoxy(45, 14); cout << "ENTER USER NAME: ";
	ui.gotoxy(45, 15); cout << "ENTER PASSWORD: ";
	ui.gotoxy(64, 14); getline(cin, userName);
	ui.gotoxy(63, 15); getline(cin, pass);
	if (st.validate(userName, pass) == true)
	{
		char choice='z';
		ui.clearArea(35, 13, 119, 15);
		ui.gotoxy(45, 14); cout << "1. VIEW INFO";
		ui.gotoxy(45, 15); cout << "2. VIEW ATTENDENCE";
		ui.gotoxy(45, 16); cout << "3. VIEW MARKS";
		ui.gotoxy(45, 17); cout << "4. Register Course";
		ui.gotoxy(45, 18); cout << "5. EXIT";
		ui.gotoxy(45, 19); cout << "backspace to go back ";
		ui.gotoxy(45, 21); cout << "ENTER CHOICE: ";
		choice = _getch();
		switch (choice)
		{
		case '1':
			st.showDetails(userName);
			menuStudent();
			break;
		case '2':
			st.viewAttendence(userName);
			menuStudent();
			break;
		case '3':
			break;
		case '4':
			st.registerCourse(userName);
			menuStudent();
			break;
		case '5':
			exit_menu();
			break;
		case 8:
			menuStudent();
			break;
		default:
			cout << "wrong choice";
			ui.delay(7);
			menuStudent();
			break;
		}
	}
	else
	{
		char ch='z';
		ui.clearArea(35, 13, 119, 15);
		ui.gotoxy(45, 14); cout << "Wrong user name or password";
		ui.gotoxy(45, 16); cout << "Press backspace to go back or any key to try again";
		ch=_getch();
		if (ch == 8)
			menu();
		menuStudent();
	}
}

void menuTeacher()
{
	string year;
	string userName, pass;
	ui.printSquareBox('|', 30, 160, 5, 7);
	ui.gotoxy(25, 12); ui.printLineSlowly('|', 49, 5);
	ui.gotoxy(78, 12); ui.printStringSlowly("TEACHER SECTION", 5);
	ui.gotoxy(95, 12); ui.printLineSlowly('|', 49, 5);
	ui.gotoxy(45, 14); cout << "ENTER USER NAME: ";
	ui.gotoxy(45, 15); cout << "ENTER PASSWORD: ";
	ui.gotoxy(64, 14); getline(cin, userName);
	ui.gotoxy(63, 15); getline(cin, pass);
	if (teach.validate(userName, pass) == true)
	{
		char choice = 'z';
		ui.clearArea(35, 13, 119, 15);
		ui.gotoxy(45, 14); cout << "1. VIEW MY INFO";
		ui.gotoxy(45, 15); cout << "2. SET STUDENT ATTENDENCE";
		ui.gotoxy(45, 16); cout << "3. SET STUDENT MARKS";
		ui.gotoxy(45, 17); cout << "4. EXIT";
		ui.gotoxy(45, 18); cout << "backspace to go back ";
		ui.gotoxy(45, 20); cout << "ENTER CHOICE: ";
		choice = _getch();
		switch (choice)
		{
		case '1':
			teach.showDetails(userName);
			menuTeacher();
			break;
		case '2':
			year = selectYear();
			teach.setAttendence(year, userName);
			break;
		case '3':
			break;
		case '4':
			exit(0);
			break;
		case 8:
			menuTeacher();
			break;
		default:
			cout << "wrong choice";
			ui.delay(7);
			menuTeacher();
			break;
		}
	}
	else
	{
		char ch = 'z';
		ui.clearArea(35, 13, 119, 15);
		ui.gotoxy(45, 14); cout << "Wrong user name or password";
		ui.gotoxy(45, 16); cout << "Press backspace to go back or any key to try again";
		ch = _getch();
		if (ch == 8)
			menu();
		menuTeacher();
	}
}

string selectDepartment()
{
	char choice = 'z';
	ui.clearArea(35, 13, 119, 15);
	ui.gotoxy(45, 14); cout << "1. Mechenical Engineering";
	ui.gotoxy(45, 15); cout << "2. Computer Science & Information Technology";
	ui.gotoxy(45, 16); cout << "3. Software Engineering";
	ui.gotoxy(45, 17); cout << "4. Electrical Engineering";
	ui.gotoxy(45, 18); cout << "5. Computer Systems & Information Engineering";
	ui.gotoxy(45, 19); cout << "press backspace to go back";
	ui.gotoxy(45, 21); cout << "ENTER CHOICE: ";
	choice = _getch();
	switch (choice)
	{
	case '1':
		return "ME";
		break;
	case '2':
		return "CSIT";
		break;
	case '3':
		return "SE";
		break;
	case '4':
		return "EE";
		break;
	case '5':
		return "CIS";
		break;
	case 8:
		menuAdmin();
		break;
	default:
		cout << "wrong choice";
		ui.delay(7);
		selectDepartment();
		break;
	}
}

string selectYear()
{
	char choice = 'z';
	ui.clearArea(35, 13, 119, 15);
	ui.gotoxy(45, 14); cout << "1. FIRST";
	ui.gotoxy(45, 15); cout << "2. SECOND";
	ui.gotoxy(45, 16); cout << "3. THIRD";
	ui.gotoxy(45, 17); cout << "4. FOURTH";
	ui.gotoxy(45, 18); cout << "press backspace to go back";
	ui.gotoxy(45, 20); cout << "ENTER CHOICE: ";
	choice = _getch();
	switch (choice)
	{
	case '1':
		return "FIRST";
		break;
	case '2':
		return "SECOND";
		break;
	case '3':
		return "THIRD";
		break;
	case '4':
		return "FOURTH";
		break;
	case 8:
		selectDepartment();
		break;
	default:
		cout << "wrong choice";
		ui.delay(7);
		selectYear();
		break;
	}
}

void login() {
	ui.clearArea(35, 13, 119, 15);
	ui.gotoxy(75, 16); ui.printStringSlowly("LOGGING IN", 5);
	for (int i = 1; i <= 2; i++) {
		ui.gotoxy(96, 16); cout << "      ";
		ui.gotoxy(96, 16); ui.printLineSlowly('.', 6, 300);
	}
}

void exit_menu() {
	ui.clearArea(0, 0, 200, 50);
	Sleep(4000);
	ui.gotoxy(85, 9);
	cout << "UNTIL WE MEET AGAIN !";
	exit(0);
}
