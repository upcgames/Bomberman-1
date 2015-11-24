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
				buffer->Graphics->Clear(Color::Bisque);
				buffer->Graphics->DrawString("Instrucciones", gcnew Font("Arial", 16), gcnew SolidBrush(Color::White), Point(350, 300));
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