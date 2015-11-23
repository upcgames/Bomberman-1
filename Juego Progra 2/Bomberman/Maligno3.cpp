#include "Winform.h"

namespace Bomberman
{
	Maligno3::Maligno3(Posicion^ p, Malignos pTipo, int pVida)
	{

	}
	void Maligno3::MostrarSprite(Graphics^ graphics)
	{
		graphics->DrawImage(imagen, Rectangle(0, 0, ancho, alto), Rectangle(0, 0, ancho, alto), GraphicsUnit::Pixel);
	}
	void Maligno3::CuandoBombaLeCae(int damageBomba)
	{

	}
	void Maligno3::CuandoMuere()
	{

	}
	void Maligno3::Avanzar()
	{

	}
}