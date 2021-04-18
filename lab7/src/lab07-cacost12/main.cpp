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
// -----------------------------
// EMPLOYEE: Homer, Simpson
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
// RESULT: PASS 
//------------------------------------------------------------------------------
// TEST CASE 2
//
// DESCRIPTION
// Performs an acceptance test of the entire program.
//
// INPUT DATA (Note that the input data is read from a file named payroll.txt)
// Acosta Colton 
// 20.5 80
// 0
//
// EXPECTED OUTPUT
// -----------------------------
// EMPLOYEE: Acosta, Colton
//
// PAY RATE:           $   20.50
// HOURS:                  80.00
// GROSS PAY:          $ 1640.00
// MED INS DEDUCT:     $   32.16
// 401K DEDUCT:        $   98.40
// FED TAX GROSS PAY:  $ 1509.44
// TAX - FEDERAL:      $  192.45
// TAX - OASDI:        $   93.59
// TAX - MEDICARE:     $   21.89
// TAX - STATE:        $   51.92
// TAX - TOTAL:        $  359.85
// NET PAY:            $ 1149.59
// -----------------------------
//
// ACTUAL OUTPUT
// -----------------------------
// EMPLOYEE: Colton, Acosta
//
// PAY RATE:           $   20.50
// HOURS:                  80.00
// GROSS PAY:          $ 1640.00
// MED INS DEDUCT:     $   32.16
// 401K DEDUCT:        $   98.40
// FED TAX GROSS PAY:  $ 1509.44
// TAX - FEDERAL:      $  192.45
// TAX - OASDI:        $   93.59
// TAX - MEDICARE:     $   21.89
// TAX - STATE:        $   51.92
// TAX - TOTAL:        $  359.85
// NET PAY:            $ 1149.59
// -----------------------------
//
// RESULT: Write PASS
//------------------------------------------------------------------------------
// TEST CASE 3
//
// DESCRIPTION
// Performs an acceptance test of the entire program.
//
// INPUT DATA (Note that the input data is read from a file named payroll.txt)
// Markey Patrick 
// 70 57
// 1
//
// EXPECTED OUTPUT
// -----------------------------
// EMPLOYEE: Markey, Patrick
//
// PAY RATE:           $   70.00
// HOURS:                  57.00
// GROSS PAY:          $ 3990.00
// MED INS DEDUCT:     $   64.97
// 401K DEDUCT:        $  239.40
// FED TAX GROSS PAY:  $ 3685.63
// TAX - FEDERAL:      $  718.70
// TAX - OASDI:        $  228.51
// TAX - MEDICARE:     $   53.44
// TAX - STATE:        $  285.27
// TAX - TOTAL:        $ 1285.92
// NET PAY:            $ 2399.71
// -----------------------------
//
// ACTUAL OUTPUT
// -----------------------------
// EMPLOYEE: Patrick, Markey
//
// PAY RATE:           $   70.00
// HOURS:                  57.00
// GROSS PAY:          $ 3990.00
// MED INS DEDUCT:     $   64.97
// 401K DEDUCT:        $  239.40
// FED TAX GROSS PAY:  $ 3685.63
// TAX - FEDERAL:      $  718.70
// TAX - OASDI:        $  228.51
// TAX - MEDICARE:     $   53.44
// TAX - STATE:        $  285.27
// TAX - TOTAL:        $ 1285.92
// NET PAY:            $ 2399.71
// -----------------------------
//
// RESULT: Write PASS
//------------------------------------------------------------------------------
// TEST CASE 4
//
// DESCRIPTION
// Performs an acceptance test of the entire program.
//
// INPUT DATA (Note that the input data is read from a file named payroll.txt)
// Hansen James 
// 15.50 10
// 0
//
// EXPECTED OUTPUT
// -----------------------------
// EMPLOYEE: Hansen, James
//
// PAY RATE:           $   15.50
// HOURS:                  10.00
// GROSS PAY:          $  155.00
// MED INS DEDUCT:     $   32.16
// 401K DEDUCT:        $    9.30
// FED TAX GROSS PAY:  $  113.54
// TAX - FEDERAL:      $    0.00
// TAX - OASDI:        $    7.04
// TAX - MEDICARE:     $    1.65
// TAX - STATE:        $    1.35
// TAX - TOTAL:        $   10.04
// NET PAY:            $  103.50
// -----------------------------
//
// ACTUAL OUTPUT
// -----------------------------
// EMPLOYEE: James, Hansen
// 
// PAY RATE:           $   15.50
// HOURS:                  10.00
// GROSS PAY:          $  155.00
// MED INS DEDUCT:     $   32.16
// 401K DEDUCT:        $    9.30
// FED TAX GROSS PAY:  $  113.54
// TAX - FEDERAL:      $    0.00
// TAX - OASDI:        $    7.04
// TAX - MEDICARE:     $    1.65
// TAX - STATE:        $    1.35
// TAX - TOTAL:        $   10.04
// NET PAY:            $  103.50
// -----------------------------
//
// RESULT: PASS
//==============================================================================

