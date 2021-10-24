#pragma once

namespace Quarantine {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de Datos
	/// </summary>
	public ref class fmrDatos : public System::Windows::Forms::Form
	{
	public:
		fmrDatos(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~fmrDatos()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	protected:
	private: System::Windows::Forms::PictureBox^  pictureBox2;
	private: System::Windows::Forms::Label^  lblnumero;

	private: System::Windows::Forms::PictureBox^  pictureBox3;
	private: System::Windows::Forms::PictureBox^  pictureBox4;
	private: System::Windows::Forms::PictureBox^  pictureBox5;
	private: System::Windows::Forms::PictureBox^  pictureBox6;
	private: System::Windows::Forms::PictureBox^  pictureBox7;
	private: System::Windows::Forms::PictureBox^  pbxFacil;
	private: System::Windows::Forms::PictureBox^  pbxDificil;
	private: System::Windows::Forms::PictureBox^  pbxPueblo;
	private: System::Windows::Forms::PictureBox^  pbxSan;


	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(fmrDatos::typeid));
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->lblnumero = (gcnew System::Windows::Forms::Label());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox4 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox5 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox6 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox7 = (gcnew System::Windows::Forms::PictureBox());
			this->pbxFacil = (gcnew System::Windows::Forms::PictureBox());
			this->pbxDificil = (gcnew System::Windows::Forms::PictureBox());
			this->pbxPueblo = (gcnew System::Windows::Forms::PictureBox());
			this->pbxSan = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox6))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox7))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbxFacil))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbxDificil))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbxPueblo))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbxSan))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pictureBox1->Location = System::Drawing::Point(250, 250);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(196, 47);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &fmrDatos::pictureBox1_Click);
			// 
			// pictureBox2
			// 
			this->pictureBox2->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox2->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pictureBox2->Location = System::Drawing::Point(634, 193);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(300, 47);
			this->pictureBox2->TabIndex = 1;
			this->pictureBox2->TabStop = false;
			this->pictureBox2->Click += gcnew System::EventHandler(this, &fmrDatos::pictureBox2_Click);
			// 
			// lblnumero
			// 
			this->lblnumero->AutoSize = true;
			this->lblnumero->BackColor = System::Drawing::Color::Transparent;
			this->lblnumero->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 40, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblnumero->Location = System::Drawing::Point(692, 462);
			this->lblnumero->Name = L"lblnumero";
			this->lblnumero->Size = System::Drawing::Size(57, 63);
			this->lblnumero->TabIndex = 2;
			this->lblnumero->Text = L"1";
			this->lblnumero->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// pictureBox3
			// 
			this->pictureBox3->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox3->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pictureBox3->Location = System::Drawing::Point(708, 572);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(253, 65);
			this->pictureBox3->TabIndex = 3;
			this->pictureBox3->TabStop = false;
			// 
			// pictureBox4
			// 
			this->pictureBox4->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox4->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pictureBox4->Location = System::Drawing::Point(546, 461);
			this->pictureBox4->Name = L"pictureBox4";
			this->pictureBox4->Size = System::Drawing::Size(65, 63);
			this->pictureBox4->TabIndex = 4;
			this->pictureBox4->TabStop = false;
			this->pictureBox4->Click += gcnew System::EventHandler(this, &fmrDatos::pictureBox4_Click);
			// 
			// pictureBox5
			// 
			this->pictureBox5->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox5->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pictureBox5->Location = System::Drawing::Point(820, 460);
			this->pictureBox5->Name = L"pictureBox5";
			this->pictureBox5->Size = System::Drawing::Size(65, 63);
			this->pictureBox5->TabIndex = 5;
			this->pictureBox5->TabStop = false;
			this->pictureBox5->Click += gcnew System::EventHandler(this, &fmrDatos::pictureBox5_Click);
			// 
			// pictureBox6
			// 
			this->pictureBox6->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox6->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pictureBox6->Location = System::Drawing::Point(143, 467);
			this->pictureBox6->Name = L"pictureBox6";
			this->pictureBox6->Size = System::Drawing::Size(179, 66);
			this->pictureBox6->TabIndex = 6;
			this->pictureBox6->TabStop = false;
			this->pictureBox6->Click += gcnew System::EventHandler(this, &fmrDatos::pictureBox6_Click);
			// 
			// pictureBox7
			// 
			this->pictureBox7->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox7->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pictureBox7->Location = System::Drawing::Point(143, 542);
			this->pictureBox7->Name = L"pictureBox7";
			this->pictureBox7->Size = System::Drawing::Size(179, 66);
			this->pictureBox7->TabIndex = 7;
			this->pictureBox7->TabStop = false;
			this->pictureBox7->Click += gcnew System::EventHandler(this, &fmrDatos::pictureBox7_Click);
			// 
			// pbxFacil
			// 
			this->pbxFacil->BackColor = System::Drawing::Color::Transparent;
			this->pbxFacil->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pbxFacil.Image")));
			this->pbxFacil->Location = System::Drawing::Point(277, 471);
			this->pbxFacil->Name = L"pbxFacil";
			this->pbxFacil->Size = System::Drawing::Size(49, 46);
			this->pbxFacil->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbxFacil->TabIndex = 8;
			this->pbxFacil->TabStop = false;
			this->pbxFacil->Visible = false;
			// 
			// pbxDificil
			// 
			this->pbxDificil->BackColor = System::Drawing::Color::Transparent;
			this->pbxDificil->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pbxDificil.Image")));
			this->pbxDificil->Location = System::Drawing::Point(287, 546);
			this->pbxDificil->Name = L"pbxDificil";
			this->pbxDificil->Size = System::Drawing::Size(49, 46);
			this->pbxDificil->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbxDificil->TabIndex = 9;
			this->pbxDificil->TabStop = false;
			this->pbxDificil->Visible = false;
			// 
			// pbxPueblo
			// 
			this->pbxPueblo->BackColor = System::Drawing::Color::Transparent;
			this->pbxPueblo->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pbxPueblo.Image")));
			this->pbxPueblo->Location = System::Drawing::Point(428, 239);
			this->pbxPueblo->Name = L"pbxPueblo";
			this->pbxPueblo->Size = System::Drawing::Size(49, 46);
			this->pbxPueblo->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbxPueblo->TabIndex = 10;
			this->pbxPueblo->TabStop = false;
			this->pbxPueblo->Visible = false;
			// 
			// pbxSan
			// 
			this->pbxSan->BackColor = System::Drawing::Color::Transparent;
			this->pbxSan->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pbxSan.Image")));
			this->pbxSan->Location = System::Drawing::Point(917, 186);
			this->pbxSan->Name = L"pbxSan";
			this->pbxSan->Size = System::Drawing::Size(49, 46);
			this->pbxSan->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbxSan->TabIndex = 11;
			this->pbxSan->TabStop = false;
			this->pbxSan->Visible = false;
			// 
			// fmrDatos
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(984, 671);
			this->Controls->Add(this->pbxSan);
			this->Controls->Add(this->pbxPueblo);
			this->Controls->Add(this->pbxDificil);
			this->Controls->Add(this->pbxFacil);
			this->Controls->Add(this->pictureBox7);
			this->Controls->Add(this->pictureBox6);
			this->Controls->Add(this->pictureBox5);
			this->Controls->Add(this->pictureBox4);
			this->Controls->Add(this->pictureBox3);
			this->Controls->Add(this->lblnumero);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->pictureBox1);
			this->DoubleBuffered = true;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"fmrDatos";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Datos";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox6))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox7))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbxFacil))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbxDificil))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbxPueblo))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbxSan))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion


	private: System::Void pictureBox5_Click(System::Object^  sender, System::EventArgs^  e) {
		Int16 num= Convert::ToInt16(lblnumero->Text);
		if(num<6)
			num++;
		lblnumero->Text = Convert::ToString(num);
	}
	private: System::Void pictureBox4_Click(System::Object^  sender, System::EventArgs^  e) {
		Int16 num = Convert::ToInt16(lblnumero->Text);
		if (num>1)
			num--;
		lblnumero->Text = Convert::ToString(num);
	}
	private: System::Void pictureBox1_Click(System::Object^  sender, System::EventArgs^  e) {
		pbxPueblo->Visible = true;
		pbxSan->Visible = false;
	
	}
	private: System::Void pictureBox2_Click(System::Object^  sender, System::EventArgs^  e) {
		pbxSan->Visible = true;
		pbxPueblo->Visible = false;
	}
	private: System::Void pictureBox6_Click(System::Object^  sender, System::EventArgs^  e) {
		pbxFacil->Visible = true;
		pbxDificil->Visible = false;
	}
	private: System::Void pictureBox7_Click(System::Object^  sender, System::EventArgs^  e) {
		pbxDificil->Visible = true;
		pbxFacil->Visible = false;
	}
};
}
