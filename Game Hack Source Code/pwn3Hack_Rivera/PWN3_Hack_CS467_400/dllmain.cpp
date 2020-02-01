/*****************************************************************************
* Name: Daniel Rivera, Molly Johnson, Gaetan Ingrassia
 * File Name:  main.cpp
 * Organization: Oregon State University
 * Project Name: Windows Game Hack
 * Created On: 1/18/2020
 * Class: CS467-400 Online Capstone Project
 * TA Name:	Iman Aminzahed, Prachi Rahurkar
 * Instructor Name: William Pfeil
 * ___COPYRIGHT___ (c) 2020 All Rights Reserved
 *****************************************************************************/

 /****************************************************************************
  * Description:
  ****************************************************************************/

// dllmain.cpp : Defines the entry point for the DLL application


#include "stdafx.h"
#include <windows.h>
#include <iostream>
#include <TlHelp32.h>
#include "mem.h"
#include "proc.h"

using std::cout;
using std::cin;
using std::endl;

DWORD WINAPI HACKTHREAD(HMODULE hModule)
{
	//Create console
	AllocConsole();
	FILE* f;
	freopen_s(&f, "CONOUT$", "w", stdout);

	cout << "message here";

	//get module base
	uintptr_t moduleBase = (uintptr_t)GetModuleHandle(L"GameLogic.dll");

	bool bHealth = false;


	//Hack Loop
	while (true) 
	{
		//key input
		if (GetAsyncKeyState(VK_END) & 1)
		{
			break;
		}

		if (GetAsyncKeyState(VK_NUMPAD1) & 1)
		{
			bHealth = !bHealth;
		}


		//cont. write/freeze
		uintptr_t* localPlayerPtr = (uintptr_t*)(moduleBase + 0x00097DE0);

		if (localPlayerPtr)
		{
			if (bHealth)
			{
				uintptr_t healthAddr = mem::FindDMAAddy(moduleBase + 0x00097DE0, { 0x0, 0x8, 0x0, 0x80, 0x30, 0x0 });
				int* Health = (int*)healthAddr;
				*Health = 600;
			 }
		}
		Sleep(5);
	}

	//clean up and eject
	fclose(f);
	FreeConsole();
	FreeLibraryAndExitThread(hModule, 0);
	return 0;
}


BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
	{
		CloseHandle(CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE)HACKTHREAD, hModule, 0, nullptr));
	}
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

