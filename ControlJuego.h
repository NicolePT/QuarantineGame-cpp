#pragma once
#include "Jugador.h"
#include "ObstaculosEscenario1.h"
#include "ObstaculosEscenario2.h"
#include "ArrAdversario.h"
#include "Ambulancia.h"
#include "Policia.h"
#include "FuerzaArmada.h"

ref class ControlJuego
{
	Jugador^ jugador;
	ObstaculosEscenario1^ obstaculos1;
	ObstaculosEscenario2^ obstaculos2;
	Drawing::Font^ mifuente = gcnew Drawing::Font("Microsoft New Tai Lue", 18);
	Bitmap^ fondo;
	Bitmap^ puntaje;
	Bitmap^ meta;
	Bitmap^ corazon;
	Graphics^ canvas;
	ArrAdversario^ adversarios;
	Ambulancia^ ambulancia;
	Policia^ policia;
	FuerzaArmada^ soldado;
	bool dificil = false;
	bool facil = false;
	Int16 nvida;
	int puntos;
	int puntosMeta;
	short cont = 0;
	bool partidaGanada = false;
	short escenario;
public:
	ControlJuego(Graphics^ lienzo, short dificultad, Int16 vida, short puntajeMeta, short escenario)
	{
		canvas = lienzo;
		nvida = vida;
		this->escenario = escenario;
		puntos = 0;
		this->puntosMeta = puntajeMeta;
		if (escenario == 1) {
			fondo = gcnew Bitmap("imagenes/fondopueblo(1).png");
			obstaculos1 = gcnew ObstaculosEscenario1();
		}
		else {
			fondo = gcnew Bitmap("imagenes/fondo1.png");
			ambulancia = gcnew Ambulancia(canvas);
			obstaculos2 = gcnew ObstaculosEscenario2();
		}
		puntaje = gcnew Bitmap("imagenes/puntaje.png");
		meta = gcnew Bitmap("imagenes/meta.png");
		corazon = gcnew Bitmap("imagenes/corazon.png");
		jugador = gcnew Jugador(canvas);
		adversarios = gcnew ArrAdversario(canvas);

		policia = gcnew Policia(canvas);
		if (dificultad == 1) {
			facil = true;
		}
		if (dificultad == 2) {
			soldado = gcnew FuerzaArmada(canvas);
			dificil = true;
		}
	}
	void graficar() {
		srand(time(NULL));
		if(escenario==1) canvas->DrawImage(fondo, 0, 0, Rectangle(0, 0, 1186, 740), GraphicsUnit::Pixel);
		else canvas->DrawImage(fondo, 0, 0, Rectangle(0, 0, 1000, 710), GraphicsUnit::Pixel);
		for (Int16 i = 0, j = 0; i < nvida; ++i, j += 30) {
			canvas->DrawImage(corazon, 5 + j, 5, Rectangle(0, 0, 30, 30), GraphicsUnit::Pixel);
		}
		jugador->Graficar();
		jugador->mostrarMensajes();
		adversarios->graficarAdversarios(dificil);
		if(escenario==2)
			ambulancia->Graficar();
		policia->Graficar();

		if (dificil) {
			soldado->Graficar();
			if (soldado->Area().IntersectsWith(jugador->Area())) {
				nvida--;
			}
		}
		if (cont == 0 || cont == 25)
			adversarios->AgregarAdversario(gcnew Adversario(canvas, 2));
		canvas->DrawImage(meta, 420, 5, Rectangle(0, 0, 140, 49), GraphicsUnit::Pixel);
		canvas->DrawImage(puntaje, 700, 5, Rectangle(0, 0, 140, 49), GraphicsUnit::Pixel);
		canvas->DrawString(puntosMeta + "", mifuente, Brushes::Black, 485, 17);
		canvas->DrawString(puntos + "", mifuente, Brushes::Black, 765, 17);
		cont++;
		if (cont > 25)cont = 1;
		if (puntos >= puntosMeta) partidaGanada = true;
	}
	void mover() {
		if (ColisionJugadorObstaculo() == false)
			jugador->mover();
		adversarios->moverAdversarios(dificil, jugador->GetX(), jugador->GetY());
		policiaMoverPerseguir();
		if (dificil) {
			soldadoPerseguirJugador();
		}
	}
	void Colisiones() {
		if(escenario==2)
			ColisionesAmbulanciaAdversario();
		ColisionesAdversarioMensaje();
		ColisionBalaJugador();
		if (facil) colisionesAdversarioJugador();

	}
	void policiaMoverPerseguir() {
		for (int a = 0; a < adversarios->getCant(); a++) {
			if (adversarios->getAdversario(a)->preguntarCambiodeColorVerde() == true) {
				if (policia->GetX() > adversarios->getAdversario(a)->GetX())
					policia->Mover(Direccion::Izquierda);
				else if (policia->GetX() < adversarios->getAdversario(a)->GetX())
					policia->Mover(Direccion::Derecha);

				if (policia->GetY() > adversarios->getAdversario(a)->GetY())
					policia->Mover(Direccion::Arriba);
				else if (policia->GetY() < adversarios->getAdversario(a)->GetY())
					policia->Mover(Direccion::Abajo);
			}
			Rectangle A = adversarios->getAdversario(a)->Area();
			Rectangle B = policia->Area();
			if (A.IntersectsWith(B) && adversarios->getAdversario(a)->preguntarCambiodeColorVerde() == true)
			{
				adversarios->EliminarAdversario(a--);
			}
		}
	}
	void colisionesAdversarioJugador() {
		for (int a = 0; a < adversarios->getCant(); a++)
		{
			Adversario^ adv = adversarios->getAdversario(a);
			if (jugador->Area().IntersectsWith(adv->Area()))
			{
				nvida--;
				break;
			}
		}
	}
	void ColisionBalaJugador() {
		for (int i = 0; i < adversarios->getCant(); i++) //Enemigos
		{
			ArrBala^ balas = adversarios->getAdversario(i)->GetBalas();

			for (int j = 0; j < balas->GetCantidad(); j++)
			{
				Bala^ bala = balas->GetBala(j);
				if (bala->Area().IntersectsWith(jugador->Area()))
				{
					balas->EliminarBala(j--);
					nvida--;
				}
			}


		}
	}
	void soldadoPerseguirJugador() {
		if (soldado->GetX() > jugador->GetX())
			soldado->Mover(Direccion::Izquierda);
		else if (soldado->GetX() < jugador->GetX())
			soldado->Mover(Direccion::Derecha);

		if (soldado->GetY() > jugador->GetY())
			soldado->Mover(Direccion::Arriba);
		else if (soldado->GetY() < jugador->GetY())
			soldado->Mover(Direccion::Abajo);
	}
	void ColisionesAmbulanciaAdversario() {
		for (int i = 0; i < adversarios->getCant(); ++i) {
			if (ambulancia->Area().IntersectsWith(adversarios->getAdversario(i)->Area())) {
				if (adversarios->getAdversario(i)->preguntarCambiodeColorRojo() == true) {
					adversarios->EliminarAdversario(i--);
				}

			}

		}
	}
	void ColisionesAdversarioMensaje()
	{
		ArrMensajes^ mensajes = jugador->GetMensajes();
		for (int m = 0; m < mensajes->GetCantidad(); m++) {
			for (int a = 0; a < adversarios->getCant(); a++)
			{
				Mensaje^ msj = mensajes->GetMensaje(m);
				Adversario^ adv = adversarios->getAdversario(a);
				if (msj->Area().IntersectsWith(adv->Area()))
				{
					adversarios->getAdversario(a)->cambiarColorPersonaje();
					mensajes->EliminarMensaje(m--);
					puntos += 10;
					break;
				}
			}
		}
	}
	bool ColisionJugadorObstaculo()
	{
		if (escenario == 1) {
			for (int i = 0; i < 14; i++)
			{
				EntidadPersonaje^ E = obstaculos1->recuperarObstaculo(i);
				Rectangle J = jugador->Area();
				J.X += jugador->GetDX();
				J.Y += jugador->GetDY();

				if (obstaculos1->recuperarObstaculo(i)->Area().IntersectsWith(J))
					return true;
			}
		}
		else {
			for (int i = 0; i < 22; i++)
			{
				EntidadPersonaje^ E = obstaculos2->recuperarObstaculo(i);
				Rectangle J = jugador->Area();
				J.X += jugador->GetDX();
				J.Y += jugador->GetDY();

				if (obstaculos2->recuperarObstaculo(i)->Area().IntersectsWith(J))
					return true;
			}
		}

		return false;
	}

	Jugador^ recuperarJugador() {
		return jugador;
	}

	void Disparar() {
		jugador->dispararMensaje();
	}
	bool pasarSiguienteNivel() {
		return partidaGanada;
	}
	Int16 vidaJugador() {
		return nvida;
	}
	~ControlJuego()
	{
	}

};
