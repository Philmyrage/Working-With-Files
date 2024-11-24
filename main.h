#pragma once

void ConvertToCelsius(std::map<std::string, int>& FahrenheitTemps, std::map<std::string, int>& CelsiusTemps);

void WriteDataToFile(std::map<std::string, int>& celsiusTemps, std::ofstream& outFileStream);
