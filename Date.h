#pragma once
#include"Date.h"
#include<string>
#include<iostream>
using namespace std;
class Date {

	int day, month, year;
	string LetterDay;
public:
	Date();
	void setDay(int);
	void setMonth(int);
	void setYear(int);
	void setLetterDay(string);
	int getDay()const;
	int getMonth()const;
	int getYear()const;
	string getLetterDay()const;
	friend ostream& operator << (ostream &, const Date&);
	//DESTRUCTOR
	~Date();
};


