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
			{ oCaja, oCaja, oCaja, oCaja, oCaja, oCaja, oCaja, oCaja, oCaja, oCaja, oCaja, oCaja, oCaja },
			{ oPiso, oBloque, oCaja, oBloque, oPiso, oBloque, oPiso, oBloque, oPiso, oBloque, oCaja, oBloque, oPiso },
			{ oPiso, oPiso, oCaja, oPiso, oPiso, oPiso, oCaja, oPiso, oPortal, oPiso, oCaja, oPiso, oPiso } };

		generarMatrizObjetos(matriz);

		arregloMalignos = gcnew ArrMalignos(3);
		arregloMalignos->arreglo[0] = gcnew Maligno1(gcnew Posicion(768, 192), 0);
		arregloMalignos->arreglo[1] = gcnew Maligno1(gcnew Posicion(512, 256), 0);
		arregloMalignos->arreglo[2] = gcnew Maligno1(gcnew Posicion(128, 320), 0);
	}
}