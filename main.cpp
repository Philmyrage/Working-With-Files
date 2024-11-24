#include<iostream>
#include<fstream>
#include<map>
#include<cmath>

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

void WriteDataToFile(std::map<std::string, int>& celsiusTemps, std::ofstream& outFileStream)
{
	std::map<std::string, int>::iterator it = celsiusTemps.begin();
	while (it != celsiusTemps.end())
	{
		outFileStream << it->first << " " << round((it->second - 32) * (5.0 / 9.0)) << std::endl;
		++it;
	}
	outFileStream.close();
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

int main()
{
	std::ifstream inFileStream;
	std::ofstream outFileStream;
	std::map<std::string, int> fahrenheitTemps;

	//Read the fahrenheitTemps from file.
	//if the OpenFile Function fails then the program terminates. 
	if(!OpenFile(inFileStream, "FahrenheitTemperature.txt")) return 1;
	ReadData(inFileStream, fahrenheitTemps);
	
	//Write CelsiusTemps to file.
	if(!OpenFile(outFileStream, "CelsiusTemperature.txt")) return 1;
	WriteDataToFile(fahrenheitTemps, outFileStream);

	std::cout << "Conversion complete and data written to file..." << std::endl;

	return 0;
}


