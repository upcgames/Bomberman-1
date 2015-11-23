#include "Directorio.h"

namespace Bomberman
{
	void Nivel::MostrarNivel(Graphics^ graphics)
	{
		for (int x = 0; x < 13; x++)
		{
			for (int y = 0; y < 9; y++)
			{
				if (Winform::objetos->matriz[x, y]->tipo == oPiso)
					dynamic_cast<Piso^>(Winform::objetos->matriz[x, y])->MostrarSprite(graphics);
				else if (Winform::objetos->matriz[x, y]->tipo == oBloque)
					dynamic_cast<Bloque^>(Winform::objetos->matriz[x, y])->MostrarSprite(graphics);
				else if (Winform::objetos->matriz[x, y]->tipo == oCaja)
					dynamic_cast<Caja^>(Winform::objetos->matriz[x, y])->MostrarSprite(graphics);
				else if (Winform::objetos->matriz[x, y]->tipo == oItem)
					dynamic_cast<Item^>(Winform::objetos->matriz[x, y])->MostrarSprite(graphics);
			}
		}
	}

	Objeto^ Nivel::getObjetoColisionante(Direcciones direccion, int velocidad)
	{
		int x = Winform::upecino->posicion->x;
		int y = Winform::upecino->posicion->y;
		Bomba^ b;

		if (direccion == Arriba)
		{
			if (y == 0)
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
			if (y == 512)
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
			if (x == 0)
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
			if (x == 768)
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

	Objeto^ Nivel::getContenidoCaja(Posicion^ p)
	{
		int random = Winform::aleatorio->Next(100);

		if (random < 40)
		{
			if (random < 20)
				return gcnew Item(gcnew Posicion(p->x, p->y), Cura);
			else
				return gcnew Item(gcnew Posicion(p->x, p->y), Powerade);
		}
		else
			return gcnew Piso(gcnew Posicion(p->x, p->y));
	}

	Objeto^ Nivel::getObjeto(Posicion^ posicion)
	{
		if (posicion->x < 0 || posicion->x > 768 || posicion->y < 0 || posicion->y > 512)
			return gcnew Bloque(gcnew Posicion(0, 0));

		return Winform::objetos->matriz[posicion->x / 64, posicion->y / 64];
		
	}

}