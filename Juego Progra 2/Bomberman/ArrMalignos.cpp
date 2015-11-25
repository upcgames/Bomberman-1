#include "Winform.h"

namespace Bomberman
{
	ArrMalignos::ArrMalignos(int size)
	{
		arreglo = gcnew array <Maligno^>(size);
		cantidad = size;
		malignosRestantes = cantidad;
	}
	void ArrMalignos::EliminarMaligno(Maligno^ maligno)
	{
		array<Maligno^>^ auxiliar = gcnew array <Maligno^>(cantidad - 1);
		int j = 0;

		for (int i = 0; i < cantidad; i++)
		{
			if (auxiliar[i] != maligno)
			{
				auxiliar[i] = arreglo[j];
				j++;
			}
		}

		cantidad--;
		delete arreglo;

		arreglo = auxiliar;
	}
	void ArrMalignos::MostrarMalignos(Graphics^ graphics)
	{
		for (int i = 0; i < cantidad; i++)
		{
			if (arreglo[i]->visible)
			{
				if (arreglo[i]->getBody().IntersectsWith(Winform::upecino->getBody()) && arreglo[i]->estado != Muriendo)
					Winform::upecino->EsAtacado();
				if (arreglo[i]->tipo == m1)
					dynamic_cast<Maligno1^>(arreglo[i])->MostrarSprite(graphics);
				if (arreglo[i]->tipo == m2)
					dynamic_cast<Maligno2^>(arreglo[i])->MostrarSprite(graphics);
				if (arreglo[i]->tipo == m3)
					dynamic_cast<Maligno3^>(arreglo[i])->MostrarSprite(graphics);
				if (arreglo[i]->tipo == m4)
					dynamic_cast<Maligno4^>(arreglo[i])->MostrarSprite(graphics);
			}
		}
	}
}