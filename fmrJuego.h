#pragma once
#include "ControlJuego.h"
#include "fmrPerdiste.h"
#include "fmrGanaste.h"
namespace Quarantine {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class fmrJuego : public System::Windows::Forms::Form
	{
		Graphics^ canvas;
		BufferedGraphicsContext^ bfc;
		BufferedGraphics^ bf;
		fmrPerdiste^ perdiste;
		fmrGanaste^ ganaste;
		Drawing::Font^ mifuente = gcnew Drawing::Font("Microsoft New Tai Lue", 21);
		Bitmap^ fondotiempo;
		Bitmap^ level1;
		Bitmap^ level2;
		Bitmap^ level3;
		Int16 segundo1 = 60;
		Int16 minutos1;

		Int16 segundo2 = 60;
		Int16 minutos2;

		Int16 segundo3 = 60;
		Int16 minutos3;
		String^ seg;
		String^ min;
	private: System::Windows::Forms::Timer^ tiempo;

		   ControlJuego^ nivel1;
		   ControlJuego^ nivel2;
		   ControlJuego^ nivel3;
	public:

		fmrJuego(Int16 nrvi, Int16 ntmin, short dificultad,short escenario)
		{
			InitializeComponent();
			minutos1 = ntmin;
			minutos2 = ntmin;
			minutos3 = ntmin;

			fondotiempo = gcnew Bitmap("imagenes/time.png");

			level1 = gcnew Bitmap("imagenes/nivel1.png");
			level2 = gcnew Bitmap("imagenes/nivel2.png");
			level3 = gcnew Bitmap("imagenes/nivel3.png");

			bfc = BufferedGraphicsManager::Current;
			canvas = panel1->CreateGraphics();
			bf = bfc->Allocate(canvas, this->ClientRectangle);
			nivel1 = gcnew ControlJuego(bf->Graphics, dificultad, nrvi, 50,escenario);
			nivel2 = gcnew ControlJuego(bf->Graphics, dificultad, nrvi, 150,escenario);
			nivel3 = gcnew ControlJuego(bf->Graphics, dificultad, nrvi, 250,escenario);

			perdiste = gcnew fmrPerdiste();
			ganaste = gcnew fmrGanaste();
			min = "0";
			seg = "00";
		}

	protected:
		~fmrJuego()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::ComponentModel::IContainer^ components;
	protected:

	private:


#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->tiempo = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::Transparent;
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1186, 740);
			this->panel1->TabIndex = 0;
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &fmrJuego::timer1_Tick);
			// 
			// tiempo
			// 
			this->tiempo->Enabled = true;
			this->tiempo->Interval = 1000;
			this->tiempo->Tick += gcnew System::EventHandler(this, &fmrJuego::tiempo_Tick);
			// 
			// fmrJuego
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(1187, 740);
			this->Controls->Add(this->panel1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"fmrJuego";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"fmrMenu";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &fmrJuego::fmrJuego_KeyDown);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &fmrJuego::fmrJuego_KeyUp);
			this->ResumeLayout(false);

		}
