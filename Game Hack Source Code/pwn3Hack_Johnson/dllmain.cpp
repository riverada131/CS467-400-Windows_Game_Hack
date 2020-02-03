/*****************************************************************************
 * Name: ___Molly Johnson (johnsmol)___
 * File Name:  ___proc.h___
 * Organization: ___Team Runtime Terror___
 * Project Name: ___pwn3Hack___
 * Created On: ___1-2-2020___
 * Class: CS 467 Online Capstone
 * Instructor/TAs:
 * William Pfeil - Instructor
 * Prachi Rahurkar - Teachers Assistant (T.A.)
 * Iman Aminzahed - Teachers Assistant (T.A.)
 *****************************************************************************/

 /****************************************************************************
  * Description:
  * adapted from: https://guidedhacking.com/threads/how-to-hack-any-game-first-internal-hack-dll-tutorial.12142/
  *  
  ****************************************************************************/

// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include "stdafx.h"
#include <iostream>
#include "mem.h"

 /****************************************************************************
  * Description:
  *  
  ****************************************************************************/
void KeepItems(uintptr_t moduleBase)
{
	//keep pwncoins and ammo even when you spend pwncoins or sell ammo
	//by nopping out the code that subtracts from your current item (ammo or pwncoins)
    mem::Nop((BYTE*)(moduleBase + 0x52215), 2);
}

 /****************************************************************************
  * Description:
  *  
  ****************************************************************************/
void IncreasedGunDamage(uintptr_t moduleBase)
{
	//set pistol damage to 2000 
	mem::Patch((BYTE*)(moduleBase + 0x13930), (BYTE*)"\xB8\xD0\x07\x00\x00", 5);

	//set AKrifle damage to 2000
	mem::Patch((BYTE*)(moduleBase + 0x139F0), (BYTE*)"\xB8\xD0\x07\x00\x00", 5);

	//set cowboy coder damage to 2000
	mem::Patch((BYTE*)(moduleBase + 0x13AA0), (BYTE*)"\xB8\xD0\x07\x00\x00", 5);
}

 /****************************************************************************
  * Description:
  *  
  ****************************************************************************/
void IncreasedSpellDamage(uintptr_t moduleBase)
{
    //set balls of fire damage to 2000
	mem::Patch((BYTE*)(moduleBase + 0xD7E0), (BYTE*)"\xB8\xD0\x07\x00\x00", 5);

	//set zero cool damage to 2000
	mem::Patch((BYTE*)(moduleBase + 0x136F0), (BYTE*)"\xB8\xD0\x07\x00\x00", 5);
}

 /****************************************************************************
  * Description:
  *  
  ****************************************************************************/
void UnlimitedAmmo(uintptr_t moduleBase)
{
	//give unlimited ammo for all guns by by nopping out the code that subtracts from your current loaded ammo
	mem::Nop((BYTE*)(moduleBase + 0x52394), 2);
}

 /****************************************************************************
  * Description:
  *  
  ****************************************************************************/
DWORD WINAPI HackThread(HMODULE hModule)
{
	//Create Console
	AllocConsole();
	FILE* f;
	freopen_s(&f, "CONOUT$", "w", stdout);

	std::cout << "Molly's pwnie island 3 hacks are running" << std::endl;

	uintptr_t moduleBase = (uintptr_t)GetModuleHandle(L"GameLogic.dll");

	//loop until user hits end key
	while (true)
	{
        //exit loop if user hits End key
		if (GetAsyncKeyState(VK_END) & 1)
		{
			break;
		}

        //keep items (ammo in inventory and pwncoins)  if user hits numpad 0
		if (GetAsyncKeyState(VK_NUMPAD0) & 1)
		{
			KeepItems(moduleBase);
		}

        //increase gun damage (one shot one kill) if user hits numpad 1
		if (GetAsyncKeyState(VK_NUMPAD1) & 1)
		{
			IncreasedGunDamage(moduleBase);
		}

		//increase spell damage (one shot one kill) if user hits numpad 2
		if(GetAsyncKeyState(VK_NUMPAD2) & 1)
		{
			IncreasedSpellDamage(moduleBase);
		}

		//give unlimited weapon ammo if user hits numpad 3
		if(GetAsyncKeyState(VK_NUMPAD3) & 1)
		{
			UnlimitedAmmo(moduleBase);
		}

		Sleep(5);
	}

	fclose(f);
	FreeConsole();
	FreeLibraryAndExitThread(hModule, 0);
	return 0;
}

 /****************************************************************************
  * Description:
  *  
  ****************************************************************************/
BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
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
