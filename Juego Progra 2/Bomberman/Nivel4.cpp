#include "Winform.h"

namespace Bomberman
{
	Nivel4::Nivel4()
	{
		Objetos matriz[9][13] = {
			{ oPiso, oPiso, oPiso, oPiso, oCaja, oPiso, oPiso, oPiso, oCaja, oPiso, oCaja, oPiso, oPiso },
			{ oPiso, oBloque, oPiso, oBloque, oPiso, oBloque, oPiso, oBloque, oPiso, oBloque, oPiso, oBloque, oPiso },
			{ oCaja, oCaja, oCaja, oPiso, oCaja, oPiso, oPiso, oPiso, oPiso, oPiso, oPiso, oPiso, oPiso },
			{ oCaja, oBloque, oPiso, oBloque, oPiso, oBloque, oPiso, oBloque, oPiso, oBloque, oPiso, oBloque, oPiso },
			{ oPiso, oPiso, oCaja, oPiso, oPiso, oPiso, oCaja, oPiso, oCaja, oPiso, oCaja, oPiso, oPiso },
			{ oPiso, oBloque, oPiso, oBloque, oPiso, oBloque, oPiso, oBloque, oPiso, oBloque, oPiso, oBloque, oPiso },
			{ oCaja, oCaja, oPiso, oPiso, oCaja, oPiso, oPiso, oPiso, oCaja, oPiso, oCaja, oPiso, oPiso },
			{ oPiso, oBloque, oPiso, oBloque, oPiso, oBloque, oPiso, oBloque, oPiso, oBloque, oPiso, oBloque, oPiso },
			{ oPortal, oPiso, oPiso, oPiso, oCaja, oPiso, oCaja, oPiso, oCaja, oPiso, oPiso, oPiso, oPiso } };

		generarMatrizObjetos(matriz);

		arregloMalignos = gcnew ArrMalignos(4);
		arregloMalignos->arreglo[0] = gcnew Maligno3(gcnew Posicion(384, 384), 0);
		arregloMalignos->arreglo[1] = gcnew Maligno3(gcnew Posicion(768, 0), 0);
		arregloMalignos->arreglo[2] = gcnew Maligno3(gcnew Posicion(512, 64), 0);
		arregloMalignos->arreglo[3] = gcnew Maligno3(gcnew Posicion(768, 512), 0);
	}
}