//**************************************************************************************************************
// FILE: main.cpp
//
// DESCRIPTION
// Reads the coefficients of a quadratic equation from an input file named "coeffs.txt". Then calculates the
// roots of the equation using the well-known quadratic formula. Finally, we output the equation and the roots
// to an output file named "roots.txt".
//
// This lab project is an extension to Lab Project 4, where we could not handle complex roots because we had not
// yet learned about selection/decision/if statements. For this lab, we shall use if statements to determmine
// when the roots are complex. We shall also use if statements to properly output the quadratic equation to the
// output file. For example, if the coefficients are: a = -2.1, b = -3.2, and c = -4.3, then when we output the
// equation, we shall output:
//
//     -2.1000x^2 - 3.20000x - 4.30000 = 0
//
// Recall that in Lab Project 4 we would have output:
//
//     -2.10000 + -3.2000x + -4.3000 = 0 to the output file.
//
// which is mathematically incorrect.
//
// Note: Be sure to include both AUTHOR lines if you work with a partner. If you work alone, then delete the
// AUTHOR2 line. Be sure to include your ASURITE ID in the zip archive filename and if you work with a partner,
// be sure to include both of your ASURITE ID's.
//
// AUTHOR1: your-name, your-asurite-username, your-email-address
// AUTHOR2: your-name, your-asurite-username, your-email-address
//
// COURSE INFO
// CSE100 Principles of Programming with C++, Fall 2019
// Lab Project 6   Day/Time: your-lab-date-and-time   TA: your-lab-ta's-name
//--------------------------------------------------------------------------------------------------------------
// NOTES REGARDING PASSING IFSTREAM AND OFSTREAM OBJECTS AS FUNCTION ARGUMENTS
//--------------------------------------------------------------------------------------------------------------
// Recall that when we pass fin and fout as arguments to a function, then in the function header of the function
// definition being called, we have to write an ampersand & symbol following the iftream and ofstream classes
// (or data types) because stream objects must always be passed by-reference. For example,
//
// void read_from_input_file(ifstream& fin, ...)
// {
//     ...
//     fin >> some_value;
//     ...
// }
//
// void write_to_output_file(ofstream& fout, ...)
// {
//     ...
//     fout << some stuff;
//     ...
// }
//
// int main()
// {
//     -- Define ifstream object named fin and open the text file "in.txt" for reading.
//     ifstream fin("in.txt");
//
//     -- Call input() to read some data from the input file. Note that when we call input(), we do not put the
//     -- data type of fin in the argument list: we simply just write 'fin'. We never, ever list data types in
//     -- the argument list of the function call because we are not defining variables there. On the other hand,
//     -- it is absolutely required to specify data types for the variables in the parameter list of the func-
//     -- tion header because we are defining local variables there.  
//     input(fin, ...);
//     ...
//
//     -- Remember that when we have read all of the data from an input file, we must close the file by calling
//     -- the close() function on the ifstream object 'fin'.
//     fin.close();
//
//     -- Define ofstream object named fout and open the text file "out.txt" for writing.
//     ofstream fout("out.txt");
//
//     -- Call output() to write some data to the output file. Note that when we call output(), we do not put
//     -- the data type of fout in the argument list. We just write 'fout'.
//     output(fout, ...);
//     ...
//
//     -- Remember that when we have written all of the information to the output file, we must close the file
//     -- by calling the close() function on the ofstream object 'fout'.
//     fout.close();
//     ...
// }
//
// Reference variables and pass by-reference were explained when we discussed Chapter 6 (Functions) so if you
// are still a bit fuzzy on it, now is the time to ask someone, e.g., the instructor, one of the TA's or UGTA's,
// a tutor in the the CIDSE Tutoring Center), or someone who knows C++ to explain it so you will learn it, as we
// will use this parameter passing method in future lab projects as well.
//
// In a similar manner, when we return the real and imaginary parts of a complex number from calc_complex_root()
// the values are being returned from the function in the 'real' and 'imag' parameter variables as "output
// parameters" and output parameters must always be defined so the argument in the function call is passed by-
// reference.
//
// If your program is not correctly displaying the roots of complex numbers then check that the required amper-
// sand symbol is in the proper place in that function header. Note also that in the calc_complex_root() func-
// tion header that the only variables which must be declared as double& (rather than as jus double) are 'real'
// and 'imag'.
//--------------------------------------------------------------------------------------------------------------
// PSEUDOCODE NOTES
//--------------------------------------------------------------------------------------------------------------
// 1. In my pseudocode I normally omit the data types of variables, because the data types can usually be
//    inferred from the descriptions and comments in the pseudocode and also from the way the variable is used.
//    For example, if I wrote the pseudocode statement: name <- "Betty Rubble" then it shouldbe obvious to you
//    that name must be a string object/variable. Similarly, if I write: x = 2.3 then it is clear that x must be
//    a double. When it is not clear or the type cannot be inferred, then I will specify a data type.
//
// 2. I use -- for pseudocode comments, which function in pseudocode exactly as // style comments function in
//    C++ code.
//
// 3. I use 'nothing' in pseudocode to represent the C++ reserved word 'void'.
//
// 4. <- is assignment operator.
//
// 5. Sometimes in the text of the comments or pseudocode, the name of a variable, function, or named constant
//    may be confused for a word of text. If I wish to emphasize that the word is the name of a variable, func-
//    tion, named constant, or something else, then I will write the name in single quote marks, e.g., if I wish
//    to explain that variable a is assigned the value 3, then I might write this:
//
//        Blah, blah, blah, and then a is assigned the value 3.
//
//    but some people might just think the letter 'a' is just another word in a grammatically incorrect sentence
//    and not the name of the variable. To emphasize that a is not just a word, I might write:
//
//        Blah, blah, blah, and then 'a' is assigned the value 3.
//
//    I don't do this all of the time, but you will see it some of the time.
//
// 6. I use -> following the function name and parameter list to specify the data type of the return value. For
//    example,
//
//        function some_function(int x, string y) -> double
//
//    is the first line of a function which returns a double value. For a function which does not return a
//    value, i.e., a void function, I write:
//
//        function some_function(int x, string y) -> nothing
//
//    where "nothing" means "void" as explained in Note 3.
//
//--------------------------------------------------------------------------------------------------------------
// QUADRATIC EQUATIONS, COMPLEX ROOTS, AND REFERENCES
//--------------------------------------------------------------------------------------------------------------
// This is a nice and simple reference site which discusses solving quadratic equations at:
//
// http://symbolab.com/solver/quadratic-equation-calculator/ax%5E2%2Bbx%2Bc%3D0
//
// and this site also contains a very nice calculator for finding the roots and an will plot the equation and
// show the roots. You can use this web site to help you choose coefficients a, b, and c and determine the roots
// for writing your test cases.
//
// Note that when the roots of a quadratic equation are complex numbers, they will be complex conjugates, i.e.,
// suppose that when we solve the equation (-b + ...) / 2a we get root1 = a + b'i', where a and b are real num-
// bers. Because the roots are complex conjugates, the second root will be root2 = a - b'i'.
//==============================================================================================================
//                                                     TESTING
//--------------------------------------------------------------------------------------------------------------
// TEST CASE 1
//
// DESCRIPTION
// Coefficients a and c are > 0 and b < 0 so the equation should be output as:
//
//     p(x) = 122.50000x^2 - 6.70000x + 3.00000 = 0
//
// where we note that the operator printed before b is subtraction and we actually output -b rather than b. Also
// this equation has complex roots so the program should output two complex numbers which are complex conjugates
//
// INPUT DATA
// a = 122.5  b = -6.7  c = 3
//
// EXPECTED OUTPUT
// The equation p(x) = 122.50000x^2 - 6.70000x + 3.00000 = 0 has two complex roots: root1 = 0.02735 + 0.15408i
// and root2 = 0.02735 - 0.15408i
//
// ACTUAL OUTPUT:
// The equation p(x) = 122.50000x^2 - 6.70000x + 3.00000 = 0 has two complex roots: root1 = 0.02735 + 0.15408i
// and root2 = 0.02735 - 0.15408i
//
// RESULT: PASS
//--------------------------------------------------------------------------------------------------------------
// TEST CASE 2
//
// DESCRIPTION
// <Write a description of the test case>
//
// INPUT DATA
// a = ???, b = ???, c = ???
//
// EXPECTED OUTPUT
// <Calculate the roots by hand using your calculator and then write here exactly what the output should be
// given the coefficients and roots.>
//
// ACTUAL OUTPUT
// <Copy-and-paste the contents of 'roots.txt' here>
//
// RESULT: <Write PASS or FAIL here>
//
// REMARK: Note that the actual output, given the input, must exactly match the expected output (including spaces,
// tabs, endlines, numbers being printed with 5 decimal digits, upper- and lower-case letters and so on. If the
// expected and actual outputs EXACTLY match, then the test case passed so write PASS above. If there is any
// mismatch at all--no matter how minor--then the test case failed, so write FAIL here. When the test cases
// fail, you must determine why and correct the problem. It will either be due to a bug in your program, or it
// will be due to a mistake you made in writing the test case.
//**************************************************************************************************************
#include <cmath>     // For sqrt()
#include <cstdlib>   // For exit()
#include <fstream>   // For ifstream and ofstream classes
#include <iomanip>   // For setprecision()
#include <iostream>  // For cout, fixed, and endl
#include <string>    // For string class

