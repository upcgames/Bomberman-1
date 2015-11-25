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
		arregloMalignos->arreglo[0] = gcnew Maligno2(gcnew Posicion(0, 128), Abajo, 0);
		arregloMalignos->arreglo[1] = gcnew Maligno2(gcnew Posicion(0, 384), Arriba, 0);
		arregloMalignos->arreglo[2] = gcnew Maligno2(gcnew Posicion(768, 128), Derecha, 0);
		arregloMalignos->arreglo[3] = gcnew Maligno2(gcnew Posicion(768, 384), Izquierda, 0);
		arregloMalignos->arreglo[4] = gcnew Maligno2(gcnew Posicion(384, 256), Abajo, 0);
		arregloMalignos->arreglo[5] = gcnew Maligno2(gcnew Posicion(384, 256), Derecha, 0);
	}
}