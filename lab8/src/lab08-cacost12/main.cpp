//*****************************************************************************
// FILE: main.cpp
//
// DESCRIPTION
// This program is designed to exercise the student's skills at writing various
// types of loops.
//
// LEARNING OBJECTIVES
// After completing this lab project, the student will be able to:
//
// * Complete all of the objectives of the previous lab projects.
// * Write a counting loop.
// * Write a vary loop.
// * Write a sentinel loop.
//
// Note: Be sure to include both AUTHOR lines if you work with a partner. If you
// work alone, then delete the AUTHOR2 line. Be sure to include your ASURITE ID 
// in the zip archive filename and if you work with a partner, be sure to
// include both of your ASURITE ID's.
//
// AUTHOR1: Colton Acosta, cacost12, 1214326892, cacost12@asu.edu 
//
// COURSE INFO
// CSE100 Principles of Programming with C++, Fall 2020
// Lab Project 8   Day/Time: Th 9:00-9:50 AM TA: Neha Rajendra Vadnere
//******************************************************************************
#include <cmath>   // For abs(), pow()
#include <iomanip>   // For setprecision()
#include <iostream>   // For cin, cout, endl, fixed
#include "get.hpp"   // For get_int(), get_double(), get_long(), get_int_in()
#include "prelab.hpp"   // For run_prelab()

using namespace std;

//------------------------------------------------------------------------------
// NAMED CONSTANTS
//
// These constants correspond to the Lab 8 Main Menu items.
//------------------------------------------------------------------------------
static const int MENU_FIRST  = 1;
static const int MENU_PRELAB = 1;
static const int MENU_ROOT   = 2;
static const int MENU_QUIT   = 3;
static const int MENU_LAST   = 3;

// Define the constant for EPSILON to be 10^-16, i.e., 1E-16.
double EPSILON = 1E-16;

//------------------------------------------------------------------------------
// FUNCTION: ath_root()
//
// DESCRIPTION
// This function calculates and returns the a-th root of n, to an accuracy 
// controlled by epsilon.
//
// Input parameter n is a real number >= 0 and parameter a is an integer >= 2. 
// This function uses Newton's method to compute and return the a-th root of n. 
// The third parameter epsilon is a small real number which is used control 
// the accuracy of the returned value. For example, if epsilon is 1E-3 (10^-3 = // 0.001), then the returned value will have 2 digits after the decimal point 
// that are accurate. In general, if epsilon is 1E-p where p >= 1, then the 
// returned value will have p-1 digits after the decimal point that are accurate//. p is limited to 1 ≤ p ≤ 16, since the double data type can only represent 
// real numbers to an accuracy of 15-16 digits.
//------------------------------------------------------------------------------
static double compute_ath_root(double n, int a, double epsilon){

    // Newton's method require a starting value for x_i; the closer x_i is to 
    // the actual root, the faster the method will converge to the result. It is
    // possible that if x_i is chosen improperly, Newton's method will not
    // converge to the root. I have some-what arbitrarily chosen n/2 as the
    // initial value for x. This choice should cause the method to converge to
    // the root in all cases.
    double x_i = n/2;
    double x_i_plus_1 = x_i - (pow(x_i,a) - n)/(a*pow(x_i, a-1));

    // Keep looping as long as the computed root is not accurate to epsilon 
    // decimal digits. The math library (include cmath) contains a function:
    // double abs(double) which returns the absolute value of its input argument
    // . Your loop condition is to determine if the absolute value of x_i_plus1 
    // - x_i is greater than or equal to epsilon.
    while (abs(x_i_plus_1 - x_i) >= epsilon){
        x_i = x_i_plus_1;
        x_i_plus_1 = x_i - (pow(x_i,a) - n)/(a*pow(x_i, a-1));
    }

    // x_i_plus_1 is the root, accurate to epsilon (or more) decimal digits.
    // Return root.
    return(x_i_plus_1);
	
}

//------------------------------------------------------------------------------
// compute_ath_root()
//
// Asks the user to enter a real number, n, n >= 0, and an integer, a, a >= 2.
// Calls ath_root() passing n, a, and EPSILON as arguments. This value for 
// epsilon ensures the value of the returned root will be accurate to 15 decimal
//  digits. Send the returned value to the output window.
//------------------------------------------------------------------------------
static void process_ath_root()
{
	cout << endl <<  "Your choice is to compute the a-th root of n." << endl;
	double n = get_double("Enter n (>= 0): ");
	int a = get_int("Enter a (>= 2): ");
	double root = compute_ath_root(n, a, 1E-16);
	cout << "The " << a << "-th root of " << n << " is " << root << endl << endl;
}

//------------------------------------------------------------------------------
// menu()
//
// Display a menu asking the user what action they wish to perform. Returns the 
// number of the selected menu item.
//
// PSEUDOCODE
// function menu() -> int
//     display the Lab 8 Main Menu
//     return what call get_int_in("Your Choice [1-3]? ", MENU_FIRST, MENU_LAST)
//     returns
// end function
//------------------------------------------------------------------------------
static int menu()
{
    // Implement the pseudocode to implement the Prelab Exercises Menu as shown 
    // on p.4 of the lab document.
    int choice;

    // Menu Items
    cout << endl;
    cout << "-------------------------------------------" << endl;
    cout << "Lab 8 Main Menu: What would you like to do?" << endl;
    cout << "-------------------------------------------" << endl;
    cout << "1. Run the prelab exercizes." << endl;
    cout << "2. Compute the a-th root of a real number." << endl;
    cout << "3. Quit the program." << endl;

    // Get User choice 
    choice = get_int_in("Your Choice [1-3]?", 1, 3);

    return(choice);
}

//------------------------------------------------------------------------------
// process_menu_choice()
//
// Examines the choice the user selected from the menu annd calls the 
// appropriate menu handler function.
//
// function process_menu_choice(choice : int)
//     if choice is MENU_PRELAB then
//         call run_prelab()
//     else if choice is MENU_ROOT then
//          call process_ath_root()
//     end if
// end function
//------------------------------------------------------------------------------
static void process_menu_choice(int choice){

    // Run functions depending on the user's choice
    switch(choice){
    
        case MENU_PRELAB:
            run_prelab();
            break;

        case MENU_ROOT:
            process_ath_root();
            break;
    }
    
}

//------------------------------------------------------------------------------
// run()
//
// Repeatedly display the menu and process the user's choice until the user 
// selects the  menu item to end the program.
//
// PSEUDOCODE
// function run() -> nothing
//     choice <- call menu()
//     while choice is not MENU_QUIT do
//         call process_menu_choice() passing choice as the arg
//         choice <- call menu()
//     end while
// end function
//------------------------------------------------------------------------------
static void run(){

    // Display Main menu and collect user's choice
    int choice = menu(); 

    // Run program continuously until user selects the quit option
    while (choice != MENU_QUIT){
        process_menu_choice(choice);
        choice = menu();
    }
}

//------------------------------------------------------------------------------
// main()
//
// PSEUDOCODE
// function main() 
//     configure cout to output real numbers in fixed notationn with 16 decimal 
//     digits
//     call run()
//     return 0
// end function
//------------------------------------------------------------------------------
int main(){

    // Configure output stream 
    cout << fixed << setprecision(16);

    // Run the main function
    run();

    return(0);
}
