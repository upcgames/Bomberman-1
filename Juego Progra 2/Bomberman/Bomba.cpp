#include "Directorio.h"

namespace Bomberman
{
	Bomba::Bomba(Posicion^ p)
	{
		posicion = gcnew Posicion(p->x, p->y, 64);
		radioExplosion = Winform::upecino->radioExplosion;
		tipo = oBomba;
		ancho = 64;
		alto = 64;
		imagen = Image::FromFile("Bombas.png");
		visible = true;
		indiceSprite = 0;
		tiempo = 80;
	}
	void Bomba::MostrarSprite(Graphics^ graphics)
	{
		indiceSprite = 3 - tiempo / 20;

		graphics->DrawImage(imagen, Rectangle(posicion->x, posicion->y, ancho, alto), Rectangle(indiceSprite * 64, 0, ancho, alto), GraphicsUnit::Pixel);

		if (indiceSprite == 3)
			Explotar(graphics);
	}
	void Bomba::Explotar(Graphics^ graphics)
	{
		Objeto^ objeto;

		//Arriba
		for (int i = 1; i <= radioExplosion; i++)
		{
			objeto = Nivel::getObjeto(posicion->getIncrementada(Arriba, 64 * i));

			if (Rectangle(posicion->x, posicion->y - 64 * i, 64, 64).IntersectsWith(Winform::upecino->getBody()))
				Winform::upecino->EsAtacado();
			
			Maligno::ColisionMaligno_Fuego(posicion->x, posicion->y - 64 * i);

			if (objeto->tipo == oBloque)
				break;
			if (objeto->tipo == oCaja)
			{
				if (tiempo == 0)
				{
					objeto = Nivel::getContenidoCaja(objeto->posicion);
					Winform::objetos->matriz[objeto->posicion->x / 64, objeto->posicion->y / 64] = objeto;
				}
				break;
			}
			if (objeto->tipo == oItem)
			{
				Winform::objetos->matriz[objeto->posicion->x / 64, objeto->posicion->y / 64] = gcnew Piso(objeto->posicion);
			}

			graphics->DrawImage(imagen, Rectangle(posicion->x, posicion->y - i * 64, ancho, alto), Rectangle(192, 0, ancho, alto), GraphicsUnit::Pixel);
		}

		//Abajo
		for (int i = 1; i <= radioExplosion; i++)
		{
			objeto = Nivel::getObjeto(posicion->getIncrementada(Abajo, 64 * i));

			if (Rectangle(posicion->x, posicion->y + 64 * i, 64, 64).IntersectsWith(Winform::upecino->getBody()))
				Winform::upecino->EsAtacado();

			Maligno::ColisionMaligno_Fuego(posicion->x, posicion->y + 64 * i);

			if (objeto->tipo == oBloque)
				break;
			if (objeto->tipo == oCaja)
			{
				if (tiempo == 0)
				{
					objeto = Nivel::getContenidoCaja(objeto->posicion);
					Winform::objetos->matriz[objeto->posicion->x / 64, objeto->posicion->y / 64] = objeto;
				}
				break;
			}
			if (objeto->tipo == oItem)
			{
				Winform::objetos->matriz[objeto->posicion->x / 64, objeto->posicion->y / 64] = gcnew Piso(objeto->posicion);
			}
			graphics->DrawImage(imagen, Rectangle(posicion->x, posicion->y + i * 64, ancho, alto), Rectangle(192, 0, ancho, alto), GraphicsUnit::Pixel);
		}

		//Izquierda
		for (int i = 1; i <= radioExplosion; i++)
		{
			objeto = Nivel::getObjeto(posicion->getIncrementada(Izquierda, 64 * i));

			if (Rectangle(posicion->x - 64 * i, posicion->y, 64, 64).IntersectsWith(Winform::upecino->getBody()))
				Winform::upecino->EsAtacado();

			Maligno::ColisionMaligno_Fuego(posicion->x - 64 * i, posicion->y);

			if (objeto->tipo == oBloque)
				break;
			if (objeto->tipo == oCaja)
			{
				if (tiempo == 0)
				{
					objeto = Nivel::getContenidoCaja(objeto->posicion);
					Winform::objetos->matriz[objeto->posicion->x / 64, objeto->posicion->y / 64] = objeto;
				}
				break;
			}
			if (objeto->tipo == oItem)
			{
				Winform::objetos->matriz[objeto->posicion->x / 64, objeto->posicion->y / 64] = gcnew Piso(objeto->posicion);
			}
			graphics->DrawImage(imagen, Rectangle(posicion->x - i * 64, posicion->y, ancho, alto), Rectangle(192, 0, ancho, alto), GraphicsUnit::Pixel);
		}

		//Derecha
		for (int i = 1; i <= radioExplosion; i++)
		{
			objeto = Nivel::getObjeto(posicion->getIncrementada(Derecha, 64 * i));

			if (Rectangle(posicion->x + 64 * i, posicion->y, 64, 64).IntersectsWith(Winform::upecino->getBody()))
				Winform::upecino->EsAtacado();

			Maligno::ColisionMaligno_Fuego(posicion->x + 64 * i, posicion->y);

			if (objeto->tipo == oBloque)
				break;
			if (objeto->tipo == oCaja)
			{
				if (tiempo == 0)
				{
					objeto = Nivel::getContenidoCaja(objeto->posicion);
					Winform::objetos->matriz[objeto->posicion->x / 64, objeto->posicion->y / 64] = objeto;
				}
				break;
			}
			if (objeto->tipo == oItem)
			{
				Winform::objetos->matriz[objeto->posicion->x / 64, objeto->posicion->y / 64] = gcnew Piso(objeto->posicion);
			}
			graphics->DrawImage(imagen, Rectangle(posicion->x + i * 64, posicion->y, ancho, alto), Rectangle(192, 0, ancho, alto), GraphicsUnit::Pixel);
		}
	}
}