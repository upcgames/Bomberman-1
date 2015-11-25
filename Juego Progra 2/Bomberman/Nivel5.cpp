#include "Winform.h"

namespace Bomberman
{
	Nivel5::Nivel5()
	{
		Objetos matriz[9][13] = {
			{ oPiso, oPiso, oCaja, oPiso, oPiso, oPiso, oCaja, oPiso, oPiso, oPiso, oCaja, oPiso, oPiso },
			{ oPiso, oBloque, oCaja, oBloque, oPiso, oBloque, oPiso, oBloque, oPiso, oBloque, oCaja, oBloque, oPiso },
			{ oCaja, oCaja, oCaja, oCaja, oCaja, oCaja, oCaja, oCaja, oCaja, oCaja, oCaja, oCaja, oCaja },
			{ oPiso, oBloque, oCaja, oBloque, oPiso, oBloque, oPiso, oBloque, oPiso, oBloque, oCaja, oBloque, oPiso },
			{ oPiso, oPiso, oCaja, oPiso, oPiso, oCaja, oCaja, oCaja, oPiso, oPiso, oCaja, oPiso, oPiso },
			{ oPiso, oBloque, oCaja, oBloque, oPiso, oBloque, oPiso, oBloque, oPiso, oBloque, oCaja, oBloque, oPiso },
			{ oCaja, oCaja, oPiso, oCaja, oCaja, oCaja, oCaja, oCaja, oCaja, oCaja, oCaja, oCaja, oCaja },
			{ oPiso, oBloque, oCaja, oBloque, oPiso, oBloque, oPiso, oBloque, oPiso, oBloque, oCaja, oBloque, oPiso },
			{ oPiso, oPiso, oCaja, oPiso, oPiso, oPiso, oCaja, oPiso, oPortal, oPiso, oCaja, oPiso, oPiso } };

		generarMatrizObjetos(matriz);

		arregloMalignos = gcnew ArrMalignos(8);
		arregloMalignos->arreglo[0] = gcnew Maligno4(gcnew Posicion(128, 320), 0);
		arregloMalignos->arreglo[1] = gcnew Maligno4(gcnew Posicion(128, 320), 0);
		arregloMalignos->arreglo[2] = gcnew Maligno4(gcnew Posicion(128, 320), 0);
		arregloMalignos->arreglo[3] = gcnew Maligno4(gcnew Posicion(128, 320), 0);
		arregloMalignos->arreglo[4] = gcnew Maligno4(gcnew Posicion(128, 320), 0);
		arregloMalignos->arreglo[5] = gcnew Maligno4(gcnew Posicion(128, 320), 0);
		arregloMalignos->arreglo[6] = gcnew Maligno4(gcnew Posicion(128, 320), 0);
		arregloMalignos->arreglo[7] = gcnew Maligno4(gcnew Posicion(128, 320), 0);
	}
}