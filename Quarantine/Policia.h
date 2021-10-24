#pragma once
#include "Personaje.h"
using namespace System;

ref class Policia :
	public EntidadPersonaje
{
	Direccion direccion;
public:
	Policia(Graphics^canvas) {
		srand(time(NULL));
		this->canvas = canvas;
		imagen = gcnew Bitmap("imagenes\\policia.png");
		ancho = imagen->Width / 3;
		alto = imagen->Height / 4;
		direccion = Abajo;
		x = RANDOM(0, 1000);
		y = RANDOM(0, 700);
		dx = dy = 7;
		fila = columna = 0;
	}

	void Graficar() {
		areavisible = Rectangle(ancho*columna, alto*fila, ancho, alto);
		canvas->DrawImage(imagen, x, y, areavisible, GraphicsUnit::Pixel);
		columna++;
		if (columna > 2)columna = 0;
	}
	void Mover(Direccion direccion) {
		switch (direccion)
		{
		case Arriba:
			if (y - dy > 0) { y -= dy; }
			fila = 3;
			break;
		case Abajo:
			if (y + alto + dy < canvas->VisibleClipBounds.Bottom) { y += dy; }
			fila = 0;
			break;
		case Izquierda:
			if (x - dx > 0) { x -= dx; }
			fila = 1;
			break;
		case Derecha:
			if (x + ancho + dx < canvas->VisibleClipBounds.Right) { x += dx; }
			fila = 2;
			break;
		default:
			break;
		}
	}

};