//==============================================================================================================
// NAMED CONSTANTS
//==============================================================================================================

// Define two named constants: ADD is an int and is equivalent to 1. SUB is an int and is equivalent to -1.
// These constants are used when calling calc_real_root(). Remember, the quadratic formula calculates the first
// root using -b + ... in the numerator of the forumla, and it calculates the second root using -b - ... in the
// numerator. So, when we want to calculate the first root, we pass ADD as the argument and when we want to
// calculate the second root, we pass SUB as the argument. This permits us to just have one function that calcu-
// lates both roots and we alter the behavior of the function by passing in this argument (which is named
// add_sub in the function header).

const int ADD = 1;   // Define ADD which is passed as the argument when calculating the root: -b + ...
???                  // Define SUB which is passed as the argument when calculating the root: -b - ...

// Define an int named constant ERR_OPEN_INPUT_FILE which is equivalent to 1.
???

// Define an int named constant ERR_OPEN_OUTPUT_FILE which is equivalent to 2.
???

// Define an int named constant ERR_NOT_QUADRATIC_EQN which is equivalent to 3.
???

using namespace std;

//==============================================================================================================
// PROTOTYPES
//==============================================================================================================

// One or more of the functions in this source code file must be declared here with a prototype because the
// function definition appears in the source code file below the point from where it is first called.
???

