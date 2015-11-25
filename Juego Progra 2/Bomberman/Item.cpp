#include "Winform.h"

namespace Bomberman
{
	Item::Item(Posicion^ p, Items pTipo)
	{
		tipo = oItem;
		tipoItem = pTipo;
		posicion = gcnew Posicion(p->x, p->y);
	}
	void Item::MostrarSprite(Graphics^ graphics)
	{
		if (tipoItem == Cura)
			graphics->DrawImage(Imagenes::Cura, Rectangle(posicion->x, posicion->y, 64, 64));
		else if (tipoItem == Powerade)
			graphics->DrawImage(Imagenes::Powerade, Rectangle(posicion->x, posicion->y, 64, 64));
		else if (tipoItem == BombaPlus)
			graphics->DrawImage(Imagenes::BombaPlus, Rectangle(posicion->x, posicion->y, 64, 64));
		else if (tipoItem == Pasamuros)
			graphics->DrawImage(Imagenes::PasaMuros, Rectangle(posicion->x, posicion->y, 64, 64));
	}
}