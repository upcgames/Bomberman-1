#include "WinForm.h"

namespace Bomberman
{
	Instrucciones::Instrucciones()
	{
		onTimerTick = gcnew EventHandler(this, &Instrucciones::timerTick);
		onKeyDown = gcnew KeyEventHandler(this, &Instrucciones::teclaDown);
	}

	void Instrucciones::timerTick(System::Object^  sender, System::EventArgs^  e)
	{
		if (activo)
		{
			if (!dibujado)
			{
				buffer->Graphics->DrawImage(Imagenes::Instrucciones, Rectangle(0, 0, 832, 577));
				buffer->Render(Winform::graphics);
				dibujado = true;
			}
		}
	}

	void Instrucciones::teclaDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e)
	{
		if (activo && dibujado)
		{
			if (e->KeyCode == Keys::Enter)
			{
				DesactivarEscena(this);
				if (Winform::pausa->opcion == "Instrucciones")
					ActivarEscena(Winform::pausa);
				else
					ActivarEscena(Winform::inicio);
			}

		}
	}
}