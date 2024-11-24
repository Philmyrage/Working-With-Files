#include<iostream>
#include<fstream>
#include<map>
#include<cmath>
#include "main.h"

int OpenFileForReading(std::ifstream& outStream, const std::string& fileName)
{
	outStream.open(fileName);
	if (!outStream.is_open())
	{
		std::cout << "Could not open file." << std::endl;
		return 1;
	}
	return 0;
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
	std::map<std::string, int> FahrenheitTemps;
	std::map<std::string, int> CelsiusTemps;

	//if the OpenFile Function fails then the program terminates. 
	if(OpenFileForReading(inFileStream, "FahrenheitTemperature.txt") == 1) return 1;
	ReadData(inFileStream, FahrenheitTemps);

	ConvertToCelsius(FahrenheitTemps, CelsiusTemps);

	PrintData(CelsiusTemps);

	return 0;
}

