#include "Winform.h"

namespace Bomberman
{
	Objeto^ Objeto::getObjetoColisionante(Direcciones direccion, int velocidad, Posicion^ pPosicion)
	{
		int x = pPosicion->x;
		int y = pPosicion->y;
		Bomba^ b;

		if (direccion == Arriba)
		{
			if (y <= 0)
				return gcnew Bloque(gcnew Posicion(x, -1));

			if (x % 64 == 0)
			{
				if (y % 64 == 0)
				{
					b = Winform::bombas->getBomba(x / 64, y / 64 - 1);

					if (b != nullptr)
						return b;
					else
						return Winform::objetos->matriz[x / 64, y / 64 - 1];
				}
				else
					return Winform::objetos->matriz[x / 64, y / 64];
			}
			else
				return gcnew Bloque(gcnew Posicion(0, 0));
		}
		else if (direccion == Abajo)
		{
			if (y >= 512)
				return gcnew Bloque(gcnew Posicion(x, 513));

			if (x % 64 == 0)
			{
				if (y % 64 == 0)
				{
					b = Winform::bombas->getBomba(x / 64, y / 64 + 1);

					if (b != nullptr)
						return b;
					else
						return Winform::objetos->matriz[x / 64, y / 64 + 1];
				}
				else
					return Winform::objetos->matriz[x / 64, y / 64 + 1];
			}
			else
				return gcnew Bloque(gcnew Posicion(0, 0));
		}
		else if (direccion == Izquierda)
		{
			if (x <= 0)
				return gcnew Bloque(gcnew Posicion(-1, y));

			if (y % 64 == 0)
			{
				if (x % 64 == 0)
				{
					b = Winform::bombas->getBomba(x / 64 - 1, y / 64);

					if (b != nullptr)
						return b;
					else
						return Winform::objetos->matriz[x / 64 - 1, y / 64];
				}
				else
					return Winform::objetos->matriz[x / 64, y / 64];
			}
			else
				return gcnew Bloque(gcnew Posicion(0, 0));
		}
		else if (direccion == Derecha)
		{
			if (x >= 768)
				return gcnew Bloque(gcnew Posicion(769, y));

			if (y % 64 == 0)
			{
				if (x % 64 == 0)
				{
					b = Winform::bombas->getBomba(x / 64 + 1, y / 64);

					if (b != nullptr)
						return b;
					else
						return Winform::objetos->matriz[x / 64 + 1, y / 64];
				}
				else
					return Winform::objetos->matriz[x / 64 + 1, y / 64];
			}
			else
				return gcnew Bloque(gcnew Posicion(0, 0));
		}
		return gcnew Bloque(gcnew Posicion(0, 0));
	}
}