//==============================================================================================================
// FUNCTION DEFINITIONS
//==============================================================================================================

//--------------------------------------------------------------------------------------------------------------
// calc_complex_root(double, double, double, double, double&, double&) -> nothing
//
// This function calculates one of the two complex roots of the quadratic equation ax^2 + bx + c = 0 using the
// (-b + ...) / 2a equation. See the notes about quadratic equations and complex roots in the header comment
// block regarding the value of the second complex root.
//
// Note: make sure to write the required & when defining parameter variables 'real' and 'imag' because the
// values written to those variables in this function need to be sent back to main(). Since a C++ function may
// return only one value via a return statement, if we wish to return more than one value from a function, we
// have to resort to "passing" the return values back to the caller via the parameter list and having the caller
// pass the corresponding argument variables by-reference.
//
// PSEUDOCODE
// function calc_complex_root(input: a, b, c, disc; output: real, imag) -> nothing
//     denom <- 2a
//     real <- -b / denom
//     imag <- sqrt(-disc) / denom  -- Do you understand why we must negate disc?
// end function
//--------------------------------------------------------------------------------------------------------------
void calc_complex_root(double a, double b, double c, double disc, double& real, double& imag)
{
    double denom = 2 * a;
    real = -b / denom;
    imag = sqrt(-disc) / denom;
}

