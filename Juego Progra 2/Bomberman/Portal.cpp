#include "WinForm.h"

namespace Bomberman
{
	Portal::Portal(Posicion^ p)
	{
		tipo = Objetos::oPortal;
		visible = false;
		posicion = gcnew Posicion(p->x, p->y);
	}
	void Portal::MostrarSprite(Graphics^ graphics)
	{
		if (visible)
			graphics->FillRectangle(gcnew SolidBrush(Color::Purple), Rectangle(posicion->x, posicion->y, 64, 64));
		else
			graphics->FillRectangle(gcnew SolidBrush(Color::White), Rectangle(posicion->x, posicion->y, 64, 64));
	}
}

