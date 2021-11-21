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
	std::string appdatafolderpath = getenv("APPDATA"); // no \ and end of path
	//std::cout << appdatafolderpath << "\n";
	appdatafolderpath += "\\TubaPlayer";
	std::string filename = appdatafolderpath;
	filename += "\\cashe1.txt";
	//std::cout << appdatafolderpath << std::endl;
	//std::cout << filename << std::endl;
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

/*
* 0 = Both File and Direcotry Exist
* 1 = Directory Exists
* 2 = Cashe and Direcotry do not exist
*/
int CheckCasheFileAndDirecotry()
{
	std::string appdatafolderpath = getenv("APPDATA");
	appdatafolderpath += "\\TubaPlayer";
	std::string filename = appdatafolderpath;
	filename += "\\cashe1.txt";
	if (std::filesystem::is_directory(appdatafolderpath)) 
	{
		if (std::filesystem::exists(filename))
		{
			return 0;
		}
		else
		{
			return 1;
		}
	}
	else 
	{
		return 2;//test
	}
}

const char* ReadOuptutCashe()
{
	
	return "penis";
}


