#include <iostream>
#include <limits>
#include "Investment.h"

using namespace std;

// Function declarations for input validation and menu handling
void DisplayInputScreen(double& t_initialInvestment, double& t_monthlyDeposit,
    double& t_annualInterest, int& t_numberOfYears);

int main() {
    char userChoice = 'y';

    while (userChoice == 'y' || userChoice == 'Y') {
        double initialInvestment = 0.0;
        double monthlyDeposit = 0.0;
        double annualInterest = 0.0;
        int numberOfYears = 0;

        // Display input form and get user data
        DisplayInputScreen(initialInvestment, monthlyDeposit, annualInterest, numberOfYears);

        // Instantiate investment object
        Investment userInvestment(initialInvestment, monthlyDeposit, annualInterest, numberOfYears);

        // Render both financial reports
        userInvestment.PrintReportWithoutMonthlyDeposits();
        userInvestment.PrintReportWithMonthlyDeposits();

        // Check if user wants to test another set of inputs
        cout << "\nWould you like to test different investment values? (y/n): ";
        cin >> userChoice;
        cout << endl;
    }

    cout << "Thank you for using the Airgead Banking Investment Calculator!" << endl;
    return 0;
}

/**
 * Prompts user for inputs with robust input validation to prevent invalid entries.
 */
void DisplayInputScreen(double& t_initialInvestment, double& t_monthlyDeposit,
    double& t_annualInterest, int& t_numberOfYears) {
    cout << "**********************************" << endl;
    cout << "********** Data Input ************" << endl;

    // Validate Initial Investment
    cout << "Initial Investment Amount: $";
    while (!(cin >> t_initialInvestment) || t_initialInvestment <= 0) {
        cout << "Invalid input. Please enter a positive dollar amount: $";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    // Validate Monthly Deposit
    cout << "Monthly Deposit: $";
    while (!(cin >> t_monthlyDeposit) || t_monthlyDeposit < 0) {
        cout << "Invalid input. Please enter a non-negative dollar amount: $";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    // Validate Annual Interest
    cout << "Annual Interest (%): %";
    while (!(cin >> t_annualInterest) || t_annualInterest <= 0) {
        cout << "Invalid input. Please enter a positive interest percentage rate: %";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    // Validate Number of Years
    cout << "Number of years: ";
    while (!(cin >> t_numberOfYears) || t_numberOfYears <= 0) {
        cout << "Invalid input. Please enter a positive integer for years: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Press Enter to continue . . .";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get(); // Wait for user keypress
}