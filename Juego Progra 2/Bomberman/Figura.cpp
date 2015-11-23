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

	Rectangle Figura::getBody(int xx, int yy, int pAncho, int pAlto)
	{
		return Rectangle(xx, yy, pAncho, pAlto);
	}
}