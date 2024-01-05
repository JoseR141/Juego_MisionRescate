#pragma once
#include "Entidad.h"

class Salvavida : public Entidad
{
public:
	Salvavida(int x, int y, int dx, int dy)
	{
		this->x = x;
		this->y = y;
		this->dx = dx;
		this->dy = dy;
		ancho = alto = 60;
	}
	void Mostrar(Graphics^ g, Bitmap^ img)
	{
		Rectangle corte = Rectangle(0, 0, ancho, alto);
		g->DrawImage(img, Area(), corte, GraphicsUnit::Pixel);
		//g->DrawRectangle(gcnew Pen(Color::Black), HitBox());
	}
	Rectangle HitBox() {
		return Rectangle(x+15, y+12, ancho/2, alto/2);
	}
};

class Salvavidas
{
public:
	vector<Salvavida*> salvavidas;

	~Salvavidas()
	{
		for (int i = 0; i < salvavidas.size(); i++)
		{
			delete salvavidas.at(i);
		}
	}
	void Agregar(Salvavida* salvavida)
	{
		salvavidas.push_back(salvavida);
	}
	bool Eliminar(Rectangle rect)
	{
		
		return false;
	}
	int Size()
	{
		return salvavidas.size();
	}
	Salvavida* Get(int pos)
	{
		return salvavidas[pos];
	}
	bool Colision(Rectangle obj)
	{
		for each (Salvavida * s in salvavidas)
			if (s->HitBox().IntersectsWith(obj))
			{
				return true;
			}
		return false;
	}
	void Mover(Graphics^ g)
	{
		for each (Salvavida * s in salvavidas)
			s->Mover(g);
		
	}

	void Mostrar(Graphics^ g, Bitmap^ img)
	{
		for each (Salvavida * s in salvavidas)
			s->Mostrar(g, img);
	}
};