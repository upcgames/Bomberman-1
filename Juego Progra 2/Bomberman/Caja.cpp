#include "Winform.h"

namespace Bomberman
{
	Caja::Caja(Posicion^ p)
	{
		tipo = Objetos::oCaja;
		posicion = gcnew Posicion(p->x, p->y);
	}
	void Caja::cuandoBombaLeCae()
	{

	}
	void Caja::MostrarSprite(Graphics^ graphics)
	{
		graphics->FillRectangle(gcnew SolidBrush(Color::Red), Rectangle(posicion->x, posicion->y, 64, 64));
	}
}