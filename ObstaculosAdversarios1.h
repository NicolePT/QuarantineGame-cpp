#pragma once
#pragma once
#include "Personaje.h"
ref class ObstaculosAdversario1 :public EntidadPersonaje
{
	array<EntidadPersonaje^>^obstaculos;
public:
	ObstaculosAdversario1()
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
		obstaculos[0]->SetData(37, 20, 80, 100);
		obstaculos[1]->SetData(307, 20, 80, 100);
		obstaculos[2]->SetData(425, 20, 80, 100);
		obstaculos[3]->SetData(545, 20, 80, 100);
		obstaculos[4]->SetData(816, 20, 80, 100);
		obstaculos[5]->SetData(36, 308, 80, 100);
		obstaculos[6]->SetData(305, 309, 80, 100);
		obstaculos[7]->SetData(425, 308, 80, 100);
		obstaculos[8]->SetData(545,308, 80, 100);
		obstaculos[9]->SetData(35, 512, 80, 100);
		obstaculos[10]->SetData(305, 512, 80, 100);
		obstaculos[11]->SetData(425, 512, 80, 100);
		obstaculos[12]->SetData(545, 512, 80, 100);
		obstaculos[13]->SetData(958, 300, 80, 220);
	}
	EntidadPersonaje^ recuperarObstaculo(short i) {
		return obstaculos[i];
	}

};

