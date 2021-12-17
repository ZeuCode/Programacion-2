#pragma once
#include"Fantasma.h"
#include"Pacman.h"
#include"PacDot.h"
#include"BonusVelocidad.h"
class Controladora {
private:
	PacMan* pacman;
	vector<Fantasma*> fantasmas;
	vector<PacDot*> pacdots;
	BonusVelocidad* bonusVelocidad;
	int pacdotsComidos;
	int tiempoPacman;
	int tiempoBonus;
	int tiempo;
public:
	Controladora(Bitmap^ sprite,Bitmap^pacdot,Bitmap^ velocidad,int vidas,int cFantasmas,int cPacdots) {
		tiempo = 0;
		tiempoBonus = 0;
		pacman = new PacMan(sprite->Width / 14,sprite->Height/4,vidas);
		bonusVelocidad = new BonusVelocidad(velocidad->Width/4,velocidad->Height);
		pacdotsComidos = 0;
		tiempoPacman = 0;
		for (int i = 0; i < cFantasmas; i++) {
			fantasmas.push_back(new Fantasma(sprite->Width / 14, sprite->Height / 4, rand() % 5));
		}
		for (int i = 0; i < cPacdots; i++) {
			pacdots.push_back(new PacDot(pacdot->Width,pacdot->Height));
		}
	}
	
	void dibujarTodo(Graphics^g, Bitmap^ sprite,Bitmap^pacdot,Bitmap^velocidad) {
		
		for (int i = 0; i < pacdots.size(); i++) {
			pacdots[i]->dibujar(g, pacdot);
		}
		for (int i = 0; i < fantasmas.size(); i++) {
			fantasmas[i]->dibujar(g, sprite);
		}
		bonusVelocidad->dibujar(g, velocidad);
		pacman->dibujar(g, sprite);
		
	}
	void moverTodo(Graphics^g) {
		for (int i = 0; i < fantasmas.size(); i++) {
			fantasmas[i]->mover(g);
		}
	}
	int getcantidadPacdots() { return pacdots.size(); }
	PacMan* getPacman() { return pacman; }
	void controlTiempo(Bitmap^velocidad) {
		tiempo++;
		if (tiempo-tiempoBonus>19) {
			delete bonusVelocidad;
			bonusVelocidad = nullptr;
			bonusVelocidad = new BonusVelocidad(velocidad->Width / 4, velocidad->Height);
			tiempoBonus = tiempo;
		}
		if (pacman->getVeloz()) {
			if (tiempo - tiempoPacman > 9) {
				pacman->setVeloz(false);
				pacman->divideVelocidad();
			}
		}
	}
	int getTiempo() {
		return tiempo;
	}
	void colision(Bitmap^velocidad) {
		for (int i = 0; i < fantasmas.size(); i++) {
			if (pacman->getRectangle().IntersectsWith(fantasmas[i]->getRectangle())) {
				pacman->reduceVidas();
				pacman->setX(0);
				pacman->setY(0);
			}
		}

		for (int i = 0; i < pacdots.size(); i++) {
			if (pacman->getRectangle().IntersectsWith(pacdots[i]->getRectangle())) {
				pacdots[i]->setVisible(false);
				pacdotsComidos += 1;
			}
		}
		if (pacman->getRectangle().IntersectsWith(bonusVelocidad->getRectangle())) {
			if (!pacman->getVeloz()) {
				pacman->duplicaVelocidad();
				pacman->setVeloz(true);
				tiempoPacman = tiempo;
				tiempoBonus = tiempo;
			}
			bonusVelocidad->setVisible(false);
		}
		//eliminacion
		for (int i = 0; i < pacdots.size(); i++) {
			if (!pacdots[i]->getVisible()) {
				pacdots.erase(pacdots.begin() + i);
			}
		}
		if (!bonusVelocidad->getVisible()) { 
			delete bonusVelocidad;
			bonusVelocidad = nullptr;
			bonusVelocidad = new BonusVelocidad(velocidad->Width / 4, velocidad->Height);
		}
	}
	int getPacDotsComidos() {
		return pacdotsComidos;
	}
	~Controladora(){}
};