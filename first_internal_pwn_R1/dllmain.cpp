// dllmain.cpp : Defines the entry point for the DLL application.
#include <windows.h>
#include <iostream>
#include <string.h>
#include "mem.h"
#include "library.h"
#include "MyForm.h"



extern int Main();

void WINAPI MainThread() {
	Main();
}


#pragma unmanaged
BOOL WINAPI DllMain(HMODULE hModule, DWORD  dwReason, LPVOID lpReserved) {
	switch (dwReason) {
	case DLL_PROCESS_ATTACH:
		DisableThreadLibraryCalls(hModule);
		if (CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)MainThread, NULL, 0, NULL) == NULL) {
			return FALSE;
		}
		break;
	case DLL_THREAD_ATTACH:
		break;
	case DLL_THREAD_DETACH:
		break;
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}