// Modules
#include <cstdlib>   // For exit()
#include <fstream>  // For ifstream, ofstream
#include <iomanip>   // For setprecision(), setw()
#include <iostream>   // For endl, fixed
#include <string>   // For string class

using namespace std;

//==============================================================================
// NAMED CONSTANTS
//
// Students: Define named constants in this section.
//==============================================================================
// Define an int named constant ERR_OPEN_INPUT_FILE which is equivalent to 1.
const int ERR_OPEN_INPUT_FILE = 1;

// Define an int named constant ERR_OPEN_OUTPUT_FILE which is equivalent to 2.
const int ERR_OPEN_OUTPUT_FILE = 2;

// Define an int named constant ERR_GROSS_PAY which is equivalent to 3
const int ERR_GROSS_PAY = 3;

// Define an int named constant ERR_MED_INS which is equivalent to 4
const int ERR_MED_INS = 4;

// Define an int named constant ERR_FED_TAX  which is equivalent to 5
const int ERR_FED_TAX = 5;

// Define an int named constant ERR_STATE_TAX which is equivalent to 6
const int ERR_STATE_TAX = 6;

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
const double MEDICARE_RATE = 0.0145;
 
// These constants are the monthly costs for each of the medical insurance
// plans. The amount an employee pays depends on his or her medical insurance
// status (see the group of constants following this group).
const double MED_INS_DEDUCT_EMPL_ONLY    = 32.16;  // Family
const double MED_INS_DEDUCT_EMPL_ONE    = 64.97;  // Family
const double MED_INS_DEDUCT_FAMILY    = 110.13;  // Family
 
// These constants match the numbers for the employee's medical insurance status
// that will be in the input file.
const int MED_INS_STATUS_EMPL_ONLY = 0;  // Employee Only
const int MED_INS_STATUS_EMPL_ONE  = 1;  // Employee + One
const int MED_INS_STATUS_FAMILY    = 2;  // Family
//------------------------------------------------------------------------------


//==============================================================================
// FUNCTION PROTOTYPES
//
// Students: Some of the functions may require prototypes. For those that do,
// write the prototype in this section.
//==============================================================================

// FUNCTION:    calc_gross_pay()
// DESCRIPTION: Calculate an Employee's Gross Pay (Pay before tax or deductions)
// INPUTS:      payrate, hours worked
// OUTPUTS:     gross pay earned by employee
double calc_gross_pay(double pay_rate, double hrs_worked);

// FUNCTION     calc_med_ins_deduct()
// DESCRIPTION: Calculate Pay Deduction for Medical Insurance
// INPUTS:      medical insurance plan type, single, plus-one, or family
// OUTPUTS:     Biweekly medical insurance deduction
double calc_med_ins_deduct(int med_ins_status);

// FUNCTION:    calc_tax_fed()
// DESCRIPTION: Calculate Employee's Federal Income Tax 
// INPUTS:      Employee's Federal Tax Gross Pay, or Taxable Income
// OUTPUTS:     Amount owed in Federal Income Tax
double calc_tax_fed(double fed_tax_gross_pay);

// FUNCTION:    calc_tax_state()
// DESCRIPTION: Calculates Employee's State Tax
// INPUTS:      Employee's Taxable Income
// OUTPUTS:     Amount due in state taxes
double calc_tax_state(double fed_tax_gross_pay);

