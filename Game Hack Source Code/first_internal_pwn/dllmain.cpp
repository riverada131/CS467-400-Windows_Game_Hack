/*****************************************************************************
 * Name: Molly Johnson, Gaetan Ingrassia, Daniel Rivera
 * File Name: dllmain.cpp
 * Team: Team Runtime Terror
 * Organization: Oregon State University
 * Project Name: Windows Hack Game
 * Created On: 2/4/2020
 * Class: CS467-400 Online Capstone Design
 * William Pfeil - Instructor
 * Prachi Rahurkar - Teachers Assistant (T.A.)
 * Iman Aminzahed - Teachers Assistant (T.A.)
 *****************************************************************************/

 /****************************************************************************
  * Description:
  * Adapted from: https://guidedhacking.com/threads/how-to-hack-any-game-first-internal-hack-dll-tutorial.12142/
  ****************************************************************************/

// dllmain.cpp : Defines the entry point for the DLL application.
#include "stdafx.h"
#include <windows.h>
#include <iostream>
#include <TlHelp32.h>
#include "mem.h"
#include "proc.h"
#include "library.h"
#include "myform.h"

DWORD WINAPI HackThread(HMODULE hModule) 
{
	//Create console
	AllocConsole();
	FILE* f;
	freopen_s(&f, "CONOUT$", "w", stdout);

	std::cout << "PwnAdventure3 internal cheat." << std::endl;;

	bool playerHealth = FALSE;
	bool bKeepItems = FALSE;
	bool bIncreasedGunDamage = FALSE;
	bool bIncreasedSpellDamage = FALSE;
	bool bUnlimitedAmmo = FALSE;
	bool bInvincibleHealth = FALSE;

	uintptr_t moduleBase = (uintptr_t)GetModuleHandle(L"GameLogic.dll");
	uintptr_t localPlayerPtr = (uintptr_t)(moduleBase + 0x97E1C);

	std::cout << "Module Base = " << std::hex << moduleBase << std::endl;
	std::cout << "Local Player Pointer = " << std::hex << localPlayerPtr << std::endl;

	uintptr_t healthPtr = mem::FindDMAAddy(localPlayerPtr, { 0x0, 0x0C, 0xE0, 0x294, 0x234, 0x50C, 0xFFFFFFC0 });
	std::cout << "Health Pointer = " << std::hex << healthPtr << std::endl;
	*(int*)(healthPtr) = 1000;

	uintptr_t manaPtr = mem::FindDMAAddy(localPlayerPtr, { 0x0, 0x0C, 0xE0, 0x294, 0x234, 0x50C, 0xBC });
	std::cout << "Mana Pointer = " << std::hex << manaPtr << std::endl;
	*(int*)(manaPtr) = 1000;

	//hack loop
	while (true) {
		//Key input section
		if (GetAsyncKeyState((VK_END) & 1)) {
			break;
		}

		if (GetAsyncKeyState((VK_NUMPAD0) & 1)) {
			playerHealth = !playerHealth;
		}

		if (GetAsyncKeyState((VK_NUMPAD1) & 1)) {
			bKeepItems = !bKeepItems;
			cheat::KeepItems(moduleBase, bKeepItems);
		}

		if (GetAsyncKeyState((VK_NUMPAD2) & 1)) {
			bIncreasedGunDamage = !bIncreasedGunDamage;
			cheat::IncreasedGunDamage(moduleBase, bIncreasedGunDamage);
		}

		if (GetAsyncKeyState((VK_NUMPAD3) & 1)) {
			bIncreasedSpellDamage = !bIncreasedSpellDamage;
			cheat::IncreasedSpellDamage(moduleBase, bIncreasedSpellDamage);
		}

		if (GetAsyncKeyState((VK_NUMPAD4) & 1)) {
			bUnlimitedAmmo = !bUnlimitedAmmo;
			cheat::UnlimitedAmmo(moduleBase, bUnlimitedAmmo);
		}

		if (GetAsyncKeyState((VK_NUMPAD5) & 1)) {
			bInvincibleHealth = !bInvincibleHealth;
			cheat::InvincibleHealth(moduleBase, bInvincibleHealth);
		}

	//	if (GetAsyncKeyState((VK_NUMPAD6) & 1)) {

	//	}

	//	if (GetAsyncKeyState((VK_NUMPAD7) & 1)) {

	//	}

	//	if (GetAsyncKeyState((VK_NUMPAD8) & 1)) {

	//	}

	//	if (GetAsyncKeyState((VK_NUMPAD9) & 1)) {

	//	}
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

