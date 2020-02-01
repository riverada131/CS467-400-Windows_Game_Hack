// Pwn_Adventure_Hack.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "stdafx.h"
#include <vector>
#include <windows.h>
#include "proc.h"

int main()
{
	//get proc id of target process
	DWORD procId = GetProcId(L"GameLogic.dll");

	//get module base address
	uintptr_t moduleBase = GetModuleBaseAddress(procId, L"GameLogic.dll");

	//get handle to process
	HANDLE hProcess = 0;
	hProcess = OpenProcess(PROCESS_ALL_ACCESS, NULL, procId);

	//resolve base address
	uintptr_t dynamicPtrBaseAddr = moduleBase + 0x00097DE0;

	std::cout << "Dynamic Base Pointer = " << "0x" << std::hex << dynamicPtrBaseAddr << std::endl;

	//resolve health pointer chain
	std::vector<unsigned int> healthOffsets = { 0x0, 0x08, 0x0, 0x80, 0x30, 0x0 };
	uintptr_t healthAddr = FindDMAAddy(hProcess, dynamicPtrBaseAddr, healthOffsets);

	std::cout << "Health Address = " << "0x" << std::hex << healthAddr << std::endl;
	//read health value
	int healthValue = 0;
	ReadProcessMemory(hProcess, (BYTE*)healthAddr, &healthValue, sizeof(healthValue), nullptr);
	std::cout << "Current Health = " << std::dec << healthValue << std::endl;

	//write health value
	int newHealth = 600;
	WriteProcessMemory(hProcess, (BYTE*)healthAddr, &newHealth, sizeof(newHealth), nullptr);

	//read out to check
	ReadProcessMemory(hProcess, (BYTE*)healthAddr, &healthValue, sizeof(healthValue), nullptr);
	std::cout << "New Health = " << std::dec << healthValue << std::endl;

	getchar();
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
