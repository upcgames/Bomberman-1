#include "WinForm.h"

namespace Bomberman
{
	Creditos::Creditos()
	{
		onTimerTick = gcnew EventHandler(this, &Creditos::timerTick);
		onKeyDown = gcnew KeyEventHandler(this, &Creditos::teclaDown);
	}

	void Creditos::timerTick(System::Object^  sender, System::EventArgs^  e)
	{
		if (activo)
		{
			if (!dibujado)
			{
				buffer->Graphics->DrawImage(Imagenes::Creditos, Rectangle(0, 0, 832, 577));
				buffer->Render(Winform::graphics);
				dibujado = true;
			}
		}
	}

	void Creditos::teclaDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e)
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