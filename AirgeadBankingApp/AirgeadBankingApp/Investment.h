#ifndef INVESTMENT_H
#define INVESTMENT_H

/**
 * @class Investment
 * @brief Manages investment parameters and calculates compound interest reports.
 */
class Investment {
private:
    double m_initialInvestment;
    double m_monthlyDeposit;
    double m_annualInterest;
    int m_numberOfYears;

public:
    // Default constructor
    Investment();

    // Parameterized constructor
    Investment(double t_initialInvestment, double t_monthlyDeposit,
        double t_annualInterest, int t_numberOfYears);

    // Mutators (Setters)
    void SetInitialInvestment(double t_initialInvestment);
    void SetMonthlyDeposit(double t_monthlyDeposit);
    void SetAnnualInterest(double t_annualInterest);
    void SetNumberOfYears(int t_numberOfYears);

    // Accessors (Getters)
    double GetInitialInvestment() const;
    double GetMonthlyDeposit() const;
    double GetAnnualInterest() const;
    int GetNumberOfYears() const;

    // Display functions for generating required reports
    void PrintReportWithoutMonthlyDeposits() const;
    void PrintReportWithMonthlyDeposits() const;
};

#endif // INVESTMENT_H