//--------------------------------------------------------------------------------------------------------------
// calc_real_root(double, double, double, double, int)
//
// This function calculates one of the real roots of the quadratic equation ax^2 + bx + c = 0. Which root we
// calculate is specified by the operation parameter. If operation is ADD, then we calculate the root involving
// the + addition operation: -b + ... On the other hand, if operation is SUB, then we calculate the root involv-
// ing the - subtraction operation: -b - ... Therefore, to calculate both real roots, this function is called
// twice from main().
//
// PSEUDOCODE
// function calc_real_root(a, b, c, disc, operation) -> double
//     denom <- 2a
//     if (operation is ADD) then
//         numer <- -b + square root(disc)
//     else
//         numer <- -b - square root(disc)
//     end if
//     return numer / denom
// end function
//--------------------------------------------------------------------------------------------------------------
???

//--------------------------------------------------------------------------------------------------------------
// discriminant(double, double, double) -> double
//
// Calculates and returns the discriminant of a quadratic equation, based on the coefficients a, b, and c.
//
// PSEUDOCODE
// Pseudcode not provided. If you need pseudocode for this function at this point in the course, then you need
// to spend more time studying programming concepts and C++ if you hope to pass.
//--------------------------------------------------------------------------------------------------------------
double discriminant(double a, double b, double c)
{
    return b * b - 4 * a * c;
}

//--------------------------------------------------------------------------------------------------------------
// open_input_file(ifstream&, string) -> nothing
//
// Try to open the file whose name is stored in 'filename' for reading. If the file is successfully opened, then
// we simply return. Otherwise, if the open() function fails, then call terminate() to end the program.
//
// Note, when we use an iftream or ofstream object such as fin or fout as the conditional expression in an if
// statement, if the stream has been successfully opened, fin or fout will evaluate to true, and if the open()
// failed, then fin or fout will evaluate to false. Therefore, to check if the fin.open() function succeeded, we
// write: if (!fin) for the conditional expression.
//
// PSEUDOCODE
// function open_input_file(fin, filename) -> nothing
//     call open() on fin passing the C-string within enclosed within the C++ string 'filename' as the arg
//     if the file could not be opened then
//         call terminate() passing "Could not open 'coeffs.txt' for reading." and ERR_OPEN_INPUT_FILE as args
//     end if
// end function
//--------------------------------------------------------------------------------------------------------------
void open_input_file(ifstream& fin, string filename) {
    fin.open(filename.c_str());
    if (!fin) {
        terminate("Could not open 'coeffs.txt' for reading", ERR_OPEN_INPUT_FILE);
    }
}

//--------------------------------------------------------------------------------------------------------------
// open_output_file(ofstream&, string) -> nothing
//
// Try to open the file whose name is stored in 'filename' for writing. If the file is successfully opened, then
// we simply return. Otherwise, if the open() function fails, then call terminate() to end the program.
//
// See the note in the header comments of open_input_file() for how to detect when the open() function fails.
//
// PSEUDOCODE
// function open_output_file(fout, filename) -> nothing
//     call open() on fout passing the C-string enclosed within the C++ string 'filename' as the arg
//     if the file could not be opened then
//         call terminate() passing "Could not open 'roots.txt' for writing." and ERR_OPEN_OUTPUT_FILE as args
//     end if
// end function
//--------------------------------------------------------------------------------------------------------------
???

