#include "WinForm.h"

namespace Bomberman
{
	Inicio::Inicio()
	{
		onTimerTick = gcnew EventHandler(this, &Inicio::timerTick);
		onKeyDown = gcnew KeyEventHandler(this, &Inicio::teclaDown);
	}

	void Inicio::timerTick(System::Object^  sender, System::EventArgs^  e)
	{
		if (activo)
		{
			if (!dibujado)
			{
				buffer->Graphics->Clear(Color::SlateBlue);
				buffer->Graphics->DrawString("Inicio", gcnew Font("Arial", 16), gcnew SolidBrush(Color::White), Point(350, 300));
				buffer->Render(Winform::graphics);
				dibujado = true;
			}
		}
	}

	void Inicio::teclaDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e)
	{
		if (activo && dibujado)
		{
			if (e->KeyCode == Keys::Enter)
			{
				DesactivarEscena(this);
				ActivarEscena(Winform::inGame);
			}

		}
	}
}