#include<iostream>
#include<fstream>
#include<map>
#include<cmath>
#include "main.h"

//Opens a file for a given stream.
template<typename T>
bool OpenFile(T& outStream, const std::string& fileName)
{
	outStream.open(fileName);
	if (!outStream.is_open())
	{
		std::cout << "Could not open file." << std::endl;
		return false;
	}
	return true;
}

void ReadData(std::ifstream& stream, std::map<std::string, int>& outMap)
{
	std::string city = "";
	int temperature = 0;

	while (!stream.eof())
	{
		stream >> city;
		stream >> temperature;
		outMap[city] = temperature;
	}

	stream.close();
}

//Helper function to verify data is being read and calculated correctly...
void PrintData(std::map<std::string, int>& map)
{
	std::map<std::string, int>::iterator it = map.begin();

	while (it != map.end())
	{
		std::cout << it->first << " " << it->second << std::endl;
		++it;
	}
}

void ConvertToCelsius(std::map<std::string, int>& FahrenheitTemps, std::map<std::string, int>& CelsiusTemps)
{
	std::map<std::string, int>::iterator it = FahrenheitTemps.begin();
	while (it != FahrenheitTemps.end())
	{
	
		CelsiusTemps[it->first] = round((it->second - 32) * (5.0 / 9.0));
		++it;
	}
}

int main()
{
	std::ifstream inFileStream;
	std::ofstream outFileStream;
	std::map<std::string, int> fahrenheitTemps;
	std::map<std::string, int> celsiusTemps;

	//if the OpenFile Function fails then the program terminates. 
	if(!OpenFile(inFileStream, "FahrenheitTemperature.txt")) return 1;
	ReadData(inFileStream, fahrenheitTemps);
	ConvertToCelsius(fahrenheitTemps, celsiusTemps);

	std::map<std::string, int>::iterator it = celsiusTemps.begin();

	if(!OpenFile(outFileStream, "CelsiusTemperature.txt")) return 1;

	while (it != celsiusTemps.end())
	{
		outFileStream << it->first << " " << it->second << std::endl;
		++it;
	}

	outFileStream.close();

	return 0;
}

