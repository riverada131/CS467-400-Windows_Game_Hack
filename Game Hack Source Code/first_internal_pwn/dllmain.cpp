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
	//freopen_s(&f, "CONIN$", "r", stdin); allows console to receive input - currently not needed
	freopen_s(&f, "CONOUT$", "w", stdout);

	std::cout << "PwnAdventure3 internal cheat." << std::endl;;
	std::cout << "Team Name: RuNt1m3 T3Rr0r (RUNTIME TERROR)" << std::endl;;
	std::cout << "Project: Windows Hack Game" << std::endl;;

	std::cout << "By: RuNt1m3 T3Rr0r\n" << std::endl;
	std::cout << "Game hacks for PwnAdventure3" << std::endl;
	std::cout << "NUMPAD TOGGLES MENU" << std::endl;
	std::cout << "[ 0 ] Change health to 999,999,999" << std::endl;
	std::cout << "[ 1 ] CHange mana to 999,999,999" << std::endl;
	std::cout << "[ 2 ] Keep Items (no inventory loss when buying/selling)" << std::endl;
	std::cout << "[ 3 ] Increased Gun Damage (one shot one kill)" << std::endl;
	std::cout << "[ 4 ] Increased Spell Damage (one shot one kill)" << std::endl;
	std::cout << "[ 5 ] Unlimited Weapons Ammo" << std::endl;
	std::cout << "[ 6 ] Increase walk speed" << std::endl;
	std::cout << "[ 7 ] Increase jump speed" << std::endl;
	std::cout << "[ 8 ] Increase jump speed hold time" << std::endl;
	std::cout << "[ 9 ] Add 999,999,999 coins" << std::endl;
	std::cout << "[ End ] Exit game trainer\n" << std::endl;

	bool playerHealth = FALSE;
	bool playerMana = FALSE;
	bool bKeepItems = FALSE;
	bool bIncreasedGunDamage = FALSE;
	bool bIncreasedSpellDamage = FALSE;
	bool bUnlimitedAmmo = FALSE;
	bool bInvincibleHealth = FALSE;
	bool bwalkspeed = FALSE;
	bool bJumpSpeed = FALSE;
	bool bJumpHoldTime = FALSE;
	bool bAddCoin = FALSE;

	uintptr_t moduleBase = (uintptr_t)GetModuleHandle(L"GameLogic.dll");
	uintptr_t localPlayerPtr = (uintptr_t)(moduleBase + 0x97E1C);
	uintptr_t localPlayerPtr1 = (uintptr_t)(moduleBase + 0x97D7C);

	//hack loop
	while (true) {
		//Key input section
		
		if (GetAsyncKeyState(VK_END) & 1) {
			break;
			
		}

		if (GetAsyncKeyState(VK_NUMPAD0) & 1) {
			//Change health to 999,999,999
			playerHealth = !playerHealth;
				if (playerHealth) {
					cheat::modPlayerHealth(localPlayerPtr, 1);
				}
				else {
					cheat::modPlayerHealth(localPlayerPtr, 0);
				}
			
		}

		if (GetAsyncKeyState(VK_NUMPAD1) & 1) {
			//Change mana to 999,999,999 or nop/patch the mana function
			playerMana = !playerMana;
			if (playerMana) {
				cheat::modPlayerMana(localPlayerPtr, moduleBase, 1);
			}
			else {
				cheat::modPlayerMana(localPlayerPtr, moduleBase, 0);
			}
		}

		if (GetAsyncKeyState(VK_NUMPAD2) & 1) {
			//Keep Items (no inventory loss when buying/selling)
			bKeepItems = !bKeepItems;
			if (bKeepItems) {
				cheat::KeepItems(moduleBase, bKeepItems, 1);
			}
			else {
				cheat::KeepItems(moduleBase, bKeepItems, 0);
			}
			
		}

		if (GetAsyncKeyState(VK_NUMPAD3) & 1) {
			//Increased Gun Damage (one shot one kill)
			bIncreasedGunDamage = !bIncreasedGunDamage;
			if (bIncreasedGunDamage) {
				cheat::IncreasedGunDamage(moduleBase, bIncreasedGunDamage, 1);
			}
			else {
				cheat::IncreasedGunDamage(moduleBase, bIncreasedGunDamage, 0);
			}
		}

		if (GetAsyncKeyState(VK_NUMPAD4) & 1) {
			//Increased Spell Damage (one shot one kill)
			bIncreasedSpellDamage = !bIncreasedSpellDamage;
			if (bIncreasedSpellDamage) {
				cheat::IncreasedSpellDamage(moduleBase, bIncreasedSpellDamage, 1);
			}
			else {
				cheat::IncreasedSpellDamage(moduleBase, bIncreasedSpellDamage, 0);
			}

		}

		if (GetAsyncKeyState(VK_NUMPAD5) & 1) {
			//Unlimited Weapons Ammo
			bUnlimitedAmmo = !bUnlimitedAmmo;
			if (bUnlimitedAmmo) {
				cheat::UnlimitedAmmo(moduleBase, bUnlimitedAmmo, 1);
			}
			else {
				cheat::UnlimitedAmmo(moduleBase, bUnlimitedAmmo, 0);
			}
		}

		if (GetAsyncKeyState(VK_NUMPAD6) & 1) {
			//Regular Walking Speed
			bwalkspeed = !bwalkspeed;
			if (bwalkspeed) {
				cheat::modWalkSpeed(localPlayerPtr1, 1);
			}
			else {
				cheat::modWalkSpeed(localPlayerPtr1, 0);
			}
		}

		if (GetAsyncKeyState(VK_NUMPAD7) & 1) {
			//Jump Speed = 999
			bJumpSpeed = !bJumpSpeed;
			if (bJumpSpeed) {
				cheat::increaseJumpSpeed(localPlayerPtr1, 1);
			}
			else {
				cheat::increaseJumpSpeed(localPlayerPtr1, 0);
			}
			
		}

		if (GetAsyncKeyState(VK_NUMPAD8) & 1) {
			//Jump Hold Time = 9999
			bJumpHoldTime = !bJumpHoldTime;
			if (bJumpHoldTime) {
				cheat::increaseJumpHoldTime(localPlayerPtr1, 1);
			}
			else {
				cheat::increaseJumpHoldTime(localPlayerPtr1, 0);
			}
		}

		if (GetAsyncKeyState(VK_NUMPAD9) & 1) {
			//Add Coins
			bAddCoin = !bAddCoin;
			if (bAddCoin) {
				cheat::AddCoins(localPlayerPtr1, 1);
			}
			else {
				cheat::AddCoins(localPlayerPtr1, 0);
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
