#include "MyForm.h"
#include <windows.h>

/*****************************************************************************
 * Name: Molly Johnson, Gaetan Ingrassia, Daniel Rivera
 * File Name: MyForm.cpp
 * Team: Team Runtime Terror
 * Organization: Oregon State University
 * Project Name: Windows Hack Game
 * Created On: 2/4/2020
 * Class: CS467-400 Online Capstone Design
 * William Pfeil - Instructor
 * Prachi Rahurkar - Teachers Assistant (T.A.)
 * Iman Aminzahed - Teachers Assistant (T.A.)
 *****************************************************************************/

using namespace GuiDLL;

/****************************************************************************
 * Description: Main function. Accepts no parameters and returns 0. Enables visual styles,
 * handles text rendering, and creates/runs the form window. 
 ****************************************************************************/
int Main() {
	//**SetProcessDPIAware(); ** //THIS
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	// Create the main window and run it
	Application::Run(gcnew MyForm()); //Form1 is the name of the form created. 
	return 0;
}
