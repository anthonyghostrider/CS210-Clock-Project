#include "GroceryTracker.h"

// Constructor: loads data from input file and generates backup file
GroceryTracker::GroceryTracker(const std::string& inputFilename) {
    loadDataFromFile(inputFilename);
    createBackupFile("frequency.dat");
}

// Private helper to parse the input file
void GroceryTracker::loadDataFromFile(const std::string& filename) {
    std::ifstream inFile(filename);
    std::string item;

    if (!inFile.is_open()) {
        std::cerr << "Error: Could not open input file " << filename << std::endl;
        return;
    }

    // Read word by word and increment count in map
    while (inFile >> item) {
        itemFrequencies[item]++;
    }

    inFile.close();
}

// Menu Option 1: Search frequency of a specific item
int GroceryTracker::getItemFrequency(const std::string& item) const {
    auto it = itemFrequencies.find(item);
    if (it != itemFrequencies.end()) {
        return it->second;
    }
    return 0; // Return 0 if item was not found in record
}

// Menu Option 2: Print list with numerical frequencies
void GroceryTracker::printAllFrequencies() const {
    std::cout << "\n====================================\n";
    std::cout << "        ITEM PURCHASE FREQUENCY      \n";
    std::cout << "====================================\n";
    for (const auto& pair : itemFrequencies) {
        std::cout << std::left << std::setw(15) << pair.first << " " << pair.second << "\n";
    }
    std::cout << "====================================\n";
}

// Menu Option 3: Print text-based histogram
void GroceryTracker::printHistogram(char symbol) const {
    std::cout << "\n====================================\n";
    std::cout << "          PURCHASE HISTOGRAM        \n";
    std::cout << "====================================\n";
    for (const auto& pair : itemFrequencies) {
        std::cout << std::left << std::setw(15) << pair.first << " ";
        std::cout << std::string(pair.second, symbol) << "\n";
    }
    std::cout << "====================================\n";
}

// Data File Creation: Writes output to backup file frequency.dat
void GroceryTracker::createBackupFile(const std::string& outputFilename) const {
    std::ofstream outFile(outputFilename);

    if (!outFile.is_open()) {
        std::cerr << "Error: Could not create backup file " << outputFilename << std::endl;
        return;
    }

    for (const auto& pair : itemFrequencies) {
        outFile << pair.first << " " << pair.second << "\n";
    }

    outFile.close();
}