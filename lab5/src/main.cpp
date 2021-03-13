//******************************************************************************
// FILE: main.cpp
//
// DESCRIPTION
// Reads season statistics for basketball players from an input file named
// "stats-season.txt", computes the per-game statistics for each player, and
// writes the per-game statistics to an output file named "stats-game.txt".
//
// AUTHOR1: Colton Acosta, cacost12, 1214326892, cacost12@asu.edu 
//
// PRIMARY LEARNING OBJECTIVES
// 1. Complete all of the objectives of the previous lab projects.
// 2. Continue learning to write functions definitions, call functions, pass
//    parameters by-value and by-reference, define local variables, and return
//    values from functions.
// 3. Write function prototypes.
// 4. Use the left, right, and setw stream manipulators.
// 5. Continue learning to write programs using text file I/O.
//
// COURSE INFO
// CSE100 Principles of Programming with C++, Fall 2020
// Lab Project 5   Day/Time: Th 9:00-9:50 AM TA: Neha Rajendra Vadnere 
//******************************************************************************
#include <cstdlib>      // For exit() function
#include <fstream>                   // For ifstream, ofstream
#include <iomanip>                   // For setprecision(), setw()
#include <iostream>                   // For cout, endl, fixed, left, right
#include <string>                   // For string class

using namespace std;

//==============================================================================
// Function Prototypes
//
// REMARK
// A prototype is a statement that provides a "function declaration" to the
// compiler. A prototype consists of just the function header of a function
// definition. For example, consider this function definition:
//
// int sqr(int x)                <-- function header
// {                        --+
//     return x * x;          |  <-- function body
// }                        --+
//
// The function header is the first line of the function which consists of:
// (1) the data type of the return value (int in this case); (2) the name of
// the function (sqr in this example); (3) the pair of parentheses; and
// (4) the optional parameter which defines one or more parameter variables
// (in this example, the parameter list is "int x" which defines x as a param-
// eter variable storing ints).
//
// The function body (or the body of the function) consists of the pair of
// braces and the enclosed statements that are executed when the function is
// called.
//
// The prototype for the sqr() function is:
//
//     int sqr(int)
//
// Note that when we write a prototype, specifying names for the parameter
// variables is optional, although it is most definitely NOT optional when
// writing the function definition.
//
// A prototype is necessary when a function is defined in a source code file
// below the last location in the source code file from where the function is
// called.
//
// There is C++ syntax rule which specifies that a function must either be
// "defined" or "declared" in the source code file above the location from where
// the function is first called. For example, in the case of the terminate()
// function, the function definition is below the locations where terminate()
// is called from open_input_file() and open_output_file(). Therefore, we have
// written a prototype for terminate() so it will be declared above the point
// from where it is called in those two functions.
//
// An alternative way to solve this problem would be to define terminate() above
// open_input_file() and open_output_file(), e.g.,
//
// void terminate(string msg)  -- terminate is defined above the locations
// {                           -- from where it is called
//     ...
// }
//
// int open_input_file(ifstream& fin, string filename)
// {
//     ...
//     terminate("Could not open input file for reading.");
//     ...
// }
//
// int open_output_file(ofstream& fout, string filename)
// {
//     ...
//     terminate("Could not open output file for writing.");
//     ...
// }
//
// Either way--define terminate() first or declare terminate()--is accept-
// able. My personal programming style is to put main() at the bottom of the
// source code file and then order the other functions in ascending alphabetical
// order (A-z). Then, for the functions which are called before they are
// defined, I write function prototypes at the top of the file.
//==============================================================================

// Write the prototype for the output_player_stats() function. Recall that it is
// up to you if you specify names for the parameters. All the compiler needs to
// know when reading the prototype is the name of the function, the data type of
// the return value, and the data types (order matters) of the parameters. My
// rule of thumb is to include the parameter variable name if it makes the code
// more readable and omit it when it does not.
void output_player_stats(ofstream& fout, string name, int gp, double fgp, double ftp, double threep, double ppg, double rpg);
                         
// Write the prototype for the terminate() function.
void terminate(string msg);

