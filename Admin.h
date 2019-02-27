#pragma once
#include"Data.h"
#include"UI.h"
#include"Person.h"
#include<string>
#include<iostream>
using namespace std;
class Admin:public Person
{
private:
	Data data;
	UI ui;
public:
	Admin();
	string checkYear(string);
	void registerStudent();
	void registerTeacher();
	void viewStudent(string depart,string year);
	void setAttendence(string depart, string year);
	~Admin();
};