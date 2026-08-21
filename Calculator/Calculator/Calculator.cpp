/*
 * Calculator.cpp
 *
 * Date: July 12, 2026
 * Author: Anthoni Rahming
 * Purpose: A fully debugged interactive calculator application that processes basic
 * arithmetic expressions while properly supporting integers and doubles.
 */

#include <iostream>

using namespace std;

// FIXED: Changed main's return type from void to int because standard C++ expects an integer status code
int main()
{
    // FIXED: Changed types from int to double so the calculator can handle decimal values smoothly
    double op1, op2;
    char operation;

    // FIXED: Enclosed 'Y' in single quotes since it's a character literal, and added the missing semicolon
    char answer = 'Y';

    // FIXED: Updated the loop condition to check for both 'y' and 'Y' so it doesn't accidentally skip execution
    while (answer == 'y' || answer == 'Y')
    {
        cout << "Enter expression (example: 12.5 + 2): " << endl;

        // FIXED: Arranged inputs as op1 then op2 so order-dependent math like subtraction doesn't run backwards
        cin >> op1 >> operation >> op2;

        // FIXED: Dropped the accidental trailing semicolon that was cutting off the conditional block early
        if (operation == '+') {
            // FIXED: Corrected the stream redirection arrow direction from '>>' to '<<' before the equals sign
            cout << op1 << " + " << op2 << " = " << op1 + op2 << endl;
        }

        // FIXED: Removed the trailing semicolon so the output string actually honors the minus sign condition
        if (operation == '-') {
            // FIXED: Flipped the chevron error right after cout from '>>' to '<<'
            cout << op1 << " - " << op2 << " = " << op1 - op2 << endl;
        }

        // FIXED: Resolved the logic mix-up where the multiplication symbol printed a division sign and performed division
        if (operation == '*') {
            cout << op1 << " * " << op2 << " = " << op1 * op2 << endl;
        }

        // FIXED: Resolved the logic mix-up for division, and included a quick zero check to prevent system crashes
        if (operation == '/') {
            if (op2 != 0) {
                cout << op1 << " / " << op2 << " = " << op1 / op2 << endl;
            }
            else {
                cout << "Error: Division by zero is undefined." << endl;
            }
        }

        cout << "Do you wish to evaluate another expression? (Y/N): " << endl;
        cin >> answer;
    }

    // FIXED: Included the required "Program Finished." termination phrase right before exiting
    cout << "Program Finished." << endl;

    return 0; // Return success code
}