#pragma once
#include "Personaje.h"
#include "ObstaculosAdversarios1.h"
#include "ObstaculosAdversarios2.h"
#include "Bala.h"
using namespace System::Windows::Forms;
using namespace System::Drawing;
using namespace System;
ref class Adversario : public EntidadPersonaje {
	short tipoAsintoSaludable;
	ObstaculosAdversario1^obsAdversario1;
	ObstaculosAdversario2^obsAdversario2;
	short tipodistrito;
	short personaje;
	bool verde;
	bool rojo;
	ArrBala^ bala;
	int contadorBala;
	Random r;
	int posXju;
	int posYju;
	bool unico;
	bool izquierda;
	bool derecha;
	bool arriba;
	bool abajo;
	bool choque;
public:
	Adversario(Graphics^canvas, short tipodistrito) {
		srand(time(NULL));
		this->canvas = canvas;
		this->tipodistrito = tipodistrito;
		izquierda = derecha = arriba = abajo = false;
		unico = true;
		bala = gcnew ArrBala(canvas);
		contadorBala = 0;
		posXju = posYju = 0;
		tipoAsintoSaludable = RANDOM(1, 2);
		personaje = RANDOM(1, 4);
		verde = false;
		rojo = false;
		switch (personaje)
		{
		case 1: imagen = gcnew Bitmap("imagenes\\A1.png"); break;
		case 2: imagen = gcnew Bitmap("imagenes\\A2.png"); break;
		case 3: imagen = gcnew Bitmap("imagenes\\A3.png"); break;
		case 4: imagen = gcnew Bitmap("imagenes\\A4.png"); break;
		default:
			break;
		}
		ancho = imagen->Width / 3;
		alto = imagen->Height / 4;
		if (this->tipodistrito == 1) {
			if (tipoAsintoSaludable == 2) {
				x = RANDOM(665,910);
				y = RANDOM(290,625);
			}
			else if (tipoAsintoSaludable == 1) {
				x = RANDOM(140,1072);
				y = RANDOM(140,260);
			}
		}
		else if (this->tipodistrito == 2) {
			if (tipoAsintoSaludable == 2) {
				x = RANDOM(295, 625);
				y = RANDOM(520, 700);
			}
			else if (tipoAsintoSaludable == 1) {
				x = RANDOM(20, 300);
				y = RANDOM(20, 400);
			}
		}
		dx = dy = 6;
		fila = columna = 0;
		obsAdversario1 = gcnew ObstaculosAdversario1();
		obsAdversario2 = gcnew ObstaculosAdversario2();
	}

	void Graficar(bool dificil) {
		if (dificil) mostrarBalas();
		areavisible = Rectangle(ancho*columna, alto*fila, ancho, alto);
		canvas->DrawImage(imagen, x, y, areavisible, GraphicsUnit::Pixel);
		columna++;
		if (columna > 2)columna = 0;
	}
	void mostrarBalas() {
		bala->Mostrar();

	}
	void moverAutoX() {
		if(tipodistrito==2){
			if (tipoAsintoSaludable == 2) {
				if (x + dx <284 || x + ancho > 643) {
					dx = dx* -1;
				}
			}
			else {
				if (x + dx <0 || x + ancho > canvas->VisibleClipBounds.Right) {
					dx = dx* -1;
				}
			}
			if (ColisionAdversarioObstaculoDistrito2() == true) {
				dx *= -1;
			}
		}	
		if (tipodistrito == 1) {
			if (tipoAsintoSaludable == 2) {
				if (x + dx <652 || x + ancho > 933) {
					dx = dx* -1;
				}
			}
			else {
				if (x + dx <0 || x + ancho > canvas->VisibleClipBounds.Right) {
					dx = dx* -1;
				}
			}
			if (ColisionAdversarioObstaculoDistrito1() == true ) {
				dx *= -1;
			}
		}

		if (dx > 0) fila = 2;
		if (dx < 0) fila = 1;

		x += dx;
	}
	void moverAutoY() {
		if (tipodistrito == 2) {
			if (tipoAsintoSaludable == 2) {
				if (y + dy < 515 || y + alto + dy > canvas->VisibleClipBounds.Bottom) {
					dy *= -1;
				}
			} else {
				if (y + dy < 0 || y + alto + dy > canvas->VisibleClipBounds.Bottom) {
					dy *= -1;
				}
			}
			if (ColisionAdversarioObstaculoDistrito2()) {
				dy *= -1;
			}

		}
		else if (tipodistrito == 1) {
			if (tipoAsintoSaludable == 2) {
				if (y + dy < 284 || y + alto + dy > 636) {
					dy *= -1;
				}
			}
			else {
				if (y + dy < 0 || y + alto + dy > canvas->VisibleClipBounds.Bottom) {
					dy *= -1;
				}
			}
			if (ColisionAdversarioObstaculoDistrito1() == true ) {
				dy *= -1;

			}
		}
		if (dy > 0) fila = 0;
		if (dy < 0) fila = 3;
		y += dy;
	}
	bool ColisionAdversarioObstaculoDistrito1() {
		for (int i = 0; i < 14; i++) {
			if (obsAdversario1->recuperarObstaculo(i)->Area().IntersectsWith(this->Area()))
			{
				return true;
			}
		}
		return false;
	}
	bool ColisionAdversarioObstaculoDistrito2(){
		for (int i = 0; i < 8; i++) {
			if (obsAdversario2->recuperarObstaculo(i)->Area().IntersectsWith(this->Area()))
			{
				return true;
			}
		}
		return false;
	}
	void moverAutomatico(bool dificil, short opcion, int x, int y) {
		if (dificil) {
			if (rand()%100 == 0)
				dispararBala(x, y);
			bala->Mover();
		}
		if (opcion == 1 || opcion == 6 || opcion == 11||opcion==16) {
			moverAutoX();
		}
		else moverAutoY();
	}
	short getTipoAsintomaticoSaludable() {
		return tipoAsintoSaludable;
	}
	void cambiarColorPersonaje() {
		switch (tipoAsintoSaludable)
		{
		case 1: {
			switch (personaje)
			{
			case 1: imagen = gcnew Bitmap("imagenes\\A1rojo.png"); break;
			case 2: imagen = gcnew Bitmap("imagenes\\A2rojo.png"); break;
			case 3: imagen = gcnew Bitmap("imagenes\\A3rojo.png"); break;
			case 4: imagen = gcnew Bitmap("imagenes\\A4rojo.png"); break;
			}
			rojo = true;
			; break; }
		case 2: {
			switch (personaje)
			{
			case 1: imagen = gcnew Bitmap("imagenes\\A1verde.png"); break;
			case 2: imagen = gcnew Bitmap("imagenes\\A2verde.png"); break;
			case 3: imagen = gcnew Bitmap("imagenes\\A3verde.png"); break;
			case 4: imagen = gcnew Bitmap("imagenes\\A4verde.png"); break;
			}
			verde = true;
			; break; }
		default:
			break;
		}
		ancho = imagen->Width / 3;
		alto = imagen->Height / 4;
	}
	bool preguntarCambiodeColorVerde() {
		return verde;
	}
	bool preguntarCambiodeColorRojo() {
		return rojo;
	}

	void dispararBala(int x, int y) {

		bala->AgregarBala(gcnew Bala(this->x,this->y,x,y));

	}

	ArrBala^ GetBalas() {
		return bala;
	}
};
