#include<iostream>
#include<fstream>
#include<vector>
#include<map>


int main()
{
	std::ifstream inFileStream;
	std::map<std::string, int> t;
	std::string city = "";
	int temperature = 0;

	inFileStream.open("FahrenheitTemperature.txt");
	if (!inFileStream.is_open())
	{
		std::cout << "Could not open file." << std::endl;
		return 1;
	}
	
	while (!inFileStream.eof())
	{
		inFileStream >> city;
		inFileStream >> temperature;
		t[city] = temperature;
	}

	std::map<std::string, int>::iterator it = t.begin();

	while (it != t.end())
	{
		std::cout << it->first << " " << it->second << std::endl;
		++it;
	}

	return 0;
}