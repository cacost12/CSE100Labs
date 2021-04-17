//****************************************************************************************
// FILE: main.cpp
//
// DESCRIPTION
// This program is designed to exercise the student's skills at writing various types of
// loops.
//
// LEARNING OBJECTIVES
// After completing this lab project, the student will be able to:
//
// * Complete all of the objectives of the previous lab projects.
// * Write a counting loop.
// * Write a vary loop.
// * Write a sentinel loop.
//
// Note: Be sure to include both AUTHOR lines if you work with a partner. If you work
// alone, then delete the AUTHOR2 line. Be sure to include your ASURITE ID in the zip
// archive filename and if you work with a partner, be sure to include both of your
// ASURITE ID's.
//
// AUTHOR1: your-name, your-asurite-username, your-email-address
// AUTHOR2: your-name, your-asurite-username, your-email-address
//
// COURSE INFO
// CSE100 Principles of Programming with C++, Spring 2021
// Lab Project 8  Day/Time: <your-lab-date-and-time>  TA: <your-lab-ta's-name>
//****************************************************************************************
#include ???   // For abs(), pow()
#include ???   // For setprecision()
#include ???   // For cin, cout, endl, fixed
#include ???   // For get_int(), get_double(), get_long(), get_int_in()
#include ???   // For run_prelab()

using namespace std;

//----------------------------------------------------------------------------------------
// NAMED CONSTANTS
//
// These constants correspond to the Lab 8 Main Menu items.
//----------------------------------------------------------------------------------------
static const int MENU_FIRST  = 1;
static const int MENU_PRELAB = 1;
static const int MENU_ROOT   = 2;
static const int MENU_QUIT   = 3;
static const int MENU_LAST   = 3;

// Define the constant for EPSILON to be 10^-16, i.e., 1E-16.
???

//----------------------------------------------------------------------------------------
// FUNCTION: ath_root()
//
// DESCRIPTION
// This function calculates and returns the a-th root of n, to an accuracy controlled by
// epsilon.
//
// Input parameter n is a real number >= 0 and parameter a is an integer >= 2. This func-
// tion uses Newton's method to compute and return the a-th root of n. The third parameter
// epsilon is a small real number which is used control the accuracy of the returned value.
// For example, if epsilon is 1E-3 (10^-3 = 0.001), then the returned value will have 2
// digits after the decimal point that are accurate. In general, if epsilon is 1E-p where
// p >= 1, then the returned value will have p-1 digits after the decimal point that are
// accurate. p is limited to 1 ≤ p ≤ 16, since the double data type can only represent
// real numbers to an accuracy of 15-16 digits.
//--------------------------------------------------------------------------------------------------
static double compute_ath_root(double n, int a, double epsilon)
{
    // Implement the pseudocode on p. 4 of the lab document.

    // Newton's method require a starting value for x_i; the closer x_i is to the actual
    // root, the faster the method will converge to the result. It is possible that if x_i
    // is chosen improperly, Newton's method will not converge to the root. I have some-
    // what arbitrarily chosen n/2 as the initial value for x. This choice should cause
    // the method to converge to the root in all cases.
	double x_i = ???
	double x_i_plus_1 = ???

	// Keep looping as long as the computed root is not accurate to epsilon decimal
    // digits. The math library (include cmath) contains a function:
    //
    //     double abs(double)
    //
    // which returns the absolute value of its input argument. Your loop condition is to
    // determine if the absolute value of x_i_plus1 - x_i is greater than or equal to
    // epsilon.
	???

	// x_i_plus_1 is the root, accurate to epsilon (or more) decimal digits. Return root.
	???
}

//----------------------------------------------------------------------------------------
// compute_ath_root()
//
// Asks the user to enter a real number, n, n >= 0, and an integer, a, a >= 2. Calls
// ath_root() passing n, a, and EPSILON as arguments. This value for epsilon ensures the
// value of the returned root will be accurate to 15 decimal digits. Send the returned
// value to the output window.
//----------------------------------------------------------------------------------------
static void process_ath_root()
{
	cout << endl <<  "Your choice is to compute the a-th root of n." << endl;
	double n = get_double("Enter n (>= 0): ");
	int a = get_int("Enter a (>= 2): ");
	double root = compute_ath_root(n, a, 1E-16);
	cout << "The " << a << "-th root of " << n << " is " << root << endl << endl;
}

//----------------------------------------------------------------------------------------
// menu()
//
// Display a menu asking the user what action they wish to perform. Returns the number of
// the selected menu item.
//
// PSEUDOCODE
// function menu() -> int
//     display the Lab 8 Main Menu
//     return what call get_int_in("Your Choice [1-3]? ", MENU_FIRST, MENU_LAST) returns
// end function
//----------------------------------------------------------------------------------------
static int menu()
{
    // Display the Lab 8 Main Menu as shown on p. 4 of the lab document.
    ???

    // Call get_int_in() and return what it returns.
    ???
}

//----------------------------------------------------------------------------------------
// process_menu_choice()
//
// Examines the choice the user selected from the menu annd calls the appropriate menu
// handler function.
//
// function process_menu_choice(choice : int)
//     if choice is MENU_PRELAB then
//         call run_prelab()
//     else if choice is MENU_ROOT then
//          call process_ath_root()
//     end if
// end function
//----------------------------------------------------------------------------------------
static void process_menu_choice(int choice)
{
    // Implement the pseudocode.
    ???
}

//----------------------------------------------------------------------------------------
// run()
//
// Repeatedly display the menu and process the user's choice until the user selects the
// menu item to end the program.
//
// PSEUDOCODE
// function run() -> nothing
//     choice <- call menu()
//     while choice is not MENU_QUIT do
//         call process_menu_choice() passing choice as the arg
//         choice <- call menu()
//     end while
// end function
//----------------------------------------------------------------------------------------
static void run()
{
    // Implement the pseudocode.
    ???
}

//----------------------------------------------------------------------------------------
// main()
//
// PSEUDOCODE
// function main()
//     configure cout to output real numbers in fixed notationn with 16 decimal digits
//     call run()
//     return 0
// end function
//----------------------------------------------------------------------------------------
int main()
{
    // Implement the pseudocode.
    ???
}
