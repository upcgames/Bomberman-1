#include "Winform.h"

namespace Bomberman
{
	MatrizObjetos::MatrizObjetos()
	{
		matriz = new Objetos*[13];
		for (int i = 0; i < 13; i++)
			matriz[i] = new Objetos[9];
	}

	MatrizObjetos::MatrizObjetos()
	{
		for (int i = 0; i < 13; ++i)
			delete[] matriz[i];

		delete[] matriz;
	}
}