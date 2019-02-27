#pragma once
#include "Person.h"
#include"UI.h"
#include<string>
#include<iostream>
#include<conio.h>
#include<fstream>
using namespace std;

class Teacher :
	public Person
{
private:
	UI ui;
public:
	Teacher();
	void showDetails(string userName);
	bool validate(string userName, string password);
	void setAttendence(string year,string userName);
	~Teacher();
};

