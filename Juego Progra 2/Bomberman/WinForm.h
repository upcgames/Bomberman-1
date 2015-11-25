#pragma once
#include "Directorio.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

namespace Bomberman 
{
	public ref class Winform : public System::Windows::Forms::Form
	{
	public:
		static Winform^ winform;
		static Imagenes^ imagenes;
		static Graphics^ graphics;
		static BufferedGraphicsContext^ context;
		static Random^ aleatorio;
		static Upecino^ upecino;

		static MatrizObjetos^ objetos;
		static ArrBombas^ bombas;
		static ArrMalignos^ malignos;

		static Introduccion^ introduccion;
		static Inicio^ inicio;
		static Instrucciones^ instrucciones;
		static Juego^ juego;
		static Pausa^ pausa;
		static YouWin^ youWin;
		static Congratulations^ congratulations;
		static GameOver^ gameOver;
		static Creditos^ creditos;

		static Nivel1^ nivel1;
		static Nivel2^ nivel2;
		static Nivel3^ nivel3;
		static Nivel4^ nivel4;
		static Nivel5^ nivel5;
		bool cambioDeEscena;

		Winform(void);
		~Winform();
	public: static System::Windows::Forms::Timer^  timer;

	private: System::ComponentModel::IContainer^  components;

#pragma region Windows Form Designer generated code

			 void InitializeComponent(void)
			 {
				 this->components = (gcnew System::ComponentModel::Container());
				 System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Winform::typeid));
				 this->timer = (gcnew System::Windows::Forms::Timer(this->components));
				 this->SuspendLayout();
				 // 
				 // timer
				 // 
				 this->timer->Enabled = true;
				 this->timer->Interval = 50;
				 // 
				 // Winform
				 // 
				 this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
				 this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				 this->ClientSize = System::Drawing::Size(832, 576);
				 this->ControlBox = false;
				 this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
				 this->MaximumSize = System::Drawing::Size(848, 615);
				 this->MinimumSize = System::Drawing::Size(848, 615);
				 this->Name = L"Winform";
				 this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
				 this->Text = L"Winform";
				 this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Winform::Winform_KeyDown);
				 this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &Winform::Winform_KeyUp);
				 this->ResumeLayout(false);

			 }
#pragma endregion
	
	private: System::Void Winform_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e);
	
	private: System::Void Winform_KeyUp(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e);
	
	};
}
