#include "pch.h"
#include "Graphical.h"
#include <filesystem>
#include <fstream>
#include <iostream>
#include <fstream>



void AddToOutputCashe(const char* Value) 
{
	if (CheckCasheFileAndDirecotry == 0) {
		std::string appdatafolderpath = getenv("APPDATA");
		appdatafolderpath += "\\TubaPlayer";
		std::string filename = appdatafolderpath;
		filename += "\\cashe1.txt";
		std::ofstream outfile;

		outfile.open(filename, std::ios_base::app); // append instead of overwrite
		outfile << Value;
		outfile << "\r\n";
	}
	else
	{
		std::cout << "Did not add to cashe because no file existed";
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

void ClearOuputCashe()
{
	std::string appdatafolderpath = getenv("APPDATA"); // no \ and end of path
	//std::cout << appdatafolderpath << "\n";
	appdatafolderpath += "\\TubaPlayer";
	std::string filename = appdatafolderpath;
	filename += "\\cashe1.txt";


	if (CheckCasheFileAndDirecotry() == 0) {
		std::ofstream myfile;
		myfile.open(filename);
		myfile << "";
		myfile.close();
	}
	else {
		Graphical g;
		g.ShowBox("There was no cashe file to clear", "Error", MB_OK);
	}
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







std::string ReadOuptutCashe()
{
	using namespace std;
	std::string appdatafolderpath = getenv("APPDATA");
	appdatafolderpath += "\\TubaPlayer";
	std::string filename = appdatafolderpath;
	filename += "\\cashe1.txt";
	ifstream file(filename);
	string s;

	copy(istream_iterator<char>{ file >> noskipws }, {}, back_inserter(s));

	return s;
	
}


