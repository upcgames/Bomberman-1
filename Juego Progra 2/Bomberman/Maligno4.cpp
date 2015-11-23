#include "Winform.h"

namespace Bomberman
{
	Maligno4::Maligno4(Posicion^ p,  int pVida)
	{

	}
	void Maligno4::MostrarSprite(Graphics^ graphics)
	{
		graphics->DrawImage(imagen, Rectangle(0, 0, ancho, alto), Rectangle(0, 0, ancho, alto), GraphicsUnit::Pixel);
	}
	void Maligno4::CuandoBombaLeCae(int damageBomba)
	{

	}
	void Maligno4::Muere()
	{

	}
	void Maligno4::Avanzar()
	{

	}
}