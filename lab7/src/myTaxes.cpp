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
#include <cstdlib>   // For exit()
#include <fstream>  // For ifstream, ofstream
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
