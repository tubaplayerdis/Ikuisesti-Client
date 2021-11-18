// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include <Windows.h>
#include <iostream>
#include <TlHelp32.h>
#include "mem.h"
#include "proc.h"
#include "ConsoleShortcuts.h"
#include "Graphical.h"
#include "TeleportLocation.h"

DWORD WINAPI HackThread(HMODULE hModule) 
{
    //To use structure dissasembler first use memory view on USE THIS PUT INTO then pess tools dissect data structures then you can look at cool stuff

    //also offset 0000 = 0x0

    //look at this tutorial for refesh

    //USE 0x as represent 00 or 000 the the digits after the 0 count not the others
    // i think put 0x before anthting

    //Raw Values
    // 0150 = current ammo = 0x150
    // 0128 clip
    // 0158 = grenade

    //Player Base : "ac_client.exe" + 0x109B74 / 0x509B74
    //Player Health : 0xF8
    //Player Primary : 0x128
    //Player Primary Clip : 0x150
    //Player Secondary : 0x114
    //Player SecondaryClip : 0x13C
    //Player Grenade Ammo : 0x158
    //Player Armor : 0xFC
    //Player Position XY : 0x4 - might be z
    //Player Position XY : 0x8 - Might be x 
    //Plyaer pos y 0x3c
    //Player Position Z : 0xC
    //Player View Angle Verticle : 0x44
    //Player View Angle Horizontal : 0x40
    //Time Between Knifes : 0x160
    //Pistol Timer : 0x164
    //Primary Timer : 0x178
    //Grenade Timer(? ) : 0x180
    //Mouse Button Down : 0x224
    //Entity Base : "ac_client.exe" + 0x110D90 / 0x510D90
    //TeamOffset1 : 0x204
    //TeamOffset2 : 0x32C


    //Create Console
    AllocConsole();
    FILE* f;
    freopen_s(&f, "CONOUT$", "w", stdout);

    

    Graphical g;
    g.ShowBoxS("Welcome to TubaPLayer's internal trianer for Assault Cube!", "Start Message", MB_OK);

    std::cout << "Console has started :) Along with Form Prep :))\n\n";

    System::Windows::Forms::Application::EnableVisualStyles();
    System::Windows::Forms::Application::SetCompatibleTextRenderingDefault(false);


    std::cout << "NUMPAD 1 = Toggle Health Freeze\nNUMPAD 2 = Toggle Ammo Freeze\nNUMPAD 3 = Recoil Disable\nNUMAPD 4 = Revert Health to 100\nNUMPAD 5 = Revert Ammo to 100\nEND = Eject\n";
    
    

    //get module base
    uintptr_t moduleBase = (uintptr_t)GetModuleHandle(L"ac_client.exe");
    HANDLE processHandle = GetCurrentProcess();

    uintptr_t* localPlayerPtrG = (uintptr_t*)(moduleBase + 0x10f4f4);// global offset

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
                        
            std::cout << "Toggled Freeze Health\n";            
            bHealth = !bHealth;
            std::cout << "Health Freeze = " << bHealth << "\n";
        }

        if (GetAsyncKeyState(VK_NUMPAD2) & 1)
        {
            std::cout << "Toggled Freeze Ammo\n";
            bAmmo = !bAmmo;
            std::cout << "Ammo Freeze = " << bAmmo << "\n";
        }

        if (GetAsyncKeyState(VK_NUMPAD3) & 1)
        {
            PrintLine("Toggled Recoil");
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
            uintptr_t* localPlayerPtr = (uintptr_t*)(moduleBase + 0x10f4f4); //0x10f4f4
            DWORD* localPlayerAddress = (DWORD*)(0x50F4F4); 
            int* health = (int*)(*localPlayerAddress + 0xF8);
            if (localPlayerAddress)
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

        if (GetAsyncKeyState(VK_NUMPAD6) & 1) 
        {
            PrintLine("moving location to 10 y");
            uintptr_t* localPlayerPtr = (uintptr_t*)(moduleBase + 0x10f4f4);
            if (localPlayerPtr)
            {
                float* playery = (float*)(*localPlayerPtr + 0x3c); // get addres is use = then sets it
                std::cout << *playery;
                *playery = 10;
            }
            else 
            {
                PrintLine("Player pointer does not exist");
            }
        }

        if (GetAsyncKeyState(VK_NUMPAD7) & 1)
        {
            uintptr_t* localPlayerPtr = (uintptr_t*)(moduleBase + 0x10f4f4);
            using namespace System::Windows::Forms;

            if (localPlayerPtr) {
                FirstInternalTrainer::TeleportLocation p;
                Application::Run(% p);
            }
            else {
                PrintLine("Local Player Pointer does not exist");
            }
            
            
            PrintLine("Enabled numpad 7");
        }

        //continues writes/freeze

        uintptr_t* localPlayerPtr = (uintptr_t*)(moduleBase + 0x10f4f4);
        DWORD* localPlayerAddress = (DWORD*)(0x50F4F4); //use this if LocalPlayerPtr does not
        int* health = (int*)(*localPlayerAddress + 0xF8);
        if (localPlayerPtr)
        {
            if (bHealth) 
            {
                *health = *Healthadd;
            }

            if (bAmmo)
            {
                uintptr_t ammoAddr = mem::FindDMAAddy(moduleBase + 0x10f4f4, { 0x374, 0x14, 0x0 });//{} is for aadresing pointers then addresing pointers then the value, does not have to be p->p->A
                int* ammo = (int*)ammoAddr;
                *ammo = 1337;

                //or this 
                //*(int*)mem::FindDMAAddy(moduleBase + 0x10f4f4, { 0x374, 0x14, 0x0 }) = 1337; //USE THIS PLEASE
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

        DisableThreadLibraryCalls(hModule); //THIS IS WHY CLR WORKS OMG WTF

        CloseHandle(CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE)HackThread, hModule, 0, nullptr));
    }
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

