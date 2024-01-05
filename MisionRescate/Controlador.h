#pragma once
#include <fstream>
#include "Jugador.h"
#include "Petroleo.h"
#include "Mapa.h"
#include "Salvavidas.h"
#include "Animal.h"
ref class Controlador 
{
private:
	Jugador* jugador;
	Petroleos* petroleos;
	Salvavidas* salvavidas;
	Animales* animales;
	Mapa* mapa;
	Mapa* mapa1;
	Bitmap^ imgJugador;
	Bitmap^ imgSalvavidas;
	Bitmap^ imgPetroleos;
	Bitmap^ imgMapa;
	Bitmap^ imgMapa2;
	Bitmap^ imgAnimales;
	int cant;
	int agregar;
	int Delay;
	int tiempo;
	int cantanimales;
	int canta;
	int cantenemigo;
	int animalesres;
	bool resul;
	int niveles;
	int mytime;
	int situacion;

public:
	Controlador(int v, int t, int a, int n, int nivel)
	{
		imgSalvavidas = gcnew Bitmap("img/Salvavidas.png");
		imgJugador = gcnew Bitmap("img/Jugador.png");
		imgPetroleos = gcnew Bitmap("img/Petroleo.png");
		imgMapa = gcnew Bitmap("img/Mapa.png");
		imgAnimales = gcnew Bitmap("img/Animales.png");
		imgMapa2 = gcnew Bitmap("img/Mapa2.png");
		animales = new Animales();

		mapa = new Mapa(imgMapa);
		mapa1 = new Mapa(imgMapa2);
		jugador = new Jugador(imgJugador, v);
		petroleos = new Petroleos();
		salvavidas = new Salvavidas();
		cant = 0;
		cantanimales = 0;
		cantenemigo = n;
		tiempo = t * 1000;
		canta = a;
		animalesres = a;
		niveles = nivel;
		srand(time(NULL));
	}
	~Controlador()
	{
		Ranking();
		delete jugador;
		delete petroleos;
		delete salvavidas;
		delete animales;
	}
	void Input(bool accion, Keys tecla)
	{
		if (accion == true)
		{
			int v = 5; // Velocidad del jugador
			if (tecla == Keys::Up)
			{
				jugador->SetDY(-v);
				jugador->SetAccion(Arriba);
			}
			else if (tecla == Keys::Down)
			{
				jugador->SetDY(v);
				jugador->SetAccion(Abajo);
			}
			else if (tecla == Keys::Left)
			{
				jugador->SetDX(-v);
				jugador->SetAccion(Izquierda);
			}
			else if (tecla == Keys::Right)
			{
				jugador->SetDX(v);
				jugador->SetAccion(Derecha);
			}
			
		}
		else
		{
			if (tecla == Keys::Up)
			{
				jugador->SetDY(0);
			}
			else if (tecla == Keys::Down)
			{
				jugador->SetDY(0);
			}
			else if (tecla == Keys::Left)
			{
				jugador->SetDX(0);
			}
			else if (tecla == Keys::Right)
			{
				jugador->SetDX(0);
			}
		}
	}
	void mostrar_raning() {
		system("Ranking.txt");
	}
	int GetResul()
	{
		return resul;
	}
	
	void Disparo(MouseButtons boton)
	{
		int v = 8; // Velocidad del salvavidas
		if (boton == MouseButtons::Left)
		{
			if (jugador->GetAccion() == Arriba)
			{
				salvavidas->Agregar(new Salvavida(jugador->GetX() + jugador->GetAncho() / 5, jugador->GetY() + jugador->GetAlto() / 5, 0, -v));
			}
			if (jugador->GetAccion() == Abajo)
			{
				salvavidas->Agregar(new Salvavida(jugador->GetX() + jugador->GetAncho() / 5, jugador->GetY() + jugador->GetAlto() / 5, 0, v));
			}
			if (jugador->GetAccion() == Derecha)
			{
				salvavidas->Agregar(new Salvavida(jugador->GetX() + jugador->GetAncho() / 5, jugador->GetY() + jugador->GetAlto() / 5, v, 0));
			}
			if (jugador->GetAccion() == Izquierda)
			{
				salvavidas->Agregar(new Salvavida(jugador->GetX() + jugador->GetAncho() / 5, jugador->GetY() + jugador->GetAlto() / 5, -v, 0));
			}

		}

	}
	
	void Mostrar(Graphics^ g)
	{
		if (niveles == 2)
		{
			mapa1->Mostrar(g, imgMapa2);
		}
		else
		{
			mapa->Mostrar(g, imgMapa);
		}
	
		petroleos->Mostrar(g, imgPetroleos); // Dependiendo del orden se dibujara en el Form (Sobre exponiendo los objetos)
		jugador->Mostrar(g, imgJugador);
		salvavidas->Mostrar(g, imgSalvavidas);
		animales->Mostrar(g, imgAnimales);
		mytime = (((tiempo)-clock()) / 1000);
		g->DrawString("Tiempo: " + (((tiempo)- clock()) / 1000) + " segundos", gcnew Font("Gill Sans", 12), Brushes::Black, 300, 1); 
		g->DrawString("Animales rescatados: " + animales->GetCant(), gcnew Font("Gill Sans", 12), Brushes::Black, 600, 1);
	}
	
	bool Mover(Graphics^ g)
	{
		if (clock() >= tiempo)
		{
			return false;
		}
		if (clock() - agregar >= 500 && cant < cantenemigo) // Agrega cada 0.5 seg y hasta 10 Barriles de Petroleo y/o Barcos enemigos
		{
			if (rand() % 2 == 0)
			{
				petroleos->Agregar(new PetroleoMarron);
			}
			else
			{
				petroleos->Agregar(new PetroleoNegro);
			}
			cant++;
			agregar = clock();
		}
		if (canta > 0)
		{
			if (rand() % 2 == 0)
			{
				animales->Agregar(new AnimalFoca);
			}
			else
			{
				animales->Agregar(new AnimalPinguino);
			}
			canta--;
		}
		salvavidas->Mover(g);
		petroleos->Mover(g);
		animales->Mover(g);
		jugador->Mover(g);
		for (int i = 0; i < salvavidas->Size(); i++)
		{
			for (int j = 0; j < animales->Size(); j++)
			{
				Animal* a = animales->Get(j);
				salvavidas->Colision(a->Area());
				if (salvavidas->Colision(a->Area()) == true)
				{
					Salvavida* s = salvavidas->Get(i);
					salvavidas->Eliminar(a->Area());
					animales->Eliminar(a->Area());
				}
			}
		}
		if (animales->GetCant() == animalesres)
		{
			
			resul = true;
			Ranking();
			return false;
			
		}
 		if (petroleos->Colision(jugador->HitBox()) == true && clock() - Delay >= 2000)  // Colisiones
		{
			jugador->SetPosicion(10, 310);
			jugador->SetVidas(-1);
			Delay = clock();
		}
		if (jugador->GetVidas() == 0)
		{
			Ranking();
			resul = false;
			return false;
		}
		if (jugador->GetVidas() > 0)
		{
			return true;
		}
	}

	private:
		void Ranking() {
			ofstream ranking;
			ranking.open("Ranking.txt", ios::out | ios::app);
			
			if (resul == false)
			{
				ranking << "Tiempo: " << mytime << "\tVidas: " << jugador->GetVidas() << "\tAnimales rescatados: " << animales->GetCant() << "\tNivel: " << niveles << "\tResultado: PERDISTE con: 0 Puntos" << endl;
			}
			if (resul == true)

			{
				ranking << "Tiempo: " << mytime << "\tVidas: " << jugador->GetVidas() << "\tAnimales rescatados: " << animales->GetCant() << "\tNivel: " << niveles << "\tResultado: GANASTE con: " << (mytime * jugador->GetVidas() + (animales->GetCant() * niveles)) << " Puntos" << endl;
			}
			
			ranking.close();
		}
		
};