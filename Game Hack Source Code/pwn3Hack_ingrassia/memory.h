#pragma once
#include <windows.h>
#include <vector>
#include <string>


namespace memory
{
	void Nop(BYTE* dst, unsigned int size);
	uintptr_t FindAddr(uintptr_t ptr, std::vector<unsigned int> offsets);
	bool hook(void* hookee, void* func, int len);
	void Patch(BYTE* dst, DWORD src, unsigned int size);
}

bool getCheat(char c, std::string s);

void unlimMana(int* mana);