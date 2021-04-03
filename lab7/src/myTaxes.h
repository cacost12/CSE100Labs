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
