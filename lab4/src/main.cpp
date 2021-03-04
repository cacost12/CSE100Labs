//******************************************************************************
// FILE: main.cpp
//
// DESCRIPTION
// Reads the coefficients of quadratic equations from "coeffs.txt". Calculates
// the roots of each equation and outputs the results to "roots.txt".
//
// AUTHOR1: Colton Acosta, cacost12, 1214326892, cacost12@asu.edu 
//
// COURSE INFO
// CSE100 Principles of Programming with C++, Fall 2020
// Lab Project 4   Day/Time: Th 9:00-9:50 AM TA: Neha Rajendra Vadnere 
//==============================================================================
//                                  TESTING
//
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// TEST CASE 1 (This test case was given to the students)
// Description:  Tests that the two real roots of 2.5x^2 + 7.6x - 3 = 0 are
// calculated correctly.
//
// Input Data:
// a = 2.5, b = 7.6, c = -3
//
// Expected Output:
// -----------------------------------------------------------------------------
// The equation 2.50000x^2 + 7.60000x + -3.00000 = 0 has roots 0.35361 and
// -3.39361.
//
// Actual Output:
// -----------------------------------------------------------------------------
// copy-and-paste the contents of roots.txt here
//
// Test Case Result: Write PASSED or FAILED
//
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// TEST CASE 2:
// Description: Tests that the two real roots of x^2 -x -2.6 are calculated correctly 
//
// Input Data:
// a = 1, b = -1, c = -2.6
//
// Expected Output:
// -----------------------------------------------------------------------------
// The equation 1.00000x^2 + -1.00000x + -2.60000 = 0 has roots 2.18819 and
// -1.18819.
// document the expected output
//
// Actual Output:
// -----------------------------------------------------------------------------
// copy-and-paste the contents of roots.txt here
//
// Test Case Result: Write PASSED or FAILED
//
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// TEST CASE 3:
// Description: Tests that the two real roots of -4.3x^2 +1.5x +12.3 are calculated correctly 
//
// Input Data:
// a = -4.3, b = 1.5, c = 12.3
//
// Expected Output:
// -----------------------------------------------------------------------------
// The equation -4.30000x^2 + 1.50000x + 12.30000 = 0 has roots 1.87468 and
// -1.52584.
//
// Actual Output:
// -----------------------------------------------------------------------------
// copy-and-paste the contents of roots.txt here
//
// Test Case Result: Write PASSED or FAILED
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// TEST CASE 4:
// Description: Tests that the two real roots of -2x^2 +2.7x +5.4 are calculated correctly 
//
// Input Data:
// a = -2, b = 2.7, c = 5.4
//
// Expected Output:
// -----------------------------------------------------------------------------
// The equation -2.00000x^2 + 2.70000x + 5.40000 = 0 has roots 2.45141 and
// -1.10141.
//
// Actual Output:
// -----------------------------------------------------------------------------
// copy-and-paste the contents of roots.txt here
//
// Test Case Result: Write PASSED or FAILED
//******************************************************************************
#include <cmath> // For sqrt()
#include <fstream>         // For ifstream and ofstream classes
#include <iomanip>         // For setprecision()
#include <iostream>         // For fixed and endl

using namespace std;

//------------------------------------------------------------------------------
// read_coeff()
//
// Students:This function is called from main() three times. The file input stream object named fin in main() is passed as the argument
// (it must be passed by-reference, so make sure to put the & symbol following the data type of the parameter). It reads the next coefficient
// from the file and returns it. Note that this function does not close the file; it is closed in main() after this function has been called the
// third time to return the c coefficient.

// 
//------------------------------------------------------------------------------
double read_coeff(ifstream& fileObject){

    // Read coefficient into double variable
    double c; 
    fileObject>>c;
    return(c);
}

//------------------------------------------------------------------------------
// discriminant()
//
// Students:Given the coefficients a, b, and c of the quadratic equation, this function calculates the value of the discriminant
// and returns the value. This function is called from calc_root1() and calc_root2().
//------------------------------------------------------------------------------
double discriminant(double a, double b, double c){

	// Calculate b^2 -4ac and return result from function
	return(pow(b,2) - 4*a*c);
}

//------------------------------------------------------------------------------
// calc_root1()
//
// Students: Write comments which explain what this function does. You can copy
// the comments from the pseudocode in the Software Design.
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// calc_root2()
//
// Students: Write comments which explain what this function does. You can copy
// the comments from the pseudocode in the Software Design.
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// output()
//
// Students: Write comments which explain what this function does. You can copy
// the comments from the pseudocode in the Software Design.
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// main()
//
// Students: Write comments which explain what this function does. You can copy
// the comments from the pseudocode in the Software Design.
//------------------------------------------------------------------------------
int main(void){

    // Instantiate file object to read quadratic coefficients 
    ifstream coeffFile;

    // Open Coeffs.txt file 
    coeffFile.open("coeffs.txt");

    // Instaniate coefficient variables 
    double coeffs[3];

    // Read Coefficients
    for(int i=0; i<3; ++i){
        coeffs[i] = read_coeff(coeffFile); 
    } 
   
    // Calculate discriminant from quadratic coefficients
    double disc = discriminant(coeffs[0], coeffs[1], coeffs[2]);

    cout<< "Discriminant: "<<disc<<endl;

    // Print Coefficients to console 
    //cout<<"a = "<<coeffs[0]<<", b = "<<coeffs[1]<<", c = "<<coeffs[2]<<endl;





    return(0);
}
