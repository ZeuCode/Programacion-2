#pragma once
#include<vector>
#include"Ave.h"
using namespace std;
class Controlador {
private:
	vector<Ave*> aves;
	int cantidadAves;
	bool go;//indica si el juego ya comenzo
	int cantidadSalvadas;
	int cantidadVenenosas;
public:
	Controlador(){
		cantidadAves = 0;
		go = false;
		cantidadSalvadas = 0;
		cantidadVenenosas = 0;
	}
	bool getGo() { return go; }
	void setGo(bool valor) { go = valor; }
	int getCantidadAves() { return cantidadAves; }
	~Controlador(){}
	void agregaAve(Image^ iAve,bool malvada) {
		if (cantidadAves < 10||malvada) {
			aves.push_back(new Ave(iAve->Width / 4, iAve->Height / 4));
			cantidadAves++;
		}
	}
	int getSalvadas() { return cantidadSalvadas; }
	int getVenenosas() { return cantidadVenenosas; }
	void mueveAves(Graphics^g) {
		for (int i = 0; i < aves.size(); i++) {
			aves[i]->mover(g);
		}
	}
	void dibujaAves(Graphics^ g, Image^ iAve) {
		for (int i = 0; i < aves.size(); i++) {
			aves[i]->dibujar(g,iAve);
		}
	}
	void dibujaUltimaAgregada(Graphics^g,Image^iAve) {
		aves[aves.size() - 1]->dibujar(g,iAve);
	}
	void click(int x,int y,Image^iAve) {
		for (int i = 0; i < aves.size(); i++) {
			if (aves[i]->getRectangle().Contains(x, y)) {
				switch (aves[i]->getTipo()) {
				case 0:
					aves[i]->setX(rand() % 800 + 50);
					aves[i]->setY(rand() % 20 + 500);
					aves[i]->setDx(0);
					aves[i]->setDy(0);
					cantidadSalvadas++;
					break;
				case 1:
					agregaAve(iAve, true);
					cantidadVenenosas++;
					break;
				}
			}
		}
	}
};