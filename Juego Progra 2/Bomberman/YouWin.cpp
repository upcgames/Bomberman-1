#include "WinForm.h"

namespace Bomberman
{
	YouWin::YouWin()
	{
		onTimerTick = gcnew EventHandler(this, &YouWin::timerTick);
		onKeyDown = gcnew KeyEventHandler(this, &YouWin::teclaDown);
	}

	void YouWin::timerTick(System::Object^  sender, System::EventArgs^  e)
	{
		if (activo)
		{
			if (!dibujado)
			{
				buffer->Graphics->DrawImage(Imagenes::YouWin, Rectangle(0, 0, 832, 577));
				buffer->Render(Winform::graphics);
				dibujado = true;
			}
		}
	}

	void YouWin::teclaDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e)
	{
		if (activo && dibujado)
		{
			if (e->KeyCode == Keys::Enter)
			{
				DesactivarEscena(this);
				ActivarEscena(Winform::juego);
				Nivel::PasarANivel(Winform::juego->nivel + 1);
			}

		}
	}
}