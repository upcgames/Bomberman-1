#include "Winform.h"

namespace Bomberman
{
	Piso::Piso(Posicion^ p)
	{
		tipo = oPiso;
		posicion = gcnew Posicion(p->x, p->y);
	}

	void Piso::MostrarSprite(Graphics^ graphics)
	{
		graphics->FillRectangle(gcnew SolidBrush(Color::White), Rectangle(posicion->x, posicion->y, 64, 64));
	}
}