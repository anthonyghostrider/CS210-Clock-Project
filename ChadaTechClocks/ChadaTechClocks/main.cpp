/**
 * @file main.cpp
 * @brief Chada Tech Clocks Application Simulation
 * @author Anthoni Rahming
 */

#include <iostream>
#include "clocks.h"

int main() {
    TimeState currentClockTime = { 0, 0, 0 };
    int userChoice = 0;

    // Get initial time inputs from the user with basic range validation
    std::cout << "--- Initial Time Configuration ---" << std::endl;

    std::cout << "Enter initial hour (0-23): ";
    while (!(std::cin >> currentClockTime.hours) || currentClockTime.hours < 0 || currentClockTime.hours > 23) {
        std::cout << "Invalid entry. Enter an hour between 0 and 23: ";
        std::cin.clear();
        std::cin.ignore(1000, '\n');
    }

    std::cout << "Enter initial minute (0-59): ";
    while (!(std::cin >> currentClockTime.minutes) || currentClockTime.minutes < 0 || currentClockTime.minutes > 59) {
        std::cout << "Invalid entry. Enter a minute between 0 and 59: ";
        std::cin.clear();
        std::cin.ignore(1000, '\n');
    }

    std::cout << "Enter initial second (0-59): ";
    while (!(std::cin >> currentClockTime.seconds) || currentClockTime.seconds < 0 || currentClockTime.seconds > 59) {
        std::cout << "Invalid entry. Enter a second between 0 and 59: ";
        std::cin.clear();
        std::cin.ignore(1000, '\n');
    }

    // Main execution application loop
    do {
        // Step 1: Display Clocks
        displayClocks(currentClockTime);

        // Step 2: Display Menu
        printMenu();
        std::cout << "Enter your choice: ";
        std::cin >> userChoice;

        // Step 3: Match choices to logical flowchart blocks
        switch (userChoice) {
        case 1:
            addHour(currentClockTime);
            break;
        case 2:
            addMinute(currentClockTime);
            break;
        case 3:
            addSecond(currentClockTime);
            break;
        case 4:
            std::cout << "Exiting system. Goodbye!" << std::endl;
            break;
        default:
            std::cout << "Invalid menu choice. Please select 1-4." << std::endl;
            break;
        }
        std::cout << std::endl;

    } while (userChoice != 4); // Loop continues until user explicitly exits

    return 0;
}