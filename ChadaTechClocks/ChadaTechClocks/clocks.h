#ifndef CLOCKS_H
#define CLOCKS_H

#include <string>

// Structure to hold the current time state
struct TimeState {
    int hours;   // 24-hour format internally (0-23)
    int minutes; // 0-59
    int seconds; // 0-59
};

// Core functional requirements
void displayClocks(const TimeState& time);
void printMenu();
void addHour(TimeState& time);
void addMinute(TimeState& time);
void addSecond(TimeState& time);

// Utility functions for formatting and output
std::string formatTime12(const TimeState& time);
std::string formatTime24(const TimeState& time);
std::string twoDigitString(int number);

#endif // CLOCKS_H