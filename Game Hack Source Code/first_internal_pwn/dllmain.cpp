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
#include <string.h>

DWORD WINAPI HackThread(HMODULE hModule) 
{
	//Create console
	AllocConsole();
	FILE* f;
	freopen_s(&f, "CONIN$", "r", stdin);
	freopen_s(&f, "CONOUT$", "w", stdout);

	std::cout << "PwnAdventure3 internal cheat." << std::endl;;
	std::cout << "Team Name: RuNt1m3 T3Rr0r (RUNTIME TERROR)" << std::endl;;
	std::cout << "Project: Windows Hack Game\n" << std::endl;;

	bool playerHealth = FALSE;
	bool bKeepItems = FALSE;
	bool bIncreasedGunDamage = FALSE;
	bool bIncreasedSpellDamage = FALSE;
	bool bUnlimitedAmmo = FALSE;
	bool bInvincibleHealth = FALSE;

	uintptr_t moduleBase = (uintptr_t)GetModuleHandle(L"GameLogic.dll");
	uintptr_t localPlayerPtr = (uintptr_t)(moduleBase + 0x97E1C);
	uintptr_t localPlayerPtr1 = (uintptr_t)(moduleBase + 0x97D7C);


	std::cout << "By: RuNt1m3 T3Rr0r\n" << std::endl;
	std::cout << "Game hacks for PwnAdventure3" << std::endl;
	std::cout << "NUMPAD TOGGLES MENU" << std::endl;
	std::cout << "[ 0 ] Change health to 999,999,999" << std::endl;
	std::cout << "[ 1 ] CHange mana to 999,999,999" << std::endl;
	std::cout << "[ 2 ] Keep Items (no inventory loss when buying/selling)" << std::endl;
	std::cout << "[ 3 ] Increased Gun Damage (one shot one kill)" << std::endl;
	std::cout << "[ 4 ] Increased Spell Damage (one shot one kill)" << std::endl;
	std::cout << "[ 5 ] Unlimited Weapons Ammo" << std::endl;
	std::cout << "[ 6 ] Regular Walking Speed" << std::endl;
	std::cout << "[ 7 ] Walking Speed = 500" << std::endl;
	std::cout << "[ 8 ] Jump Speed = 999" << std::endl;
	std::cout << "[ 9 ] Jump Hold Time = 9999" << std::endl;
	std::cout << "[ End ] Exit game trainer" << std::endl;

	//hack loop
	while (true) {
		//Key input section
		

		// NOP use mana cmp and sub
		DWORD nopAddr = moduleBase + 0x525C1;
		mem::Nop((BYTE*)nopAddr, 6);

		if (GetAsyncKeyState(VK_END) & 1) {
			break;
		}

		if (GetAsyncKeyState(VK_NUMPAD0) & 1) {
			//Change health to 999,999,999
			std::cout << "Player health changed to 999,999,999" << std::endl;
			uintptr_t healthPtr = mem::FindDMAAddy(localPlayerPtr, { 0x0, 0x0C, 0xE0, 0x294, 0x234, 0x50C, 0xFFFFFFC0 });
			*(int*)(healthPtr) = 999999999;
		}

		if (GetAsyncKeyState(VK_NUMPAD1) & 1) {
			//Change mana to 999,999,999
			std::cout << "Player mana changed to 999,999,999" << std::endl;
			uintptr_t manaPtr = mem::FindDMAAddy(localPlayerPtr, { 0x0, 0x0C, 0xE0, 0x294, 0x234, 0x50C, 0xBC });
			*(int*)(manaPtr) = 999999999;
		}

		if (GetAsyncKeyState(VK_NUMPAD2) & 1) {
			//Keep Items (no inventory loss when buying/selling)
			std::cout << "KeepItems cheat activated" << std::endl;
			bKeepItems = !bKeepItems;
			cheat::KeepItems(moduleBase, bKeepItems);
		}

		if (GetAsyncKeyState(VK_NUMPAD3) & 1) {
			//Increased Gun Damage (one shot one kill)
			std::cout << "Increase gun damage cheat activated" << std::endl;
			bIncreasedGunDamage = !bIncreasedGunDamage;
			cheat::IncreasedGunDamage(moduleBase, bIncreasedGunDamage);
		}

		if (GetAsyncKeyState(VK_NUMPAD4) & 1) {
			//Increased Spell Damage (one shot one kill)
			std::cout << "Increase spell damage cheat activated" << std::endl;
			bIncreasedSpellDamage = !bIncreasedSpellDamage;
			cheat::IncreasedSpellDamage(moduleBase, bIncreasedSpellDamage);
		}

		if (GetAsyncKeyState(VK_NUMPAD5) & 1) {
			//Unlimited Weapons Ammo
			std::cout << "Unlimited weapon ammo cheat activated" << std::endl;
			bUnlimitedAmmo = !bUnlimitedAmmo;
			cheat::UnlimitedAmmo(moduleBase, bUnlimitedAmmo);
		}

		if (GetAsyncKeyState(VK_NUMPAD6) & 1) {
			//Regular Walking Speed
			std::cout << "Player walking speed set to normal" << std::endl;
			uintptr_t walkSpeed = mem::FindDMAAddy(localPlayerPtr1, { 0x4 , 0x8, 0x4, 0x4, 0x10, 0x120 }); //0x97E48
			float* wsPtr = (float*)walkSpeed;
			*wsPtr = 200.0;
		}

		if (GetAsyncKeyState(VK_NUMPAD7) & 1) {
			//Walking Speed = 500
			std::cout << "Player walking speed set to 500" << std::endl;
			uintptr_t walkSpeed = mem::FindDMAAddy(localPlayerPtr1, { 0x4 , 0x8, 0x4, 0x4, 0x10, 0x120 }); //0x97E48
			float* wsPtr = (float*)walkSpeed;
			*wsPtr = 500.0;
		}

		if (GetAsyncKeyState(VK_NUMPAD8) & 1) {
			//Jump Speed = 999
			std::cout << "Player jump speed set to 999" << std::endl;
			uintptr_t jumpSpeed = mem::FindDMAAddy(localPlayerPtr1, { 0x4 , 0x8, 0x10, 0x124 }); //0x97E48
			float* jsPtr = (float*)jumpSpeed;
			*jsPtr = 999.0;
		}

		if (GetAsyncKeyState(VK_NUMPAD9) & 1) {
			//Jump Hold Time = 9999
			std::cout << "Player jump hold time set to 9999" << std::endl;
			uintptr_t jumpHoldTime = mem::FindDMAAddy(localPlayerPtr1, { 0x1C , 0x4, 0x224, 0x30, 0x18, 0x3E0, 0x128 }); //0x97E48
			float* jhtPtr = (float*)jumpHoldTime;
			*jhtPtr = 9999.0;
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

//Unused code:
//std::cout << "Module Base = " << std::hex << moduleBase << std::endl;
//std::cout << "Local Player Pointer = " << std::hex << localPlayerPtr << std::endl;

/*uintptr_t healthPtr = mem::FindDMAAddy(localPlayerPtr, { 0x0, 0x0C, 0xE0, 0x294, 0x234, 0x50C, 0xFFFFFFC0 });
std::cout << "Health Pointer = " << std::hex << healthPtr << std::endl;
*(int*)(healthPtr) = 1000;

uintptr_t manaPtr = mem::FindDMAAddy(localPlayerPtr, { 0x0, 0x0C, 0xE0, 0x294, 0x234, 0x50C, 0xBC });
std::cout << "Mana Pointer = " << std::hex << manaPtr << std::endl;
*(int*)(manaPtr) = 1000;*/

/*std::string gameHack;
std::cin.clear();
std::cin >> gameHack;*/