#include "Winform.h"

using namespace System::Windows::Forms;

namespace Bomberman
{
	Figura::Figura()
	{

	}

	Rectangle Figura::getBody()
	{
		return Rectangle(posicion->x, posicion->y, ancho, alto);
	}
}


