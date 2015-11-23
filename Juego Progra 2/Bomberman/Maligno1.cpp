#include "Winform.h"

namespace Bomberman
{
	Maligno1::Maligno1(Posicion^ p, Malignos pTipo, int pVida)
	{

	}
	void Maligno1::MostrarSprite(Graphics^ graphics)
	{
		graphics->DrawImage(imagen, Rectangle(0, 0, ancho, alto), Rectangle(0, 0, ancho, alto), GraphicsUnit::Pixel);
	}
	void Maligno1::CuandoBombaLeCae(int damageBomba)
	{

	}
	void Maligno1::CuandoMuere()
	{

	}
	void Maligno1::Avanzar()
	{
	
	}
}