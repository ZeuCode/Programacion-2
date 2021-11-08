#pragma once
#include<iostream>
using namespace System::Drawing;
class Ave {
protected:
	int x, y;
	int dx, dy;
	int ancho, alto;
	int idx, idy;
	int aumento;
	int tipo;
	int tipoMovimiento;
public:
	Ave(int ancho, int alto) {
		int tipos[] = { 0,1,0,1,1,1 };//0: tipo en extincion
		//1: venenosas
		//lo hago asi para que hayan mas aves venenosas que en extincion
		this->ancho = ancho;
		this->alto = alto;
		dx = dy = rand() % 10 + 5;
		aumento = 1;
		tipo = tipos[rand() % 6];
		idy = 0;
		idx = 1;
		x = rand() % 800 + 50;
		y = rand() % 200 + 20;
		tipoMovimiento = rand() % 3;//0: solo en x,1: solo en y,2: en x y y
	}
	~Ave() {}
	void dibujar(Graphics^ g, Image^ image) {
		Rectangle porcion = Rectangle(idx * ancho, idy * ancho, ancho, alto);
		Rectangle zoom = Rectangle(x, y, ancho * aumento, alto * aumento);
		g->DrawImage(image, zoom, porcion, GraphicsUnit::Pixel);
	}
	int getTipo() { return tipo; }
	void mover(Graphics^ g) {
		switch (tipoMovimiento) {
		case 0:
			if (x + ancho * aumento > g->VisibleClipBounds.Width || x < 0)dx *= -1;
			x += dx;
			if (dx > 0)idy = 2;
			else idy = 1;
			break;
		case 1:
			if (y + alto * aumento > g->VisibleClipBounds.Height * 3 / (float)4 || y < 0)dy *= -1;
			y += dy;
			if (dy > 0)idy = 0;
			else idy = 3;
			break;
		case 2:
			if (x + ancho * aumento > g->VisibleClipBounds.Width || x < 0)dx *= -1;
			x += dx;
			
			if (y + alto * aumento > g->VisibleClipBounds.Height * 3 / (float)4 || y < 0)dy *= -1;
			y += dy;
			if (dx > 0)idy = 2;
			else idy = 1;
			if (dy > 0)idy = 0;
			else idy = 3;
			break;
		}
		
		idx++;
		if (idx > 3)idx = 0;
	}
	Rectangle getRectangle() {
		return Rectangle(x, y, ancho * aumento, alto * aumento);
	}
	void setX(int x) { this->x = x; }
	void setY(int y) { this->y = y; }
	void setDx(int n) { dx = n; }
	void setDy(int n) { dy = n; }
};

//*aumento* (3 / 4)