//------------------------------------------------------------------------------
// FUNCTION: compute_per_game_stats()
//
// DESCRIPTION
// Reads one line at a time from the input file, computes the per game stats for
// the player, and calls output_player_stats() to send the player's stats to the
// output file.
//
// PARAMETERS
// fin  - The input file stream, which is passed by-reference (ifstream&).
// fout - The output file stream, which is passed by-reference (ofstream&).
//------------------------------------------------------------------------------
void compute_per_game_stats(ifstream& fin, ofstream& fout)
{
    // Define int variables: gp, fgm, fga, ftm, fta, threem, threea, pts, rebs
    int gp, fgm, fga, ftm, fta, threem, threea, pts, rebs;
    
    // Define double variables: fgp, ftp, threep, ppg, rpg
    double fgp, ftp, threep, ppg, rpg;
    
    // Define string variable: name
    string name;
    
    // Do not worry about what the code on lines 148-149 and 193-184 does. We
    // will discuss it when we cover Ch. 5 of the book. In the meantime, if you
    // are curious, this code causes each line of the input file to be read one
    // at a time, until we reach the line containing "end" when we stop reading
    // and return.

    // Read the player's name from the input file. If we just read the "end"
    // string, then drop out of the while loop.
    fin >> name;
    while (name != "end") {
    
        // Read nine values from fin storing the values in the variables gp,
        // fgm, fga, ftm, fta, threem, threea, pts, and rebs -- in that order.
        // This can all be done in one input statement or you may break it up
        // into multiple input statements.
        fin >> gp;
	fin >> fgm;
	fin >> fga;
	fin >> ftm; 
	fin >> fta;
	fin >> threem;
	fin >> threea;
	fin >> pts;
	fin >> rebs;
        
        // Calculate the player's field goal percentage which is fgm/fga. Note:
        // since fgm and fga are both ints, the division will be performed as
        // integer division. However, we must perform floating point division,
        // so typecast either fgm or fga to double before dividing.
        fgp = static_cast<double>(fgm)/fga; 
        
        // Calculate the player's free throw percentage which is ftm/fta. Note:
        // typecast ftm to double.
        ftp = static_cast<double>(ftm)/fta;

        // Calculate the player's three point percentage which is threem/threea.
        // Note: typecast threem to double.
        threep = static_cast<double>(threem)/threea;
        
        // Calculate the player's points per game, which is pts/gp. Note:
        // typecast pts to double.
        ppg = static_cast<double>(pts)/gp;

        // Calculate the player's rebounds per game, which is rebs/gp. Note:
        // typecast rebs to double.
        rpg = static_cast<double>(rebs)/gp;
        
        // Call output_player_stats() to output the player's stats. The args are
        // fout, name, gp, fgp, ftp, threep, ppg, and rpg.
        output_player_stats(fout, name, gp, fgp, ftp, threep, ppg, rpg);
        
        // Read the name of the next player from the input file.
        fin >> name;
   }
}

//------------------------------------------------------------------------------
// FUNCTION: open_input_file()
//
// DESCRIPTION
// Opens the file with name 'filename' for reading. Returns the file stream
// object fin by-reference. If the file cannot be opened for reading then call
// terminate() to gracefully exit the program.
//
// PARAMETERS
// fin      - The input file stream (ifstream&).
// filename - The name of the file to be opened (string).
//
// Note: see the comments regarding ifstream& in the comments for computer_per_
// game_stats().
//------------------------------------------------------------------------------
void open_input_file(ifstream& fin, string filename)
{
    // Call the open() function on the fin parameter. Note that the open()
    // function expects the filename string to be a C-string rather than a C++
    // string. We can retrieve the C-string contained within the filename string
    // object by calling the c_str() function on 'filename', i.e., by writing
    // filename.c_str().
    fin.open(filename.c_str());
    
    // At this time, the file should be opened for reading. However, if the file
    // could not be opened (most likely because the file is not in the proper
    // folder where your IDE expects it to be) then we will call terminate() to
    // shut down the program. Note: do not worry about what this code does as we
    // will discuss the if reserved word and how to use it when we cover Ch. 4
    // of the book.
    if (!fin) {
        terminate("Could not open input file for reading.");
    }
}

//------------------------------------------------------------------------------
// FUNCTION: open_output_file()
//
// DESCRIPTION
// Opens the file with name 'filename' for writing. Returns the file stream
// object fout by-reference. If the file cannot be opened for writing then call
// terminate() to gracefully exit the program.
//
// PARAMETERS
// fout     - The output file stream (ofstream&).
// filename - The name of the file to be opened (string).
//
// Note: see the comments regarding ofstream& in the comments for computer_per_
// game_stats().
//------------------------------------------------------------------------------
void open_output_file(ofstream& fout, string filename)
{
    // Call the open() function on the fout parameter. See open_input_file()
    // for how to do this.
    fout.open(filename.c_str());
    
    // See comments in open_input_file().
    if (!fout) {
        terminate("Could not open output file for writing.");
    }
}

