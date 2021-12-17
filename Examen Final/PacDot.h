#pragma once
#include<iostream>
#include"Elemento.h"
using namespace System::Drawing;
class PacDot :public Elemento{
private:
public:
	PacDot(int ancho,int alto){
		this->alto = alto;
		this->ancho = ancho;
		x = rand() % 800 + 40;
		y = rand() % 400 + 40;
		visible = true;
		aumento = 1.2;
	}
	~PacDot(){}
	void dibujar(Graphics^ g, Bitmap^ image) {
		Rectangle porcion = Rectangle(0, 0, ancho, alto);
		Rectangle zoom = Rectangle(x, y, ancho * aumento, alto * aumento);
		g->DrawImage(image, zoom, porcion, GraphicsUnit::Pixel);
	}
};