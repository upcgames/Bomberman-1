#include "Winform.h"

namespace Bomberman
{
	ArrBombas::ArrBombas()
	{
		arreglo = nullptr;
		cantidad = 0;
	}
	array<Bomba^>^ ArrBombas::CrearArreglo(int size)
	{
		return gcnew array<Bomba^>(size);
	}

	void ArrBombas::AgregarBomba(Bomba^ bomba)
	{
		if (Upecino::contadorBombas == cantidad)
			return;

		array<Bomba^>^ auxiliar;

		if (arreglo == nullptr)
		{
			auxiliar = CrearArreglo(1);
			auxiliar[0] = bomba;
		}
	
		else
		{
			auxiliar = CrearArreglo(arreglo->Length + 1);
			for (int i = 0; i < arreglo->Length; i++)
				auxiliar[i] = arreglo[i];
			auxiliar[arreglo->Length] = bomba;
		}
	
		cantidad++;

		if (arreglo != nullptr)
			delete arreglo;

		arreglo = auxiliar;
	}
	void ArrBombas::MostrarBombas(Graphics^ graphics)
	{
		if (arreglo == nullptr)
			return;

		CorrerBombas();

		for (int i = 0; i < arreglo->Length; i++)
		{
			if (arreglo[i]->visible)
				arreglo[i]->MostrarSprite(graphics);

			if (arreglo[i]->tiempo == 0)
			{
				arreglo[i]->tiempo -= 10;
				arreglo[i]->visible = false;
				cantidad--;
			}
		}

		if (cantidad == 0 && arreglo != nullptr)
			LimpiarArreglo();
	}
	void ArrBombas::CorrerBombas()
	{
		for (int i = 0; i < arreglo->Length; i++)
		{
			arreglo[i]->tiempo -= 1;
		}
	}
	void ArrBombas::LimpiarArreglo()
	{
			delete arreglo;
			arreglo = nullptr;
			cantidad = 0;
	}

	Bomba^ ArrBombas::getBomba(int pX, int pY)
	{
		if (arreglo == nullptr)
			return nullptr;

		for (int i = 0; i < arreglo->Length; i++)
		{
			if (arreglo[i]->visible && arreglo[i]->posicion->x == pX * 64 && arreglo[i]->posicion->y == pY * 64)
				return arreglo[i];
		}

		return nullptr;
	}
}