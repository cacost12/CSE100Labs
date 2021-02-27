//******************************************************************************
// FILE: main.cpp 
//
// DESCRIPTION
// This program will ask the user to enter some personal information and will
// then use Zelda's lucky number formula to determine the user's lucky number.
//
// After completing this lab project, the student should be able to:
// 1. Define and use local variables of the int, double, and string data types.
// 2. Use cout to display string literals and variables.
// 3. Use cin to read values from the keyboard into variables.
// 4. Use the arithmetic operators.
// 5. Call math functions from the C++ Standard Library.
// 6. Write a function definition, call functions, pass arguments, and return
//    values.
// 7. Define and use named constants.
//
// AUTHOR1: Colton Acosta, 1214326892, cacost12@asu.edu 
//
// COURSE INFO
// CSE100 Principles of Programming with C++, Fall 2020
// Lab Project 3   Day/Time: Thursday, 9:00-9:50 AM TA: Neha Rajendra Vadnere

//==============================================================================
//                                TESTING RESULTS
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// TEST CASE 1
// Description: Tests that the program computes and displays the correct lucky
// number.
//
// Input Data:
//     Customer name    = Wilma
//     Birthdate month  = 3
//     Birthdate day    = 13
//     Birthdate year   = 1970
//     Height in inches = 80
//     Weight in lbs    = 120
//
// Expected Output:
// -----------------------------------------------------------------------------
// "Wilma, your lucky number is 5. Thank you, that will be $25."
// 
// Actual Output:
// -----------------------------------------------------------------------------
// After performing the test case, copy and paste the actual output from your
// program to here
// 
// Test Case Result: Write PASSED or FAILED
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// TEST CASE 2
// Document your second test case here, using the same format as Test Case 1.
//
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// TEST CASE 3
// Document your second test case here, using the same format as Test Case 1.
//******************************************************************************

// Include the three required header files.
#include <cmath>
#include <iostream>
#include <string>

// What goes here so that we can refer to std::cout as simply cout and 
// std::endl as simply endl.
using namespace std;

// Define a named constant CM_PER_INCH which is a double and is equivalent to
// 2.54. Read about named constants in Chapter 3 section 3.5 of your textbook.
const double CM_PER_INCH = 2.54;

// Define a named constant LB_PER_KG which is a double and is equivalent to
// 2.20462262.
const double LB_PER_KG = 2.20462262;

//------------------------------------------------------------------------------
// FUNCTION: calc_lucky()
//
// DESCRIPTION
// Calculates the customers's lucky number using Zelda's way cool formula.
//------------------------------------------------------------------------------
int calc_lucky(int date, int month, int year, double height, double weight)
{
    // Define an int variable named 'term1' and assign to term1 the result of
    // evaluating:    100 x month^2

    int term1 = static_cast<int>(100*pow(static_cast<double>(month),2));

    // Define an int variable named 'term2' and assign to it:  10 x date^3 

    int term2 = static_cast<int>(10*pow(static_cast<double>(date), 3));

    // Define an int variable named 'term3' and assign to it: (term1 + term2) / year

    int term3 = (term1 + term2)/year;

    // Note: the division of term1 + term2 by year is to be performed as int
    // division, meaning a static_cast<> is not required in this case.
    

    // Define a double variable named 'term4' and assign to it:  weight^6 / height
    //
    double term4 = pow(weight,6)/height;

    // Calculate and return the lucky number using term3, term4, and the lucky
    // number formula. Note: you need to typecast term3 + sqrt(term) to an int
    // before performing the modulus by 10 operation (recall that the % modulus
    // operator is not defined to operate on floating-point data values).
    return ((static_cast<int>(term3 + sqrt(term4)))%10 + 1);
}

//------------------------------------------------------------------------------
// FUNCTION: convert_inch_to_cm()
//
// DESCRIPTION
// Converts inches to centimeters.
//------------------------------------------------------------------------------
double convert_inch_to_cm(double p_inches)
{
    return p_inches * CM_PER_INCH;
}

