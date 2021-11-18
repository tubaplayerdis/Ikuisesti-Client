#include <iostream>
#include <TlHelp32.h>
#include <Windows.h>
#include <WinUser.h>
#include "pch.h"
#include "CoordChange.h"


//Player Position XY : 0x4 - might be z
//Player Position XY : 0x8 - Might be x 
//Plyaer pos y 0x3c

uintptr_t moduleBase = (uintptr_t)GetModuleHandle(L"ac_client.exe");
uintptr_t* localPlayerPtr = (uintptr_t*)(moduleBase + 0x10f4f4);

// int* health = (int*)(*localPlayerAddress + 0xF8); example


void SetCoordinates(float X, float Y, float Z)
{
	if (localPlayerPtr)
	{
		
	}
	else {
		std::cout << "Local Player Pointer does not exist\n";
	}


}

float ReturnXvalue() {
	HANDLE processHandle = GetCurrentProcess();
	//ReadProcessMemory(processHandle, )


	return 1.2;
}

