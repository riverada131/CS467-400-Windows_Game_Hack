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

#include "stdafx.h"
#include <iostream>
#include <windows.h>
#include <vector>
#include "mem.h"

namespace cheat {
	void KeepItems(uintptr_t moduleBase, bool bKeepItems);
	void IncreasedGunDamage(uintptr_t moduleBase, bool bIncreasedGunDamage);
	void IncreasedSpellDamage(uintptr_t moduleBase, bool bIncreasedSpellDamage);
	void UnlimitedAmmo(uintptr_t moduleBase, bool bUnlimitedAmmo);
	void InvincibleHealth(uintptr_t moduleBase, bool bInvincibleHealth);
}