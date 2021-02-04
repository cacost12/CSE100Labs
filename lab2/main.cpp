//******************************************************************************
// FILE: main.cpp
//
// DESCRIPTION
// Use include pre-processor directives to include header file such as cmath, iomanip, and istream
// Define and use a named constant
// Use cout to send string literals int and double values to the output window
// Assign values using an assignment operator
// Store integer and real numbers read from the keyboard using cin into int and double variables
// Write arithmetic expressions using the arithmetic operators
// Understand operator precedence rules and the difference between integer and floating point division
// Use the statis_cast<> operator
// Call C++ standard library math function
// Use fixed and setprecision stream manipulators to output real numbers with a specific number of digits after the decimal point
// Use indentation and proper spacing to format code 
// 
//
// AUTHOR1: Colton Acosta, cacost12@asu.edu, 1214326892 
//
// COURSE INFO
// CSE100 Principles of Programming with C++, Fall 2020
// Lab Project 2 Day/Time: 
// Day/Time: Thursday, 9:00 - 9:50 AM
// TA: Neha Rajendra Vadnere
//******************************************************************************

//------------------------------------------------------------------------------
// main() is where the program begins executing.
//------------------------------------------------------------------------------

// Include Standard Libraries with preprocessor directive
#include <iostream>
#include <cmath>
#include <iomanip> 

// Declare global constant integer for the total number of students
const int NUM_STUDENTS = 3;

// Use standard namespace to facilitate printing messages to the console
using namespace std;

int main(void){

    // Declare integers for storing the exam scores
    int exam_homer, exam_lisa, exam_ralph;

    // Get Exam Scores from the user 
    cout<<"Enter exam score for Homer? ";
    cin>> exam_homer;
    
    cout<<"Enter exam score for Lisa? ";
    cin>> exam_lisa;

    cout<<"Enter exam score for Ralph? ";
    cin>> exam_ralph;

    // Calculate the exam average 
    double exam_avg = (exam_homer + exam_lisa + exam_ralph)/(static_cast<double>(NUM_STUDENTS));

    // Calculate the square differences
    double sq_diff_homer, sq_diff_lisa, sq_diff_ralph;
    sq_diff_homer = pow(exam_homer - exam_avg,2);
    sq_diff_lisa = pow(exam_lisa - exam_avg,2);
    sq_diff_ralph = pow(exam_ralph - exam_avg,2);

    // Calculate Exam Variance
    double exam_variance = (sq_diff_homer + sq_diff_lisa + sq_diff_ralph)/(NUM_STUDENTS - 1); 

   // Calculate Exam Standard Deviation
   double exam_stddev = sqrt(exam_variance); 

    // Output the data to the console
    cout<<endl;
    cout<<setprecision(2)<<"The exam average is: "<<exam_avg<<"%"<<endl;
    cout<<setprecision(2)<<"The exam standard deviation is: "<<exam_stddev<<"%"<<endl; 
    
return 0;
}

