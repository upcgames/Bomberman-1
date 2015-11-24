#include "WinForm.h"

namespace Bomberman
{
	GameOver::GameOver()
	{
		onTimerTick = gcnew EventHandler(this, &GameOver::timerTick);
		onKeyDown = gcnew KeyEventHandler(this, &GameOver::teclaDown);
	}

	void GameOver::timerTick(System::Object^  sender, System::EventArgs^  e)
	{
		if (activo)
		{
			if (!dibujado)
			{
				buffer->Graphics->Clear(Color::MediumSeaGreen);
				buffer->Graphics->DrawString("GameOver", gcnew Font("Arial", 16), gcnew SolidBrush(Color::White), Point(350, 300));
				buffer->Render(Winform::graphics);
				dibujado = true;
			}
		}
	}

	void GameOver::teclaDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e)
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