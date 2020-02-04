// Memory operations
#include "memory.h"


void memory::Nop(BYTE* dst, unsigned int size)
{
	DWORD oldprotect;
	VirtualProtect(dst, size, PAGE_EXECUTE_READWRITE, &oldprotect);
	memset(dst, 0x90, size);
	VirtualProtect(dst, size, oldprotect, &oldprotect);
}


uintptr_t memory::FindAddr(uintptr_t ptr, std::vector<unsigned int> offsetVec)
{
	uintptr_t addr = ptr;

	for (unsigned int i = 0; i < offsetVec.size(); i++)
	{
		addr = *(uintptr_t*)addr;
		addr += offsetVec[i];
	}

	return addr;
}


bool memory::hook(void* hookee, void* func, int len)
{
	if (len < 5)
	{
		return false;
	}

	DWORD oldProtect;
	VirtualProtect(hookee, len, PAGE_EXECUTE_READWRITE, &oldProtect);

	memset(hookee, 0x90, len);

	DWORD relAddr = ((DWORD)func - (DWORD)hookee) - 5;

	*(BYTE*)hookee = 0xE9;  // jmp instruction
	*(DWORD*)((DWORD)hookee + 1) = relAddr;

	DWORD temp;
	VirtualProtect(hookee, len, oldProtect, &temp);

	return true;
}

void memory::Patch(BYTE* dst, DWORD src, unsigned int size)
{
	DWORD oldprotect;
	VirtualProtect(dst, size, PAGE_EXECUTE_READWRITE, &oldprotect);

	*(BYTE*)dst = src;
	VirtualProtect(dst, size, oldprotect, &oldprotect);
}


bool getCheat(char c, std::string s)
{
	for (int i = 0; i < s.length(); i++)
		if (s[i] == c)
			return true;

	return false;
}


void unlimMana(int* mana)
{
	while (true)
	{
		if (GetAsyncKeyState(VK_END) & 1)
			break;

		*mana = 105;
	}
	std::terminate();
}