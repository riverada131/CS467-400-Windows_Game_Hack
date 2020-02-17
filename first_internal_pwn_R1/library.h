#pragma once
/*****************************************************************************
 * Name: Molly Johnson, Gaetan Ingrassia, Daniel Rivera
 * File Name: library.h
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

#include <iostream>
#include <windows.h>
#include <ios>
#include <vector>
#include "mem.h"

namespace cheat {
    void modPlayerHealth(uintptr_t localPlayerPtr, int check_val);
    void AddCoins(uintptr_t localPlayerPtr, int check_val);
    void modPlayerMana(uintptr_t localPlayerPtr, uintptr_t moduleBase, int check_val);
	void KeepItems(uintptr_t moduleBase, int check_val);
	void IncreasedGunDamage(uintptr_t moduleBase, int check_val);
	void IncreasedSpellDamage(uintptr_t moduleBase, int check_val);
    void UnlimitedAmmo(uintptr_t moduleBase, int check_val);
	void InvincibleHealth(uintptr_t moduleBase, int check_val);
    void modWalkSpeed(uintptr_t localPlayerPtr1, int speed_modifier);
    void increaseJumpSpeed(uintptr_t localPlayerPtr1, int speed_modifier);
    void increaseJumpHoldTime(uintptr_t localPlayerPtr1, int check_val);
    void Teleport(uintptr_t localPlayerPtr, float xPosVal, float yPosVal, float zPosVal);
}
