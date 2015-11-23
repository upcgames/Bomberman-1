#include "Winform.h"

using namespace System;
using namespace System::Windows::Forms;

namespace Bomberman
{
	[STAThread]
	void main()
	{
		Application::EnableVisualStyles();
		Application::SetCompatibleTextRenderingDefault(false);

		Winform^ w = gcnew Winform();

		Application::Run(w);
	}
}




