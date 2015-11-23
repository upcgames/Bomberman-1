#include "Winform.h"

namespace Bomberman
{
	Nivel1::Nivel1()
	{
		matrizObjetos = gcnew MatrizObjetos();
		matrizObjetos->matriz = gcnew array<Objeto^, 2>(13, 9);

		matrizObjetos->matriz[0, 2] = gcnew Caja(gcnew Posicion(0, 128));
		matrizObjetos->matriz[0, 3] = gcnew Caja(gcnew Posicion(0, 192));
		matrizObjetos->matriz[0, 7] = gcnew Caja(gcnew Posicion(0, 448));
		matrizObjetos->matriz[0, 8] = gcnew Caja(gcnew Posicion(0, 512));
		matrizObjetos->matriz[2, 1] = gcnew Caja(gcnew Posicion(128, 64));
		matrizObjetos->matriz[2, 3] = gcnew Caja(gcnew Posicion(128, 192));
		matrizObjetos->matriz[2, 5] = gcnew Caja(gcnew Posicion(128, 320));
		matrizObjetos->matriz[3, 0] = gcnew Caja(gcnew Posicion(192, 0));
		matrizObjetos->matriz[4, 3] = gcnew Caja(gcnew Posicion(256, 192));
		matrizObjetos->matriz[4, 8] = gcnew Caja(gcnew Posicion(256, 512));
		matrizObjetos->matriz[5, 2] = gcnew Caja(gcnew Posicion(320, 128));
		matrizObjetos->matriz[5, 4] = gcnew Caja(gcnew Posicion(320, 256));
		matrizObjetos->matriz[6, 0] = gcnew Caja(gcnew Posicion(384, 0));
		matrizObjetos->matriz[6, 2] = gcnew Caja(gcnew Posicion(384, 128));
		matrizObjetos->matriz[6, 5] = gcnew Caja(gcnew Posicion(384, 320));
		matrizObjetos->matriz[6, 7] = gcnew Caja(gcnew Posicion(384, 448));
		matrizObjetos->matriz[8, 0] = gcnew Caja(gcnew Posicion(512, 0));
		matrizObjetos->matriz[8, 5] = gcnew Caja(gcnew Posicion(512, 320));
		matrizObjetos->matriz[8, 7] = gcnew Caja(gcnew Posicion(512, 448));
		matrizObjetos->matriz[8, 8] = gcnew Caja(gcnew Posicion(512, 512));
		matrizObjetos->matriz[9, 4] = gcnew Caja(gcnew Posicion(576, 256));
		matrizObjetos->matriz[10, 2] = gcnew Caja(gcnew Posicion(640, 128));
		matrizObjetos->matriz[10, 5] = gcnew Caja(gcnew Posicion(640, 320));
		matrizObjetos->matriz[10, 7] = gcnew Caja(gcnew Posicion(640, 448));
		matrizObjetos->matriz[11, 0] = gcnew Caja(gcnew Posicion(704, 0));
		matrizObjetos->matriz[11, 2] = gcnew Caja(gcnew Posicion(704, 128));
		matrizObjetos->matriz[11, 6] = gcnew Caja(gcnew Posicion(704, 384));
		matrizObjetos->matriz[12, 0] = gcnew Caja(gcnew Posicion(768, 0));
		matrizObjetos->matriz[12, 3] = gcnew Caja(gcnew Posicion(768, 192));
		matrizObjetos->matriz[12, 8] = gcnew Caja(gcnew Posicion(768, 512));

		for (int y = 0; y < 9; y++)
		{
			if (y % 2 == 0)
			{
				for (int x = 0; x < 13; x++)
				{
					if (matrizObjetos->matriz[x, y] == nullptr)
						matrizObjetos->matriz[x, y] = gcnew Piso(gcnew Posicion(x * 64, y * 64));
				}
			}
			else
			{
				for (int x = 0; x < 13; x++)
				{
					if (x % 2 == 0)
					{ 
						if (matrizObjetos->matriz[x, y] == nullptr)
							matrizObjetos->matriz[x, y] = gcnew Piso(gcnew Posicion(x * 64, y * 64));
					}
					else
					{
						if (matrizObjetos->matriz[x, y] == nullptr)
							matrizObjetos->matriz[x, y] = gcnew Bloque(gcnew Posicion(x * 64, y * 64));
					}
				}
			}
		}
		
		arregloMalignos = gcnew ArrMalignos(4);
		arregloMalignos->arreglo[0] = gcnew Maligno1(gcnew Posicion(320, 0), 0);
		arregloMalignos->arreglo[1] = gcnew Maligno1(gcnew Posicion(448, 128), 0);
		arregloMalignos->arreglo[2] = gcnew Maligno1(gcnew Posicion(512, 384), 0);
		arregloMalignos->arreglo[3] = gcnew Maligno1(gcnew Posicion(640, 512), 0);
	}
}