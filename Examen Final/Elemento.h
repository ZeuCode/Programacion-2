#pragma once
using namespace System::Drawing;
class Elemento {
protected:
	int x, y;
	int ancho, alto;
	float aumento;
	bool visible;
public:
	Elemento(){}
	~Elemento(){}
	bool getVisible() { return visible; }
	void setVisible(bool visible) { this->visible = visible; }
	Rectangle getRectangle() {
		return Rectangle(x, y, ancho * aumento, alto * aumento);
	}
};