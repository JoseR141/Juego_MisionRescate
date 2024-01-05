#pragma once
#include <iostream>
#include <vector>
#include <time.h>
using namespace std;
using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;
using namespace System::Media;

class Entidad
{
protected:
	int x, y;
	int dx, dy;
	int ancho, alto;
	int IDx;
public:
	Entidad()  // Constructor (Inicia en 0)
	{
		x = y = 0;
		dx = dy = 0;
		ancho = alto = 0;
		IDx = 0;
	} 
	void SetDY(int value)
	{
		dy = value;
	}
	void SetDX(int value) 
	{
		dx = value;
	}
	int GetX()
	{
		return x;
	}
	int GetY()
	{
		return y;
	}
	int GetAncho()
	{
		return ancho;
	}
	int GetAlto()
	{
		return alto;
	}
	Rectangle Area() // Funcion para definir el area (Facilita el pedido de datos)
	{
		return Rectangle(x, y, ancho, alto);
	} 
	Rectangle NextArea()
	{
		return Rectangle(x + dx, y + dy, ancho, alto);
	}
	virtual Rectangle HitBox()
	{
		return Rectangle(x + ancho / 4, y + alto / 4, ancho / 2, alto / 2);
	}
	virtual void Mostrar(Graphics^ g, Bitmap^ img) // Funcion para mostrar el Bitmap de la entidad con poliformismo (Poder sobreescribirse)
	{
		g->FillRectangle(Brushes::Black, Area());
	}
	virtual void Mover(Graphics^ g)
	{
		x += dx;
		y += dy;
	}
};