#include <iostream>
#include <Windows.h>
#include <TlHelp32.h>
#include <WinUser.h>
#include "pch.h"
#include "CoordChange.h"


//Player Position XY : 0x4 - might be z
//Player Position XY : 0x8 - Might be x 
//Plyaer pos y 0x3c


/*
WORD m_XPos = 0x0038;
WORD m_YPos = 0x003C;
WORD m_ZPos = 0x0040;

WORD m_isPosMoving = 0x0070;
WORD m_Speed = 0x0080;
WORD m_Health = 0x00F8;
WORD m_Vest = 0x00FC;
WORD m_AmmoMags = 0x0128;
WORD m_Ammo = 0x0150;
WORD m_SecAmmo = 0x013C;
WORD m_Flashbangs = 0x0158;
WORD m_WeaponTimer = 0x0178;
WORD m_ShotsFired = 0x01A0;

VISUALS AND SOME OTHER STUFF
Just test it out. You can add this Addresses in Cheatengine or with some other WPM stuff to see what it changes

__int32 sv_GetMode = 0x50F49C ;
__int32 sv_ClientNumber = 0x510198 ;
__int32 sv_name = 0x51019C ;
__int32 p_MaxRoll = 0x510144 ;
__int32 p_AutoReload = 0x5101D0 ;
__int32 o_Paused = 0x510CE0 ;
__int32 o_GameSpeed = 0x510CDC ;
__int32 m_MouseShotSensitivity = 0x4EE444 ; //CHANGE THIS TO 0 FOR NO RECOIL
__int32 m_InvertMouse = 0x51016C ;
__int32 h_ToggleConsole = 0x4FEC10 ;
__int32 h_ShowTarget = 0x50F284 ;
__int32 h_ShowSpeed = 0x50F288 ;
__int32 h_ShowScoreOnDeath = 0x50F514 ;
__int32 h_ShowRadarValues = 0x50F268 ;
__int32 h_ShowMap = 0x50F240 ;
__int32 h_Righthanded = 0x510A4C ;
__int32 h_RadarHeight = 0x50F264 ;
__int32 h_RadarEntSize = 0x50F208 ;
__int32 h_OldAmmoHUD = 0x510A48 ;
__int32 h_HideRadar = 0x50F21C ;
__int32 h_HideHudMessages = 0x50F230 ;
__int32 h_HideHudEquipment = 0x50F234 ;
__int32 h_HideDamageIndicator = 0x50F248 ;
__int32 h_HideCompass = 0x50F220 ;
__int32 h_DrawGun = 0x50F200 ;
__int32 h_DrawFPS = 0x50F210 ;
__int32 h_DbgPos = 0x50F280 ;
__int32 h_DamageScreenFade = 0x50F278 ;
__int32 h_DamageScreenFactor = 0x50F270 ;
__int32 h_DamageScreenAlpha = 0x50F274 ;
__int32 h_DamageScreen = 0x50F26C ;
__int32 h_CrosshairSize = 0x50F20C ;
__int32 g_GameVersion = 0x510CF4 ;
__int32 dbg_FlySpeed = 0x510148 ;
__int32 EngineState_Test = 0x509BD8 ;


*/


uintptr_t moduleBase = (uintptr_t)GetModuleHandle(L"ac_client.exe");
uintptr_t* localPlayerPtrG = (uintptr_t*)(moduleBase + 0x10f4f4);
DWORD* localPlayerAddress = (DWORD*)(0x50F4F4);

// int* health = (int*)(*localPlayerAddress + 0xF8); example


void SetCoordinates(Coordinates Values)
{
	
	
	if (localPlayerPtrG)
	{
		float X = Values.X;
		float Y = Values.Y;
		float Z = Values.Z;


		float* Xpos = (float*)(*localPlayerAddress + 0x0038);
		float* Ypos = (float*)(*localPlayerAddress + 0x003C);
		float* Zpos = (float*)(*localPlayerAddress + 0x0040);

		*Xpos = X;
		*Ypos = Y;
		*Zpos = Z;

	}
	else {
		std::cout << "Local Player Pointer does not exist\n";
	}
	

}

float ReturnXvalue() {
	if (localPlayerPtrG)
	{
		float* Xpos = (float*)(*localPlayerAddress + 0x8);
		float I = *Xpos;
		return I;
	}
	else {
		std::cout << "Local Player Pointer does not exist\n";
	}
	
	
}

float ReturnYvalue() {
	if (localPlayerPtrG)
	{
		float* Ypos = (float*)(*localPlayerAddress + 0x3c);
		float I = *Ypos;
		return I;
	}
	else {
		std::cout << "Local Player Pointer does not exist\n";
	}
	
}

float ReturnZvalue() {
	if (localPlayerPtrG)
	{
		float* Zpos = (float*)(*localPlayerAddress + 0x4);
		float I = *Zpos;
		return I;
	}
	else {
		std::cout << "Local Player Pointer does not exist\n";
	}
	
}

/*
* int lol = CreateOutputCashe();
            if (lol == 0) {
                PrintLine("Error with creating cashe");
            }
            else if (lol == 1) {
                PrintLine("Directory and file existed");
            }
            else if (lol == 2) {
                PrintLine("Directory existed and file was created");
            }
            else if (lol == 3) {
                PrintLine("Directory and file were created");
            }
*/

