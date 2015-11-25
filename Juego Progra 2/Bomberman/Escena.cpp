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

	void Escena::CambiarEscena(Escena^ escena)
	{
		
		if (Winform::introduccion->activo)
			DesactivarEscena(Winform::introduccion);
		if (Winform::inicio->activo)
			DesactivarEscena(Winform::inicio);
		if (Winform::instrucciones->activo)
			DesactivarEscena(Winform::instrucciones);
		 if(Winform::juego->activo)
			 DesactivarEscena(Winform::juego);
		 if(Winform::pausa->activo)
			 DesactivarEscena(Winform::pausa);
		 if(Winform::youWin->activo)
			 DesactivarEscena(Winform::youWin);
		 if(Winform::gameOver->activo)
			 DesactivarEscena(Winform::gameOver);
		 if(Winform::congratulations->activo)
			DesactivarEscena(Winform::congratulations);
		 if (Winform::creditos->activo)
			DesactivarEscena(Winform::creditos);

		ActivarEscena(escena);
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