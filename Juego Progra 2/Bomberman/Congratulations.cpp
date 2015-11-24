#include "WinForm.h"

namespace Bomberman
{
	Congratulations::Congratulations()
	{
		onTimerTick = gcnew EventHandler(this, &Congratulations::timerTick);
		onKeyDown = gcnew KeyEventHandler(this, &Congratulations::teclaDown);
	}

	void Congratulations::timerTick(System::Object^  sender, System::EventArgs^  e)
	{
		if (activo)
		{
			if (!dibujado)
			{
				buffer->Graphics->DrawImage(Imagenes::Congratulations, Rectangle(0, 0, 832, 577));
				buffer->Render(Winform::graphics);
				dibujado = true;
			}
		}
	}

	void Congratulations::teclaDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e)
	{
		if (activo && dibujado)
		{
			if (e->KeyCode == Keys::Enter)
			{
				DesactivarEscena(this);
				ActivarEscena(Winform::creditos);
			}

		}
	}
}