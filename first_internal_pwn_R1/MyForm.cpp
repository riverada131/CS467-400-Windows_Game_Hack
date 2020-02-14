#include "pch.h"
#include "MyForm.h"
#include <windows.h>

using namespace GuiDLL;

int Main() {
	
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	// Create the main window and run it
	Application::Run(gcnew MyForm()); //Form1 is the name of the form created. 
	return 0;
}

