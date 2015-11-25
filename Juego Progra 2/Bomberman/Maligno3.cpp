#include "Winform.h"

namespace Bomberman
{
	Maligno3::Maligno3(Posicion^ p, int pVida)
	{
		imagen = Imagenes::NinjaBombermanSprite;

		EsAtacado += gcnew Action(this, &Maligno3::Muere);
		posicion = p;
		tipo = m3;
		vida = pVida;
		indiceSprite = 0;
		ancho = 64;
		alto = 64;
		visible = true;
		estado = Idle;
		velocidad = 8;
	}
	void Maligno3::MostrarSprite(Graphics^ graphics)
	{
		if (direccion == Arriba)
			subIndice = 0;
		else if (direccion == Abajo)
			subIndice = 1;
		else if (direccion == Izquierda)
			subIndice = 2;
		else if (direccion == Derecha)
			subIndice = 3;

		if (estado == Idle)
			Avanzar();

		else if (estado == Muriendo)
		{
			indiceSprite++;
			subIndice = 5;

			if (indiceSprite == 8)//Termina animacion de muerte
			{
				visible = false;
				Winform::malignos->malignosRestantes--;

				if (Winform::malignos->malignosRestantes == 0)
				{
					if (Winform::upecino->estado != Celebrando)
					{
						Winform::upecino->estado = Celebrando;
						Winform::upecino->indiceSprite = -1;
					}
				}
				return;
			}
		}

		graphics->DrawImage(imagen, Rectangle(posicion->x, posicion->y, ancho, alto), Rectangle(indiceSprite * 24, subIndice * 24, 23, 23), GraphicsUnit::Pixel);
	}
	
	void Maligno3::Muere()
	{
		estado = Muriendo;
		indiceSprite = -1;
	}
	
	void Maligno3::Avanzar()
	{
		indiceSprite++;

		if ((posicion->x % 128 == 0) && (posicion->y % 128 == 0))
			CambiarDeDireccion();

		if (indiceSprite == 8)
			indiceSprite = 0;

		Objeto^ objeto = Objeto::getObjetoColisionante(direccion, velocidad, this->posicion);

		if (objeto->tipo == oBomba)
		{
			CambiarDeDireccion();
			return;
		}
		if (objeto->tipo == oBloque)
		{
			CambiarDeDireccion();
			return;
		}
		if (objeto->tipo == oCaja)
		{
			CambiarDeDireccion();
			return;
		}
		if (objeto->tipo == oItem)
		{
			posicion->Aumentar(direccion, velocidad);
			return;
		}
		if (objeto->tipo == oPortal)
		{
			posicion->Aumentar(direccion, velocidad);
			return;
		}
		if (objeto->tipo == oPiso)
		{
			posicion->Aumentar(direccion, velocidad);
			return;
		}
	}

	void Maligno3::CambiarDeDireccion()
	{
		int random = Winform::aleatorio->Next(3);

		if (direccion == Arriba)
		{
			if (random == 0)
				direccion = Abajo;
			else if (random == 1)
				direccion = Izquierda;
			else if (random == 2)
				direccion = Derecha;
		}
		else if (direccion == Abajo)
		{
			if (random == 0)
				direccion = Arriba;
			else if (random == 1)
				direccion = Izquierda;
			else if (random == 2)
				direccion = Derecha;
		}
		else if (direccion == Izquierda)
		{
			if (random == 0)
				direccion = Arriba;
			else if (random == 1)
				direccion = Abajo;
			else if (random == 2)
				direccion = Derecha;
		}
		else if (direccion == Derecha)
		{
			if (random == 0)
				direccion = Arriba;
			else if (random == 1)
				direccion = Abajo;
			else if (random == 2)
				direccion = Izquierda;
		}
	}

}