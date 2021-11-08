#pragma once
#include<iostream>
using namespace std;
using namespace System;
using namespace System::Drawing;

class Virus {

protected:
	int x, y;
	int color;
	int ancho, alto;
public:
	Virus(int color) {
		x = rand() % 120 + 5;
		y = rand() % 25 + 2;
		this->color = color;
		ancho = 9;
		alto = 5;
	}
	void dibujar() {
		Console::ForegroundColor = ConsoleColor(color);
		Console::SetCursorPosition(x, y);
		cout << "    q    ";
		Console::SetCursorPosition(x, y + 1);
		cout << " o.-o-.o ";
		Console::SetCursorPosition(x, y + 2);
		cout << "o-(ooo)-o";
		Console::SetCursorPosition(x, y + 3);
		cout << " o.-o-.o ";
		Console::SetCursorPosition(x, y + 4);
		cout << "    b    ";
		Console::ForegroundColor = ConsoleColor(15);
	}
	void borrar() {
		Console::SetCursorPosition(x, y);
		cout << "         ";
		Console::SetCursorPosition(x, y + 1);
		cout << "         ";
		Console::SetCursorPosition(x, y + 2);
		cout << "         ";
		Console::SetCursorPosition(x, y + 3);
		cout << "         ";
		Console::SetCursorPosition(x, y + 4);
		cout << "         ";
	}
	virtual void mover() {

	}
	virtual void setX(int _x){}
	virtual void setY(int _y){}
	Rectangle getRectangle() {
		return Rectangle(x, y, ancho, alto);
	}
	~Virus() {}
};

class Delta :public Virus {
private:
	int dy;
public:
	Delta() :Virus(4) {
		dy = rand() % 2 + 1;
	}
	~Delta() {}
	void setX(int _x) { x = _x; }
	void setY(int _y) { y = _y; }
	void mover() {
		if (y + dy < 0 || y + dy + alto>39)dy *= -1;
		y += dy;
	}
};
class MU :public Virus {
private:
	int dx;
public:
	MU() :Virus(2) {
		dx = rand() % 2 + 1;
	}
	void mover() {
		if (x + dx < 0 || x + dx + ancho>175)dx *= -1;
		x += dx;
	}
	void setX(int _x) { x = _x; }
	void setY(int _y) { y = _y; }
	~MU() {}
};