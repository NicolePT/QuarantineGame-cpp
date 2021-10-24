#pragma once

namespace Quarantine {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de fmrPerdiste
	/// </summary>
	public ref class fmrPerdiste : public System::Windows::Forms::Form
	{
		bool salir = false;
	public:
		fmrPerdiste(void)
		{
			InitializeComponent();
			//
			//TODO: agregar c�digo de constructor aqu�
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se est�n usando.
		/// </summary>
		~fmrPerdiste()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:

	protected:


	private:
		/// <summary>
		/// Variable del dise�ador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// M�todo necesario para admitir el Dise�ador. No se puede modificar
		/// el contenido de este m�todo con el editor de c�digo.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(fmrPerdiste::typeid));
			this->SuspendLayout();
			// 
			// fmrPerdiste
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(560, 300);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"fmrPerdiste";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"fmrPerdiste";
			this->ResumeLayout(false);

		}
#pragma endregion

	};
}
