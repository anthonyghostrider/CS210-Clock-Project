#include "clocks.h"
#include <iostream>
#include <iomanip>

// Formats an integer to always display as at least two digits (e.g., 5 -> "05")
std::string twoDigitString(int number) {
    if (number < 10) {
        return "0" + std::to_string(number);
    }
    return std::to_string(number);
}

// Formats internal 24-hour time into a standard 12-hour AM/PM string
std::string formatTime12(const TimeState& time) {
    int displayHours = time.hours % 12;
    if (displayHours == 0) {
        displayHours = 12; // Handle midnight and noon boundaries
    }
    std::string amPm = (time.hours >= 12) ? "P.M." : "A.M.";

    return twoDigitString(displayHours) + ":" +
        twoDigitString(time.minutes) + ":" +
        twoDigitString(time.seconds) + " " + amPm;
}

// Formats internal time into a standard 24-hour ISO 8601 string
std::string formatTime24(const TimeState& time) {
    return twoDigitString(time.hours) + ":" +
        twoDigitString(time.minutes) + ":" +
        twoDigitString(time.seconds);
}

// Displays both clocks side-by-side using specified decorative star formatting
void displayClocks(const TimeState& time) {
    std::cout << "*************************** ***************************" << std::endl;
    std::cout << "* 12-Hour Clock      * * 24-Hour Clock      *" << std::endl;
    std::cout << "* " << std::setw(11) << std::left << formatTime12(time) << "       * ";
    std::cout << "* " << std::setw(8) << std::left << formatTime24(time) << "       *" << std::endl;
    std::cout << "*************************** ***************************" << std::endl;
}

// Prints the interactive choice menu for the user interface
void printMenu() {
    std::cout << "***************************" << std::endl;
    std::cout << "* 1 - Add One Hour        *" << std::endl;
    std::cout << "* 2 - Add One Minute      *" << std::endl;
    std::cout << "* 3 - Add One Second      *" << std::endl;
    std::cout << "* 4 - Exit Program        *" << std::endl;
    std::cout << "***************************" << std::endl;
}

// Increments the hour, rolling over to 0 if it exceeds 23
void addHour(TimeState& time) {
    time.hours = (time.hours + 1) % 24;
}

// Increments the minute, rolling over and cascading into an hour increment if needed
void addMinute(TimeState& time) {
    time.minutes++;
    if (time.minutes >= 60) {
        time.minutes = 0;
        addHour(time);
    }
}

// Increments the second, rolling over and cascading into a minute increment if needed
void addSecond(TimeState& time) {
    time.seconds++;
    if (time.seconds >= 60) {
        time.seconds = 0;
        addMinute(time);
    }
}