#pragma endregion
		Void nivel1Timer() {
			nivel1->mover();
			nivel1->graficar();
			nivel1->Colisiones();
			bf->Graphics->DrawImage(fondotiempo, 1070, 5, Rectangle(0, 0, 100, 52), GraphicsUnit::Pixel);
			bf->Graphics->DrawImage(level1, 220, 3, Rectangle(0, 0, 120, 65), GraphicsUnit::Pixel);

			bf->Graphics->DrawString(min, mifuente, Brushes::Black, 1085, 8);
			if (segundo1 < 10) {
				bf->Graphics->DrawString("0" + seg, mifuente, Brushes::Black, 1117, 8);
			}
			else bf->Graphics->DrawString(seg, mifuente, Brushes::Black, 1117, 8);
			this->Text = Convert::ToString(nivel1->recuperarJugador()->GetMensajes()->GetCantidad());
			if (nivel1->vidaJugador() == 0) {
				perdiste->Show();
				timer1->Enabled = false;
				tiempo->Enabled = false;
				
			}
			bf->Render(canvas);
		}
		Void nivel2Timer() {
			nivel2->mover();
			nivel2->graficar();
			nivel2->Colisiones();
			bf->Graphics->DrawImage(fondotiempo, 1070, 5, Rectangle(0, 0, 100, 52), GraphicsUnit::Pixel);
			bf->Graphics->DrawImage(level2, 220, 3, Rectangle(0, 0, 120, 65), GraphicsUnit::Pixel);

			bf->Graphics->DrawString(min, mifuente, Brushes::Black, 1085, 8);
			if (segundo2 < 10) {
				bf->Graphics->DrawString("0" + seg, mifuente, Brushes::Black, 1117, 8);
			}
			else bf->Graphics->DrawString(seg, mifuente, Brushes::Black, 1117, 8);
			this->Text = Convert::ToString(nivel1->recuperarJugador()->GetMensajes()->GetCantidad());
			if (nivel2->vidaJugador() == 0) {
				perdiste->Show();
				timer1->Enabled = false;
				tiempo->Enabled = false;
			}
			bf->Render(canvas);
		}
		Void nivel3Timer() {
			nivel3->mover();
			nivel3->graficar();
			nivel3->Colisiones();
			bf->Graphics->DrawImage(fondotiempo, 1070, 5, Rectangle(0, 0, 100, 52), GraphicsUnit::Pixel);
			bf->Graphics->DrawImage(level3, 220, 3, Rectangle(0, 0, 120, 65), GraphicsUnit::Pixel);

			bf->Graphics->DrawString(min, mifuente, Brushes::Black, 1085, 8);
			if (segundo3 < 10) {
				bf->Graphics->DrawString("0" + seg, mifuente, Brushes::Black, 1117, 8);
			}
			else bf->Graphics->DrawString(seg, mifuente, Brushes::Black, 1117, 8);
			this->Text = Convert::ToString(nivel1->recuperarJugador()->GetMensajes()->GetCantidad());
			if (nivel3->vidaJugador() == 0) {
				perdiste->Show();
				timer1->Enabled = false;
				tiempo->Enabled = false;
			}
			bf->Render(canvas);
		}

		Void nivel1KeyDown(KeyEventArgs^ e) {
			nivel1->recuperarJugador()->establecerDireccionJugador(e);
			nivel1->recuperarJugador()->establecerDireccionMensaje(e);
			if (e->KeyCode == Keys::Space)
				nivel1->Disparar();
		}
		Void nivel2KeyDown(KeyEventArgs^ e) {
			nivel2->recuperarJugador()->establecerDireccionJugador(e);
			nivel2->recuperarJugador()->establecerDireccionMensaje(e);
			if (e->KeyCode == Keys::Space)
				nivel2->Disparar();
		}
		Void nivel3KeyDown(KeyEventArgs^ e) {
			nivel3->recuperarJugador()->establecerDireccionJugador(e);
			nivel3->recuperarJugador()->establecerDireccionMensaje(e);
			if (e->KeyCode == Keys::Space)
				nivel3->Disparar();
		}

		Void nivel1Cronometro() {
			segundo1--;
			if (segundo1 == 0) {
				if (segundo1 == 0 && minutos1 == 0) {
					perdiste->Show();
					timer1->Enabled = false;
					tiempo->Enabled = false;

				}
				segundo1 = 59;
				minutos1--;
			}
			min = Convert::ToString(minutos1);
			seg = Convert::ToString(segundo1);
		}
		Void nivel2Cronometro() {
			segundo2--;
			if (segundo2 == 0) {
				if (segundo2 == 0 && minutos2 == 0) {
					perdiste->Show();
					timer1->Enabled = false;
					tiempo->Enabled = false;

				}
				segundo2 = 59;
				minutos2--;
			}
			min = Convert::ToString(minutos2);
			seg = Convert::ToString(segundo2);
		}
		Void nivel3Cronometro() {
			segundo3--;
			if (segundo3 == 0) {
				if (segundo3 == 0 && minutos3 == 0) {
					perdiste->Show();
					timer1->Enabled = false;
					tiempo->Enabled = false;

				}
				segundo3 = 59;
				minutos3--;
			}
			min = Convert::ToString(minutos3);
			seg = Convert::ToString(segundo3);
		}


	private: Void timer1_Tick(Object^ sender, EventArgs^ e) {
		if (nivel1->pasarSiguienteNivel() == false) {
			nivel1Timer();
		}
		if (nivel1->pasarSiguienteNivel() && nivel2->pasarSiguienteNivel() == false) {
			nivel2Timer();
		}
		if (nivel2->pasarSiguienteNivel() && nivel3->pasarSiguienteNivel() == false) {
			nivel3Timer();
		}
		if (nivel3->pasarSiguienteNivel()) {
			ganaste->Show();
			this->Close();
		}
	}
	private: Void fmrJuego_KeyDown(Object^ sender, KeyEventArgs^ e) {
		if (nivel1->pasarSiguienteNivel() == false) {
			nivel1KeyDown(e);
		}
		if (nivel1->pasarSiguienteNivel() && nivel2->pasarSiguienteNivel() == false) {
			nivel2KeyDown(e);
		}
		if (nivel2->pasarSiguienteNivel() && nivel3->pasarSiguienteNivel() == false) {
			nivel3KeyDown(e);
		}
	}
	private: Void fmrJuego_KeyUp(Object^ sender, KeyEventArgs^ e) {

		if (nivel1->pasarSiguienteNivel() == false) {
			nivel1->recuperarJugador()->neutralizarDireccionJugador(e);
		}
		if (nivel1->pasarSiguienteNivel() && nivel2->pasarSiguienteNivel() == false) {
			nivel2->recuperarJugador()->neutralizarDireccionJugador(e);
		}
		if (nivel2->pasarSiguienteNivel() && nivel3->pasarSiguienteNivel() == false) {
			nivel3->recuperarJugador()->neutralizarDireccionJugador(e);
		}
	}
	private: Void tiempo_Tick(Object^ sender, EventArgs^ e) {
		if (nivel1->pasarSiguienteNivel() == false) {
			nivel1Cronometro();
		}
		if (nivel1->pasarSiguienteNivel() && nivel2->pasarSiguienteNivel() == false) {
			nivel2Cronometro();
		}
		if (nivel2->pasarSiguienteNivel() && nivel3->pasarSiguienteNivel() == false) {
			nivel3Cronometro();
		}
	}



	};
}