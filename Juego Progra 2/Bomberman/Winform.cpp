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
		instrucciones = gcnew Instrucciones();
		pausa = gcnew Pausa();
		youWin = gcnew YouWin();
		congratulations = gcnew Congratulations();
		gameOver = gcnew GameOver();
		creditos = gcnew Creditos();

		//Empezar el juego
		Escena::ActivarEscena(introduccion);
	}

	Winform::~Winform()
	{
		if (components)
		{
			delete components;
		}
	}
}