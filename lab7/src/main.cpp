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
// AUTHOR1: your-name, your-asurite-username, your-email-address
// AUTHOR2: your-name, your-asurite-username, your-email-address
//
// COURSE INFO
// CSE100 Principles of Programming with C++, Spring 2021
// Lab Project 7   Day/Time: your-lab-date-and-time   TA: your-lab-ta's-name
// =============================================================================
//                                    TESTING
//------------------------------------------------------------------------------
// TEST CASE 1
//
// DESCRIPTION
// Performs an acceptance test of the entire program.
//
// INPUT DATA (Note that the input data is read from a file named payroll.txt)
// Simpson Homer
// 15.25 84
// 2
//
// EXPECTED OUTPUT
// -----------------------------
// EMPLOYEE: Simpson, Homer
//
// PAY RATE:           $   15.25
// HOURS:                  84.00
// GROSS PAY:          $ 1311.50
// MED INS DEDUCT:     $  110.13
// 401K DEDUCT:        $   78.69
// FED TAX GROSS PAY:  $ 1122.68
// TAX - FEDERAL:      $   89.48
// TAX - OASDI:        $   69.61
// TAX - MEDICARE:     $   16.28
// TAX - STATE:        $   38.62
// TAX - TOTAL:        $  213.98
// NET PAY:            $  908.70
// -----------------------------
//
// ACTUAL OUTPUT
// Run the program and copy-and-paste the contents of paycheck.txt here. If the
// actual output exactly matches the expected output, then the test case passes,
// so write PASS for the RESULT. Otherwise, if there are any mismatches, even if
// it is only one character or even just a space, then the test case fails, so
// write FAILS for the RESULT. Of course, try to determine why the test case
// failed and correct the mistakes if you can.
//
// RESULT: Write PASS or FAIL here
//------------------------------------------------------------------------------
// TEST CASE 2
//
// DESCRIPTION
// Performs an acceptance test of the entire program.
//
// INPUT DATA (Note that the input data is read from a file named payroll.txt)
// make-up-a-name
// make-up-an-hourly-pay-rate make-up-hours-worked
// make-up-an-med-insurance-code
//
// EXPECTED OUTPUT
// -----------------------------
// EMPLOYEE: ???
//
// PAY RATE:           $ ???
// HOURS:                ???
// GROSS PAY:          $ ???
// MED INS DEDUCT:     $ ???
// 401K DEDUCT:        $ ???
// FED TAX GROSS PAY:  $ ???
// TAX - FEDERAL:      $ ???
// TAX - OASDI:        $ ???
// TAX - MEDICARE:     $ ???
// TAX - STATE:        $ ???
// TAX - TOTAL:        $ ???
// NET PAY:            $ ???
// -----------------------------
//
// ACTUAL OUTPUT
// Run the program and copy-and-paste the contents of paycheck.txt here. If the
// actual output exactly matches the expected output, then the test case passes,
// so write PASS for the RESULT. Otherwise, if there are any mismatches, even if
// it is only one character or even just a space, then the test case fails, so
// write FAILS for the RESULT. Of course, try to determine why the test case
// failed and correct the mistakes if you can.
//
// RESULT: Write PASS or FAIL here
//------------------------------------------------------------------------------
// TEST CASE 3
// Document Test Case 3 in the same manner as Test Cases 1 and 2
//==============================================================================
???   // For exit()
???   // For ifstream, ofstream
???   // For setprecision(), setw()
???   // For endl, fixed
???   // For string class

using namespace std;

//==============================================================================
// FUNCTION PROTOTYPES
//
// Students: Some of the functions may require prototypes. For those that do,
// write the prototype in this section.
//==============================================================================
0 or more ???

//==============================================================================
// NAMED CONSTANTS
//
// Students: Define named constants in this section.
//==============================================================================

// Define an int named constant ERR_OPEN_INPUT_FILE which is equivalent to 1.
???

// Define an int named constant ERR_OPEN_OUTPUT_FILE which is equivalent to 2.
???

// This is the percentage rate for calculating the OASDI deduction (this is com-
// monly known as social security). It is 6.2% of the employee's federal taxable
// gross pay.
const double OASDI_RATE = 0.062;

// All employees are required to contribute 6.0% of their pretax gross pay to
// the company 401K plan.
const double FOUR01K_RATE = 0.06;

// Define a double constant named MEDICARE_RATE initialized to 0.0145.
// This is the percentage rate for calculating the medicare deduction. It is
// 1.45% of the employee's federal taxable gross pay.
// ???
const double MEDICARE_RATE = 0.0145;

// These constants are the monthly costs for each of the medical insurance
// plans. The amount an employee pays depends on his or her medical insurance
// status (see the group of constants following this group).
const double MED_INS_DEDUCT_EMPL_ONLY =  32.16;  // Employee Only
const double MED_INS_DEDUCT_EMPL_ONE  =  64.97;  // Employee + One
const double MED_INS_DEDUCT_FAMILY    = 110.13;  // Family

// These constants match the numbers for the employee's medical insurance status
// that will be in the input file.
const int MED_INS_STATUS_EMPL_ONLY = ???;  // Employee Only
const int MED_INS_STATUS_EMPL_ONE  = ???;  // Employee + One
const int MED_INS_STATUS_FAMILY    = ???;  // Family

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
