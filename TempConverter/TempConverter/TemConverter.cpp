#include <iostream>
#include <fstream>
#include <string>

int main() {
    // Declare input stream and open the Fahrenheit file
    std::ifstream inFile;
    inFile.open("FahrenheitTemperature.txt");

    // Check if input file opened successfully
    if (!inFile.is_open()) {
        std::cout << "Error: Could not open FahrenheitTemperature.txt" << std::endl;
        return 1;
    }

    // Declare output stream and create/open the Celsius file
    std::ofstream outFile;
    outFile.open("CelsiusTemperature.txt");

    // Check if output file created successfully
    if (!outFile.is_open()) {
        std::cout << "Error: Could not create CelsiusTemperature.txt" << std::endl;
        inFile.close();
        return 1;
    }

    std::string city;
    int tempFahrenheit;

    // Read line-by-line: single-word city name followed by integer temperature
    while (inFile >> city >> tempFahrenheit) {
        // Convert Fahrenheit to Celsius: (F - 32) * (5 / 9)
        // Using 5.0 / 9.0 ensures floating-point division instead of integer truncation
        double tempCelsius = (tempFahrenheit - 32.0) * (5.0 / 9.0);

        // Write converted result to the new text file
        outFile << city << " " << tempCelsius << std::endl;
    }

    // Always close file streams when done
    inFile.close();
    outFile.close();

    std::cout << "Conversion complete! File 'CelsiusTemperature.txt' has been generated." << std::endl;

    return 0;
}