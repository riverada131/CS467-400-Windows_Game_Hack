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
#include <iostream>
#include "mem.h"
#include "library.h"

/****************************************************************************
 * Description:
 *
 ****************************************************************************/

void cheat::modPlayerHealth(uintptr_t localPlayerPtr, int check_val) {
	if (check_val == 1) {
		std::cout << "Player health changed to 999,999,999" << std::endl;
		uintptr_t healthPtr = mem::FindDMAAddy(localPlayerPtr, { 0x0, 0x0C, 0xE0, 0x294, 0x234, 0x50C, 0xFFFFFFC0 });
		*(int*)(healthPtr) = 999999999;
	}
	else {
		std::cout << "Player health changed to 100" << std::endl;
		uintptr_t healthPtr = mem::FindDMAAddy(localPlayerPtr, { 0x0, 0x0C, 0xE0, 0x294, 0x234, 0x50C, 0xFFFFFFC0 });
		*(int*)(healthPtr) = 100;
	}
}

/****************************************************************************
 * Description:
 *
 ****************************************************************************/

void cheat::AddCoins(uintptr_t localPlayerPtr, int check_val) {
	if (check_val == 1) {
		std::cout << "Player coin amount changed to 999,999,999" << std::endl;
		uintptr_t coinPtr = mem::FindDMAAddy(localPlayerPtr, { 0x4, 0x0, 0x10, 0x4C, 0x4, 0x0, 0x18 });
		*(int*)(coinPtr) = 999999999;
	}
	else {
		std::cout << "Player coin amount changed to 100" << std::endl;
		uintptr_t coinPtr = mem::FindDMAAddy(localPlayerPtr, { 0x4, 0x0, 0x10, 0x4C, 0x4, 0x0, 0x18 });
		*(int*)(coinPtr) = 100;
	}
}

/****************************************************************************
 * Description:
 *
 ****************************************************************************/

void cheat::modPlayerMana(uintptr_t localPlayerPtr, uintptr_t moduleBase, int check_val) {
	if (check_val == 1) {
		std::cout << "Player mana cheat activated" << std::endl;
		uintptr_t manaPtr = mem::FindDMAAddy(localPlayerPtr, { 0x0, 0x0C, 0xE0, 0x294, 0x234, 0x50C, 0xBC });
		*(int*)(manaPtr) = 999999999;

		DWORD nopAddr = moduleBase + 0x525C1;
		mem::Nop((BYTE*)nopAddr, 6);

	}
	else {
		std::cout << "Player mana cheat deactivated" << std::endl;
		uintptr_t manaPtr = mem::FindDMAAddy(localPlayerPtr, { 0x0, 0x0C, 0xE0, 0x294, 0x234, 0x50C, 0xBC });
		*(int*)(manaPtr) = 100;

		// reset useMana - this changes is back to the orginal code
		DWORD useManaAddr = moduleBase + 0x525C1;
		mem::Patch((BYTE*)useManaAddr, (BYTE*)"\x3b\xc2\x7c\xe6\x2b\xc2", 6);
	}
}

/****************************************************************************
 * Description:
 *
 ****************************************************************************/
void cheat::KeepItems(uintptr_t moduleBase, int check_val)
{
	//if hack is toggled on
	if (check_val == 1)
	{
		//keep pwncoins and ammo even when you spend pwncoins or sell ammo
		//by nopping out the code that subtracts from your current inventory item (ammo or pwncoins)
		mem::Nop((BYTE*)(moduleBase + 0x52215), 2);
		std::cout << "Keep items cheat activated" << std::endl;
	}
	//if hack is toggled off
	else
	{
		//patch back in the original code that subtracts from your current inventory item (ammo or pwncoins)
		mem::Patch((BYTE*)(moduleBase + 0x52215), (BYTE*)"\x2B\xCF", 2);
		std::cout << "Keep items cheat deactivated" << std::endl;
	}
}

/****************************************************************************
 * Description:
 *
 ****************************************************************************/
void cheat::IncreasedGunDamage(uintptr_t moduleBase, int check_val)
{
	//if hack is toggled on
	if (check_val == 1)
	{
		//set pistol damage to 2000 via patch
		mem::Patch((BYTE*)(moduleBase + 0x13930), (BYTE*)"\xB8\xD0\x07\x00\x00", 5);

		//set AKrifle damage to 2000 via patch
		mem::Patch((BYTE*)(moduleBase + 0x139F0), (BYTE*)"\xB8\xD0\x07\x00\x00", 5);

		//set cowboy coder damage to 2000 via patch
		mem::Patch((BYTE*)(moduleBase + 0x13AA0), (BYTE*)"\xB8\xD0\x07\x00\x00", 5);

		std::cout << "Increase gun damage cheat activated" << std::endl;
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

		std::cout << "Increase gun damage cheat deactivated" << std::endl;
	}
}

/****************************************************************************
 * Description:
 *
 ****************************************************************************/