//------------------------------------------------------------------------------
// FUNCTION: convert_lb_to_kg()
//
// DESCRIPTION
// Converts pounds to kilograms.
//
// REMARK
// Make sure to use the named constant LB_TO_KG in your conversion expression.
//------------------------------------------------------------------------------
double convert_lb_to_kg(double p_lb)
{
    return p_lb*LB_PER_KG;
}
    
//------------------------------------------------------------------------------
// FUNCTION: get_int()
//
// DESCRIPTION
// Display the prompt string prompt, read an int from the keyboard, and return
// the int.
//------------------------------------------------------------------------------
int get_int(string prompt)
{
    cout << prompt;
    int n; cin >> n;
    return n;
}

//------------------------------------------------------------------------------
// FUNCTION: get_string()
//
// DESCRIPTION
// Display the prompt string prompt, read a string from the keyboard, and
// return the string.
//------------------------------------------------------------------------------
string get_string(string prompt)
{
    cout << prompt;
    string s; cin >> s;
    return s;
}

//------------------------------------------------------------------------------
// FUNCTION: main()
//
// DESCRIPTION:
// main() is where the program starts executing. We shall read the customer's
// personal information, calculate his or her lucky number, and then display
// the lucky number.
//------------------------------------------------------------------------------
int main()
{
    // Send "Zelda's Lucky Number Calculator" and two endl's to cout. The first
    // endl terminates the line of text and the second endl causes a blank line
    // to be output between the line of text and the string prompt for the
    // customer's name.
    cout << "Zelda's Lucky Number Calculator" << endl << endl;

    // Call get_string() and pass the string literal "What is your name? " as
    // the argument to the function. The function returns a string which we
    // assign to the defined string variable named 'name'.
    string name = get_string("What is your name? ");

    // Call get_int() and pass the string literal "In what month were you
    // born? " as the argument to the function. Assign the return value to an
    // int variable named 'birth_month' which must be defined as an int.
    int birth_month = get_int("In what month were you born? ");

    // Call get_int() passing "What was the date? " as the argument to read the
    // date of the customer's birthdate. Assign the return value to an int vari-
    // able named 'birth_date' (which must be defined as an int).
    int birth_date = get_int("What was the date? ");

    // Call get_int() passing "What was the year? " as the argument to read the
    // year of the customer's birthdate. Assign the return value to an int vari-
    // able named 'birth_year' (which must be defined as an int).
    int birth_year = get_int("What was the year (yyyy)? ");

    // Call get_int() passing the string literal shown in the project document
    // as the function argument. Assign the returned value to an int variable
    // named 'height_inch' (which must be defined as an int).
    int height_inch = get_int("What is your height (inches)? ");

    // Call get_int() passing the string literal shown in the project document
    // as the function argument. Assign the returned value to an int variable
    // named 'weight_lb' (which must be defined as an int).
    int weight_lb = get_int("What is your weight (lbs)? ");

    // Call convert_inch_to_cm() passing height_inch as the function argument.
    // Assign the returned value to an double variable named 'height_cm' (which
    // must be defined as a double).
    double height_cm = convert_inch_to_cm(height_inch);

    // Call convert_lb_to_kg() passing weight_lb as the function argument.
    // Assign the returned value to an double variable named 'weight_kg' (which
    // must be defined as a double).
    double weight_kg = convert_lb_to_kg(weight_lb);

    // Call calc_lucky() passing variables birth_date, height_cm, birth_month,
    // weight_kg, and birth_year as parameters. Assign the returned value to an
    // int variable named 'lucky' (which must be defined as an int).
    int lucky = calc_lucky(birth_date, birth_month, birth_year, height_cm, weight_kg);

    // Display the  customer's name, lucky number, and other required output.
    cout<<name<<", your lucky number is "<<lucky<<". Thank you, that will be $25"<<endl;

    // End the program by returning 0 from main().
    return(0);
}
