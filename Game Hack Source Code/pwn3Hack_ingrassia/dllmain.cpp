// dllmain.cpp : Defines the entry point for the DLL application.
#include "memory.h"
#include <iostream>
#include <ios>
#include <limits>
#include <thread>

using namespace std;

// Assembly Replacement for function hooking
DWORD jmpBackAddr;

// Get Mana
void __declspec(naked) func0()
{
	__asm
	{
		mov EAX, 0x69
		jmp[jmpBackAddr]
	}
}

// Reset Mana
void __declspec(naked) func01()
{
	__asm
	{
		mov EAX, dword ptr[ECX + 0xBC]
		jmp[jmpBackAddr]
	}
}
void __declspec(naked) func02()
{
	__asm
	{
		cmp EAX, EDX

		jmp[jmpBackAddr]
	}
}

// Walking Speed - Normal
void __declspec(naked) func1()
{
	__asm
	{
		mov dword ptr[ECX + 0x120], 0x437a0000
		FLD dword ptr[ECX + 0x120]
		jmp[jmpBackAddr]
	}
}

// Walking Speed - 500.0
void __declspec(naked) func2()
{
	__asm
	{
		mov dword ptr[ECX + 0x120], 0x43fa0000
		FLD dword ptr[ECX + 0x120]
		jmp[jmpBackAddr]
	}
}

// Walking Speed - 1000.0
void __declspec(naked) func3()
{
	__asm
	{
		mov dword ptr[ECX + 0x120], 0x447a0000
		FLD dword ptr[ECX + 0x120]
		jmp[jmpBackAddr]
	}
}

// Walking Speed - 10000.0
void __declspec(naked) func4()
{
	__asm
	{
		mov dword ptr[ECX + 0x120], 0x461c4000
		FLD dword ptr[ECX + 0x120]
		jmp[jmpBackAddr]
	}
}

// Jumping Speed - 999.0
void __declspec(naked) func5()
{
	__asm
	{
		mov dword ptr[ECX + 0x124], 0x4479c000
		FLD dword ptr[ECX + 0x124]
		jmp[jmpBackAddr]
	}
}

