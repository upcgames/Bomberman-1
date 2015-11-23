#include "WinForm.h"

namespace Bomberman
{
	InGame::InGame()
	{
		onTimerTick = gcnew EventHandler(this, &InGame::timerTick);
		onKeyDown = gcnew KeyEventHandler(this, &InGame::teclaDown);
		onKeyUp = gcnew KeyEventHandler(this, &InGame::teclaUp);
	}

	void InGame::timerTick(System::Object^  sender, System::EventArgs^  e)
	{
		if (activo)
		{
			if (!dibujado)
			{
				buffer->Graphics->Clear(Color::Tomato);
				buffer->Graphics->DrawString("InGame", gcnew Font("Arial", 16), gcnew SolidBrush(Color::White), Point(350, 300));
				buffer->Render(Winform::graphics);
				dibujado = true;
			}
		}
	}
	
	void InGame::teclaDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e)
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

	void InGame::teclaUp(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e)
	{
	
	}
}