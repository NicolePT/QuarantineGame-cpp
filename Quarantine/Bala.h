#pragma once
#include "Personaje.h"
#include <cmath>
#include "ArrAdversario.h"

ref class Bala : public EntidadPersonaje {
public:	
	Bala(int x, int y, int fx, int fy) {
		this->x = x;
		this->y = y;
		fx += 32;
		fy += 32;
		imagen = gcnew Bitmap("imagenes\\Bala.png");
		ancho = imagen->Width / 16;
		alto = imagen->Height / 16;
		fila = 7;
		columna = 8;
		double V = 10;
		double c1 = fx - x;
		double c2 = fy - y;
		double h = sqrt(c1*c1 + c2*c2);
		double C = V / h;
		dx = c1 * C;
		dy = c2 * C;
	}
	void Graficar(Graphics^ canvas) {
		areavisible = Rectangle(ancho*columna, alto*fila, ancho, alto);
		canvas->DrawImage(imagen, x, y, areavisible, GraphicsUnit::Pixel);
	}
	void Mover() {

		x += dx;
		y += dy;
	}
};
ref class ArrBala { 
private:
	array<Bala^>^balas;
	Graphics^canvas;
	int cant;
public:
	ArrBala(Graphics^canvas)
	{
		this->canvas = canvas;
		balas = gcnew array<Bala^>(300);
		cant = 0;
	}
	~ArrBala()
	{

		delete balas;
	}

	void AgregarBala(Bala^ nuevo)
	{
		balas[cant] = nuevo;
		cant++;
		
	}

	void EliminarBala(int pos)
	{
		for (int i = pos; i < cant-1; i++)
		{
			balas[i] = balas[i + 1];
		}
		cant--;
	}
	Bala^ GetBala(int pos)
	{
		return balas[pos];
	}
	int GetCantidad()
	{
		return cant;
	}

	void Mover()
	{
		for (int i = 0; i < cant; i++)
		{
			Bala^ msj = balas[i];
			if (msj->GetX() >= canvas->VisibleClipBounds.Width || msj->GetX() + msj->GetAncho() < 0 || msj->GetY() >= canvas->VisibleClipBounds.Height || msj->GetY() + msj->GetAlto() < 0)
				EliminarBala(i--);

		}

		for (int i = 0; i < cant; i++)
			balas[i]->Mover();
	}
	void Mostrar()
	{
		for (int i = 0; i < cant; i++)
			balas[i]->Graficar(canvas);
	}
};
