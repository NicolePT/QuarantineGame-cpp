#pragma once
#include "Personaje.h"
using namespace System;
ref class Ambulancia : public EntidadPersonaje {
	bool arriba, abajo, izquierda, derecha;
	Random r;

	public:
	Ambulancia(Graphics^ canvas) {
		this->canvas = canvas;
		imagen = gcnew Bitmap("imagenes\\Ambulancia1.png");
		ancho = imagen->Width / 3;
		alto = imagen->Height / 4;
		x = 0;
		y = 160;
		fila = columna = 0;
		contador = 0;
		inversaD = inversaAb = inversaAr = inversaI = true;
		contador = 0;
		unico = true;
		ro = rt = rtr = rf = 0;
		arriba = abajo = izquierda = derecha = false;
	}
	void Graficar() {
		areavisible = Rectangle(ancho*columna, alto*fila, ancho, alto);
		if (unico) {
			ro = r.Next(1, 3);
			switch (1) {
			case 1:derecha = true;
			case 2:izquierda = true;
			}
			unico = false;
		}

		if (x == 160) {
			if (y == 0) {
				if (arriba = true) {
					abajo = true; arriba = izquierda = derecha = false;
				}
			}
			if (y == 160) {
				if (derecha == true) {
					arriba = true; abajo = izquierda = derecha = false;
				}
				if (abajo == true && inversaAb == true) {
					derecha = true; arriba = abajo = izquierda = false;
				}
			}
			if (y == 420) {
				if (izquierda) {
					abajo = true; izquierda = false;
				}
				if (arriba) {
					derecha = true; arriba = false;
				}
			}
			if (y == 670) {
				arriba = true; abajo = false;
			}

		}

		if (x == 0 && y == 160) {
			derecha = true; arriba = abajo = izquierda = false;

		}

		if (x == 665) {
			if (y == 0) {
				abajo = true; izquierda = derecha = arriba = false;
			}
			if (y == 160) {
				if (derecha == true) {
					abajo = true; izquierda = arriba = derecha = false;

				}
				if (izquierda == true) {

					izquierda = true; abajo = arriba = derecha = false;
				}

				if (arriba) {
					derecha = true; abajo = arriba = izquierda = false;
				}
			}
			if (y == 670) {
				if (abajo) {
					derecha = true; abajo = izquierda = arriba = false;
				}
				if (izquierda) {
					arriba = true; abajo = derecha = izquierda = false;
				}
			}
			if (y == 420) {
				if (abajo) {
					izquierda = true;  abajo = false;
				}
				if (derecha) {
					abajo = true; derecha = false;
				}
			}
		}


		if (x == 1000) {
			if (y == 670) {
				izquierda = true; derecha = false;
			}
			if (y == 160) {
				izquierda = true; derecha = false;
			}

		}
		//-14 ->Y

		if (arriba) {
			caminarArriba();
		}
		else if (abajo) {
			caminarAbajo();
		}
		else if (izquierda) {
			caminarIzquierda();
		}
		else if (derecha) {
			caminarDerecha();
		}
	}
	void caminarDerecha() {

		if (x <= 1000) { fila = 2; x += 5; }
		canvas->DrawImage(imagen, x, y, areavisible, GraphicsUnit::Pixel);
		columna++;
		if (columna > 2) { columna = 0; }




	}
	void caminarIzquierda() {

		if (x >= 0) { fila = 1; x -= 5; }
		canvas->DrawImage(imagen, x, y, areavisible, GraphicsUnit::Pixel);
		columna++;
		if (columna > 2) { columna = 0; }




	}
	void caminarAbajo() {

		if (y <= 710) { fila = 0; y += 5; }
		canvas->DrawImage(imagen, x, y, areavisible, GraphicsUnit::Pixel);
		columna++;
		if (columna > 2) { columna = 0; }

	}
	void caminarArriba() {

		if (y >= 0) { fila = 3; y -= 5; }
		canvas->DrawImage(imagen, x, y, areavisible, GraphicsUnit::Pixel);
		columna++;
		if (columna > 2) { columna = 0; }

	}
};