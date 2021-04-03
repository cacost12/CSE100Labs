//*****************************************************************************
// FILE: myTaxes.cpp 
// 
// DESCRIPTION
// Contains all functions definitions for lab07
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

// Include Header file to get named constants and function prototypes
#include "myTaxes.h"

using namespace std;

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
void terminate(string, msg, int exit_code){
   cout << msg << endl;
   exit(exit_code);
}
