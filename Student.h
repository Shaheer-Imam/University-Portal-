#pragma once
#include "Person.h"
#include"UI.h"
class Student :
	public Person
{
private:
	UI ui;
public:
	Student();
	void showDetails(string userName);
	void registerCourse(string userName);
	bool validate(string userName,string password);
	void viewAttendence(string userName);
	~Student();
};

