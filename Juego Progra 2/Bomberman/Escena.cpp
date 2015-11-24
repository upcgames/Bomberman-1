#include "Winform.h"

namespace Bomberman
{
	Escena::Escena()
	{
		buffer = Winform::context->Allocate(Winform::graphics, Winform::winform->ClientRectangle);
		activo = false;
		dibujado = false;
		contador = 0;
	}
	void Escena::ActivarEscena(Escena^ escena)
	{
		escena->activo = true;

		if (escena->onTimerTick != nullptr)
			Winform::winform->timer->Tick += escena->onTimerTick;
		if (escena->onTimerTick != nullptr)
			Winform::winform->KeyDown += escena->onKeyDown;
		if (escena->onTimerTick != nullptr)
			Winform::winform->KeyUp += escena->onKeyUp;
		if (escena->onMouseClick != nullptr)
			Winform::winform->MouseClick += escena->onMouseClick;
	}

	void Escena::DesactivarEscena(Escena^ escena)
	{
		escena->activo = false;

		if (escena->onTimerTick != nullptr)
			Winform::winform->timer->Tick -= escena->onTimerTick;
		if (escena->onTimerTick != nullptr)
			Winform::winform->KeyDown -= escena->onKeyDown;
		if (escena->onTimerTick != nullptr)
			Winform::winform->KeyUp -= escena->onKeyUp;
		if (escena->onMouseClick != nullptr)
			Winform::winform->MouseClick -= escena->onMouseClick;

		escena->dibujado = false;
	}
}