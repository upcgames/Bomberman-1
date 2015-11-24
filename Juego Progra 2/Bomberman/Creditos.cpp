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
				buffer->Graphics->Clear(Color::LightGoldenrodYellow);
				buffer->Graphics->DrawString("Creditos", gcnew Font("Arial", 16), gcnew SolidBrush(Color::White), Point(350, 300));
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