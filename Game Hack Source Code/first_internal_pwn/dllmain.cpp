// dllmain.cpp : Defines the entry point for the DLL application.
#include "stdafx.h"
#include <windows.h>
#include <iostream>
#include <TlHelp32.h>
#include "mem.h"
#include "proc.h"

DWORD WINAPI HackThread(HMODULE hModule)
{
	//Create console
	AllocConsole();
	FILE* f;
	freopen_s(&f, "CONOUT$", "w", stdout);

	std::cout << "PwnAdventure3 internal cheat." << std::endl;;

	//get module base
	uintptr_t moduleBase = (uintptr_t)GetModuleHandle(L"GameLogic.dll");
	std::cout << "Module Base Address = " << "0x" << std::hex << moduleBase << std::endl;

	uintptr_t* localPlayerPtr = (uintptr_t*)(moduleBase + 0x97E1C);
	std::cout << "Local player address = " << "0x" << std::hex << localPlayerPtr << std::endl;

	uintptr_t manaPtr = mem::FindDMAAddy(moduleBase + 0x97E1C, {0x0, 0xC, 0xE0, 0x294, 0x234, 0x50C, 0xBC});
	std::cout << "Mana pointer = " << "0x" << std::hex << manaPtr << std::endl;
	*(int*)(manaPtr) = 600;

	uintptr_t healthPtr = mem::FindDMAAddy(moduleBase + 0x97E1C, { 0x0, 0xC, 0xE0, 0x294, 0x234, 0x50C, 0x40 });
	std::cout << "Health pointer = " << "0x" << std::hex << healthPtr << std::endl;
	*(int*)(healthPtr) = 600;

	bool playerHealth = false;

	//hack loop
	while (true) {
		//Key input section
		if (GetAsyncKeyState((VK_END) & 1)) {
			break;
		}

		if (GetAsyncKeyState((VK_NUMPAD1) & 1)) {
			playerHealth = !playerHealth;
		}
		//cont write/freeze
		uintptr_t* localPlayerPtr = (uintptr_t*)(moduleBase + 0x97E1C);
		
		if (localPlayerPtr) {
			if (playerHealth) {
				*(int*)(*localPlayerPtr + 0xf8) = 1337;
			}
		}
		Sleep(5);
	}					  
	
	//cleanup and eject
	fclose(f);
	FreeConsole();
	FreeLibraryAndExitThread(hModule, 0);
	return 0;
}


BOOL APIENTRY DllMain(HMODULE hModule,
	DWORD  ul_reason_for_call,
	LPVOID lpReserved
)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		CloseHandle(CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE)HackThread, hModule, 0, nullptr));
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}

