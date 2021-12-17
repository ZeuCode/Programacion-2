#pragma once
#include"Personaje.h"
class Fantasma :public Personaje {
private:
	int id;//propiedad para cambiar el fantasma del sprite que se muestra
public:
	Fantasma(int ancho, int alto,int id) :Personaje(ancho, alto)
	{
		this->id = id;
		x = rand() % 500;
		y = rand() % 200;
		indiceX = 2*id;
		indiceY = 0;
		dx = dy = rand() % 5 + 5;
	}
	void mover(Graphics^ g) {
		if (x<0 || x + ancho>g->VisibleClipBounds.Width)dx *= -1;
		x += dx;
		if (dx < 0)indiceY = 2;
		else indiceY = 0;
		if (y<0 || y + alto>g->VisibleClipBounds.Height)dy *= -1;
		y += dy;
		if (dy < 0)indiceY = 3;
		else indiceY = 1;
		indiceX++;
		if (indiceX > (2*id)+1)indiceX = 2*id;

	}
	~Fantasma() {}
};