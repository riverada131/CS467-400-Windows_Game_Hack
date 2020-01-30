// dllmain.cpp : Defines the entry point for the DLL application.
#include "memory.h"
#include <iostream>


DWORD jmpBackAddr;

// Walking Speed
void __declspec(naked) func4()
{
	__asm
	{
		mov dword ptr[ECX + 0x120], 0x461c3c00
		FLD dword ptr[ECX + 0x120]
		jmp[jmpBackAddr]
	}
}

// Jumping Speed
void __declspec(naked) func5()
{
	__asm
	{
		mov dword ptr[ECX + 0x124], 0x4479c000
		FLD dword ptr[ECX + 0x124]
		jmp[jmpBackAddr]
	}
}

// Jumping Hold Time
void __declspec(naked) func6()
{
	__asm
	{
		mov dword ptr[ECX + 0x128], 0x4479c000
		FLD dword ptr[ECX + 0x128]
		jmp[jmpBackAddr]
	}
}


DWORD WINAPI HackThr(HMODULE hmodule)
{
	AllocConsole();
	FILE *f;
	freopen_s(&f, "CONOUT$", "w", stdout);
	std::cout << "Hello there!" << std::endl;

	uintptr_t moduleBase = (uintptr_t)GetModuleHandle(L"GameLogic.dll");
	int hookLen;
	DWORD hookAddr;

	// Get Walking
	hookLen = 6;
	hookAddr = moduleBase + 0x4FF90;
	jmpBackAddr = hookAddr + hookLen;
	memory::hook((void*)hookAddr, func4, hookLen);

	// Get Jump Speed
	hookLen = 6;
	hookAddr = moduleBase + 0x4FFA0;
	jmpBackAddr = hookAddr + hookLen;
	memory::hook((void*)hookAddr, func5, hookLen);

	// Get Jump Hold Time
	hookLen = 6;
	hookAddr = moduleBase + 0x4FFB0;
	jmpBackAddr = hookAddr + hookLen;
	memory::hook((void*)hookAddr, func6, hookLen);

	uintptr_t mana;
	int* manaPtr;
	mana = memory::FindAddr(moduleBase + 0x97E1C, { 0x0 , 0xC, 0xE0, 0x294, 0x234, 0x50C, 0xBC }); //0x97D7C
	manaPtr = (int*)mana;

	while (true)
	{
		if (GetAsyncKeyState(VK_END) & 1)
		{
			break;
		}
		
		*manaPtr = 105;
	}

	fclose(f);
	FreeConsole();
	FreeLibraryAndExitThread(hmodule, 0);
	return 0;
}


BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
		case DLL_PROCESS_ATTACH:
			CloseHandle(CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE)HackThr, hModule, 0, nullptr));
		case DLL_THREAD_ATTACH:
		case DLL_THREAD_DETACH:
		case DLL_PROCESS_DETACH:
			break;
    }
    return TRUE;
}










/*
// SERVER Implementation 

void __declspec(naked) func1()
{
	__asm
	{
		mov dword ptr[EDX + 0x12c], 0x64
		jmp[jmpBackAddr]
	}
}

void __declspec(naked) func2()
{
	__asm
	{
		mov EAX, 0x64
		jmp[jmpBackAddr]
	}
}

void __declspec(naked) func3()
{
	__asm
	{
		mov ECX, 0x64
		mov dword ptr[EAX + 0x8], 0x64
		jmp[jmpBackAddr]
	}
}

// Hook Mana Function - use mana func
int hookLen = 6;
DWORD hookAddr = moduleBase + 0x52590; //0x345E6; useMana func
jmpBackAddr = hookAddr + hookLen; //0x525DC;
memory::hook((void*)hookAddr, func1, hookLen);

// Hook get mana function - getmana func
hookLen = 6;
hookAddr = moduleBase + 0x4FF70; //0x52590; getMana func
jmpBackAddr = hookAddr + hookLen; //0x525DC;
memory::hook((void*)hookAddr, func2, hookLen);

// Hook Mana Function - unknown func
hookLen = 6;
hookAddr = moduleBase + 0x345CE; //0x52590; unknown func
jmpBackAddr = hookAddr + hookLen; //0x525DC;
memory::hook((void*)hookAddr, func3, hookLen);

// remove mana checks
DWORD nopAddr = moduleBase + 0x2137;
memory::Nop((BYTE*)nopAddr, 4);
nopAddr = moduleBase + 0x2145;
memory::Nop((BYTE*)nopAddr, 4);

uintptr_t jumpSpeed = memory::FindAddr(moduleBase + 0x97D7C, { 0x124 }); //0x97E48
float* jsPtr = (float*)jumpSpeed;
*jsPtr = 999.0;

uintptr_t jumpHold = memory::FindAddr(moduleBase + 0x97D7C, { 0x128 }); //0x97E48
float* jhPtr = (float*)jumpHold;
*jhPtr = 999.0;

uintptr_t walkSpeed = memory::FindAddr(moduleBase + 0x97D7C, { 0x120 }); //0x97E48
float* wsPtr = (float*)walkSpeed;
*wsPtr = 9999.0;


		uintptr_t manaRegenTimer = memory::FindAddr(moduleBase + 0x97E48, { 0x130 }); //0x130});   0x78B0C
		float* mrtPtr = (float*)manaRegenTimer;
		*mrtPtr = 10.000000;

		uintptr_t mana;
		int* manaPtr;
		mana = memory::FindAddr(moduleBase + 0x97E48, { 0xBC });
		manaPtr = (int*)mana;
		*manaPtr = 105;

		mana = memory::FindAddr(moduleBase + 0x97D94, { 0x14, 0x0, 0x20, 0x8 });
		manaPtr = (int*)mana;
		*manaPtr = 99;
		mana = memory::FindAddr(moduleBase + 0x97D94, { 0x14, 0x0, 0x1C, 0x8 });
		manaPtr = (int*)mana;
		*manaPtr = 99;
		mana = memory::FindAddr(moduleBase + 0x8D3C0, { 0x34, 0x18, 0x430, 0x28, 0x3C, 0x8, 0x8 });
		manaPtr = (int*)mana;
		*manaPtr = 99;



		uintptr_t jumpSpeed = memory::FindAddr(moduleBase + 0x97E1C, { 0x124 }); //0x97E48
		float* jsPtr = (float*)jumpSpeed;
		*jsPtr = 999.0;

		uintptr_t jumpHold = memory::FindAddr(moduleBase + 0x97E1C, { 0x128 }); //0x97E48
		float* jhPtr = (float*)jumpHold;
		*jhPtr = 999.0;

		uintptr_t walkSpeed = memory::FindAddr(moduleBase + 0x97E1C, { 0x120 }); //0x97E48
		float* wsPtr = (float*)walkSpeed;
		*wsPtr = 9999.0;
*/