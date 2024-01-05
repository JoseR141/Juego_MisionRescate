#pragma once
#include "Entidad.h"

enum TAnimales
{
	Pinguino,
	Foca
};
class Animal : public Entidad
{
protected:
	TAnimales color;
public:
	Animal()
	{
		ancho = 60; // Divisor del Sprite
		alto = 60; // Divisor del Sprite// Falta ancho y alto
	}
	virtual Rectangle HitBox() = 0;

	void Mostrar(Graphics^ g, Bitmap^ img)
	{
		Rectangle corte = Rectangle(IDx * ancho, color * alto, ancho, alto);
		g->DrawImage(img, Area(), corte, GraphicsUnit::Pixel);
		// g->DrawRectangle(Pens::Black, HitBox());
	}
};

class AnimalPinguino : public Animal
{
public:
	AnimalPinguino()
	{

		x = rand() % 700;
		y = rand() % 700;
		dx = 0;
		color = Pinguino;
	}
	void Mover(Graphics^ g)
	{
		if (!(x + dx >= 0 && x + ancho + dx < g->VisibleClipBounds.Width)) // Validar movimiento dentro del Form
		{
			dx *= -1;  // Invierte posicion en X
		}
		x += dx;
	}
	Rectangle HitBox() {
		return Rectangle(x+12, y+10, ancho/2, alto/2);
	}
};

class AnimalFoca : public Animal
{
public:
	AnimalFoca()
	{
		x = rand() % 700;
		y = rand() % 700;
		dy = 0;
		color = Foca;
	}
	
	void Mover(Graphics^ g)
	{
		if (!(y + dy >= 0 && y + alto + dy < g->VisibleClipBounds.Height))
		{
			dy *= -1;
		}
		y += dy;
	}
	Rectangle HitBox() {
		return Rectangle(x+8, y+10, ancho-20, alto-20);
	}
};
class Animales
{
	int cant;
private:
	vector<Animal*> animales;
public:
	
	~Animales()
	{
		for each (Animal * A in animales)
			delete A;
	}
	int Eliminar(Rectangle rect)
	{
		for (int i = 0; i < animales.size(); i++)
		{
			if (animales[i]->HitBox().IntersectsWith(rect))
			{
				animales.erase(animales.begin() + i--);
				cant++;
			}
		}
		return cant;
	}
	Animal* Get(int pos)
	{
		return animales[pos];
	}
	int GetCant()
	{
		return cant;
	}
	int Size()
	{
		return animales.size();
	}
	bool Colision(Rectangle obj)
	{
		for each (Animal * ani in animales)
			if (ani->HitBox().IntersectsWith(obj))
			{
				return true;
			}
		return false;
	}
	void Agregar(Animal* animal)
	{
		animales.push_back(animal);
	}
	void Mover(Graphics^ g)
	{
		for each (Animal * A in animales)
			A->Mover(g);
	}
	void Mostrar(Graphics^ g, Bitmap^ img)
	{
		for each (Animal * A in animales)
			A->Mostrar(g, img);
	}
};
