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
using std::cout;
using std::endl;

 /****************************************************************************
  * Description:
  *  
  ****************************************************************************/
void KeepItems(uintptr_t moduleBase, bool bKeepItems)
{
	//if hack is toggled on
	if (bKeepItems)
	{
	    //keep pwncoins and ammo even when you spend pwncoins or sell ammo
	    //by nopping out the code that subtracts from your current inventory item (ammo or pwncoins)
        mem::Nop((BYTE*)(moduleBase + 0x52215), 2);
		cout << "[ 0 ] Keep Items hack turned ON" << endl;
	}
	//if hack is toggled off
	else
	{
		//patch back in the original code that subtracts from your current inventory item (ammo or pwncoins)
		mem::Patch((BYTE*)(moduleBase + 0x52215), (BYTE*)"\x2B\xCF", 2);
		cout << "[ 0 ] Keep Items hack turned OFF" << endl;
	}
}

 /****************************************************************************
  * Description:
  *  
  ****************************************************************************/
void IncreasedGunDamage(uintptr_t moduleBase, bool bIncreasedGunDamage)
{
	//if hack is toggled on
	if (bIncreasedGunDamage)
	{
        //set pistol damage to 2000 via patch
        mem::Patch((BYTE*)(moduleBase + 0x13930), (BYTE*)"\xB8\xD0\x07\x00\x00", 5);

        //set AKrifle damage to 2000 via patch
        mem::Patch((BYTE*)(moduleBase + 0x139F0), (BYTE*)"\xB8\xD0\x07\x00\x00", 5);

        //set cowboy coder damage to 2000 via patch
        mem::Patch((BYTE*)(moduleBase + 0x13AA0), (BYTE*)"\xB8\xD0\x07\x00\x00", 5);
		cout << "[ 1 ] Increased Gun Damage hack turned ON" << endl;
	}
	//if hack is toggled off
	else
	{
        //set pistol damage back to default via patch of original code
        mem::Patch((BYTE*)(moduleBase + 0x13930), (BYTE*)"\xB8\x0E\x00\x00\x00", 5);

		//set AKrifle damage back to default via patch of original code
        mem::Patch((BYTE*)(moduleBase + 0x139F0), (BYTE*)"\xB8\x0B\x00\x00\x00", 5);

		//set cowboy coder damage back to default via patch of original code
        mem::Patch((BYTE*)(moduleBase + 0x13AA0), (BYTE*)"\xB8\x3C\x00\x00\x00", 5);
		cout << "[ 1 ] Increased Gun Damage hack turned OFF" << endl;
	}
}

 /****************************************************************************
  * Description:
  *  
  ****************************************************************************/
void IncreasedSpellDamage(uintptr_t moduleBase, bool bIncreasedSpellDamage)
{
	//if hack is toggled on
	if (bIncreasedSpellDamage)
	{
        //set balls of fire damage to 2000 via patch
        mem::Patch((BYTE*)(moduleBase + 0xD7E0), (BYTE*)"\xB8\xD0\x07\x00\x00", 5);

        //set zero cool damage to 2000 via patch
        mem::Patch((BYTE*)(moduleBase + 0x136F0), (BYTE*)"\xB8\xD0\x07\x00\x00", 5);
		cout << "[ 2 ] Increased Spell Damage hack turned ON" << endl;
	}
	//if hack is toggled off
	else
	{
        //set balls of fire damage back to default via patch of the original code
        mem::Patch((BYTE*)(moduleBase + 0xD7E0), (BYTE*)"\xB8\x19\x00\x00\x00", 5);

        //set zero cool damage back to default via patch of the original code
        mem::Patch((BYTE*)(moduleBase + 0x136F0), (BYTE*)"\xB8\x20\x00\x00\x00", 5);
		cout << "[ 2 ] Increased Spell Damage hack turned OFF" << endl;
	}
}

 /****************************************************************************
  * Description:
  *  
  ****************************************************************************/
void UnlimitedAmmo(uintptr_t moduleBase, bool bUnlimitedAmmo)
{
	//if hack is toggled on
	if (bUnlimitedAmmo)
	{
        //give unlimited ammo for all guns by by nopping out the code that subtracts from your current loaded ammo
        mem::Nop((BYTE*)(moduleBase + 0x52394), 2);
		cout << "[ 3 ] Unlimited Ammo hack turned ON" << endl;
	}
	//if hack is toggled off
	else
	{
	    //put back in the code that subtracts from your current loaded ammo via patch of the original code 
        mem::Patch((BYTE*)(moduleBase + 0x52394), (BYTE*)"\x2B\xCF", 2);
		cout << "[ 3 ] Unlimited Ammo hack turned OFF" << endl;
	}
}

 /****************************************************************************
  * Description:
  *  
  ****************************************************************************/
