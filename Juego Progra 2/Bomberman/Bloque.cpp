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
		if (Winform::juego->nivel == 1)
			graphics->DrawImage(Imagenes::Bloque1, Rectangle(posicion->x, posicion->y, 64, 64));
		else if (Winform::juego->nivel == 2)
			graphics->DrawImage(Imagenes::Bloque2, Rectangle(posicion->x, posicion->y, 64, 64));
		else if (Winform::juego->nivel == 3)
			graphics->DrawImage(Imagenes::Bloque3, Rectangle(posicion->x, posicion->y, 64, 64));
		else if (Winform::juego->nivel == 4)
			graphics->DrawImage(Imagenes::Bloque4, Rectangle(posicion->x, posicion->y, 64, 64));
		else if (Winform::juego->nivel == 5)
			graphics->DrawImage(Imagenes::Bloque5, Rectangle(posicion->x, posicion->y, 64, 64));
	}
}