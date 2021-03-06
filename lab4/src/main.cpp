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
// Test Case Result: PASSED 
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
// The equation 1.00000x^2 + -1.00000x + -2.60000 = 0 has roots 2.18819 and -1.18819.
// Test Case Result: PASSED 
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
// The equation -4.30000x^2 + 1.50000x + 12.30000 = 0 has roots -1.52584 and 1.87468.
//
// Test Case Result: PASSED 
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
// The equation -2.00000x^2 + 2.70000x + 5.40000 = 0 has roots -1.10141 and 2.45141.
// copy-and-paste the contents of roots.txt here
//
// Test Case Result: PASSED 
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
// Students:Given the coefficients of the quadratic equation, this function uses the "-b + ..." root equation to calculate the first root. This function is called from main().
//------------------------------------------------------------------------------
double calc_root1(double a, double b, double c){
    return((-b + sqrt(discriminant(a,b,c)))/(2*a));
}

//------------------------------------------------------------------------------
// calc_root2()
//
// Students: Given the coefficients of the quadratic equation, this function uses the "-b - ..." root equation to calculate the second root. This function is called from main().
//------------------------------------------------------------------------------
double calc_root2(double a, double b, double c){
    return((-b - sqrt(discriminant(a,b,c)))/(2*a));
}

//------------------------------------------------------------------------------
// output()
//
// Students:  The input parameters are the three coefficients a, b, and c, and the two roots root1 and root2 . See the Software Requirements for a discussion of the format of the output file. This function is called from main().
//------------------------------------------------------------------------------
void output(double a, double b, double c, double root1, double root2){

    // Define output file object
    ofstream outputFile;

    // Open File for writing 
    outputFile.open("roots.txt");

    // Configure presision of file stream 
    outputFile << fixed << setprecision(5);

    // Write the data to roots.txt 
    outputFile << "The equation " << a << "x^2 + "<<b<<"x + "<<c<<" = 0 has roots "<<root1<<" and "<<root2<<"."<<endl ;

    // Close the file 
    outputFile.close();
}

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
  
    // Close File 
    coeffFile.close();

    // Instaniate variable for roots 
    double roots[2];

    // Calculate roots 
    roots[0] = calc_root1(coeffs[0], coeffs[1], coeffs[2]);
    roots[1] = calc_root2(coeffs[0], coeffs[1], coeffs[2]);

    // Write Roots to roots.txt file 
    output(coeffs[0], coeffs[1], coeffs[2], roots[0], roots[1]);

    return(0);
}
