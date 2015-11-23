#include "Winform.h"

namespace Bomberman
{
	Maligno2::Maligno2(Posicion^ p, int pVida)
	{

	}
	void Maligno2::MostrarSprite(Graphics^ graphics)
	{
		graphics->DrawImage(imagen, Rectangle(0, 0, ancho, alto), Rectangle(0, 0, ancho, alto), GraphicsUnit::Pixel);
	}
	void Maligno2::CuandoBombaLeCae(int damageBomba)
	{

	}
	void Maligno2::Muere()
	{

	}
	void Maligno2::Avanzar()
	{

	}
}