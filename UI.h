#pragma once
#include<string>
#include<iostream>
#include<Windows.h>
#include<ctime>

using namespace std;

class UI
{
public:
	void gotoxy(int, int);
	void boxOperation(char l, int height, int width, int x, int y, void(*functionPtr)(char, int, int, int, int));
	int t(void);
	void printLine(char, int);
	void delay(unsigned int);
	void printLineSlowly(char, int, int);
	void printSquareBox(char, int, int, int, int);
	void printStringSlowly(string, int);
	void clearArea(int, int, int, int);
	UI();
	~UI();
};

