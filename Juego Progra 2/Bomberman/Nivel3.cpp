#include "Winform.h"

namespace Bomberman
{
	Nivel3::Nivel3()
	{
		Objetos matriz[9][13] = {
			{ oPiso, oPiso, oCaja, oPiso, oCaja, oPiso, oCaja, oPiso, oCaja, oPiso, oCaja, oPiso, oPiso },
			{ oPiso, oBloque, oPiso, oBloque, oPiso, oBloque, oPiso, oBloque, oPiso, oBloque, oPiso, oBloque, oPiso },
			{ oPiso, oPiso, oCaja, oPiso, oCaja, oPiso, oCaja, oPiso, oCaja, oPiso, oCaja, oPiso, oPiso },
			{ oPiso, oBloque, oPiso, oBloque, oPiso, oBloque, oPiso, oBloque, oPiso, oBloque, oPiso, oBloque, oPiso },
			{ oPiso, oPiso, oCaja, oPiso, oCaja, oPiso, oPortal, oPiso, oCaja, oPiso, oCaja, oPiso, oPiso },
			{ oPiso, oBloque, oPiso, oBloque, oPiso, oBloque, oPiso, oBloque, oPiso, oBloque, oPiso, oBloque, oPiso },
			{ oPiso, oPiso, oCaja, oPiso, oCaja, oPiso, oCaja, oPiso, oCaja, oPiso, oCaja, oPiso, oPiso },
			{ oPiso, oBloque, oPiso, oBloque, oPiso, oBloque, oPiso, oBloque, oPiso, oBloque, oPiso, oBloque, oPiso },
			{ oPiso, oPiso, oCaja, oPiso, oCaja, oPiso, oCaja, oPiso, oCaja, oPiso, oCaja, oPiso, oPiso } };

		generarMatrizObjetos(matriz);

		arregloMalignos = gcnew ArrMalignos(6);
		arregloMalignos->arreglo[0] = gcnew Maligno1(gcnew Posicion(64, 128), 0);
		arregloMalignos->arreglo[1] = gcnew Maligno1(gcnew Posicion(64, 384), 0);
		arregloMalignos->arreglo[2] = gcnew Maligno1(gcnew Posicion(704, 128), 0);
		arregloMalignos->arreglo[3] = gcnew Maligno1(gcnew Posicion(704, 384), 0);
		arregloMalignos->arreglo[4] = gcnew Maligno1(gcnew Posicion(384, 64), 0);
		arregloMalignos->arreglo[5] = gcnew Maligno1(gcnew Posicion(384, 448), 0);
	}
}