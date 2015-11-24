#include "Winform.h"

namespace Bomberman
{
	Nivel1::Nivel1()
	{
		Objetos matriz[9][13] = {
			{ oPiso, oPiso, oPiso, oPiso, oCaja, oPiso, oPiso, oPiso, oPiso, oPiso, oPiso, oPiso, oPiso },
			{ oPiso, oBloque, oPiso, oBloque, oPiso, oBloque, oPiso, oBloque, oPiso, oBloque, oPiso, oBloque, oPiso },
			{ oPiso, oPiso, oCaja, oPiso, oCaja, oPortal, oCaja, oPiso, oCaja, oPiso, oPiso, oPiso, oPiso },
			{ oPiso, oBloque, oPiso, oBloque, oCaja, oBloque, oPiso, oBloque, oPiso, oBloque, oPiso, oBloque, oPiso },
			{ oPiso, oPiso, oPiso, oPiso, oPiso, oPiso, oPiso, oCaja, oPiso, oPiso, oCaja, oPiso, oPiso },
			{ oPiso, oBloque, oPiso, oBloque, oPiso, oBloque, oPiso, oBloque, oPiso, oBloque, oPiso, oBloque, oPiso },
			{ oPiso, oPiso, oCaja, oPiso, oPiso, oPiso, oPiso, oPiso, oPiso, oPiso, oPiso, oPiso, oPiso },
			{ oPiso, oBloque, oPiso, oBloque, oPiso, oBloque, oPiso, oBloque, oPiso, oBloque, oPiso, oBloque, oPiso },
			{ oCaja, oPiso, oCaja, oPiso, oCaja, oPiso, oPiso, oPiso, oPiso, oPiso, oPiso, oPiso, oPiso } };

		generarMatrizObjetos(matriz);

		arregloMalignos = gcnew ArrMalignos(4);
		arregloMalignos->arreglo[0] = gcnew Maligno1(gcnew Posicion(320, 0), 0);
		arregloMalignos->arreglo[1] = gcnew Maligno1(gcnew Posicion(448, 128), 0);
		arregloMalignos->arreglo[2] = gcnew Maligno1(gcnew Posicion(512, 384), 0);
		arregloMalignos->arreglo[3] = gcnew Maligno1(gcnew Posicion(640, 512), 0);
	}
}