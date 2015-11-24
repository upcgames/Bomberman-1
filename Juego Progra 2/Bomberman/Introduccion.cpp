#include "WinForm.h"

namespace Bomberman
{
	Introduccion::Introduccion()
	{
		onTimerTick = gcnew EventHandler(this, &Introduccion::timerTick);
		onKeyDown = gcnew KeyEventHandler(this, &Introduccion::teclaDown);
	}

	void Introduccion::timerTick(System::Object^  sender, System::EventArgs^  e)
	{
		if (activo)
		{
			if (!dibujado)
			{
				buffer->Graphics->DrawImage(Imagenes::Introducion, Rectangle(0, 0, 832, 577));
				buffer->Render(Winform::graphics);
				dibujado = true;
			}
		}
	}
	
	void Introduccion::teclaDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e)
	{
		if (activo && dibujado)
		{
			if (e->KeyCode == Keys::Enter)
			{
				DesactivarEscena(this);
				ActivarEscena(Winform::inicio);
			}

		}
	}
}