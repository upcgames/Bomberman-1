#include "Directorio.h"

using namespace System::Windows::Forms;

namespace Bomberman
{
	public ref class Figura
	{
	public:
		Image^ imagen;
		Posicion^ posicion;
		int alto;
		int ancho;
		int indiceSprite;
		int subIndice;
		Figura();
		Rectangle getBody();
		static Rectangle getBody(int xx, int yy, int pAncho, int pAlto);
	};

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