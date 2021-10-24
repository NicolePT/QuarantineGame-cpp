#pragma once
#include "Personaje.h"
ref class ObstaculosAdversario2 :public EntidadPersonaje
{
	array<EntidadPersonaje^>^obstaculos;
public:
	ObstaculosAdversario2()
	{
		obstaculos = gcnew array<EntidadPersonaje^>(8);
		for (int i = 0; i < 8; ++i) {
			obstaculos[i] = gcnew EntidadPersonaje();
		}
		crearObstaculos();
	}
	void mostrarObstaculosAdversarios(Graphics^canvas) {
		for (short i = 0; i < 8; i++) {
			canvas->FillRectangle(Brushes::Green, obstaculos[i]->Area());
		}
	}
	void crearObstaculos() {
		obstaculos[0]->SetData(550, 0, 88, 130);
		obstaculos[1]->SetData(815, 0, 120, 130);
		obstaculos[2]->SetData(410, 295, 215, 85);
		obstaculos[3]->SetData(805, 295, 110, 120);
		obstaculos[4]->SetData(805, 510, 110, 120);
		obstaculos[5]->SetData(955, 515, 110, 120);
		obstaculos[6]->SetData(1100, 305, 170, 75);
		obstaculos[7]->SetData(20, 405, 100, 225);

	}
	EntidadPersonaje^ recuperarObstaculo(short i) {
		return obstaculos[i];
	}

};

