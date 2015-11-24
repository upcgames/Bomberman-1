#include "Winform.h"

namespace Bomberman
{
	Nivel5::Nivel5()
	{
		Objetos matriz[9][13] = {
			{ oPiso, oPiso, oCaja, oPiso, oPiso, oPiso, oCaja, oPiso, oPiso, oPiso, oCaja, oPiso, oPiso },
			{ oPiso, oBloque, oCaja, oBloque, oPiso, oBloque, oPiso, oBloque, oPiso, oBloque, oPiso, oBloque, oPiso },
			{ oCaja, oPiso, oCaja, oPiso, oPiso, oCaja, oPiso, oPiso, oCaja, oPiso, oPiso, oPiso, oPiso },
			{ oCaja, oBloque, oPiso, oBloque, oPiso, oBloque, oPiso, oBloque, oPiso, oBloque, oCaja, oBloque, oPiso },
			{ oPiso, oPiso, oPiso, oPiso, oCaja, oPiso, oPiso, oPiso, oPiso, oPiso, oPiso, oPiso, oPiso },
			{ oPiso, oBloque, oCaja, oBloque, oPiso, oBloque, oPiso, oBloque, oCaja, oBloque, oPiso, oBloque, oPiso },
			{ oCaja, oPiso, oPiso, oCaja, oPiso, oPiso, oCaja, oPiso, oCaja, oPiso, oCaja, oCaja, oCaja },
			{ oPiso, oBloque, oPiso, oBloque, oPiso, oBloque, oPiso, oBloque, oPiso, oBloque, oCaja, oBloque, oCaja },
			{ oPiso, oPiso, oCaja, oPiso, oCaja, oPiso, oPiso, oCaja, oPiso, oPiso, oCaja, oCaja, oPortal } };

		generarMatrizObjetos(matriz);

		arregloMalignos = gcnew ArrMalignos(2);
		arregloMalignos->arreglo[0] = gcnew Maligno1(gcnew Posicion(0, 512), 0);
		arregloMalignos->arreglo[1] = gcnew Maligno1(gcnew Posicion(128, 384), 0);
	}
}