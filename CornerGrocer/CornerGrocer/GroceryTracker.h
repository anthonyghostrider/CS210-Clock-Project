#ifndef GROCERY_TRACKER_H
#define GROCERY_TRACKER_H

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <iomanip>

class GroceryTracker {
private:
    std::map<std::string, int> itemFrequencies;

    // Internal helper to read input file and populate the map
    void loadDataFromFile(const std::string& filename);

public:
    // Constructor initializes data and creates the backup file automatically
    GroceryTracker(const std::string& inputFilename);

    // Core functional methods required by prompt
    int getItemFrequency(const std::string& item) const;
    void printAllFrequencies() const;
    void printHistogram(char symbol = '*') const;
    void createBackupFile(const std::string& outputFilename) const;
};

#endif
