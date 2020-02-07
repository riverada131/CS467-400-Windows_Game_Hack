#pragma once
#pragma once
/*****************************************************************************
 * Name: ___Molly Johnson (johnsmol)___
 * File Name:  ___func_library.h___
 * Organization: ___Team Runtime Terror___
 * Project Name: ___pwn3Hack___
 * Created On: ___1-2-2020___
 * Class: CS 467 Online Capstone
 * Instructor/TAs:
 * William Pfeil - Instructor
 * Prachi Rahurkar - Teachers Assistant (T.A.)
 * Iman Aminzahed - Teachers Assistant (T.A.)
 *****************************************************************************/

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