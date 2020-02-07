/*****************************************************************************
 * Name: Molly Johnson, Gaetan Ingrassia, Daniel Rivera
 * File Name: library.cpp
 * Team: Team Runtime Terror
 * Organization: Oregon State University
 * Project Name: Windows Hack Game
 * Created On: 2/4/2020
 * Class: CS467-400 Online Capstone Design
 * William Pfeil - Instructor
 * Prachi Rahurkar - Teachers Assistant (T.A.)
 * Iman Aminzahed - Teachers Assistant (T.A.)
 *****************************************************************************/

/*****************************************************************************
* Description:
* Adapted from: https://guidedhacking.com/threads/how-to-hack-any-game-first-internal-hack-dll-tutorial.12142/
*
****************************************************************************/

// dllmain.cpp : Defines the entry point for the DLL application.
#include "stdafx.h"
#include <iostream>
#include "mem.h"
#include "library.h"


/****************************************************************************
 * Description:
 *
 ****************************************************************************/
void cheat::KeepItems(uintptr_t moduleBase, bool bKeepItems)
{
	//if hack is toggled on
	if (bKeepItems)
	{
		//keep pwncoins and ammo even when you spend pwncoins or sell ammo
		//by nopping out the code that subtracts from your current inventory item (ammo or pwncoins)
		mem::Nop((BYTE*)(moduleBase + 0x52215), 2);
	}
	//if hack is toggled off
	else
	{
		//patch back in the original code that subtracts from your current inventory item (ammo or pwncoins)
		mem::Patch((BYTE*)(moduleBase + 0x52215), (BYTE*)"\x2B\xCF", 2);
	}
}

/****************************************************************************
 * Description:
 *
 ****************************************************************************/
void cheat::IncreasedGunDamage(uintptr_t moduleBase, bool bIncreasedGunDamage)
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
	}
}

/****************************************************************************
 * Description:
 *
 ****************************************************************************/
void cheat::IncreasedSpellDamage(uintptr_t moduleBase, bool bIncreasedSpellDamage)
{
	//if hack is toggled on
	if (bIncreasedSpellDamage)
	{
		//set balls of fire damage to 2000 via patch
		mem::Patch((BYTE*)(moduleBase + 0xD7E0), (BYTE*)"\xB8\xD0\x07\x00\x00", 5);

		//set zero cool damage to 2000 via patch
		mem::Patch((BYTE*)(moduleBase + 0x136F0), (BYTE*)"\xB8\xD0\x07\x00\x00", 5);
	}
	//if hack is toggled off
	else
	{
		//set balls of fire damage back to default via patch of the original code
		mem::Patch((BYTE*)(moduleBase + 0xD7E0), (BYTE*)"\xB8\x19\x00\x00\x00", 5);

		//set zero cool damage back to default via patch of the original code
		mem::Patch((BYTE*)(moduleBase + 0x136F0), (BYTE*)"\xB8\x20\x00\x00\x00", 5);
	}
}


void cheat::UnlimitedAmmo(uintptr_t moduleBase, bool bUnlimitedAmmo)
{
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
	}
	//if hack is toggled off
	else
	{
		//put back in the code that subtracts from your current loaded ammo via patch of the original code 
		mem::Patch((BYTE*)(moduleBase + 0x52394), (BYTE*)"\x2B\xCF", 2);
	}
}

/****************************************************************************
 * Description:
 *
 ****************************************************************************/
void cheat::InvincibleHealth(uintptr_t moduleBase, bool bInvincibleHealth)
{
	//if hack is toggled on
	if (bInvincibleHealth)
	{
		//make player invincible by preventing any damage to health by nopping out the player::Damage() function (except for the return)
		mem::Nop((BYTE*)(moduleBase + 0x51150), 202);
	}
	
}


