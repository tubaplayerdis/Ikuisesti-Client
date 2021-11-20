#include "pch.h"
#include <filesystem>
#include <fstream>



void AddToOutputCashe(const char Value) 
{

}

void ClearOuputCashe()
{

}

/*
* Return Values
* 0 = failed
* 1 = directory and file existed
* 2 = direcotry existed and file was created
* 3 = directory and file were created
*/
int CreateOutputCashe()
{
	const char* appdatafolderpath = getenv("APPDATA"); // no \ and end of path
	appdatafolderpath =+ "\\TubaPlayer";
	const char* filename = appdatafolderpath;
	filename =+ "\\cashe1.txt";
	if (std::filesystem::is_directory(appdatafolderpath)) {
		if (std::filesystem::exists(filename))
		{
			return 1;
		}
		else
		{
			std::ofstream file (filename);
			if (file.is_open()) {
				return 1;
			}
			else
			{
				file.open(filename);
				return 2;
			}
		}

	}
	else 
	{
		if (!std::filesystem::create_directory(appdatafolderpath))
		{
			return 0;
		}
		else 
		{
			std::ofstream file(filename);
			if (file.is_open()) {
				return 1;
			}
			else {
				file.open(filename);
				return 3;
			}
		}
	}
	
}

const char* ReadOuptutCashe()
{
	
	return "penis";
}


