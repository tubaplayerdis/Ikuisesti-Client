#include "pch.h"
#include "mem.h"
#include "LogFrameWork.h"


void mem::PatchEx(BYTE* dst, BYTE* src, unsigned int size, HANDLE hProcess)
{
	DWORD oldprotect;
	VirtualProtectEx(hProcess, dst, size, PAGE_EXECUTE_READWRITE, &oldprotect);
	WriteProcessMemory(hProcess, dst, src, size, nullptr);
	VirtualProtectEx(hProcess, dst, size, oldprotect, &oldprotect);
}

void mem::NopEx(BYTE* dst, unsigned int size, HANDLE hProcess)
{
	BYTE* nopArray = new BYTE[size];
	memset(nopArray, 0x90, size);

	PatchEx(dst, nopArray, size, hProcess);
	delete[] nopArray;
}

/*
uintptr_t mem::FindDMAAddy(HANDLE hProc, uintptr_t ptr, std::vector<unsigned int> offsets)
{
	uintptr_t addr = ptr;
	for (unsigned int i = 0; i < offsets.size(); ++i)
	{
		ReadProcessMemory(hProc, (BYTE*)addr, &addr, sizeof(addr), 0);
		addr += offsets[i];
	}
	return addr;
}
*/

void mem::Patch(BYTE* dst, BYTE* src, unsigned int size)
{
	try
	{
		DWORD oldprotect;
		VirtualProtect(dst, size, PAGE_EXECUTE_READWRITE, &oldprotect);
		memcpy(dst, src, size);
		VirtualProtect(dst, size, oldprotect, &oldprotect);
	}
	catch (...)
	{
		AddToOutputCashe("Terminal Error in Patch");
	}
	
}

void mem::Nop(BYTE* dst, unsigned int size)
{
	try
	{
		DWORD oldprotect;
		VirtualProtect(dst, size, PAGE_EXECUTE_READWRITE, &oldprotect);
		memset(dst, 0x90, size);
		VirtualProtect(dst, size, oldprotect, &oldprotect);
	}
	catch (...)
	{
		AddToOutputCashe("Terminal Error in Nop");
	}
	
}

uintptr_t mem::FindDMAAddy(uintptr_t ptr, std::vector<unsigned int> offsets)
{
	try
	{
		uintptr_t addr = ptr;
		for (unsigned int i = 0; i < offsets.size(); ++i)
		{
			addr = *(uintptr_t*)addr;
			addr += offsets[i];
		}
		return addr;
	}
	catch(...)
	{
		AddToOutputCashe("Ternminal Error in FindDMAAddy");
	}
	
}