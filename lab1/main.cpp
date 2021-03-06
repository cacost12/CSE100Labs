//******************************************************************************
// FILE: main.cpp
//
// DESCRIPTION
// This program does x, y, and z. Then it explodes with such force that it
// triggers massive world-wide geothermal volcanic activity that ultimately
// results in the almost complete extinction of all life on Earth with the
// exception of members of the order Blattodea, which have always been destined
// to someday rule the world anyway.
//
// AUTHOR1: Colton Acosta, 1214326892, cacost12@asu.edu 
//
// COURSE INFO
// CSE100 Principles of Programming with C++, Fall 2020
// Lab Project 1
// Day/Time: Thursday, 9:00 - 9:50 AM
// TA: Neha Rajendra Vadnere
//******************************************************************************
#include <iostream>
#include <string>

using namespace std;

int main()
{

    // Print the initial prompt to the console
    cout<<"Hello, this is Lab Project 1. There are several goals:\n"<<endl;
    cout<<"1. Learn how to use the Repl.it Integrated Development Environment (IDE)."<<endl;
    cout<<"2. Learn how to locate and correct syntax errors in source code."<<endl;
    cout<<"3. Learn how to build and run my program."<<endl;
    cout<<"4. Learn the basic template for every C++ program."<<endl;
    cout<<"5. Learn how to write cout statements. "<<endl;
    cout<<"6. Learn how to write cin statements. "<<endl;
    cout<<"7. Learn how to define and use double and string variables."<<endl;
    cout<<"8. Learn how to use the basic arithmetic operators.\n"<<endl;

    // Ask the user for their name and store in a string object
    cout<<"What is your first name? ";
    string firstName;
    cin>>firstName;

    // Ask the user for their yearly salary 
    cout<<"What is your yearly salary? ";
    double salary;
    cin>>salary;

    // Print the yearly salary to the console 
    cout<<firstName<<", your yearly salary is $";
    printf("%.2lf \n", salary);

    // Calculate Monthly and biWeekly Salarys
    cout<<"Your monthly salary is $";
    printf("%.2lf\n", salary/12.0);
    cout<<"Your biweekly salary is $";
    printf("%.2lf\n", salary/(26.0));

    // Print Ending Message
    cout<<firstName<<", this was a blast. Let's do it again sometime."<<endl;

    return 0;
}

