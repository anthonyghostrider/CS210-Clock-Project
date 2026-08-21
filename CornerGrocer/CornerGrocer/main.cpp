#include <iostream>
#include <limits>
#include "GroceryTracker.h"

void displayMenu() {
    std::cout << "\n--- CORNER GROCER ITEM TRACKER ---\n";
    std::cout << "1. Search for item purchase frequency\n";
    std::cout << "2. Display all item frequencies\n";
    std::cout << "3. Display item frequency histogram\n";
    std::cout << "4. Exit program\n";
    std::cout << "Enter your choice (1-4): ";
}

int main() {
    // Instantiate tracker object (reads CS210_Project_Three_Input_File.txt & builds frequency.dat)
    GroceryTracker tracker("CS210_Project_Three_Input_File.txt");

    int userChoice = 0;

    while (userChoice != 4) {
        displayMenu();

        // Input validation check for integers 1-4
        if (!(std::cin >> userChoice)) {
            std::cout << "\nInvalid input! Please enter a numerical menu option (1-4).\n";
            std::cin.clear(); // Clear error state flags
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear stream buffer
            continue;
        }

        switch (userChoice) {
        case 1: {
            std::string searchItem;
            std::cout << "\nEnter item name to search: ";
            std::cin >> searchItem;

            int count = tracker.getItemFrequency(searchItem);
            std::cout << "\nResult: " << searchItem << " was purchased " << count << " time(s).\n";
            break;
        }
        case 2:
            tracker.printAllFrequencies();
            break;
        case 3:
            tracker.printHistogram('*');
            break;
        case 4:
            std::cout << "\nExiting Corner Grocer Tracking System. Data backed up to frequency.dat.\n";
            break;
        default:
            std::cout << "\nInvalid option! Choice must be between 1 and 4.\n";
            break;
        }
    }

    return 0;
}