void cheat::IncreasedSpellDamage(uintptr_t moduleBase, int check_val)
{
	//if hack is toggled on
	if (check_val == 1)
	{
		//set balls of fire damage to 2000 via patch
		mem::Patch((BYTE*)(moduleBase + 0xD7E0), (BYTE*)"\xB8\xD0\x07\x00\x00", 5);

		//set zero cool damage to 2000 via patch
		mem::Patch((BYTE*)(moduleBase + 0x136F0), (BYTE*)"\xB8\xD0\x07\x00\x00", 5);

		std::cout << "Increase spell damage cheat activated" << std::endl;
	}
	//if hack is toggled off
	else
	{
		//set balls of fire damage back to default via patch of the original code
		mem::Patch((BYTE*)(moduleBase + 0xD7E0), (BYTE*)"\xB8\x19\x00\x00\x00", 5);

		//set zero cool damage back to default via patch of the original code
		mem::Patch((BYTE*)(moduleBase + 0x136F0), (BYTE*)"\xB8\x20\x00\x00\x00", 5);

		std::cout << "Increase spell damage cheat deactivated" << std::endl;
	}
}

/****************************************************************************
 * Description:
 *
 ****************************************************************************/
void cheat::UnlimitedAmmo(uintptr_t moduleBase, int check_val)
{
	//if hack is toggled on
	if (check_val == 1)
	{
		//give unlimited ammo for all guns by by nopping out the code that subtracts from your current loaded ammo
		mem::Nop((BYTE*)(moduleBase + 0x52394), 2);

		std::cout << "Unlimited weapon ammo cheat activated" << std::endl;
	}
	//if hack is toggled off
	else
	{
		//put back in the code that subtracts from your current loaded ammo via patch of the original code 
		mem::Patch((BYTE*)(moduleBase + 0x52394), (BYTE*)"\x2B\xCF", 2);

		std::cout << "Unlimited weapon ammo cheat deactivated" << std::endl;
	}
}

/****************************************************************************
 * Description:
 *
 ****************************************************************************/
void cheat::InvincibleHealth(uintptr_t moduleBase, int check_val)
{
	//if hack is toggled on
	if (check_val == 1)
	{
		//make player invincible by preventing any damage to health by nopping out the player::Damage() function (except for the return)
		mem::Nop((BYTE*)(moduleBase + 0x51150), 202);

		std::cout << "Unlimited health cheat activated" << std::endl;
	}	
}

/****************************************************************************
 * Description:
 *
 ****************************************************************************/

void cheat::modWalkSpeed(uintptr_t localPlayerPtr1, int speed_modifier) {
		uintptr_t walkSpeed = mem::FindDMAAddy(localPlayerPtr1, { 0x4 , 0x8, 0x4, 0x4, 0x10, 0x120 }); //0x97E48
		float* wsPtr = (float*)walkSpeed;
		*wsPtr = (float)200.0 * speed_modifier;
}


/****************************************************************************
 * Description:
 *
 ****************************************************************************/

void cheat::increaseJumpSpeed(uintptr_t localPlayerPtr1, int speed_modifier) {
		uintptr_t jumpSpeed = mem::FindDMAAddy(localPlayerPtr1, { 0x4 , 0x8, 0x10, 0x124 }); //0x97E48
		float* jsPtr = (float*)jumpSpeed;
		*jsPtr = (float)420.0 * speed_modifier;
}

/****************************************************************************
 * Description:
 *
 ****************************************************************************/

void cheat::increaseJumpHoldTime(uintptr_t localPlayerPtr1, int check_val) {
		uintptr_t jumpHoldTime = mem::FindDMAAddy(localPlayerPtr1, { 0x1C , 0x4, 0x224, 0x30, 0x18, 0x3E0, 0x128 }); //0x97E48
		float* jhtPtr = (float*)jumpHoldTime;
		if (check_val == 1) {
			*jhtPtr = (float)10000.0;
		}
		else {
			*jhtPtr = (float)0.200000003;
		}
}

/****************************************************************************
 * Description:
 *
 ****************************************************************************/

void cheat::Teleport(uintptr_t localPlayerPtr, float xPosVal, float yPosVal, float zPosVal) {
	/*
	Starting Position: x:-53090, y:-57298, z:1027
	Fireball: x:-43651, y:-55970, z:324
	Starting Buildings: x:-39456, y:-21931, z:2796
	*/

	std::cout << "Teleporting to (" << xPosVal << ", " << yPosVal << ", " << zPosVal << ")" << std::endl;
	uintptr_t xPosAddr = mem::FindDMAAddy(localPlayerPtr, { 0x24 , 0xC, 0xC8, 0x424, 0x184, 0x74, 0x90 }); //0x97E1C
	float* xPos = (float*)xPosAddr;
	*xPos = xPosVal;

	uintptr_t yPosAddr = mem::FindDMAAddy(localPlayerPtr, { 0x24 , 0xC, 0xC8, 0x424, 0x184, 0x74, 0x94 }); //0x97E1C
	float* yPos = (float*)yPosAddr;
	*yPos = yPosVal;

	uintptr_t zPosAddr = mem::FindDMAAddy(localPlayerPtr, { 0x24 , 0xC, 0xC8, 0x424, 0x184, 0x74, 0x98 }); //0x97E1C
	float* zPos = (float*)zPosAddr;
	*zPos = zPosVal;
}
