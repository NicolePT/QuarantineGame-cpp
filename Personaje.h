#pragma once
using namespace System::Drawing;
using namespace System::Windows;
using namespace System::Windows::Forms;
#include <cstdlib>
#include <ctime>
enum Direccion { Arriba, Abajo, Izquierda, Derecha };

#define RANDOM(INI,FIN)	INI+rand()%(FIN+1-INI)
ref class EntidadPersonaje
{
protected:
	int x, y;
	int dx, dy;
	int ancho, alto;
	int fila, columna;
	bool cambioColor;
	int contador;
	bool dificultad;
	Rectangle areavisible;
	Bitmap ^imagen;
	Bitmap ^imagenColor;
	Graphics^canvas;

	bool unico;
	int random;
	int ro, rt, rtr, rf;
	bool inversaD;
	bool inversaI;
	bool inversaAr;
	bool inversaAb;
public:
	EntidadPersonaje()
	{
	}

	int GetX() { return x; }
	int GetY() { return y; }
	int GetDX() { return dx; }
	int GetDY() { return dy; }
	int GetAncho() { return ancho; }
	int GetAlto() { return alto; }
	int GetFila() { return fila; }
	int GetColumna() { return columna; }

	void SetX(int x) { this->x = x; }
	void SetY(int y) { this->y = y; }
	void SetDX(int dx) { this->dx = dx; }
	void SetDY(int dy) { this->dy = dy; }
	void SetAncho(int ancho) { this->ancho = ancho; }
	void SetAlto(int alto) { this->alto = alto; }
	Rectangle Area()
	{
		return Rectangle(x, y, ancho, alto);
	}

	void SetData(int x, int y, int ancho, int alto)
	{
		this->x = x;
		this->y = y;
		this->alto = alto;
		this->ancho = ancho;
	}

};

