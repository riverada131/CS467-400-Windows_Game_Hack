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

#include "pch.h"
#include "stdafx.h"
#include "mem.h"

 /****************************************************************************
  * Description:
  * adapted from: https://guidedhacking.com/threads/how-to-hack-any-game-first-internal-hack-dll-tutorial.12142/
  *  
  ****************************************************************************/
void mem::Patch(BYTE* dst, BYTE* src, unsigned int size)
{
	DWORD oldprotect;
	VirtualProtect(dst, size, PAGE_EXECUTE_READWRITE, &oldprotect);

	memcpy(dst, src, size);
	VirtualProtect(dst, size, oldprotect, &oldprotect);
}

 /****************************************************************************
  * Description:
  * adapted from: https://guidedhacking.com/threads/how-to-hack-any-game-first-internal-hack-dll-tutorial.12142/
  *  
  ****************************************************************************/
void mem::Nop(BYTE* dst, unsigned int size)
{
	DWORD oldprotect;
	VirtualProtect(dst, size, PAGE_EXECUTE_READWRITE, &oldprotect);
	memset(dst, 0x90, size);
	VirtualProtect(dst, size, oldprotect, &oldprotect);
}

 /****************************************************************************
  * Description:
  * adapted from: https://guidedhacking.com/threads/how-to-hack-any-game-first-internal-hack-dll-tutorial.12142/
  *  
  ****************************************************************************/
uintptr_t mem::FindDMAAddy(uintptr_t ptr, std::vector<unsigned int> offsets)
{
	uintptr_t addr = ptr;
	for (unsigned int i = 0; i < offsets.size(); ++i)
	{
		addr = *(uintptr_t*)addr;
		addr += offsets[i];
	}
	return addr;
}