//rpncalc.cpp
//Alexander E Johnson
//Started: 2023-11-12
//Updated: 2023-11-tbd
//
//For CS301 Fall 2023
//Cpp functionallity for rpncalc


#include <iostream> 
using std::cout;
using std::cin; 
using std::endl;
#include <string> 
using std::string;
#include <list> 
using std::list; 
#include "rpncalc.hpp"











//As of right now due to the storage of floats as strings the precision is lost,
//the final product will not have this issue
//
//main stores a std::list of strings that are supposed to be either floats or chars + - * / 
int main()
{
	std::cout << "Please enter an operation using reverse polish notation" << std::endl; 
	std::cout << "(values may be up to 32 bit floats)" << std::endl;                       
	
	string token; 
	list<string> inputstream {};
	while(cin >> token) 
	{ 	
		inputstream.push_back(token); 
	
	}
	cout << rpnAssess(inputstream) << endl;
	
	return 0; 
} 





