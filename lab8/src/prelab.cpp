//******************************************************************************
// FILE: prelab.cpp
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

#include <iostream>

// Write #include directives to include get.hpp and prelab.hpp
#include "get.hpp"
#include "prelab.hpp"

using namespace std;

//------------------------------------------------------------------------------
// NAMED CONSTANTS
//
// These constants correspond to the menu item numbers displayed in menu().
//------------------------------------------------------------------------------
static const int MENU_FIRST      = 1;
static const int MENU_VARY_FOR1  = 1;
static const int MENU_VARY_FOR2  = 2;
static const int MENU_VARY_WHILE = 3;
static const int MENU_RETURN     = 4;
static const int MENU_LAST       = 4;

//------------------------------------------------------------------------------
// FUNCTION PROTOTYPES
//
// Write prototypes for any function which is defined below the location in this
// source code file from where the function is first called.
//------------------------------------------------------------------------------
static void vary_for1();
static void vary_for2();
static void vary_while();

//------------------------------------------------------------------------------
// menu()
//
// This function is called from run() to display the menu for the program. The u
// ser will select one of these menu items to perform. Note that get_int_in() 
// will not return until the user enters an integer in [1, 4] so it is 
// guaranteed that the returned value will be a valid choice.
//
// PSEUDOCODE
// function menu() -> int
//     output a blank line
//     output each of the menu item lines
//     return what call get_int_in("Your Choice 1-4]? ", MENU_FIRST, MENU_LAST)
// returns
// end function
//------------------------------------------------------------------------------
static int menu()
{
    // Implement the pseudocode to implement the Prelab Exercises Menu as shown 
    // on p.4 of the lab document.
    int choice;

    // Menu Items
    cout << endl;
    cout << "-------------------------------------------------" << endl;
    cout << "Prelab Exercises Menu: What would you like to do?" << endl;
    cout << "-------------------------------------------------" << endl;
    cout << "1. Prelab Exercise 2: Vary Using For Loop 1" << endl;
    cout << "2. Prelab Exercise 3: Vary Using For Loop 2" << endl;
    cout << "3. Prelab Exercise 4: Vary Using While Loop" << endl;
    cout << "4. Return to the Main Menu";

    // Get User choice 
    choice = get_int_in("Your Choice [1-4]?", 1, 4);

    return(choice);
}

//------------------------------------------------------------------------------
// process_menu_choice()
//
// This function is called from run() after the user selects their choice from
// the menu. It uses an if-elseif-... statement to determine which function to 
// call.
//
// PSEUDOCODE
// function process_menu_choice(choice : int) -> nothing
//     output a blank line
//     if choice is MENU_VARY_FOR1 then
//         call vary_for1()
//     else if choice is MENU_VARY_FOR2 then
//         call vary_for2()
//     else if choice is MENU_VARY_WHILE then
//         call vary_while()
//     end if
// end function
//------------------------------------------------------------------------------
static void process_menu_choice(int choice)
{
    // Implement the pseudocode
    switch(choice){
        case MENU_VARY_FOR1:
            vary_for1();
            break;

        case MENU_VARY_FOR2:
            vary_for2();
            break;

        case MENU_VARY_WHILE:
            vary_while();
            break;
    }
}

//----------------------------------------------------------------------------------------
// vary_for1()
//
// See the Prelab Exercises section of the project document for the software 
// requirements.
//
// PSEUDOCODE
// function vary_for1()
//     output '['
//     for n <- -1 to -25 by -1
//         output n << " "
//     end for
//     output ']'
//     output blank line
// end function
//
// REMARKS
// Note that in this loop, every integer is followed by one space including the 
// last
// integer.
//------------------------------------------------------------------------------
static void vary_for1(){
    // Implement the pseudocode.
    cout << "[";

    for (int i = -1; i >= -25; --i){
        cout << i << " ";
    }
   
    cout << "]" << endl << endl;
}

//------------------------------------------------------------------------------
// vary_for2()
//
// See the Prelab Exercises section of the project document for the software 
// requirements.
//
// PSEUDOCODE
// function vary_for2()
//     output '['
//     for n <- -1 to -25 by -1
//         output n
//         if n is not -25 then output space character
//     end for
//     output ']'
//     output blank line
// end function
//
// Alternative Implementation
// function vary_for2()
//     output '['
//     for n <- -1 to -24 by -1
//         output n << ' '
//     end for
//     output n
//     output ']'
//     output blank line
// end function
//
// REMARKS
// Note that in this loop, every integer is followed by one space except for the
// last integer, which is not followed by a space.
//------------------------------------------------------------------------------
static void vary_for2(){

    // Implement either the first or the alternative version of the pseudocode.
    cout << "[";
    
    for (int i=-1; i>-25; --i){
        cout << i << " ";
    }

    cout << -25 << "]"<<endl<<endl;
}

//------------------------------------------------------------------------------
// vary_while()
//
// See the Prelab Exercises section of the project document for the software 
// requirements.
//
// PSEUDOCODE
// function vary_while()
//     output '['
//     n = 100
//     while n >= 1 do
//         output n << ' '
//         n -= 3
//     end while
//     output ']'
//     output blank line
// end function
//------------------------------------------------------------------------------
static void vary_while()
{
    // Implement the pseudocode.
    cout << "[";

    int n = 100;

    while(n>=1){
        cout << n << " ";
        n -= 3;
    }

    cout << "]" << endl << endl;
}

//------------------------------------------------------------------------------
// run_prelab()
//
// This function implements a sentinel loop which will repeatedly display the 
// menu, get the user's choice, call the appropriate looping function, and then
// the sentinel loop repeats.
//
// PSEUDOCODE
// function run() -> nothing
//     int choice <- call menu()
//     while (choice is not MENU_RETURN) do
//         call process_prelab_menu_choice() passing choice as the arg
//         choice <- call menu()
//     end while
//     output a blank liine
// end function
//------------------------------------------------------------------------------
void run_prelab(){
    // Display the menu and get the user choice
    int choice = menu();

    // Loop until MENU_RETURN option is recieved
    while (choice != MENU_RETURN){
        process_menu_choice(choice);
        choice = menu();
    }    

    cout << endl;
}
