#pragma once
#include "Directorio.h"

namespace Bomberman
{
	ref class Bloque : public Objeto
	{
	public:
		Bloque(Posicion^ p);
		void MostrarSprite(Graphics^ graphics);
	};

	Bloque::Bloque(Posicion^ p)
	{
		tipo = Objetos::oBloque;
		posicion = gcnew Posicion(p->x, p->y);
	}
	void Bloque::MostrarSprite(Graphics^ graphics)
	{
		graphics->FillRectangle(gcnew SolidBrush(Color::Black), Rectangle(posicion->x, posicion->y, 64, 64));

	}
}