#pragma once
#include<iostream>
using namespace std;
using namespace System;
using namespace System::Drawing;
class Monigote {
private:
	int x, y;
	int dx, dy;
	int color;
	int ancho, alto;
public:
	Monigote(){
		x = rand() % 160 + 5;
		y = rand() % 35 + 2;
		dx = rand() % 2 + 1;
		dy = 1;
		color = 15;
		ancho = 1;
		alto = 2;
	}
	void setX(int _x) { x = _x; }
	void setY(int _y) { y = _y; }
	void setColor(int _color) { color = _color; }
	int getColor() { return color; }
	void dibujar() {
		Console::ForegroundColor = ConsoleColor(color);
		Console::SetCursorPosition(x, y);
		cout << "O";
		Console::SetCursorPosition(x, y+1);
		cout << (char)197;
		Console::ForegroundColor = ConsoleColor(15);
	}
	void borrar() {
		Console::SetCursorPosition(x, y);
		cout << " ";
		Console::SetCursorPosition(x, y+1);
		cout << " ";
	}
	void mover() {
		if (x + dx < 0 || x + dx + ancho>175)dx *= -1;
		if (y + dy < 0 || y + dy + alto>39)dy *= -1;
		x += dx;
		y += dy;
	}
	Rectangle getRectangle() {
		return Rectangle(x, y, ancho, alto);
	}
	~Monigote(){}
};