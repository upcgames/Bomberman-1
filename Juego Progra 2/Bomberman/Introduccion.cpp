#include "Directorio.h"

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
				buffer->Graphics->Clear(Color::SkyBlue);
				buffer->Graphics->DrawString("Introduccion", gcnew Font("Arial", 16), gcnew SolidBrush(Color::White), Point(350, 300));
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