//--------------------------------------------------------------------------------------------------------------
// output_complex_number(ofstream&, double, double) -> nothing
//
// Outputs a complex number in the format: <real> + <imag>i or <real> - <imag>i, where <real> and <imag> are the
// real and imaginary parts of the number. For example, if our complex number is 12.3456789897 - 5.12346789i
// then <real> is 12.3456789897 and <imag> is -5.12346789. Then the number shall be output as (remember, we are
// outputting real numbers with 5 digits after the decimal point):
//
//     12.34568 - 5.12347i
//
// Note how the 5th decimal digit is rounded up. This is the default behavior of a C++ output stream. (I think
// there is way to configure the stream to NOT round up but we don't wanna do that so its good that I don't know
// how to.)
//
// PSEUDOCODE
// function output_complex_number(fout, real, imaginary) -> nothing
//     -- For parameter real we have two cases to handle: (1) rea; is zero so we skip outputting it; or (2) real
//     -- is nonzero so we send real to fout.
//     if (real is not 0) then
//         send to fout: real
//     end if
//
//     -- Next, for parameter imag, we have three cases to handle. Note that imag cannot be 0 or we would not be
//     -- dealin with a complex number: (1) when real is zero, we send imag followed by 'i' to fout; (2) when
//     -- real is nonzero and imag is negative, we send  " - ", -imag, 'i' to fout; (3) when real is nonzero and
//     -- imag is positive, we send " + ", imag, 'i' to fout.
//     if (real is 0) then
//        send to fout: imag
//     else if (imag < 0) then
//        send to fout: " - " followed by -imag
//     else if (imaginary > 0) {
//        send to fout: " + " followed by imag
//     end if
//     send to fout: 'i'  -- I am a mathematician so it is 'i' and not 'j', bwahahaha I love driving EE's crazy :)
// end function
//--------------------------------------------------------------------------------------------------------------
???

//--------------------------------------------------------------------------------------------------------------
// output_complex_roots(ofstream&, double, double) -> nothing
//
// 1. Outputs the two complex roots of a quadratic equation.
// 2. See the note in the source code file header comment block about the complex roots being complex conjugates.
// 3. Note that fout has already been configured in main() to output real numbers with 5 decimal digits.
//
// PSEUDOCODE
// function output_complex_roots(fout, real, imag) -> nothing
//     send to fout: " has two complex roots: root1 = "
//     call output_complex_number(fout, real, imag)
//     send to fout: " and root2 = "
//     call output_complex_number(fout, real, -imag)
//     send to fout: a newline
// end function
//--------------------------------------------------------------------------------------------------------------
void output_complex_roots(ofstream& fout, double real, double imag)
{
    fout << " has two complex roots: root1 = ";
    output_complex_number(fout, real, imag);
    fout << " and root2 = ";
    output_complex_number(fout, real, -imag);
    fout << endl;
}

//--------------------------------------------------------------------------------------------------------------
// output_quad_eqn(ofstream&, double, double, double) -> nothing
//
// 1. This function outputs the formatted quadratic equation as described in the lab project document.
// 2. The output stream fout, which writes to "roots.txt", has already been opened when this function is called.
// 3. This function must not close fout: after we output the quadratic equation, we still have to output roots.
// 4. Note that fout has already been configured in main() to output real numbers with 5 decimal digits.
//
// PSEUDOCODE
// function output_quad_eqn(fout, a, b, c) returns nothing
//     send to fout: "The equation p(x) = "
//
//     -- Output the x^2 term. Note first that coefficient a cannot be 0 because if it were, then p(x) would not
//     -- be a quadratic equation and we would have terminated the program when verify_quad_eqn() was called
//     -- after we read the coefficients from the inputn file. For coefficient a, we have three cases to handle:
//     -- (1) a is 1: we just output "x^2" without printing 1.00000 in front of "x^2"; (2) a is -1: we just
//     -- output "-x^2" without printing -1.00000 in front of "x^2"; (3) Otherwise, a is not 0, not 1, and not
//     -- -1: so we just send 'a' followed by "x^2" to fout.
//     if (a is 1) then
//         send to fout: "x^2"
//     else if (a is -1) then
//         send to fout: "-x^2"
//     else
//         send to fout: a followed by "x^2"
//     end if
//
//     -- Output the x term. Unlike coefficient a, coefficients b and c can be 0 so we have to check for those
//     -- cases. For b, we have four cases to handle: (1) b is 1: we should not output b but just output " + x";
//     -- (2) b is -1: we should not output b but just output " - x"; (3) b is < 0: we should output " - "
//     -- followed by -b "x"; and (4) b is > 0: we should output " + " followed by b followed by "x".
//     if (b is 1) then
//         send to fout: " + "
//     else if (b is -1) then
//         send to fout: " - "
//     else if (b < 0) then
//         send to fout: " - " followed by -b 
//     else if (b > 0) then
//         send to fout: " + " followed by b
//     endif
//     sent to fout: "x"
//
//     -- Output the constant term. Unlike coefficient a, c can be 0. We have three cases to handle:
//     -- (1) c < 0: we should output " - " followed by -c; (2) c > 0: we should output " + " followed by c;
//     -- and (3) c is 0: we should skip outputting the plus or minus operator and the value of c, i.e., we
//     -- output nothing.
//     if (c < 0) then
//         send to fout: " - " followed by -c
//     else if (c > 0) then
//         send to fout: " + " followed by c
//     end if
//
//     -- We just output p(x) = ax^2 + bx + c, which is a homogeneous equation, so now we must output the
//     -- " = 0" part.
//     send to fout: " = 0"
// end function
//--------------------------------------------------------------------------------------------------------------
???

