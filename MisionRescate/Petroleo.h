#pragma once
#include "Entidad.h"

enum Charcos
{
	Negro,
	Marron
};
class Petroleo : public Entidad
{
protected:
	Charcos color;
public:
	Petroleo()
	{
		ancho = 60; // Divisor del Sprite
		alto = 60; // Divisor del Sprite// Falta ancho y alto
	}
	void Mostrar(Graphics^ g, Bitmap^ img)
	{
		Rectangle corte = Rectangle(IDx * ancho, color * alto, ancho, alto);
		g->DrawImage(img, Area(), corte, GraphicsUnit::Pixel);
		// g->DrawRectangle(Pens::Black, HitBox());
	}
};

class PetroleoNegro : public Petroleo
{
public:
	PetroleoNegro() 
	{
		
		x = 700;
		y = rand() % 700;
		dx = rand() % 15 - 8;
		color = Negro;
	}
	void Mover(Graphics^ g)
	{
		if (!(x + dx >= 0 && x + ancho + dx < g->VisibleClipBounds.Width)) // Validar movimiento dentro del Form
		{
			dx *= -1;  // Invierte posicion en X
		}
		x += dx;
	}
};

class PetroleoMarron : public Petroleo 
{
public:
	PetroleoMarron()
	{
		x = rand() % 400;
		y = 15;
		dy = rand() % 8 - 5;
		color = Marron;
	}
	void Mover(Graphics^ g)
	{
		if (!(y + dy >= 0 && y + alto + dy < g->VisibleClipBounds.Height))
		{
			dy *= -1;
		}
		y += dy;
	}
};
class Petroleos
{
private:
	vector<Petroleo*> petroleos;
public:
	~Petroleos()
	{
		for each (Petroleo * P in petroleos)
			delete P;
	}
	bool Colision(Rectangle obj)
	{
		for each (Petroleo * obs in petroleos)
			if (obs->HitBox().IntersectsWith(obj))
			{
				return true;
			}
			
		return false;
	}
	void Agregar(Petroleo* petroleo)
	{
		petroleos.push_back(petroleo);
	}
	void Mover(Graphics^ g)
	{
		for each (Petroleo * P in petroleos)
			P->Mover(g);
	}
	void Mostrar(Graphics^ g, Bitmap^ img)
	{
		for each (Petroleo * P in petroleos)
			P->Mostrar(g, img);
	}
};