// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include <Windows.h>
#include <iostream>
#include <TlHelp32.h>
#include "mem.h"
#include "proc.h"

DWORD WINAPI HackThread(HMODULE hModule) 
{
    //Create Console
    AllocConsole();
    FILE* f;
    freopen_s(&f, "CONOUT$", "w", stdout);

    std::cout << "Console has started :)\n\n";

    std::cout << "NUMPAD 1 = Toggle Health Freeze\nNUMPAD 2 = Toggle Ammo Freeze\nNUMPAD 3 = Recoil Disable\nNUMAPD 4 = Revert Health to 100\nNUMPAD 5 = Revert Ammo to 100\nEND = Eject\n";

    //get module base
    uintptr_t moduleBase = (uintptr_t)GetModuleHandle(L"ac_client.exe");

    bool bHealth = false, bAmmo = false, bRecoil = false;

    int h = 1337;
    int* Healthadd = &h;

    //Big Juicy Penis

    //hack loop
    while (true)
    {
        //key input
        if (GetAsyncKeyState(VK_END) & 1) 
        {
            break;
        }

        if (GetAsyncKeyState(VK_NUMPAD1) & 1)
        {     
                        
            std::cout << "Freezing health...\n";            
            bHealth = !bHealth;
            std::cout << "Health Freeze = " << bHealth << "\n";
        }

        if (GetAsyncKeyState(VK_NUMPAD2) & 1)
        {
            std::cout << "Freezing ammo...\n";
            bAmmo = !bAmmo;
            std::cout << "Ammo Freeze = " << bAmmo << "\n";
        }

        if (GetAsyncKeyState(VK_NUMPAD3) & 1)
        {
            bRecoil = !bRecoil;

            if (bRecoil) 
            {
                mem::Nop((BYTE*)(moduleBase + 0x63786), 10);
            }
            else
            {
                //write back original instuctions
                //50 8D 4C 24 1C 51 8B CE FF D2 the original stack setup and call
                mem::Patch((BYTE*)(moduleBase + 0x63786), (BYTE*)"\x50\x8d\x4c\x24\x1c\x51\x8b\xce\xff\xd2", 10);
            }
        }

        if (GetAsyncKeyState(VK_NUMPAD4) & 1) 
        {
            std::cout << "Reverting Health(Will not work if freeze is on)\n";
            uintptr_t* localPlayerPtr = (uintptr_t*)(moduleBase + 0x10f4f4);
            DWORD* localPlayerAddress = (DWORD*)(0x50F4F4);
            int* health = (int*)(*localPlayerAddress + 0xF8);
            if (localPlayerPtr)
            {
                *health = 100;
            }
            else
            {
                std::cout << "Player Pointer does not exist, please get into the game\n";
            }
        }

        if (GetAsyncKeyState(VK_NUMPAD5) & 1)
        {
            std::cout << "Reverting Ammo(Will not work if freeze is on)\n";
            uintptr_t* localPlayerPtr = (uintptr_t*)(moduleBase + 0x10f4f4);
            if (localPlayerPtr) 
            {
                uintptr_t ammoAddr = mem::FindDMAAddy(moduleBase + 0x10f4f4, { 0x374, 0x14, 0x0 });
                int* ammo = (int*)ammoAddr;
                *ammo = 100;
            }
            else
            {
                std::cout << "Player Pointer does not exist, please get into the game\n";
            }
            
        }

        //continues writes/freeze

        uintptr_t* localPlayerPtr = (uintptr_t*)(moduleBase + 0x10f4f4);
        DWORD* localPlayerAddress = (DWORD*)(0x50F4F4);
        int* health = (int*)(*localPlayerAddress + 0xF8);
        if (localPlayerPtr)
        {
            if (bHealth) 
            {
                *health = *Healthadd;
            }

            if (bAmmo)
            {
                uintptr_t ammoAddr = mem::FindDMAAddy(moduleBase + 0x10f4f4, { 0x374, 0x14, 0x0 });
                int* ammo = (int*)ammoAddr;
                *ammo = 1337;

                //or this 
                //*(int*)mem::FindDMAAddy(moduleBase + 0x10f4f4, { 0x374, 0x14, 0x0 }) = 1337;
            }

            

            
        }        
        Sleep(5);
    }
    
    //cleanup & eject
    fclose(f);
    FreeConsole();
    FreeLibraryAndExitThread(hModule, 0);
    return 0;
}


BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH: {
        CloseHandle(CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE)HackThread, hModule, 0, nullptr));
    }
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

