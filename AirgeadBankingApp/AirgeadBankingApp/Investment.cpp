#include "Investment.h"
#include <iostream>
#include <iomanip>

using namespace std;

// Default constructor initializing fields to standard defaults
Investment::Investment()
    : m_initialInvestment(0.0), m_monthlyDeposit(0.0), m_annualInterest(0.0), m_numberOfYears(0) {}

// Parameterized constructor initializing fields with user inputs
Investment::Investment(double t_initialInvestment, double t_monthlyDeposit,
    double t_annualInterest, int t_numberOfYears)
    : m_initialInvestment(t_initialInvestment), m_monthlyDeposit(t_monthlyDeposit),
    m_annualInterest(t_annualInterest), m_numberOfYears(t_numberOfYears) {}

// Setters
void Investment::SetInitialInvestment(double t_initialInvestment) { m_initialInvestment = t_initialInvestment; }
void Investment::SetMonthlyDeposit(double t_monthlyDeposit) { m_monthlyDeposit = t_monthlyDeposit; }
void Investment::SetAnnualInterest(double t_annualInterest) { m_annualInterest = t_annualInterest; }
void Investment::SetNumberOfYears(int t_numberOfYears) { m_numberOfYears = t_numberOfYears; }

// Getters
double Investment::GetInitialInvestment() const { return m_initialInvestment; }
double Investment::GetMonthlyDeposit() const { return m_monthlyDeposit; }
double Investment::GetAnnualInterest() const { return m_annualInterest; }
int Investment::GetNumberOfYears() const { return m_numberOfYears; }

/**
 * Calculates and prints year-end balances and earned interest
 * assuming NO additional monthly deposits are made.
 */
void Investment::PrintReportWithoutMonthlyDeposits() const {
    cout << "\n===================================================================\n";
    cout << "  Balance and Interest Without Additional Monthly Deposits\n";
    cout << "===================================================================\n";
    cout << setw(10) << "Year" << setw(25) << "Year End Balance" << setw(30) << "Year End Earned Interest\n";
    cout << "-------------------------------------------------------------------\n";

    double currentBalance = m_initialInvestment;

    for (int year = 1; year <= m_numberOfYears; ++year) {
        double yearEndInterest = 0.0;

        for (int month = 1; month <= 12; ++month) {
            // Formula: Interest = Opening Amount * ((Interest Rate / 100) / 12)
            double monthlyInterest = currentBalance * ((m_annualInterest / 100.0) / 12.0);
            yearEndInterest += monthlyInterest;
            currentBalance += monthlyInterest;
        }

        cout << setw(10) << year
            << setw(24) << fixed << setprecision(2) << "$" << currentBalance
            << setw(29) << "$" << yearEndInterest << "\n";
    }
}

/**
 * Calculates and prints year-end balances and earned interest
 * WITH regular monthly deposits included.
 */
void Investment::PrintReportWithMonthlyDeposits() const {
    cout << "\n===================================================================\n";
    cout << "   Balance and Interest With Additional Monthly Deposits\n";
    cout << "===================================================================\n";
    cout << setw(10) << "Year" << setw(25) << "Year End Balance" << setw(30) << "Year End Earned Interest\n";
    cout << "-------------------------------------------------------------------\n";

    double currentBalance = m_initialInvestment;

    for (int year = 1; year <= m_numberOfYears; ++year) {
        double yearEndInterest = 0.0;

        for (int month = 1; month <= 12; ++month) {
            // Formula: Total = Opening Amount + Deposited Amount
            double total = currentBalance + m_monthlyDeposit;

            // Formula: Monthly Interest = Total * ((Interest Rate / 100) / 12)
            double monthlyInterest = total * ((m_annualInterest / 100.0) / 12.0);

            yearEndInterest += monthlyInterest;

            // Formula: Closing Balance = Total + Monthly Interest
            currentBalance = total + monthlyInterest;
        }

        cout << setw(10) << year
            << setw(24) << fixed << setprecision(2) << "$" << currentBalance
            << setw(29) << "$" << yearEndInterest << "\n";
    }
}