#pragma once
#include"Monigote.h"
#include"Virus.h"
#include"Vacuna.h"
class Controller {
private:
	Virus** virus;
	Vacuna* vacuna;
	Monigote** monigotes;
	int cantidadVirus;
	int cantidadMonigotes;
	int contador;
	int eliminadosPorDelta;
	int salvados;
	bool gameOver;
public:

	Controller() {
		gameOver = false;
		salvados = 0;
		eliminadosPorDelta = 0;
		contador = 0;
		cantidadVirus = 0;
		virus = nullptr;
		cantidadMonigotes = 15;
		vacuna = new Vacuna();
		monigotes = new Monigote * [cantidadMonigotes];
		for (int i = 0; i < cantidadMonigotes; i++) {
			monigotes[i] = new Monigote();
		}
	}
	bool getGameOver() { return gameOver; }
	int getCantidadMonigotes() { return  cantidadMonigotes; }

	void aumentarContador() { contador += 1; }
	int getContador() { return contador; }
	int getCantidadVirus() { return cantidadVirus; }
	void agregarVirus() {
		Virus** aux = new Virus * [cantidadVirus + 1];
		for (int i = 0; i < cantidadVirus; i++) {
			aux[i] = virus[i];
		}
		//los pares seran Delta y los impares seran MU
		if (cantidadVirus % 2 == 0)aux[cantidadVirus] = new Delta();
		else aux[cantidadVirus] = new MU();
		if (virus != nullptr)delete[] virus;
		virus = aux;
		cantidadVirus += 1;
	}
	void moverTodo() {
		for (int i = 0; i < cantidadMonigotes; i++) {
			if (monigotes[i]->getColor() == 4) {
				monigotes[i]->dibujar();
			}
			else {
				monigotes[i]->borrar();
				monigotes[i]->mover();
				monigotes[i]->dibujar();
			}
		}
		for (int i = 0; i < cantidadVirus; i++) {
			virus[i]->borrar();
			virus[i]->mover();
			virus[i]->dibujar();
		}

		vacuna->borrarVacuna();
		vacuna->moverVacuna();
		vacuna->imprimirVacuna();
	}
	Vacuna* getVacuna() {
		return vacuna;
	}
	void dibujarTodo() {
		for (int i = 0; i < cantidadMonigotes; i++) {
			monigotes[i]->dibujar();
		}
		for (int i = 0; i < cantidadVirus; i++) {
			virus[i]->dibujar();
		}
		vacuna->imprimirVacuna();
	}


	void borrarTodo() {
		for (int i = 0; i < cantidadMonigotes; i++) {
			monigotes[i]->borrar();
		}
		for (int i = 0; i < cantidadVirus; i++) {
			virus[i]->borrar();
		}
		vacuna->borrarVacuna();
	}
	void eliminarMonigote(int pos) {
		Monigote** aux = new Monigote * [cantidadMonigotes - 1];
		for (int i = 0; i < cantidadMonigotes - 1; i++) {
			if (i < pos)aux[i] = monigotes[i];
			else aux[i] = monigotes[i + 1];
		}
		monigotes[pos]->borrar();
		delete monigotes[pos];
		delete[] monigotes;
		monigotes = aux;
		cantidadMonigotes -= 1;

	}
	void colision() {
		for (int i = 0; i < cantidadMonigotes; i++) {
			for (int j = 0; j < cantidadVirus; j++) {
				if (monigotes[i]->getRectangle().IntersectsWith(virus[j]->getRectangle())) {
					if (j % 2 == 0) {//Delta
						if (monigotes[i]->getColor() == 15) {
							monigotes[i]->setColor(4);
							virus[j]->borrar();
							virus[j]->setX(rand() % 150 + 5);
							virus[j]->setY(rand() % 30 + 5);
						}
						else {
							//wliminar monigote y contado como muerto por delta
							eliminarMonigote(i);
							eliminadosPorDelta += 1;
							break;
						}
					}
					else {//MU
						if (monigotes[i]->getColor() == 15) {
							monigotes[i]->setColor(2);
							virus[j]->borrar();
							virus[j]->setX(rand() % 150 + 5);
							virus[j]->setY(rand() % 30 + 5);
						}
						else if (monigotes[i]->getColor() == 2) {
							eliminarMonigote(i);
							break;
						}
					}
				}
			}
		}


		for (int i = 0; i < cantidadMonigotes; i++) {
			if (vacuna->getRectangle().IntersectsWith(monigotes[i]->getRectangle())) {
				if (monigotes[i]->getColor() == 15) {
					eliminarMonigote(i);
					salvados += 1;
				}
				else {
					monigotes[i]->setColor(15);
					monigotes[i]->borrar();
					monigotes[i]->setX(rand() % 100 + 5);
					monigotes[i]->setY(rand() % 20 + 5);
				}
			}
		}

		for (int i = 0; i < cantidadVirus; i++) {
			if (vacuna->getRectangle().IntersectsWith(virus[i]->getRectangle())) {
				gameOver = true;
				break;
			}
		}
	}
	void cambiarPosDeltas() {
		int pos;
		do {
			pos = rand() % 20;
		} while (pos % 2 != 0);
		virus[pos]->borrar();
		virus[pos]->setX(rand() % 160 + 2);
		virus[pos]->setY(rand() % 25 + 2);
	}
	void imprimeMensajeFinal() {
		Console::ForegroundColor = ConsoleColor::DarkYellow;
		Console::SetCursorPosition(20, 20);
		cout << "Cantidad de monigotes que fueron eliminados por la variante Delta: " << eliminadosPorDelta << endl;
		Console::SetCursorPosition(20, 22);
		cout << "Cantidad de monigotes que fueron salvados por la vacuna: " << salvados << endl;
	}
	~Controller() {
		for (int i = 0; i < cantidadMonigotes; i++) {
			delete monigotes[i];
		}
		delete[] monigotes;
		for (int i = 0; i < cantidadVirus; i++) {
			delete virus[i];
		}
		delete[] virus;

	}
};