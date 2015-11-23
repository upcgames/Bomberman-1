#include "Winform.h"

namespace Bomberman
{
	void Maligno::ColisionMaligno_Fuego(int xFuego, int yFuego)
	{
		for (int i = 0; i < Winform::malignos->cantidad; i++)
		{
			if (Winform::malignos->arreglo[i]->visible)
				if (Winform::malignos->arreglo[i]->getBody().IntersectsWith(Figura::getBody(xFuego, yFuego, 64, 64)))
					Winform::malignos->arreglo[i]->EsAtacado();
		}
	}
}