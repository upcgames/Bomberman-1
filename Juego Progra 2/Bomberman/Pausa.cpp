#include "WinForm.h"

namespace Bomberman
{
	Pausa::Pausa()
	{
		onTimerTick = gcnew EventHandler(this, &Pausa::timerTick);
		onKeyDown = gcnew KeyEventHandler(this, &Pausa::teclaDown);
	}

	void Pausa::timerTick(System::Object^  sender, System::EventArgs^  e)
	{
		if (activo)
		{
			if (!dibujado)
			{
				buffer->Graphics->Clear(Color::Crimson);
				buffer->Graphics->DrawString("Pausa", gcnew Font("Arial", 16), gcnew SolidBrush(Color::White), Point(350, 300));
				buffer->Render(Winform::graphics);
				dibujado = true;
			}
		}
	}

	void Pausa::teclaDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e)
	{
		if (activo && dibujado)
		{
			if (e->KeyCode == Keys::Enter)
			{
				DesactivarEscena(this);
				ActivarEscena(Winform::youWin);
			}

		}
	}
}