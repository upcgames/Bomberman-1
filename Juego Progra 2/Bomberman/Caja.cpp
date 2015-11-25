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
		if (Winform::juego->nivel == 1)
			graphics->DrawImage(Imagenes::Caja1, Rectangle(posicion->x, posicion->y, 64, 64));
		else if (Winform::juego->nivel == 2)
			graphics->DrawImage(Imagenes::Caja2, Rectangle(posicion->x, posicion->y, 64, 64));
		else if (Winform::juego->nivel == 3)
			graphics->DrawImage(Imagenes::Caja3, Rectangle(posicion->x, posicion->y, 64, 64));
		else if (Winform::juego->nivel == 4)
			graphics->DrawImage(Imagenes::Caja4, Rectangle(posicion->x, posicion->y, 64, 64));
		else if (Winform::juego->nivel == 5)
			graphics->DrawImage(Imagenes::Caja5, Rectangle(posicion->x, posicion->y, 64, 64));
	}
}