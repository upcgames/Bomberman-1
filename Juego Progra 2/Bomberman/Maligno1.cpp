#include "Winform.h"

namespace Bomberman
{
	Maligno1::Maligno1(Posicion^ p, int pVida)
	{
		imagen = Imagenes::NinjaBombermanSprite;
		
		EsAtacado += gcnew Action(this, &Maligno1::Muere);
		posicion = p;
		tipo = m1;
		vida = pVida;
		contador = -1;
		indiceSprite = 0;
		ancho = 64;
		alto = 64;
		direccion = Abajo;
		visible = true;
		estado = Idle;
		velocidad = 0;
	}
	void Maligno1::MostrarSprite(Graphics^ graphics)
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
	void Maligno1::Muere()
	{
		estado = Muriendo;
		indiceSprite = -1;
	}
	void Maligno1::Avanzar()
	{
		contador++;

		indiceSprite = (contador % 8);
		
		if (contador % 8 == 0)
			this->direccion = (Direcciones)(Winform::aleatorio->Next(4));
	}
}