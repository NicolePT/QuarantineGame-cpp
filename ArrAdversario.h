#pragma once
#include "Adversario.h"
ref class ArrAdversario
{
	array<Adversario^>^adversarios;
	Graphics^canvas;
	short cant;
	short total;
	short contA;
public:
	ArrAdversario(Graphics^lienzo)
	{
		canvas = lienzo;
		total = RANDOM(5, 10);
		cant = 0;
		contA = 0;
		adversarios = gcnew array<Adversario^>(cant);
	}

	~ArrAdversario()
	{
	}
	void AgregarAdversario(Adversario^ nuevo)
	{
		if (contA < total) {
			array<Adversario^>^aux = gcnew array<Adversario^>(cant + 1);
			for (int i = 0; i < cant; i++)
				aux[i] = adversarios[i];

			aux[cant] = nuevo;

			cant++;
			contA++;
			adversarios = aux;
		}
	}
	void graficarAdversarios(bool dificil) {
		for (int i = 0; i < cant; ++i) {
			adversarios[i]->Graficar(dificil);
		}
		
	}
	void moverAdversarios(bool dificil, int x, int y) {
		for (int i = 0; i < cant; ++i) {
			adversarios[i]->moverAutomatico(dificil,RANDOM(1, 20), x, y);
		}
	}
	short getCant() {
		return cant;
	}
	short getTotal() {
		return total;
	}
	Adversario^ getAdversario (short pos) {
		return adversarios[pos];
	}
	void EliminarAdversario(short pos) {
		array<Adversario^>^aux = gcnew array<Adversario^>(cant - 1);
		for (int i = 0; i < pos; ++i) {
			aux[i] = adversarios[i];
		}
		for (int j = pos; j < cant - 1; ++j) {
			aux[j] = adversarios[j + 1];
		}
		delete adversarios[pos];
		cant--;
		adversarios = aux;
	}
};
