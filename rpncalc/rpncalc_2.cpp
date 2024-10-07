//rpncalc_2.cpp
//Alexander E Johnson
//Started: 2023-11-12
//Updated: 2023-12-03
//
//For CS301 Fall 2023
//Cpp functionallity for rpncalc


#include <iostream> 
using std::cout;
using std::cin; 
using std::endl;
#include <string> 
using std::string;
using std::stof;
#include <list> 
using std::list; 
#include <sstream>
using std::istringstream;
#include <iomanip>
using std::setprecision;
#include "rpncalc_2.hpp"
#include <chrono>





// main function for rnpcalc_2
// takes an expression in reverse polish notation and returns the result
// will continue to take expressions until an empty line is given or ctrl-d
//
int main()
{
	string prompt {"Please enter an operation using reverse polish notation"}; // prompt for user input	
	cout << prompt << endl;  //initial user input prompt
	cout << "(push enter on empty line or hit ctrl-d to stop running)" << endl; // single time prompt showing how to end program

	while(true) // main loop 
	{ 
		string line;  // input line
		getline(cin, line); // reads line from user	
		if(line.find_first_not_of(' ')!= std::string::npos)  // checks if given line was empty
		{ 	
			bool broke = false; // stores whether an error has occured
			float result = 0; // declare float outside of try block
			try 
			{
				auto t1 = std::chrono::high_resolution_clock::now();
				result = rpnAssess(line); // evaluates the inputed line
				auto t2 = std::chrono::high_resolution_clock::now();
				std::chrono::duration<double, std::milli> ms_double = t2 - t1;
				std::cout << ms_double.count() << "ms" << endl;
 
			}
			catch(const std::invalid_argument& e) // tells user if the expression wasn't evaluatable or has an invalid character
			{ 
					broke = true;
				     	cout << "\"" << line << "\"" << endl << e.what() << endl << prompt << endl;
			} 
			catch(const std::out_of_range& e) // tells user if they went over the floating point maximum
			{
					broke = true;
					cout << "\"" << line << "\"" << endl << " is out of range " <<endl << prompt << endl;
			} 
			if(broke == false) // outputs the result if no errors were thrown 
			{
				cout << setprecision(6) << "result = " << result << endl << prompt << endl;

			} 
					
		}
		else
		{ 
		break; // leave loop if empty line given 
		} 
	} 	
	return 0; 
} 





