#include "Winform.h"

namespace Bomberman
{
	ArrMalignos::ArrMalignos(int size)
	{
		arreglo = gcnew array <Maligno^>(size);
		cantidad = size;
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

	}
}