#include "Winform.h"

namespace Bomberman
{
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