/*****************************************************************************
 * Name: Molly Johnson, Gaetan Ingrassia, Daniel Rivera
 * File Name: mem.cpp
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
* Nop, patch, and DMAAddy functions adapted from:
* https://guidedhacking.com/threads/how-to-hack-any-game-first-internal-hack-dll-tutorial.12142/
****************************************************************************/

#include "mem.h"
//from https://guidedhacking.com/threads/how-to-hack-any-game-first-internal-hack-dll-tutorial.12142/

/****************************************************************************
 * Description: function adapted from Guided Hacking internal dll tutorial. Accepts a BYTE* paramter
 * for the patch destination location, a BYTE* parameter for the patch source code (in hex), and an unsigned
 * int for the patch size. Returns nothing. Uses VirtualProtect and memcpy to patch specified bytes into
 * the specified destination memory location.
 ****************************************************************************/
void mem::Patch(BYTE* dst, BYTE* src, unsigned int size)
{
	DWORD oldprotect;
	VirtualProtect(dst, size, PAGE_EXECUTE_READWRITE, &oldprotect);

	memcpy(dst, src, size);
	VirtualProtect(dst, size, oldprotect, &oldprotect);
}

/****************************************************************************
 * Description: function adapted from Guided Hacking internal dll tutorial. Accepts a BYTE* paramter
 * for the nop destination, and an unsigned int for the nop (no operation) size. Returns nothing.
 * Uses VirtualProtect and memset to set the specified number of bytes at the specified memory
 * location to hex value 90 (hex 90 = no operation or NOP).
 ****************************************************************************/
void mem::Nop(BYTE* dst, unsigned int size)
{
	DWORD oldprotect;
	VirtualProtect(dst, size, PAGE_EXECUTE_READWRITE, &oldprotect);
	memset(dst, 0x90, size);
	VirtualProtect(dst, size, oldprotect, &oldprotect);
}

/****************************************************************************
 * Description: function adapted from Guided Hacking internal dll tutorial. Accepts a uintptr_t parameter
 * for the base pointer and a vector of unsigned ints where each value in the vector represents
 * an offset that is to be used with the base pointer to point to the desired value. This function will
 * add those offsets to the base pointer address that was passed in, and the address reached after
 * adding those offsets (i.e. the address that points to the desired value) will be returned.
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

