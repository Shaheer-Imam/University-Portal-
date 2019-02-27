#include "UI.h"

UI::UI()
{
}

UI::~UI()
{
}

void UI:: gotoxy(int x, int y) {
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void UI:: boxOperation(char l, int height, int width, int x, int y, void(*functionPtr)(char, int, int, int, int)) {
	(*functionPtr)(l, height, width, x, y);
}

int UI:: t(void) {
	char str[50];
	time_t t;
	time(&t);
	ctime_s(str, sizeof(str), &t);
	cout<<str;
	return 0;
}

void UI:: printLine(char l, int k) {
	for (int i = 0; i<k; i++) {
		cout << l;
	}
}

void UI:: delay(unsigned int mseconds) {
	clock_t goal = mseconds + clock();
	while (goal > clock());
}

void UI:: printLineSlowly(char l, int k, int t) {
	for (int i = 0; i<k; i++) {
		delay(t);
		cout << l;
	}
}

void UI:: printSquareBox(char l, int height, int width, int x, int y) {
	if (width >= 200) {
		width = 180;
	}
	if (y >= 140) {
		y = 100;
	}
	if (height >= 80) {
		height = 70;
	}
	if (x >= 60) {
		x = 50;
	}
	gotoxy(x, y++);
	for (int i = 1; i <= height; i++) {
		for (int j = 1; j <= width; j++) {
			if (i == height || i == 1 || i == height - 1 || i == 2 || i == height - 2 || i == 3 || i == height - 3 || i == 4) {
				cout << l;
			}
			else
			{
				if (j == 1 || j == width || j == 2 || j == width - 1 || j == 3 || j == width - 2 || j == 4 || j == width - 3 || j == 5 || j == width - 4) {
					cout << l;
				}
				else {
					cout << " ";
				}
			}
		}
		cout << endl;
		gotoxy(x, y++);
	}
}

void UI:: printStringSlowly(string s, int t) {
	int len = s.length();
	for (int i = 0; i<len; i++) {
		delay(t);
		cout << s[i];
	}
}

void UI:: clearArea(int x, int y, int width, int height) {
	int x1 = x;
	for (int i = 1; i <= height; i++) {
		for (int j = 1; j <= width; j++) {
			gotoxy(x, y); cout << " ";
			x++;
		}
		x = x1;
		y++;
	}
}
