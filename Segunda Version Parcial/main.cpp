#include<iostream>
#include<conio.h>
#include"Controller.h"
using namespace std;

int main() {
	//TODO
	Console::SetWindowSize(180, 40);
	Console::CursorVisible = false;
	srand(time(NULL));
	int marca = 0;
	int descarte;
	int tecla;
	Controller* controller = new Controller();
	controller->dibujarTodo();
	while (!controller->getGameOver()) {
		if (controller->getCantidadVirus() < 20) {
			controller->aumentarContador();
			if (controller->getContador() - marca > 50) {
				controller->agregarVirus();
				marca = controller->getContador();
			}
		}
		else {
			controller->aumentarContador();
			if (controller->getContador() - marca > 20) {
				controller->cambiarPosDeltas();
				marca = controller->getContador();
			}
		}
		if (_kbhit()) {
			descarte = _getch();
			if (descarte == 224) {
				tecla = _getch();
				controller->getVacuna()->cambiarDireccion(tecla);
			}
		}
		controller->colision();
		controller->moverTodo();
		_sleep(70);
	}
	controller->borrarTodo();
	controller->imprimeMensajeFinal();
	delete controller;
	system("pause>nul");
	return 0;
}