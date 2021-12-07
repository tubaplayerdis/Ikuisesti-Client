
#include "pch.h"
#include "Armor.h"
#include "LogFrameWork.h"
#include "mem.h"
#include <string>
#include <Windows.h>
#include <TlHelp32.h>

uintptr_t moduleBaseH = (uintptr_t)GetModuleHandle(L"ac_client.exe");
uintptr_t localPlayerPtrH = (uintptr_t)(moduleBaseH + 0x509B74);
uintptr_t localPlayerAddressH = (uintptr_t)(moduleBaseH + 0x50F4F4);



void SetCrosshairSize(int size) {

}


int GetCorsshairSize() {
	

	try 
	{
		uintptr_t speedv = mem::FindDMAAddy(localPlayerPtrH, { 0xFC });
		int* SpeedValue = (int*)speedv;				
		return *SpeedValue;
	}
	catch (...)
	{
		
		AddToOutputCashe("Memory Accces violation");
	}
	
}