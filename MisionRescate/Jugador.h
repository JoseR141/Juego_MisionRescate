#pragma once
#include "Entidad.h"
#include <time.h>
#include <stdlib.h>
enum SpriteJugador // Enumerador de Sprites (Dependiendo de la cantidad de animaciones)
{
	Arriba,
	Izquierda,
	Abajo,
	Derecha
};

class Jugador : public Entidad
{
	SpriteJugador accion;
	int vidas;
public:
	Jugador(Bitmap^ img, int v)
	{
		x = 10;  // Iniciar posicion en X
		y = 310; // Iniciar posicion en Y
		dx = dy = 0; // Movimiento
		ancho = img->Width / 4; // Divisor del Sprite
		alto = img->Height / 4; // Divisor del Sprite
		accion = Derecha;
		vidas = v;
	}
	SpriteJugador GetAccion()
	{
		return accion;
	}
	void SetPosicion(int value1, int value2)
	{
		x = value1;
		y = value2;
	}
	void SetVidas(int value)
	{
		vidas += value;
	}
	int GetVidas()
	{
		return vidas;
	}
	void SetAccion(SpriteJugador value)
	{
		if (accion != value)
		{
			IDx = 0;
		}
		accion = value;
	}
	void Mover(Graphics^ g)
	{
		if (x + dx >= 0 && x + ancho + dx < g->VisibleClipBounds.Width) // Validar movimiento dentro del Form
		{
			x += dx;
		}
		if (y + dy >= 0 && y + alto + dy < g->VisibleClipBounds.Height)
		{
			y += dy;
		}
	}
	void Mostrar(Graphics^ g, Bitmap^ img)
	{
		Rectangle corte = Rectangle(IDx * ancho, accion * alto, ancho, alto); // Crear rectangulo para cortarlo 
		g->DrawImage(img, Area(), corte, GraphicsUnit::Pixel);
		g->DrawString("Vidas: " + vidas, gcnew Font("Arial", 14), Brushes::Black, 1, 1);
		//g->DrawRectangle(gcnew Pen(Color::Black), HitBox());
		if (true) // dx != 0 || dy != 0 Si se desea solo movimiento al moverse en x o y
		{
			IDx = (IDx + 1) % 4;
		}
	}
	Rectangle HitBox() {
		return Rectangle(x+20, y+20, (ancho/2)+3, alto / 2);
	}
};