//------------------------------------------------------------------------------
// FUNCTION: output_header()
//
// DESCRIPTION
// Outputs the row containing the column header labels to the output file.
//------------------------------------------------------------------------------
void output_header(ofstream& fout)
{
    // Make certain you understand how left, right, and setw are used to
    // format the column headers.
    fout << left << setw(16) << "Name";
    fout << right << setw(4) << "GP";
    fout << setw(6) << "PPG";
    fout << setw(6) << "RPG";
    fout << setw(7) << "FG%";
    fout << setw(7) << "FT%";
    fout << setw(7) << "3P%";
    fout << endl;
}

//------------------------------------------------------------------------------
// FUNCTION: output_player_stats()
//
// DESCRIPTION
// Outputs the stats for one player to the output file. Configures fout to
// properly display the results per the example in the lab project document.
//
// PARAMETERS
// fout    - The output file stream (ofstream&)
// name    - The player's name (string)
// gp      - Games played (int)
// fgp     - Field goal percentage (double)
// ftp     - Free throw percentage (double)
// threep  - Three point percentage (double)
// ppg     - Points per game (double)
// rpg     - Rebounds per game (double)
//------------------------------------------------------------------------------
void output_player_stats(ofstream& fout, string name, int gp, double fgp,
    double ftp, double threep, double ppg, double rpg)
{
    // Configure fout for fixed mode, left justification, and a field width of
    // 16. Then output the value of variable 'name'.
    fout << fixed << left << setw(16) << name;
    
    // Configure fout for right justification, display 1 digit after the decimal
    // point, and a field width of 4. Then output the value of variable gp.
    fout << right << setprecision(1) << setw(4) << gp;   
    
    // Configure fout for a field of width 6. Output ppg (Note: fout has remem-
    // bered the right and setprecision(1) manipulators so ppg will be output
    // right-justified in a field of width 6 with one digit after the decimal
    // point.
    fout << setw(6) << ppg; 
    
    // Configure fout for a field of width 6. Output rpg right-justified in a
    // field of width 6 with one digit after the decimal point.
    fout << setw(6) << rpg;
    
    // Configure fout for 3 digits after the decimal point, and a field width
    // of 7. Then output the value of variable fgp which will be right-justified
    // in the field.
    fout << setprecision(3) << setw(7) << fgp;
        
    // Configure fout for a field of width 7. Output ftp which will be printed
    // right-justified in a field of width 7 with 3 digits after the decimal
    // point.
    fout << setw(7) << ftp;
    
    // Configure fout for a field of width 7. Output threep  which will be
    // printed right-justified in a field of width 7 with 3 digits after the
    // decimal point.
    fout << setw(7) << threep;
    
    // Send an endline (or newline) to fout.
    fout << endl;
}

//------------------------------------------------------------------------------
// FUNCTION: terminate()
//
// DESCRIPTION
// Called when either the input or output file cannot be opened. Sends msg to
// the output window and then calls the C++SL exit() function to terminate the
// program. The value that exit() returns goes back to the operating system. We
// shall return the positive integer 1 to indicate failure due to either the
// input or outputf ile not being opened.
//
// PARAMETERS
// msg - The message to be displayed (string)
//------------------------------------------------------------------------------
void terminate(string msg)
{
    // Send msg to cout to display the message on the output window.
    cout << msg << endl;
    
    // There is a function in the C++SL called exit(). It has one parameter,
    // which is an int. exit() will terminate the program and send the int param
    // value back to the operating system. We shall return 1 to indicate that
    // the program had to terminate early due to either the input or output file
    // not being opened.
    //
    // Call exit() passing 1 as the arg.
    exit(1);
}

//------------------------------------------------------------------------------
// FUNCTION: main()
//
// DESCRIPTION
// main() opens the input and output files. Then it calls compute_per_game_
// stats() to compute and send the player's stats to the output file. Closes
// the input and output files before returning.
//------------------------------------------------------------------------------
int main()
{
    // Define an ifstream object named fin (fin = File INput).
    ifstream fin;
    
    // Define an ofstream object named fout (fout = File OUTput).
    ofstream fout;
    
    // Call open_input_file() passing fin and the input file name as args.
    open_input_file(fin, "io/stats-season.txt");
    
    // Call open_output_file() passing fout and the output file name as args.
    open_output_file(fout, "io/stats-game.txt");
    
    // Call output_header() passing fout as the arg.
    output_header(fout);
    
    // Call compute_per_game_stats() passing fin and fout as args.
    compute_per_game_stats(fin, fout);
    
    // Close the input and output files by calling the close() functions on fin
    // and fout.
    fin.close();
    fout.close();
    
    // Return 0 from main().
    return (0);
}
