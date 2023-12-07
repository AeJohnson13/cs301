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







int main()
{
	string prompt {"Please enter an operation using reverse polish notation"};	
	cout << prompt << endl;
	cout << "(push enter on empty line or hit ctrl-d to stop running)" << endl;
	while(true)
	{ 
		string line;
		getline(cin, line);	
		if(line.find_first_not_of(' ')!= std::string::npos)
		{ 	
			bool broke = false;
			float result = 0;
			try 
			{
				result = rpnAssess(line);
			}
			catch(const std::invalid_argument& e) 
			{ 
					broke = true;
				     	cout << "\"" << line << "\"" << endl << e.what() << endl << prompt << endl;
			} 
			catch(const std::out_of_range& e)
			{
					broke = true;
					cout << "\"" << line << "\"" << endl << " is out of range " <<endl << prompt << endl;
			} 
			if(broke == false)
			{ 
				cout << setprecision(6) << "result = " << result << endl << prompt << endl;

			} 
					
		}
		else
		{ 
		break;
		} 
	} 	
	return 0; 
} 





