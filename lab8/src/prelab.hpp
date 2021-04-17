//****************************************************************************************
// FILE: prelab.hpp
//
// DESCRIPTION
// This header file contains a function prototype for prelab_run(). Remember that a proto-
// type is also called a function declaration and remember the rule that a function has to
// be defined or declared above the location in a source code file from where that func-
// tion is first called. When this header file is #included in another C++ source code
// file--which contains a call to the function--then it provides the function declaration
// so the "defined or declared" rule is satisfied.
//
// LEARNING OBJECTIVES
// To learn how to write a header file containing function prototypes.
//
// AUTHOR1: your-name, your-asurite-username, your-email-address
// AUTHOR2: your-name, your-asurite-username, your-email-address
//
// COURSE INFO
// CSE100 Principles of Programming with C++, Spring 2021
// Lab Project 8  Day/Time: <your-lab-date-and-time>  TA: <your-lab-ta's-name>
//****************************************************************************************

//----------------------------------------------------------------------------------------
// This #ifndef ... #endif preprocessor directives forms what is called a preprocessor
// guard or an include guard. It is necessary because without it, in some situations a
// header file can be #included more than once in a C++ source code file and this causes
// problems. Without going into the gory details of how this works, it checks to see if
// the name PRELAB_HPP has been defined. If it has not, then PRELAB_HPP is defined, and
// the code between the #ifndef and the #endif is included. This will happen the first
// time prelab.hpp is #included in a C++ source code file. Then, if it is #included again
// in the same source code file, the preprocessor will determine that PRELAB_HPP has
// already been defined, and then the code between the #ifndef and the #endif will not be
// included. By not including it a second time, we avoid problems with things, e.g., named
// constants, global variables, functions, etc, being declared more than once.
//----------------------------------------------------------------------------------------
#ifndef PRELAB_HPP
#define PRELAB_HPP

// Write a prototype for the run_prelab() function defined in prelab.cpp.
???

#endif