//--------------------------------------------------------------------------------------------------------------
// output_real_roots(ofstream&, double, double) -> nothing
//
// Outputs the two real roots of the quadratic equation. We have two cases to handle: (1) if root1 equals root2
// then we have only one repeated root, so we output the root and tell the user that this is a repeated root; 
// (2) when root1 does not equal root2, we have two different roots, so we output both roots and tell the user
// that there are two real roots.
//
// PSEUDOCODE
// function output_real_roots(fout, root1, root2) returns nothing
//     -- Check for one repeated root.
//     if (root1 is root2) then
//         send to fout: " has one repeated root = " followed by root1
//     else -- there are two real roots
//         send to fout: " has two real roots: root1 = " followed by root1
//         send to fout: " and root2 = " followed by root2
//     end if
//     send to fout: newline
// end function
//--------------------------------------------------------------------------------------------------------------
???

//--------------------------------------------------------------------------------------------------------------
// read_coeff(ifstream&) -> double
//
// Reads one coefficient from the file input stream fin and return the coefficient value as a double. Note that
// when this function is called, the input file has already been opened in main() for reading and since this
// function is called three times from main() to read the coefficients a, b, and c [in that order], you must
// not close the input file stream before returning.
//
// See your source code for Lab Project 4 regarding how to write this function.
//--------------------------------------------------------------------------------------------------------------
double read_coeff(ifstream& fin)
{
    double coeff;
    fin >> coeff;
    return coeff;
}

//--------------------------------------------------------------------------------------------------------------
// terminate(string, int) -> nothing
//
// This method is called when the program needs to end early due to something bad happening, which we cannot
// recover from. It sends 'message' to the output window, aka, the console (cout) and then calls the C++ Std Lib
// exit() function to end the program; exit() expects one argument which is the exit code that was passed as the
// argument. Note that it is a convention in C++ to return 0 from main() or call exit(0) when the program
// finishes normally without anything bad happening, and to return a non-zero value when the program terminates
// abnormally.
//
// PSEUDOCODE
// function terminate(message, exit_code) -> does not return
//     send message to cout followed by a newline
//     call exit() passing exit_code as the arg
// end function
//--------------------------------------------------------------------------------------------------------------
void terminate(string message, int exit_code)
{
    cout << message << endl;
    exit(exit_code);
}

//--------------------------------------------------------------------------------------------------------------
// verify_quad_eqn(ofstream&, double) -> nothing
//
// This function is called from main() after we have read the three coefficients and closed the input file. It
// checks that the coefficient of the x^2 term, i.e., coefficient 'a', is 0 or not 0. If 'a' is 0 then we do not
// have a quadratic equation so we will send an error message to the output file 'roots.txt' and then end the
// program with an exit code of 3 by calling terminate().
//
// PSEUDOCODE
// function verify_quad_eqn(fout, a) returns nothing
//     if (a is 0) then
//         close fout
//         string message = "The coefficient for the x^2 term is zero so this is not a quadratic equation.\n"
//         message = message + "Please change the value of this coefficient and try again.\n"
//         message = message + "Exiting the program now.\n"
//         call terminate() passing message and 3 as the arguments
//     end if
// end function
//--------------------------------------------------------------------------------------------------------------
void verify_quad_eqn(ofstream& fout, double a) {
    if (a == 0) {
        fout.close();
        string message = "The coefficient for the x^2 term is zero so this is not a quadratic equation.\n";
        message = message + "Please change the value of this coefficient and try again.\n";
        message = message + "Exiting the program now.\n";
        terminate(message, ERR_NOT_QUADRATIC_EQN);
    }
}