// Jumping Hold Time - 999.0
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
	freopen_s(&f, "CONIN$", "r", stdin);
	freopen_s(&f, "CONOUT$", "w", stdout);


	cout << "Hello there!" << endl;
	cout << "Enter Corresponding Number for Desired Cheat" << endl;
	cout << "1  -  Unlimited Mana" << endl;
	cout << "Please only choose one walking speed:" << endl;
	cout << "  2  -  Regular Walking Speed" << endl;
	cout << "  3  -  Walking Speed = 500" << endl;
	cout << "  4  -  Walking Speed = 1000" << endl;
	cout << "  5  -  Walking Speed = 10000" << endl;
	cout << "6  -  Jump Speed = 999" << endl;
	cout << "7  -  Jump Hold Time = 9999" << endl;
	cout << endl << "0  -  Exit" << endl;

	// Module Base is the start of GameLogic.dll
	uintptr_t moduleBase = (uintptr_t)GetModuleHandle(L"GameLogic.dll");
	int hookLen;
	DWORD hookAddr;
	/*
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
	
	uintptr_t mana; // this def works
	int* manaPtr;
	mana = memory::FindAddr(moduleBase + 0x97E1C, { 0x0 , 0xC, 0xE0, 0x294, 0x234, 0x50C, 0xBC }); //0x97D7C
	manaPtr = (int*)mana;
	*/

	while (true)
	{
		// Get desired cheats
		string cheat;
		cin.clear();
		cin >> cheat;


		if (getCheat('1', cheat))  //mana
		{
			cout << "unlimited mana Active" << endl;
			//thread th1(unlimMana, manaPtr);
			/*
			uintptr_t mana; // this def works
			int* manaPtr;
			mana = memory::FindAddr(moduleBase + 0x97D7C, { 0x4 , 0x0, 0x8, 0x8, 0x10, 0xBC }); // 0x97E1C
			manaPtr = (int*)mana;
			*manaPtr = 105;
			*/

			// Hook get mana function - getmana func
			hookLen = 6;
			hookAddr = moduleBase + 0x4FF70; //0x52590; getMana func
			jmpBackAddr = hookAddr + hookLen; //0x525DC;
			memory::hook((void*)hookAddr, func0, hookLen);

			// NOP use mana cmp and sub
			DWORD nopAddr = moduleBase + 0x525C1;
			memory::Nop((BYTE*)nopAddr, 6);
		}
		if (getCheat('6', cheat))  //jump speed 999
		{
			////
			//uintptr_t jumpSpeed = memory::FindAddr(moduleBase + 0x97D7C, { 0x1C , 0x244, 0x250, 0x50C, 0x5C, 0x30, 0x124 }); //0x97E48
			uintptr_t jumpSpeed = memory::FindAddr(moduleBase + 0x97D7C, { 0x4 , 0x8, 0x10, 0x124 }); //0x97E48
			float* jsPtr = (float*)jumpSpeed;
			*jsPtr = 999.0;
			////
			cout << "jump speed 999 Active" << endl;
			//hookLen = 6;
			//hookAddr = moduleBase + 0x4FFA0;
			//jmpBackAddr = hookAddr + hookLen;
			//memory::hook((void*)hookAddr, func5, hookLen);
		}
		if (getCheat('7', cheat))  //Jump Hold Time 9999
		{
			////
			uintptr_t jumpHoldTime = memory::FindAddr(moduleBase + 0x97D7C, { 0x1C , 0x4, 0x224, 0x30, 0x18, 0x3E0, 0x128 }); //0x97E48
			float* jhtPtr = (float*)jumpHoldTime;
			*jhtPtr = 9999.0;
			////
			cout << "jump hold time 9999 Active" << endl;
			//hookLen = 6;
			//hookAddr = moduleBase + 0x4FFB0;
			//jmpBackAddr = hookAddr + hookLen;
			//memory::hook((void*)hookAddr, func6, hookLen);
		}
		if (getCheat('2', cheat)) //normal walk
		{
			cout << "normal walk Active" << endl;
			////
			uintptr_t walkSpeed = memory::FindAddr(moduleBase + 0x97D7C, { 0x4 , 0x8, 0x4, 0x4, 0x10, 0x120 }); //0x97E48
			float* wsPtr = (float*)walkSpeed;
			*wsPtr = 200.0;
			////
			// Get Walking
			//hookLen = 6;
			//hookAddr = moduleBase + 0x4FF90;
			//jmpBackAddr = hookAddr + hookLen;
			//memory::hook((void*)hookAddr, func1, hookLen);
		}
		else if (getCheat('3', cheat)) //walk 500
		{
			cout << "walk 500 Active" << endl;

			////
			uintptr_t walkSpeed = memory::FindAddr(moduleBase + 0x97D7C, { 0x4 , 0x8, 0x4, 0x4, 0x10, 0x120 }); //0x97E48
			float* wsPtr = (float*)walkSpeed;
			*wsPtr = 500.0;
			////

			// Get Walking
			//hookLen = 6;
			//hookAddr = moduleBase + 0x4FF90;
			//jmpBackAddr = hookAddr + hookLen;
			//memory::hook((void*)hookAddr, func2, hookLen);
		}
		else if (getCheat('4', cheat)) //walk 1000
		{
			////
			uintptr_t walkSpeed = memory::FindAddr(moduleBase + 0x97D7C, { 0x4 , 0x8, 0x4, 0x4, 0x10, 0x120 }); //0x97E48
			float* wsPtr = (float*)walkSpeed;
			*wsPtr = 1000.0;
			////
			cout << "walk 1000 Active" << endl;
			// Get Walking
			//hookLen = 6;
			//hookAddr = moduleBase + 0x4FF90;
			//jmpBackAddr = hookAddr + hookLen;
			//memory::hook((void*)hookAddr, func3, hookLen);
		}
		else if (getCheat('5', cheat)) //walk 10000
		{
			cout << "walk 10000 Active" << endl;
			////
			uintptr_t walkSpeed = memory::FindAddr(moduleBase + 0x97D7C, { 0x4 , 0x8, 0x4, 0x4, 0x10, 0x120 }); //0x97E48
			float* wsPtr = (float*)walkSpeed;
			*wsPtr = 10000.0;
			////
			// Get Walking
			//hookLen = 6;
			//hookAddr = moduleBase + 0x4FF90;
			//jmpBackAddr = hookAddr + hookLen;
			//memory::hook((void*)hookAddr, func4, hookLen);
		}
		else if (getCheat('0', cheat))
		{
			cout << "Hacks Disabled" << endl;

			//reset getMana
			DWORD getManaAddr = moduleBase + 0x4FF70;
			memory::Patch((BYTE*)getManaAddr, (DWORD)0x8b, 1);
			memory::Patch((BYTE*)(getManaAddr + 1), (DWORD)0x81, 1);
			memory::Patch((BYTE*)(getManaAddr + 2), (DWORD)0xbc, 1);
			memory::Patch((BYTE*)(getManaAddr + 3), (DWORD)0x00, 1);
			memory::Patch((BYTE*)(getManaAddr + 4), (DWORD)0x00, 1);
			memory::Patch((BYTE*)(getManaAddr + 5), (DWORD)0x00, 1);

			// reset useMana
			DWORD useManaAddr = moduleBase + 0x525C1;
			memory::Patch((BYTE*)useManaAddr, (DWORD)0x3b, 1);
			memory::Patch((BYTE*)(useManaAddr + 1), (DWORD)0xc2, 1);
			memory::Patch((BYTE*)(useManaAddr + 2), (DWORD)0x7c, 1);
			memory::Patch((BYTE*)(useManaAddr + 3), (DWORD)0xe6, 1);
			memory::Patch((BYTE*)(useManaAddr + 4), (DWORD)0x2b, 1);
			memory::Patch((BYTE*)(useManaAddr + 5), (DWORD)0xc2, 1);

			//reset walk speed
			uintptr_t walkSpeed = memory::FindAddr(moduleBase + 0x97D7C, { 0x4 , 0x8, 0x4, 0x4, 0x10, 0x120 }); //0x97E48
			float* wsPtr = (float*)walkSpeed;
			*wsPtr = 200.0;

			// reset jump speed
			uintptr_t jumpSpeed = memory::FindAddr(moduleBase + 0x97D7C, { 0x4 , 0x8, 0x10, 0x124 }); //0x97E48
			float* jsPtr = (float*)jumpSpeed;
			*jsPtr = 420.0;

			// reset jump hold time
			uintptr_t jumpHoldTime = memory::FindAddr(moduleBase + 0x97D7C, { 0x1C , 0x4, 0x224, 0x30, 0x18, 0x3E0, 0x128 }); //0x97E48
			float* jhtPtr = (float*)jumpHoldTime;
			*jhtPtr = .200000003;
			////

			break;
		}
		//*manaPtr = 105;
		
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






/*Hook Function Implementation













*/



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