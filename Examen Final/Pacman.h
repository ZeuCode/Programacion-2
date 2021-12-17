#pragma once
#include<vector>
#include"Personaje.h"
using namespace std;
class PacMan :public Personaje {
private:
	int vidas;
	bool veloz;
public:
	PacMan(int ancho, int alto,int vidas) :Personaje(ancho, alto)
	{
		x = 0;
		y = 0;
		indiceX = 10;
		indiceY = 0;
		this->vidas = vidas;//de un txt
		dx = dy = 5;
		veloz = false;
	}
	bool getVeloz() { return veloz; }
	void setVeloz(bool veloz) { this->veloz = veloz; }
	int getVidas() { return vidas; }
	void reduceVidas() { vidas--; }
	void setX(int x) { this->x = x; }
	void setY(int y) { this->y = y; }
	void mover(char direccion,Graphics^ g) {
		switch (direccion) {
		case 'A':
			if (x-dx > 0) {
				x -= dx;
				indiceY = 2;
			}
			break;
		case 'W':
			if (y-dy > 0) {
				y -= dy;
				indiceY = 3;
			}
			break;
		case 'D':
			if (x+ancho+dx < g->VisibleClipBounds.Width) {
				x += dx;
				indiceY = 0;
			}
			break;
		case 'S':
			if (y +alto+dy< g->VisibleClipBounds.Height) {
				y += dy;
				indiceY = 1;
			}
			break;
		}
		indiceX++;
		if (indiceX > 11)indiceX = 10;
	}
	void duplicaVelocidad() { 
		dx *= 2;
		dy *= 2;
	}
	void divideVelocidad() {
		dx /= 2;
		dy /= 2;
	}
	~PacMan() {}
};