//--------------------------------------------------------------------------------------------------------------
// main() -> int
//
// PSEUDOCODE
// function main() -> 0
//     -- Read the coefficients a, b, and c from "coeffs.txt".
//     define an input file stream object named fin
//     call open_input_file() to open 'coeffs.txt' for reading
//     a <- call read_coeff() to read the coefficient a -- define local var 'a' as a double
//     b <- call read_coeff() to read the coefficient b -- define local var 'b' as a double
//     c <- call read_coeff() to read the coefficient c -- define local var 'c' as a double
//     close the input file
//
//     -- Open the output file for writing.
//     define an output file stream object named fout
//     call open_output_file() to open 'roots.txt' for writing
//
//     -- Configure the format of real numbers sent to fout so they are output in fixed notation with 5 digits
//     -- after the decimal point.
//     configure fout ...
//
//     -- Verify that we have a quadratic equation by calling verify_quad_eqn() passing fout and coeff a as
//     -- arguments. If coefficient a is 0, then our "quadratic equation" is actually a line so verify_quad_
//     -- eqn() will send an error message to the output file, close the output file, and then end the program
//     -- by calling terminate().
//     call verify_quad_eqn(fout, a)
//
//     -- If we return from verify_quad_eqn() then coefficient a is not 0 and we can now solve the equation.
//     -- First, we send the formatted quadratic equation to the output file by calling output_quad_eqn() and
//     -- passing fout and the coefficients a, b, and c as the arguments.
//     call output_quad_eqn(fout, a, b, c)
//
//     -- In Lab Project 4, we calculated the value of the discriminant twice when we called discriminant() from
//     -- both calc_root1() and calc_root2(). This was wasteful because we could simply calculate the value once,
//     -- save it in a variable, and then use the value stored in the variable when calculating the two roots.
//     -- Calculate the discriminant of the equation with coefficients a, b, and c, by calling discriminant()
//     -- and passing a, b, and c as the arguments. Assign the return value to a defined double variable named
//     -- 'disc'. Later, when we calculate the roots, we shall pass 'disc' as a function argument when calculat-
//     -- ing the roots because the function needs the value of the discriminant in order to do its job.
//     disc <- call discriminant(a, b, c)
//
//     -- If the discriminant is 0 then we have only one (repeated) root. Call calc_real_root() and store the
//     -- return value in defined local variable 'root1'. Then call output_real_roots() to send the repeated
//     -- root to the output file.
//     if (disc is 0) then
//         root1 <- call calc_real_root(a, b, c, disc, ADD) -- Define root1 as a double var
//         call output_real_roots(fout, root1, root1)

//     -- Else if the discriminant is greater than 0 then we have two real roots so call calc_real_root() twice
//     -- to get the two roots and then call output_real_roots() to display the two roots.
//     else if (disc > 0) then
//         root1 <- call calc_real_root(a, b, c, disc, ADD) -- Define root1 as a double var
//         root2 <- call calc_real_root(a, b, c, disc, SUB) -- Define root2 as a double var
//         output_real_roots(fout, root1, root2)
//
//     -- Else, if we reach this point, the discriminant is less than 0 indicating that we have two complex
//     -- roots. Call calc_complex_root() once to obtain the complex root that comes from calculating (-b + ...).
//     -- This root will be <real> + <imag>i. Because complex roots are complex conjugates, the second root will
//     -- be <real> - <imag>i. Remember that real and imag are output parameters from calc_complex_root(), i.e.,
//     -- when the function is called those variables may contain garbage but they will contain the real and
//     -- imaginary parts of one of the complex roots when the function returns.
//     else
//         define real and imag as double variables
//         call calc_complex_root(a, b, c, disc, real, imag)
//         output_complex_roots(fout, real, imag)
//     end if
//
//     close the file output stream
//
//     return 0 to indicate the program finished successfully
// end function
//--------------------------------------------------------------------------------------------------------------
???