#include "Winform.h"

namespace Bomberman
{
	Maligno3::Maligno3(Posicion^ p, int pVida)
	{

	}
	void Maligno3::MostrarSprite(Graphics^ graphics)
	{
		graphics->DrawImage(imagen, Rectangle(0, 0, ancho, alto), Rectangle(0, 0, ancho, alto), GraphicsUnit::Pixel);
	}
	void Maligno3::CuandoBombaLeCae(int damageBomba)
	{

	}
	void Maligno3::Muere()
	{

	}
	void Maligno3::Avanzar()
	{

	}
}