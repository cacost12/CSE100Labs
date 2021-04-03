//******************************************************************************
// FILE: main.cpp
//
// DESCRIPTION
// Opens a file named "payroll.txt" for reading and reads payroll information
// for one employee. Calculates the employee's paycheck information. Outputs the
// employee paycheck data to a file named "paycheck.txt".
//
// LEARNING OBJECTIVES
// After completing this lab project, the student will be able to:
//
// 1. Write function definitions, call functions, pass parameters, define local
//    variables, return a value from a function.
// 2. Open a text file for reading/writing and read/write from/to the text file.
// 3. Write if, if-else, and if-elseif-... (if/else if) statements.
// 4. Document formal test cases and perform testing to verify program correct-
//    ness.
//
// Note: Be sure to include both AUTHOR lines if you work with a partner. If you
// work alone, then delete the AUTHOR2 line. Be sure to include your ASURITE ID
// in the zip archive filename and if you work with a partner, be sure to in-
// clude both of your ASURITE ID's.
//
// AUTHOR1: Colton Acosta, cacost12, 1214326892, cacost12@asu.edu 
//
// COURSE INFO
// CSE100 Principles of Programming with C++, Fall 2020
// Lab Project 7   Day/Time: Th 9:00-9:50 AM TA: Neha Rajendra Vadnere 
//****************************************************************************

// Modules
#include <cstlib>   // For exit()
#include <ofstream>  // For ifstream, ofstream
#include <iomanip>   // For setprecision(), setw()
#include <iostream>   // For endl, fixed
#include <string>   // For string class

using namespace std;

//==============================================================================
// FUNCTION PROTOTYPES
//
// Students: Some of the functions may require prototypes. For those that do,
// write the prototype in this section.
//==============================================================================
0 or more ???

//------------------------------------------------------------------------------
// FUNCTION: calc_gross_pay()
//
// Calculates and returns an employee's gross pay which is based on the number
// of hours worked (in parameter hrs_worked) and the employee's pay rate (in
// parameter pay_rate).
//------------------------------------------------------------------------------
??? Implement the pseudocode from the lab project document

//------------------------------------------------------------------------------
// FUNCTION: calc_med_ins_deduct()
//
// Determines and returns the employee's medical insurance deduction which is
// based on the employee's medical insurance status in parameter med_ins_status.
//------------------------------------------------------------------------------
??? Implement the pseudocode from the lab project document

//------------------------------------------------------------------------------
// FUNCTION: calc_tax_fed()
//
// Calculates and returns the employee's federal income tax which is based on
// his or her federal taxable gross pay (in parameter fed_tax_gross_pay) and the
// federal tax withholding percentage table in the lab project document.
//------------------------------------------------------------------------------
??? Implement the pseudocode from the lab project document.

//------------------------------------------------------------------------------
// FUNCTION: calc_tax_state()
//
// Calculates and returns the employee's state income tax which is based on his
// or her federal taxable gross pay (in parameter fed_tax_gross_pay) and the
// state tax withholding percentage table in the lab project document.
//------------------------------------------------------------------------------
double calc_tax_state(double fed_tax_gross_pay)
{
    double tax_state = 0;
    if (fed_tax_gross_pay < 961.54) {
        tax_state = fed_tax_gross_pay * 0.0119;
    } else if (fed_tax_gross_pay < 2145.66) {
        tax_state = fed_tax_gross_pay * 0.0344;
    } else {
        tax_state = fed_tax_gross_pay * 0.0774;
    }
    return tax_state;
}

//------------------------------------------------------------------------------
// open_input_file(ifstream&, string) -> nothing
//
// See the comments in the function header of this function in main.cpp of Lab
// Project 6 for more information on how this function operates. Copy-and-paste
// the code for this function from your Lab 6 main.cpp source code file.
//------------------------------------------------------------------------------
???

//------------------------------------------------------------------------------
// open_output_file(ofstream&, string) -> nothing
//
// See the comments in the function header of this function in main.cpp of Lab
// Project 6 for more information on how this function operates. Copy-and-paste
// the code for this function from your Lab 6 main.cpp source code file.
//------------------------------------------------------------------------------
???

//------------------------------------------------------------------------------
// terminate(string, int) -> nothing
//
// See the comments in the function header of this function in main.cpp of Lab
// Project 6 for more information on how this function operates. Copy-and-paste
// the code for this function from your Lab 6 main.cpp source code file.
//------------------------------------------------------------------------------
???

