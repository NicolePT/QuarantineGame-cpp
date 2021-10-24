#pragma once
#include "Personaje.h"

ref class Mensaje : public EntidadPersonaje
{
	int tipo;
public:
	Mensaje( int x, int y, int dx, int dy)
	{
		srand(time(NULL));
		this->x = x;
		this->y = y;
		this->dx = dx;
		this->dy = dy;
		ancho = alto = 0;
		tipo = RANDOM(1, 2);
		if (tipo == 1) {
			imagen = gcnew Bitmap("imagenes/mensaje1.png");
		} else 	imagen = gcnew Bitmap("imagenes/mensaje2.png");
		ancho = imagen->Width / 8;
		alto = imagen->Height;
		columna = 0;
	}
	void graficar(Graphics^ canvas)
	{
		areavisible = Rectangle(ancho*columna, 0, ancho, alto);
		canvas->DrawImage(imagen, x, y, areavisible, GraphicsUnit::Pixel);
		columna++;
		if (columna > 7)columna = 0;
	}
	void mover() {
		x += dx;
		y += dy;
	}

};

ref class ArrMensajes
{
private:
	array<Mensaje^>^mensajes;
	Graphics^canvas;
	int cant;
public:
	ArrMensajes(Graphics^canvas)
	{
		this->canvas = canvas;
		mensajes = gcnew array<Mensaje^>(300);
		cant = 0;
	}
	~ArrMensajes()
	{
		
		delete mensajes;
	}

	void AgregarMensaje(Mensaje^ nuevo)
	{
		mensajes[cant] = nuevo;
		cant++;

	}

	void EliminarMensaje(int pos)
	{
		for (int i = pos; i < cant - 1; ++i) {
			mensajes[i] = mensajes[i + 1];
		}
		cant--;
	}
	Mensaje^ GetMensaje(int pos)
	{
		return mensajes[pos];
	}
	int GetCantidad()
	{
		return cant;
	}

	void Mover( )
	{
		for (int i = 0; i < cant; i++)
		{
			Mensaje^ msj = mensajes[i];
			if ( msj->GetX() >= canvas->VisibleClipBounds.Width || msj->GetX() + msj->GetAncho() < 0 || msj->GetY() >= canvas->VisibleClipBounds.Height || msj->GetY() + msj->GetAlto() < 0)
				 EliminarMensaje(i--);

		}

		for (int i = 0; i < cant; i++)
			mensajes[i]->mover();
	}
	void Mostrar()
	{
		for (int i = 0; i < cant; i++)
			mensajes[i]->graficar(canvas);
	}
};