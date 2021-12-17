#pragma once
#include<iostream>
#include"Elemento.h"
using namespace System::Drawing;
class Personaje:public Elemento {
protected:
	int dx, dy;
	int indiceX, indiceY;
public:
	Personaje(int ancho, int alto) {
		this->ancho = ancho;
		this->alto = alto;
		aumento = 1.2;
		visible = true;
	}
	~Personaje() {}
	
	void dibujar(Graphics^ g, Bitmap^ image) {
		Rectangle porcion = Rectangle(indiceX * ancho, indiceY * alto, ancho, alto);
		Rectangle zoom = Rectangle(x, y, ancho * aumento, alto * aumento);
		g->DrawImage(image, zoom, porcion, GraphicsUnit::Pixel);
	}
};