void InvincibleHealth(uintptr_t moduleBase, bool bInvincibleHealth)
{
	//if hack is toggled on
	if (bInvincibleHealth)
	{
        //make player invincible by preventing any damage to health by nopping out the player::Damage() function (except for the return)
        mem::Nop((BYTE*)(moduleBase + 0x51150), 202);
		cout << "[ 4 ] Invincible Player Health hack turned ON" << endl;
	}
	//else if hack is toggled off
	else
	{
	   //allow player to be damaged again by patching back in the player::Damage() function original code
		mem::Patch((BYTE*)(moduleBase + 0x51150), (BYTE*)"\x55\x8B\xEC\x57\x8B\xF9\x8B\x0D\x7C\x7D\xF4\x7B\x85\xC9\x74\x0F\x8B\x01\x8B\x40\x0C\xFF\xD0\x84\xC0\x0F\x84\xA9\x00\x00\x00\x80\xBF\xF0\x00\x00\x00\x00\x0F\x85\x9C\x00\x00\x00\x53\x8B\x5D\x08\x3B\xDF\x75\x16\x66\x0F\x6E\x45\x10\x0F\x5B\xC0\xF3\x0F\x59\x05\xF8\x8A\xF2\x7B\xF3\x0F\x2C\xC0\xEB\x2A\x85\xDB\x74\x23\x8B\x03\x8B\xCB\x8B\x40\x0C\xFF\xD0\x84\xC0\x74\x16\x80\xBF\xE5\x00\x00\x00\x00\x74\x63\x8B\x03\x8B\xCB\x8B\x40\x58\xFF\xD0\x84\xC0\x74\x56\x8B\x45\x10\x56\xFF\x75\x14\x8B\x77\x30\x8B\xCF\x50\xFF\x75\x0C\x89\x45\x10\x53\xE8\x06\x0E\xFB\xFF\x39\x77\x30\x5E\x7D\x0A\xC7\x87\x34\x01\x00\x00\x00\x00\xA0\x41\x8B\x55\x0C\x85\xD2\x74\x26\x83\x7D\x10\x00\x7E\x20\x8B\x0D\x7C\x7D\xF4\x7B\x89\x97\xD0\x01\x00\x00\xC7\x87\xD4\x01\x00\x00\x00\x00\xA0\x40\x52\x8B\x01\x57\xFF\x90\x04\x01\x00\x00\x5B\x5F\x5D", 202);
		cout << "[ 4 ] Invincible Player Health hack turned OFF" << endl;
	}
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

	cout << "Welcome to Molly's pwnie island 3 hacks" << endl;
	cout << "NUMPAD TOGGLES MENU" << endl;
	cout << "[ 0 ] Keep Items (no inventory loss when buying/selling)" << endl;
	cout << "[ 1 ] Increased Gun Damage (one shot one kill)" << endl;
	cout << "[ 2 ] Increased Spell Damage (one shot one kill)" << endl;
	cout << "[ 3 ] Unlimited Weapons Ammo" << endl;
	cout << "[ 4 ] Invincible Player Health" << endl;
	cout << "[ End ] Exit game trainer\n" << endl;
    
	uintptr_t moduleBase = (uintptr_t)GetModuleHandle(L"GameLogic.dll");

    //bools for toggling hacks
	bool bKeepItems = false, bIncreasedGunDamage = false, bIncreasedSpellDamage = false,
        bUnlimitedAmmo = false, bInvincibleHealth = false;

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
			//toggle hack via bool
			bKeepItems = !bKeepItems;

			KeepItems(moduleBase, bKeepItems);
		}

        //increase gun damage (one shot one kill) if user hits numpad 1
		if (GetAsyncKeyState(VK_NUMPAD1) & 1)
		{
			//toggle hack via bool
			bIncreasedGunDamage = !bIncreasedGunDamage;

			IncreasedGunDamage(moduleBase, bIncreasedGunDamage);
		}

		//increase spell damage (one shot one kill) if user hits numpad 2
		if (GetAsyncKeyState(VK_NUMPAD2) & 1)
		{
			//toggle hack via bool
			bIncreasedSpellDamage = !bIncreasedSpellDamage;

			IncreasedSpellDamage(moduleBase, bIncreasedSpellDamage);
		}

		//give unlimited weapon ammo if user hits numpad 3
		if (GetAsyncKeyState(VK_NUMPAD3) & 1)
		{
			//toggle hack via bool
			bUnlimitedAmmo = !bUnlimitedAmmo;

			UnlimitedAmmo(moduleBase, bUnlimitedAmmo);
		}

		//give invincible health if user hits numpad 4
		if (GetAsyncKeyState(VK_NUMPAD4) & 1)
		{
			//toggle hack via bool
			bInvincibleHealth = !bInvincibleHealth;

			InvincibleHealth(moduleBase, bInvincibleHealth);
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
