#pragma once
#include "Personaje.h"
ref class ObstaculosEscenario2:public EntidadPersonaje
{
	array<EntidadPersonaje^>^obstaculos;
public:
	ObstaculosEscenario2()
	{
		obstaculos = gcnew array<EntidadPersonaje^>(22);
		for (int i = 0; i < 22; ++i) {
			obstaculos[i] = gcnew EntidadPersonaje();
		}
		crearObstaculos();
	}

	void crearObstaculos() {
		obstaculos[0]->SetData(0, 0, 138, 120);
		obstaculos[1]->SetData(180, 0, 62, 120);
		obstaculos[2]->SetData(284, 0, 360, 120);
		obstaculos[3]->SetData(686, 0, 62, 120);
		obstaculos[4]->SetData(790, 0, 283, 120);
		obstaculos[5]->SetData(1115, 0, 72, 120);
		obstaculos[6]->SetData(0, 162, 590, 60);
		obstaculos[7]->SetData(655, 162, 120, 60);
		obstaculos[8]->SetData(837, 162, 350, 60);
		obstaculos[9]->SetData(0, 264, 643, 110);
		obstaculos[10]->SetData(686, 222, 62, 400);
		obstaculos[11]->SetData(790, 264, 397, 110);
		obstaculos[12]->SetData(0, 370, 138, 255);
		obstaculos[13]->SetData(180, 413, 62, 210);
		obstaculos[14]->SetData(0, 665, 242, 53);
		obstaculos[15]->SetData(242, 413, 348, 62);
		obstaculos[16]->SetData(284, 515, 359, 420);
		obstaculos[17]->SetData(790, 370, 283, 255);
		obstaculos[18]->SetData(686, 665, 335, 60);
		obstaculos[19]->SetData(1115, 413, 70, 660);
		obstaculos[20]->SetData(655, 413, 20, 62);
		obstaculos[21]->SetData(1085, 665, 20, 62);
	}
	EntidadPersonaje^ recuperarObstaculo(short i) {
		return obstaculos[i];
	}

};

