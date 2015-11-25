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
			graphics->DrawImage(Imagenes::Portal, Rectangle(posicion->x, posicion->y, 64, 64));
		else
		{
			if (Winform::juego->nivel == 1)
				graphics->DrawImage(Imagenes::Piso1, Rectangle(posicion->x, posicion->y, 64, 64));
			else if (Winform::juego->nivel == 2)
				graphics->DrawImage(Imagenes::Piso2, Rectangle(posicion->x, posicion->y, 64, 64));
			else if (Winform::juego->nivel == 3)
				graphics->DrawImage(Imagenes::Piso3, Rectangle(posicion->x, posicion->y, 64, 64));
			else if (Winform::juego->nivel == 4)
				graphics->DrawImage(Imagenes::Piso4, Rectangle(posicion->x, posicion->y, 64, 64));
			else if (Winform::juego->nivel == 5)
				graphics->DrawImage(Imagenes::Piso5, Rectangle(posicion->x, posicion->y, 64, 64));
		}
	}
}

