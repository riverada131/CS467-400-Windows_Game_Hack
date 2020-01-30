#pragma once
//#include <dlfcn.h>
#include <windows.h>
#include <vector>
#include <string.h>


namespace memory
{
	void Nop(BYTE* dst, unsigned int size);
	uintptr_t FindAddr(uintptr_t ptr, std::vector<unsigned int> offsets);
	bool hook(void* hookee, void* func, int len);
}