// FUNCTION:    open_input_file()
// DESCRIPTION: Opens file with given filename, terminates program if input
//              file fails to open
// INPUTS:      File input stream, filename
// OUTPUTS:     None
void open_input_file(ifstream& fin, string filename);

// FUNCTION:    open_output_file()
// DESCRIPTION: Opens file for writing output, terminates program if file fails
//              to open
// INPUTS:      output file stream object, filename
// OUTPUTS:     None
void open_output_file(ofstream& fout, string filename);

// FUNCTION:    terminate() 
// DESCRIPTION: Exits the program and returns an error message 
// INPUTS:      Exit code
// OUTPUTS:     Nothing
void terminate(string msg, int exit_code);

// FUNCTION:    calc_gross_pay()
// DESCRIPTION: Calculate an Employee's Gross Pay (Pay before tax or deductions)
// INPUTS:      payrate, hours worked
// OUTPUTS:     gross pay earned by employee
double calc_gross_pay(double pay_rate, double hrs_worked){

   double gross_pay;

   // Calculate gross pay, first checking whether or not the employee worked 
   // overtime
   if (hrs_worked <= 80){
      gross_pay = pay_rate*hrs_worked;
   } else if(hrs_worked > 80){
      gross_pay = 80*pay_rate + 1.5*(hrs_worked - 80)*pay_rate;
   } else{
      terminate("An error occured while calculating gross pay.", ERR_GROSS_PAY);
   }

   return(gross_pay);
}

// FUNCTION     calc_med_ins_deduct()
// DESCRIPTION: Calculate Pay Deduction for Medical Insurance
// INPUTS:      medical insurance plan type, single, plus-one, or family
// OUTPUTS:     Biweekly medical insurance deduction
double calc_med_ins_deduct(int med_ins_status){

   double med_ins_deduct;

   // Check the status of the medical insurance plan to output the correct 
   // deduction 
   if(med_ins_status == MED_INS_STATUS_EMPL_ONLY){
      med_ins_deduct = MED_INS_DEDUCT_EMPL_ONLY;
   } else if(med_ins_status == MED_INS_STATUS_EMPL_ONE){
      med_ins_deduct = MED_INS_DEDUCT_EMPL_ONE;
   } else if(med_ins_status == MED_INS_STATUS_FAMILY){
      med_ins_deduct = MED_INS_DEDUCT_FAMILY;
   } else {
      terminate("An error ocurred while calculating medical insurance deduction.", ERR_MED_INS);
   }

   return(med_ins_deduct);
}

// FUNCTION:    calc_tax_fed()
// DESCRIPTION: Calculate Employee's Federal Income Tax 
// INPUTS:      Employee's Federal Tax Gross Pay, or Taxable Income
// OUTPUTS:     Amount owed in Federal Income Tax
double calc_tax_fed(double fed_tax_gross_pay){

    double tax_fed;

    if (fed_tax_gross_pay < 384.62){
        tax_fed = 0;
    } else if (fed_tax_gross_pay >= 384.62 && fed_tax_gross_pay < 1413.67){
        tax_fed = fed_tax_gross_pay*0.0797;
    } else if (fed_tax_gross_pay >= 1413.67 && fed_tax_gross_pay < 2695.43){
        tax_fed = fed_tax_gross_pay*0.1275;
    } else if (fed_tax_gross_pay >= 2695.43){
        tax_fed = fed_tax_gross_pay*0.195;
    } else {
        terminate("An error occured while calculated federal income tax.", ERR_FED_TAX);
    }

    return(tax_fed);
}

// FUNCTION:    calc_tax_state()
// DESCRIPTION: Calculates Employee's State Tax
// INPUTS:      Employee's Taxable Income
// OUTPUTS:     Amount due in state taxes
double calc_tax_state(double fed_tax_gross_pay){

    double tax_state;

    // Determine Employee State tax bracket and return appropriate state tax
    if (fed_tax_gross_pay < 961.54){
        tax_state = fed_tax_gross_pay*0.0119;
    } else if (fed_tax_gross_pay >= 961.54 && fed_tax_gross_pay < 2145.66){
        tax_state = fed_tax_gross_pay*0.0344;
    } else if (fed_tax_gross_pay >= 2145.66){
        tax_state = fed_tax_gross_pay*0.0774;
    } else {
        terminate("An error occured while calculating the state income tax.", ERR_STATE_TAX);
    }

    return(tax_state);
}

