//******************************************************************************
// FILE: main.cpp
//
// DESCRIPTION
// This program reads data on energy consumption from a csv file and parses it 
// to simpler format. The program iterates through the data to find the city 
// with the largest energy consumption
//
// LEARNING OBJECTIVES
// After completing this lab project, the student will be able to:
//
// 1. Use 1D/2D Arrays
// 2. Use Nested for and while loops
//
// Note: Be sure to include both AUTHOR lines if you work with a partner. If you
// work alone, then delete the AUTHOR2 line. Be sure to include your ASURITE ID
// in the zip archive filename and if you work with a partner, be sure to in-
// clude both of your ASURITE ID's.
//
// AUTHOR1: Colton Acosta, cacost12, 1214326892, cacost12@asu.edu 
//
// COURSE INFO
// CSE100 Principles of Programming with C++, Fall 2020
// Lab Project 9   Day/Time: Th 9:00-9:50 AM TA: Neha Rajendra Vadnere
//******************************************************************************

// Include all libraries needed 
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//==============================================================================
// NAMED CONSTANTS
//
// Students: Define named constants in this section.
//==============================================================================
// Define an int named constant rows which is equivalent to 51.
const int ROWS = 51;

// Define an int named constant columns which is equivalent to 14.
const int COLUMNS = 14;

// Define an int named constant index_energy_class which is equivalent to 1.
const int INDEX_ENERGY_CLASS = 1;

// Define an int named constant index_city which is equivalent to 4.
const int INDEX_CITY = 4;

// Define an int named constant index_zipcode which is equivalent to 6.
const int INDEX_ZIPCODE = 6;

// Define an int named constant index_value which is equivalent to 11.
const int INDEX_VALUE = 11;

//==============================================================================
// FUNCTION PROTOTYPES
//
// Students: Some of the functions may require prototypes. For those that do,
// write the prototype in this section.
//==============================================================================
void terminate (string message);

//------------------------------------------------------------------------------
// FUNCTION open_input_file(ifstream&, string) -> nothing
//
// See the comments in the function header of this function in main.cpp of Lab
// Project 6 or 7 for more information on how this function operates.
//------------------------------------------------------------------------------
void open_input_file(ifstream& fin, string filename)
{
    // Try to open the file whose name is stored in 'filename' for reading.
    fin.open(filename.c_str());
    
    // If the file could not be opened, then call terminate() to display the
    // error message specified in the lab project document.
    if (!fin) {
        string message = "Could not open 'energy_dataset.csv' for reading.";
        terminate(message);
    }
}

// ------------------------------------------------------------------------------
// FUNCTION terminate(string) -> nothing
//
// PSEUDOCODE
// function terminate(message) -> does not return
//     send message to cout followed by a newline
//     call exit() passing 1 as the arg
// end function
//------------------------------------------------------------------------------
void terminate(string message)
{
    cout << message << endl;
    exit(1);
}

// ------------------------------------------------------------------------------
// FUNCTION output_header() -> nothing
// It will print the first two rows of the table containing the header titles 
// and a separator line (------)
//
// PSEUDOCODE
// function output_header() -> does not return
//      output the header as shown in the pdf. Between each title you should 
//      include a setw() of 20 characters.
//      output "-" 80 times
//      output a new line.
// end function
// -----------------------------------------------------------------------------
void output_header(){

    // Table Headers
    cout << setw(20) << right << "Class";
    cout << setw(20) << right << "ZIP City";
    cout << setw(20) << right << "ZIP Code"; 
    cout << setw(20) << right << "Value "; 
    cout << endl;
    
    // Dashes 
    for(int i = 0; i < 80; ++i){
        cout << "-";
    }
    cout << endl;
}


// -----------------------------------------------------------------------------
// FUNCTION output_table(const string) -> nothing
// Prints the body of the table as can be seen in the pdf.
//
// PSEUDOCODE
// function output_table(const string (&content)[rows][columns]) -> does not 
// return
//      for loop (from i = 1 to rows, incrementing)
//          for loop (from j = 1 to columns, incrementing)
//              if j is index_energy_class or j is index_city or j is 
//              index_zipcode or j is index_value
//                  output content[i][j] with a setw() of 20 characters
//              end if
//          end for loop
//          output new line
//      end for loop
// end function
// -----------------------------------------------------------------------------
void output_table(const string)

// ------------------------------------------------------------------------------
// FUNCTION find_largest_city(const string) -> nothing
// It will traverse the array in order to find the city which is consuming the 
// most energy. After that it will print it out in the terminal.
//
// Note: convert-to-int() from string to int you could use stoi(). Example:
// string year = "2021";
// int current_year = stoi(year);
//
// PSEUDOCODE
// function find_largest_city(const string (&content)[rows][columns]) -> does not return
//      create a variable type int named largest equal to convert-to-int( content[1][index_value] )
//      create a variable type int named index equal to 1
//      for loop (from int i=1 to rows, incrementing)
//          if largest less than stoi(content[i][index_value])
//              largest equal to stoi(content[i][index_value])
//              index equal to i
//          end if
//      end for
//      output "\nThe city with the most consumption was: " , content[index][index_city ] , " with an energy use of " , content[index][index_value  ] , " MWh.\n\n"
// end function
// ------------------------------------------------------------------------------
??

// ------------------------------------------------------------------------------
// FUNCTION main() -> int
//
// PSEUDOCODE
// -within the code-
// ------------------------------------------------------------------------------
int main() {
    // define ifstream input file named fin
	??
    //call open_input_file passing fin and "energy_dataset.csv" as arguments.
    ??

    // -Now we will read the csv file and parse the information into a 2D array
    // create a variable named line type string
    ??

    // create a 2D string array named content with size rows*columns
    ??

    // define a variable type int named i and equal to 0
	??
	
    // Read every line from the input file
	while(getline (fin, line)){
        // create a stringstream named s 
		stringstream s (line);
        // create a variable named value type string
		??
        // define a variable type int named j and equal to 0
        ??
        // parse every data separated by a comma (,)
		while (getline (s, value, ',')){
            //content[i][j] equal to value
		 	??
            // increment 1 to j
			??
		}
        // increment 1 to i
	    ??
	}

    // After parsing the information, now it is time to display the output in the terminal
    // call the function output_header();
    ??

    // call the function output_table() with the 2D array content as argument
    ??

    // call the function find_largest_city() with the 2D array content as argument
    ??

    // output from where did you retrieve the information as explained in the pdf.
    ??

    return 0;
}
