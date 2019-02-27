#include "Date.h"
#include<string>
#include<iostream>
using namespace std;




/********************************************************* DATE CLASS FUNCTIONS **********************************************************/
Date::Date() :day(0), month(0), year(0), LetterDay("none") {
}
Date::~Date() {

}
void Date::setDay(int n) {
	if (n<1 || n>31) {
		day = 0;
	}
	else {
		day = n;
	}
}
void Date::setMonth(int n) {
	if (n<1 || n>12) {
		month = 0;
	}
	else {
		month = n;
	}
}
void Date::setYear(int n) {
	if (n<0) {
		year = 0;
	}
	else {
		year = n;
	}
}
void Date::setLetterDay(string n) {
	LetterDay = n;
}
int Date::getDay()const {
	return day;
}
int Date::getMonth()const {
	return month;
}
int Date::getYear()const {
	return year;
}
string Date::getLetterDay()const {
	return LetterDay;
}
ostream& operator<< (ostream& os, const Date& l) {
	os << l.day << "-" << l.month << "-" << l.year;
	return os;
}

