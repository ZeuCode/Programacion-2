#pragma once
#include<iostream>
using namespace std;
using namespace System;

class Vacuna {
private:
	int x, y;
	int ancho, alto;
	int color;
	int dx, dy;
	char direccion;
public:
	Vacuna() :
		ancho(2), alto(1), color(15), dx(2), dy(1), direccion('H')
	{
		x = rand() % 100 + 20;
		y = rand() % 15 + 5;

	}
	~Vacuna() {}
	int getX() { return x; }
	int getY() { return y; }
	int getAncho() { return ancho; }
	int getAlto() { return alto; }
	int getColor() { return color; }
	int getDx() { return dx; }
	int getDy() { return dy; }
	char getDireccion() { return direccion; }
	void borrarVacuna() {
		Console::SetCursorPosition(x, y);
		cout << "  ";
	}
	void imprimirVacuna() {
		Console::ForegroundColor = ConsoleColor(color);
		Console::SetCursorPosition(x, y);
		cout << (char)195 << ">";
		Console::ForegroundColor = ConsoleColor(15);
	}
	void moverVacuna() {
		if (direccion == 'H') {
			if (x + dx < 0 || x + dx + ancho>179)dx *= -1;
			x += dx;
		}
		else {
			if (y + dy < 0 || y + dy + alto>39)dy *= -1;
			y += dy;
		}
	}
	Rectangle getRectangle() {
		return Rectangle(x, y, ancho, alto);
	}

	void cambiarDireccion(int tecla) {
		switch (tecla) {
		case 72:
			// arriba
			if (direccion != 'V')direccion = 'V';
			if (dy > 0)dy *= -1;
			break;
		case 80:
			// abajo
			if (direccion != 'V')direccion = 'V';
			if (dy < 0)dy *= -1;
			break;
		case 75:
			// izquierda
			if (direccion != 'H')direccion = 'H';
			if (dx > 0)dx *= -1;
			break;
		case 77:
			// derecha
			if (direccion != 'H')direccion = 'H';
			if (dx < 0)dx *= -1;
			break;
		}
	}

};
