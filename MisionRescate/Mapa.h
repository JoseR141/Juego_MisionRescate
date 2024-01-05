#pragma once
#include "Entidad.h"
class Mapa : public Entidad
{
	int time;
public:
	Mapa(Bitmap^ img)
	{
		x = 0; // Iniciar posicion en X
		y = 0; // Iniciar posicion en Y
		ancho = 800; // Divisor del Sprite
		alto = 800; // Divisor del Sprite
	}

	void Mostrar(Graphics^ g, Bitmap^ img)
	{
		Rectangle corte = Rectangle(IDx * ancho, 0, ancho, alto); // Crear rectangulo para cortarlo 
		g->DrawImage(img, Area(), corte, GraphicsUnit::Pixel);

		if (clock() - time >= 500) // dx != 0 || dy != 0 Si se desea solo movimiento al moverse en x o y
		{
			IDx = (IDx + 1) % 2;
			time = clock();
		}
	}
};