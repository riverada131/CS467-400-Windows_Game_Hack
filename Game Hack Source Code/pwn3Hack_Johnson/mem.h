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

#pragma once
#include "stdafx.h"
#include <windows.h>
#include <vector>

namespace mem
{
	void Patch(BYTE* dst, BYTE* src, unsigned int size);
	void Nop(BYTE* dst, unsigned int size);
	uintptr_t FindDMAAddy(uintptr_t ptr, std::vector<unsigned int> offsets);
}