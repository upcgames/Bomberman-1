#include "Directorio.h"

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
			graphics->FillRectangle(gcnew SolidBrush(Color::Green), Rectangle(posicion->x, posicion->y, 64, 64));
		else if (tipoItem == Powerade)
			graphics->FillRectangle(gcnew SolidBrush(Color::Yellow), Rectangle(posicion->x, posicion->y, 64, 64));
	}
}