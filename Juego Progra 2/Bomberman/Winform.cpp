#include "WinForm.h"

namespace Bomberman
{
	Winform::Winform(void)
	{
		InitializeComponent();
		winform = this;

		imagenes = gcnew Imagenes();
		graphics = this->CreateGraphics();
		context = BufferedGraphicsManager::Current;
		aleatorio = gcnew Random();

		introduccion = gcnew Introduccion();
		inicio = gcnew Inicio();
		juego = gcnew Juego();
		instrucciones = gcnew Instrucciones();
		pausa = gcnew Pausa();
		youWin = gcnew YouWin();
		congratulations = gcnew Congratulations();
		gameOver = gcnew GameOver();
		creditos = gcnew Creditos();
		cambioDeEscena = false;
		

		//Empezar el juego
		Escena::ActivarEscena(introduccion);
		Nivel::PasarANivel(1);
	}

	Winform::~Winform()
	{
		if (components)
		{
			delete components;
		}
	}

	System::Void Winform::Winform_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e)
	{
		if (e->KeyCode == Keys::E)
			cambioDeEscena = true;
		else if (e->KeyCode == Keys::D1)
		{
			if (cambioDeEscena)
				Escena::CambiarEscena(introduccion);
		}
		else if (e->KeyCode == Keys::D2)
		{
			if (cambioDeEscena)
				Escena::CambiarEscena(inicio);
		}
		else if (e->KeyCode == Keys::D3)
		{
			if (cambioDeEscena)
				Escena::CambiarEscena(instrucciones);
		}
		else if (e->KeyCode == Keys::D4)
		{
			if (cambioDeEscena)
				Escena::CambiarEscena(juego);
		}
		else if (e->KeyCode == Keys::D5)
		{
			if (cambioDeEscena)
				Escena::CambiarEscena(pausa);
		}
		else if (e->KeyCode == Keys::D6)
		{
			if (cambioDeEscena)
				Escena::CambiarEscena(youWin);
		}
		else if (e->KeyCode == Keys::D7)
		{
			if (cambioDeEscena)
				Escena::CambiarEscena(gameOver);
		}
		else if (e->KeyCode == Keys::D8)
		{
			if (cambioDeEscena)
				Escena::CambiarEscena(congratulations);
		}
		else if (e->KeyCode == Keys::D9)
		{
			if (cambioDeEscena)
				Escena::CambiarEscena(creditos);
		}
	}

	System::Void Winform::Winform_KeyUp(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e)
	{
		if (e->KeyCode == Keys::E && cambioDeEscena)
			cambioDeEscena = false;
	}
}