//------------------------------------------------------------------------------
// FUNCTION: main()
//
// This is the starting point of execution.
//------------------------------------------------------------------------------
int main()
{
    // Define an ifstream object named 'fin' to read from the input file. Then
    // call open_input_file() passing "payroll.txt" as the name of the file to
    // be opened. If the file could not be opened for reading, then open_input
    // _file() will not return.
    ???

    // Read the employee's last and first names from the input file.
    string first_name, last_name;
    ???
    ???

    // Read the employee's pay rate from the input file.
    double pay_rate;
    ???

    // Read the employee's hours worked from the input file.
    double hrs_worked;
    ???

    // Read the employee's medical insurance status from the input file.
    int med_ins_status;
    ???

    // Close the input file because we're done reading from it.
    ???

    // Call calc_gross_pay() to calculate the employee's gross pay. The input
    // params are pay_rate and hrs_worked. The return value is assigned to vari-
    // able gross_pay which is defined as a double.
    double gross_pay = calc_gross_pay(pay_rate, hrs_worked);

    // Calculate the employee's mandatory contribution to his/her 401k. This is
    // gross_pay multiplied by the 401K rate.
    double four01k_deduct = ???;

    // Call calc_med_ins_deduct() to determine the employee's medical insurance
    // deduction which is based on the employee's medical insurance status
    // stored in med_ins_status. The return value is assigned to variable
    // med_ins_deduct which is defined as a double.
    ???

    // Calculate the employee's federal taxable gross pay which is gross_pay
    // minus deductions for medical insurance and 401K.
    double fed_tax_gross_pay = ???;

    // Call calc_tax_fed() to calculate the employee's federal income tax. The
    // input parameter is fed_tax_gross_pay and the returned value is assigned
    // to variable tax_fed which is defined as a double.
    ???

    // Calculate the amount withheld for OASDI and store in tax_oasdi.
    ???

    // Calculate the amount withheld for medicare and store in tax_medicare.
    ???

    // Call calc_tax_state() to determine the employee's state tax deduction.
    // The input parameter is fed_tax_gross_pay and the returned value is
    // assigned to variable tax_state which is defined as a double.
    ???

    // Calculate the employee's total tax which is the sum of his/her federal
    // tax, OASDI tax, medicare tax, and state tax. Assign to tax_total.
    ???

    // Calculate the employee's net pay which is federal taxable gross pay with
    // taxes deducted. Assign to net_pay.
    ???

    // Define an ofstream object named fout to write to the output file. Then
    // call open_output_file() passing fout and "paycheck.txt" as the name of
    // the file to be opened. If the file could not be opened for writing, then
    // open_output_file() will not return.
    ofstream fout;
    open_output_file(fout, "paycheck.txt");

    // Configure fout so real numbers will be printed in fixed notation with two
    // digits after the decimal point.
    fout << fixed << setprecision(2);

    // Configure fout so the numbers will be printed right-justified in their
    // respective fields.
    fout << right;

    // Output the employee paycheck. All numerical values are output in a field
    // of width 8.
    fout << "-----------------------------"    << endl;
    fout << "EMPLOYEE: " << last_name << ", "  << first_name << endl << endl;
    fout << "PAY RATE:           $" << setw(8) << pay_rate << endl;
    fout << "HOURS:               " << setw(8) << hrs_worked << endl;
    fout << "GROSS PAY:          $" << setw(8) << gross_pay << endl;
    fout << "MED INS DEDUCT:     $" << setw(8) << med_ins_deduct << endl;
    fout << "401K DEDUCT:        $" << setw(8) << four01k_deduct << endl;
    fout << "FED TAX GROSS PAY:  $" << setw(8) << fed_tax_gross_pay << endl;
    fout << "TAX - FEDERAL:      $" << setw(8) << tax_fed << endl;
    fout << "TAX - OASDI:        $" << setw(8) << tax_oasdi << endl;
    fout << "TAX - MEDICARE:     $" << setw(8) << tax_medicare << endl;
    fout << "TAX - STATE:        $" << setw(8) << tax_state << endl;
    fout << "TAX - TOTAL:        $" << setw(8) << tax_total << endl;
    fout << "NET PAY:            $" << setw(8) << net_pay << endl;
    fout << "-----------------------------"    << endl;

    // Close the output file.
    ???

    // Return 0 from main() to indicate to the OS that the program terminated
    // normally.
    ???
}
