#include "proc.h"
#include "stdafx.h"

DWORD GetProcId(const wchar_t* procName) {
	DWORD procId = 0;	  //Error checking set process id to 0
	HANDLE hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);	//take a snapshot of the process id store in hsnap
	if (hSnap != INVALID_HANDLE_VALUE) {  //error check
		PROCESSENTRY32 procEntry;																	   
		procEntry.dwSize = sizeof(procEntry); //set dwsize 
		if (Process32First(hSnap, &procEntry)) {// grabs first process in the snapshot store in proc entry
			do {
				if (!_wcsicmp(procEntry.szExeFile, procName)) {	//compare file name to given process name
					procId = procEntry.th32ProcessID;	// if pass then pass the process id to proc id
					break;
				}
			} while (Process32Next(hSnap, &procEntry));
		}
	}
	CloseHandle(hSnap);	 //close the handle	for proper memory management
	return procId;	//return the process id
}

uintptr_t GetModuleBaseAddress(DWORD procId, const wchar_t* modName) {
	uintptr_t modBaseAddr = 0;
	HANDLE hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE | TH32CS_SNAPMODULE32, procId);
	if (hSnap != INVALID_HANDLE_VALUE) {
		MODULEENTRY32 modEntry;
		modEntry.dwSize = sizeof(modEntry);
		if (Module32First(hSnap, &modEntry)) {
			do {
				if (!_wcsicmp(modEntry.szModule, modName)) {
					modBaseAddr = (uintptr_t)modEntry.modBaseAddr;
					break;
				}
			} while (Module32Next(hSnap, &modEntry));
		}
		CloseHandle(hSnap);
		return modBaseAddr;
	}

}

uintptr_t FindDMAAddy(HANDLE hProc, uintptr_t ptr, std::vector<unsigned int> offsets) {
	uintptr_t addr = ptr;
	for (unsigned int i = 0; i < offsets.size(); i++) {
		ReadProcessMemory(hProc, (BYTE*)addr, &addr, sizeof(addr), 0);
		addr += offsets[i];
	}
	return addr;
}





