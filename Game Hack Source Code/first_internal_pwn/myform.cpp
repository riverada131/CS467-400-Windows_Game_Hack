#include "MyForm.h"

using namespace first_internal_pwn;

int UIMain()
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	MyForm^ NewUi = gcnew MyForm();
	Application::Run(NewUi);
	return 1;
}

