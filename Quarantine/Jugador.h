#pragma once
#include "Personaje.h"
#include "Mensaje.h"
ref class Jugador :
	public EntidadPersonaje
{
	ArrMensajes^mensajes;
	Direccion direccion;
public:

	Jugador(Graphics^canvas)
	{
		srand(time(NULL));
		this->canvas = canvas;
		imagen = gcnew Bitmap("imagenes\\jugador.png");
		ancho = imagen->Width / 3;
		alto = imagen->Height / 4;
		direccion = Abajo;
		x = 500;
		y = 125;
		dx = dy = 0;
		fila = columna = 0;
		mensajes = gcnew ArrMensajes(this->canvas);
	}
	void Graficar() {
		areavisible = Rectangle(ancho*columna, alto*fila, ancho, alto);
		canvas->DrawImage(imagen, x, y, areavisible, GraphicsUnit::Pixel);
		columna++;
		if (columna > 2)columna = 0;
	}
	void mover() {

		if (x + dx >= 0 && x + ancho + dx < canvas->VisibleClipBounds.Width)
			x += dx;
		if (y + dy >= 0 && y + alto + dy < canvas->VisibleClipBounds.Height)
			y += dy;
		mensajes->Mover();
	}
	void mostrarMensajes() {
		mensajes->Mostrar();

	}

	void establecerDireccionJugador(System::Windows::Forms::KeyEventArgs^tecla) {
		switch (tecla->KeyCode)
		{
		case Keys::Down: { dy = 10; fila = 0; } break;
		case Keys::Right: {dx = 10;fila = 2; }; break;
		case Keys::Left: {dx = -10;  fila = 1; }; break;
		case Keys::Up: { dy = -10; fila = 3; }; break;
		default:
			break;
		}
	}
	void neutralizarDireccionJugador(System::Windows::Forms::KeyEventArgs^tecla) {
		switch (tecla->KeyCode)
		{
		case Keys::Down: { dy = 0; fila = 0; } break;
		case Keys::Right: { dx = 0; fila = 2; }; break;
		case Keys::Left: { dx = 0; fila = 1; }; break;
		case Keys::Up: {dy = 0; fila = 3; }; break;
		default:
			break;
		}
	}
	void establecerDireccionMensaje(System::Windows::Forms::KeyEventArgs^tecla) {
		switch (tecla->KeyCode)
		{
		case Keys::Down: { direccion = Abajo; } break;
		case Keys::Right: { direccion = Derecha; }; break;
		case Keys::Left: {direccion = Izquierda; }; break;
		case Keys::Up: {direccion = Arriba; }; break;
		default:
			break;
		}
	}
	void dispararMensaje() {
			int dx = 0, dy = 0;
			if (direccion == Abajo)
				dy = 20;
			else if (direccion == Arriba)
				dy = -20;
			else if (direccion == Izquierda)
				dx = -20;
			else if (direccion == Derecha)
				dx = 20;
			Mensaje^ mensj = gcnew Mensaje(x, y, dx, dy);
			mensajes->AgregarMensaje(mensj);
	}
	ArrMensajes^ GetMensajes()
	{
		return mensajes;
	}


};

