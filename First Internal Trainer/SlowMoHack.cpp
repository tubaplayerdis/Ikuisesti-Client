
#include "pch.h"
#include "SlowMoHack.h"

uintptr_t moduleBaseH = (uintptr_t)GetModuleHandle(L"ac_client.exe");
uintptr_t* localPlayerPtrH = (uintptr_t*)(moduleBaseH + 0x10f4f4);
DWORD* localPlayerAddressH = (DWORD*)(moduleBaseH + 0x50F4F4);

void SetSpeedOfGame(float speed) {

}


int GetSpeedOfGame() {
	
	int* SpeedValue = (int*)(*localPlayerAddressH + 0x510CDC);
	return *SpeedValue;
}