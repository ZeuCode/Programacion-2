#pragma once
#include<iostream>
#include"PacDot.h"
using namespace System::Drawing;
class BonusVelocidad :public PacDot{
private:
	int indiceX;
public:
	BonusVelocidad(int ancho,int alto):PacDot(ancho,alto){
		x = rand() % 700 + 40;
		y = rand() % 350 + 40;
		visible = true;
		aumento = 1;
		indiceX = rand() % 4;
	}
	~BonusVelocidad(){}
	void dibujar(Graphics^ g, Bitmap^ image) {
		Rectangle porcion = Rectangle(indiceX*ancho, 0, ancho, alto);
		Rectangle zoom = Rectangle(x, y, ancho * aumento, alto * aumento);
		g->DrawImage(image, zoom, porcion, GraphicsUnit::Pixel);
	}
};