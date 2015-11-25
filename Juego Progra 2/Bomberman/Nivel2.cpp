#include "Winform.h"

namespace Bomberman
{
	Nivel2::Nivel2()
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
		
		arregloMalignos = gcnew ArrMalignos(6);
		arregloMalignos->arreglo[0] = gcnew Maligno2(gcnew Posicion(576, 512), Izquierda, 0);
		arregloMalignos->arreglo[1] = gcnew Maligno2(gcnew Posicion(768, 320), Arriba, 0);
		arregloMalignos->arreglo[2] = gcnew Maligno2(gcnew Posicion(640, 64), Abajo, 0);
		arregloMalignos->arreglo[3] = gcnew Maligno2(gcnew Posicion(256, 64), Arriba, 0);
		arregloMalignos->arreglo[4] = gcnew Maligno2(gcnew Posicion(0, 512), Abajo, 0);
		arregloMalignos->arreglo[5] = gcnew Maligno2(gcnew Posicion(128, 384), Derecha, 0);

	}
}