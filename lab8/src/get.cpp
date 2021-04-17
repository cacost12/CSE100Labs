//******************************************************************************
// FILE: get.cpp
//
// DESCRIPTION
// This file contains a function to display a prompt and ask the user to enter
// an integer. The entered integer has to be within a specified range of 
// integers, e.g., [1, 4] and the function will prompting and reading integers
// until the user finally enters an int which is within the range.
//
// AUTHOR1: Colton Acosta, cacost12, 1214326892, cacost12@asu.edu 
//
// COURSE INFO
// CSE100 Principles of Programming with C++, Fall 2020
// Lab Project 8   Day/Time: Th 9:00-9:50 AM TA: Neha Rajendra Vadnere
//******************************************************************************
#include <iostream>
#include <string>
#include "get.hpp"

using namespace std;

//----------------------------------------------------------------------------------------
// FUNCTION: get_double()
//
// DESCRIPTION
// Display the prompt string prompt, read a double from the keyboard, and return
// the double.
//------------------------------------------------------------------------------
double get_double(string prompt)
{
    cout << prompt;
    double n;
    cin >> n;
    return n;
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
    int n;
    cin >> n;
    return n;
}

//------------------------------------------------------------------------------
// get_int_in()
//
// Displays a message prompting the user to enter an integer in the range [low, 
// high]. Does not return until the user enters a value choice, which is the 
// function return value.
//
// REMARKS
// This is a sentinel loop, with the sentinel being any integer in the range 
// [low, high]. Make sure that when you write the loop that you do not omit the 
// second cin statement at the bottom of the while loop. If you do, you will 
// create an infinite loop.
//
// PSEUDOCODE
// function get_int_in (msg: string, low: int, high: int) -> int
//     output msg
//     n <- read int from keybd
//     while (n is not in [low, high]) do
//         output "Your choice must be in [" << low " << " high "]" << endl
//         output msg
//         n <- read int from keybd
//     end while
//     return n
// end function
//------------------------------------------------------------------------------
int get_int_in(string msg, int low, int high)
{
    // Output Message
    cout << msg;
 
    // Get integer from the keyboard
    int n;
    cin >> n;

    // Loop until the number is in the correct range
    while (n<low && n>high){
        cout << "Your choice must be in " << "[" << low << "-" << high "]";
        cout << endl;
        cout << msg;
        cin >> n;
    }

    return(n);
}

//--------------------------------------------------------------------------------------------------
// FUNCTION: get_long()
//
// DESCRIPTION
// Display the prompt string prompt, read a long int from the keyboard, and return the long int.
//--------------------------------------------------------------------------------------------------
long get_long(string prompt)
{
    cout << prompt;
    long n;
    cin >> n;
    return n;
}
