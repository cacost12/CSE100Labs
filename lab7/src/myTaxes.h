//*****************************************************************************
// FILE: myTaxes.h 
// 
// DESCRIPTION
// Contains all the macro definitions and function prototypes for the myTaxes.cpp C++ source code file.
// 
// AUTHOR: Colton Acosta, cacost12, 1214326892, cacost12@asu.edu
// 
// DATE: April 3, 2021
//*****************************************************************************

// Include Guards
#ifndef MYTAXES_H
#define MYCLASS_H

// External Libraries
#include <cstlib>   // For exit()
#include <ofstream>  // For ifstream, ofstream
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
void terminate(string, msg, int exit_code);

#endif // MYTAXES_H