// FUNCTION:    open_input_file()
// DESCRIPTION: Opens file with given filename, terminates program if input
//              file fails to open
// INPUTS:      File input stream, filename
// OUTPUTS:     None
void open_input_file(ifstream& fin, string filename) {
   fin.open(filename.c_str());
   if (!fin) {
      terminate("Could not open 'payroll.txt' for opening.", ERR_OPEN_INPUT_FILE);
   }
}

// FUNCTION:    open_output_file()
// DESCRIPTION: Opens file for writing output, terminates program if file fails
//              to open
// INPUTS:      output file stream object, filename
// OUTPUTS:     None
void open_output_file(ofstream& fout, string filename){
   fout.open(filename.c_str());
   if (!fout){
      terminate("Could not open 'paycheck.txt' for writing.", ERR_OPEN_OUTPUT_FILE);
   }
}

// FUNCTION:    terminate() 
// DESCRIPTION: Exits the program and returns an error message 
// INPUTS:      Exit code
// OUTPUTS:     Nothing
void terminate(string msg, int exit_code){
   cout << msg << endl;
   exit(exit_code);
}

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
    ifstream fin; 
    open_input_file(fin, "payroll.txt");

    // Read the employee's last and first names from the input file.
    string first_name, last_name;
    fin >> first_name;
    fin >> last_name;

    // Read the employee's pay rate from the input file.
    double pay_rate;
    fin >> pay_rate;

    // Read the employee's hours worked from the input file.
    double hrs_worked;
    fin >> hrs_worked;

    // Read the employee's medical insurance status from the input file.
    int med_ins_status;
    fin >> med_ins_status;

    // Close the input file because we're done reading from it.
    fin.close();

    // Call calc_gross_pay() to calculate the employee's gross pay. The input
    // params are pay_rate and hrs_worked. The return value is assigned to vari-
    // able gross_pay which is defined as a double.
    double gross_pay = calc_gross_pay(pay_rate, hrs_worked);

    // Calculate the employee's mandatory contribution to his/her 401k. This is
    // gross_pay multiplied by the 401K rate.
    double four01k_deduct = gross_pay*FOUR01K_RATE;

    // Call calc_med_ins_deduct() to determine the employee's medical insurance
    // deduction which is based on the employee's medical insurance status
    // stored in med_ins_status. The return value is assigned to variable
    // med_ins_deduct which is defined as a double.
    double med_ins_deduct = calc_med_ins_deduct(med_ins_status);

    // Calculate the employee's federal taxable gross pay which is gross_pay
    // minus deductions for medical insurance and 401K.
    double fed_tax_gross_pay = gross_pay - four01k_deduct - med_ins_deduct;

    // Call calc_tax_fed() to calculate the employee's federal income tax. The
    // input parameter is fed_tax_gross_pay and the returned value is assigned
    // to variable tax_fed which is defined as a double.
    double tax_fed = calc_tax_fed(fed_tax_gross_pay);

    // Calculate the amount withheld for OASDI and store in tax_oasdi.
    double tax_oasdi = fed_tax_gross_pay*OASDI_RATE;

    // Calculate the amount withheld for medicare and store in tax_medicare.
    double tax_medicare = fed_tax_gross_pay*MEDICARE_RATE;

    // Call calc_tax_state() to determine the employee's state tax deduction.
    // The input parameter is fed_tax_gross_pay and the returned value is
    // assigned to variable tax_state which is defined as a double.
    double tax_state = calc_tax_state(fed_tax_gross_pay);

    // Calculate the employee's total tax which is the sum of his/her federal
    // tax, OASDI tax, medicare tax, and state tax. Assign to tax_total.
    double tax_total = tax_fed + tax_oasdi + tax_medicare + tax_state;

    // Calculate the employee's net pay which is federal taxable gross pay with
    // taxes deducted. Assign to net_pay.
    double net_pay = fed_tax_gross_pay - tax_total;

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
    fout.close();

    // Return 0 from main() to indicate to the OS that the program terminated
    // normally.
    return(0);
}
