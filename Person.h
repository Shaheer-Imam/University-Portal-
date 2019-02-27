#pragma once
#include"Data.h"
#include"UI.h"
#include<string>
#include<iostream>
using namespace std;

class Person
{
private:
	UI ui;
	Data data;
public:
	int ran[5] = { 73,51,23,31,91 };
	string departs[5] = { "ME","CSIT","SE","EE","CIS" };
	string years[4] = { "FIRST","SECOND","THIRD","FOURTH" };
	Person();
	Data get();
	string checkDepart(string);
	char selectCourses(string depart,string year);
	~Person();
};

