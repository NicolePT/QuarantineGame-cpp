#pragma once
#pragma once
#include "Personaje.h"
ref class ObstaculosEscenario1 :public EntidadPersonaje
{
	array<EntidadPersonaje^>^obstaculos;
public:
	ObstaculosEscenario1()
	{
		obstaculos = gcnew array<EntidadPersonaje^>(14);
		for (int i = 0; i < 14; ++i) {
			obstaculos[i] = gcnew EntidadPersonaje();
		}
		crearObstaculos();
	}
	void mostrarObstaculos(Graphics^canvas) {
		for (short i = 0; i < 14; i++) {
			canvas->FillRectangle(Brushes::Green, obstaculos[i]->Area());
		}
	}
	void crearObstaculos() {
		obstaculos[0]->SetData(0, 0, 138, 120);
		obstaculos[1]->SetData(180, 0, 62, 120);
		obstaculos[2]->SetData(284, 0, 350, 120);
		obstaculos[3]->SetData(680, 0, 62, 120);
		obstaculos[4]->SetData(785, 0, 280, 120);
		obstaculos[5]->SetData(1105, 0, 72, 590);
		obstaculos[6]->SetData(0, 162, 590, 60);
		obstaculos[7]->SetData(655, 162, 460, 60);
		obstaculos[8]->SetData(0, 264, 138, 350);
		obstaculos[9]->SetData(284, 264, 778, 350);
		obstaculos[10]->SetData(0, 656,1184, 50);
		obstaculos[11]->SetData(180, 255, 62, 10);
		obstaculos[12]->SetData(180, 325, 62, 225);
		obstaculos[13]->SetData(180, 640, 62, 10);
	}
	EntidadPersonaje^ recuperarObstaculo(short i) {
		return obstaculos[i];
	}

};

