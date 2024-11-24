#include<iostream>
#include<fstream>
#include<vector>
#include<map>

int OpenFile(std::ifstream& outStream, const std::string& fileName)
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

int main()
{
	std::ifstream inFileStream;
	std::map<std::string, int> t;


	if(OpenFile(inFileStream, "FahrenheitTemperature.txt") == 1) return 1;
	ReadData(inFileStream, t);
	PrintData(t);


	return 0;
}