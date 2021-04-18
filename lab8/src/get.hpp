//******************************************************************************
// FILE: get.hpp
//
// DESCRIPTION
// This header file contains a function prototype for get_int_in(). Remember 
// that a prototype is also called a function declaration and remember the rule 
// that a function has to be defined or declared above the location in a source 
// code file from where that function is first called. When this header file is 
// #included in another C++ source code file--which contains a call to the 
// function -- then it provides the function declaration so the "defined or 
// declared" rule is satisfied.
//
// LEARNING OBJECTIVES
// To learn how to write a header file containing function prototypes.
//
// AUTHOR1: Colton Acosta, cacost12, 1214326892, cacost12@asu.edu 
//
// COURSE INFO
// CSE100 Principles of Programming with C++, Fall 2020
// Lab Project 8   Day/Time: Th 9:00-9:50 AM TA: Neha Rajendra Vadnere
//******************************************************************************

// See the comments in prelab.hpp regarding preprocessor include guards.
#ifndef GET_HPP
#define GET_HPP

#include <string>
using namespace std;

// Write prototypes for the functions defined in get.cpp.
double get_double(string prompt);

int get_int(string prompt);

int get_int_in(string msg, int low, int high);

long get_long(string prompt);


#endif
