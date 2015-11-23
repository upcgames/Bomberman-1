#include "Directorio.h"

namespace Bomberman
{
	Winform::Winform(void)
	{
		InitializeComponent();
		graphics = this->CreateGraphics();
		context = BufferedGraphicsManager::Current;
		winform = this;
		aleatorio = gcnew Random();
		introduccion = gcnew Introduccion();
		inicio = gcnew Inicio();
		juego = gcnew Juego();
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