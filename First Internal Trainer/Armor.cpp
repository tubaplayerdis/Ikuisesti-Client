
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
uintptr_t pppp = (uintptr_t)(moduleBaseH + 0x109B74);
uintptr_t* AAAA = (uintptr_t*)(moduleBaseH + 0x109B74);



void SetArmorSize(int size) {
	try
	{
		int* armor = (int*)(*AAAA + 0xFC);
		*armor = size;
	}
	catch (...)
	{
		AddToOutputCashe("Terminal Error in Seting Armor: Armor.cpp");
	}
}


int GetArmorSize() {
	

	try 
	{
		uintptr_t speedv = mem::FindDMAAddy(pppp, { 0xFC });
		
		int* SpeedValue = (int*)speedv;				
		return *SpeedValue;
	}
	catch(...)
	{
		AddToOutputCashe("Terminal Error in Armor.cpp");
	}
	
	
}