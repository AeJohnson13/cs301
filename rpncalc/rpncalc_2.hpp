//rpncalc.hpp
//Alexander E Johnson
//Started: 2023-11-12
//Updated: 2023-11-tbd
//
//For CS301 Fall 2023
//header file for rpncalc



#ifndef FILE_RPNCALC_2_HPP_INCLUDED
#define FILE_RPNCALC_2_HPP_INCLUDED

#include <string>
//for std::string
//for std::stof
#include <iostream>
//for std::cerr
#include <sstream> 
//for std::stringstream
#include <stack>
//for std::stack
#include <stdexcept>
//for std::invalid_argument



	
inline
int evalstring(const std::string & myString)
{

	try
	{ 
		std::stof(myString);
	//	std::cerr << "found float" << std::endl;
		return 1;   //this one represents a valid float value;
	} 
	catch(std::invalid_argument & e)
	{
		if(myString.size() != 1) 
		{
		       throw std::invalid_argument("contains invalid char");	
		} 
	       	char token = myString.front();
		if(token == '+' || token == '-' || token == '*' || token == '/')
		{ 
	//	std::cerr << "found char" << std::endl;
			return 2; //in this context the two will represent a valid 
		} 	
		else
		{ 
			throw std::invalid_argument("contains invalid char"); 
		} 
	}
       return 3; //this shouldn't happen 	
} 	

extern "C" float assembleval(float op1, float op2, char op); 


float rpnAssess(const std::string & line) 
{
	istringstream lineStream(line);
	string opertor;
	std::stack<float> numStack;
	while(lineStream >> opertor)
	{ 
		if(evalstring(opertor) == 1)
		{ 
			numStack.push(std::stof(opertor));
		} 	
		else if(evalstring(opertor) == 2 && numStack.size() >= 2)
		{ 
			float num2 = numStack.top();
			numStack.pop(); 
			float num1 = numStack.top();
			numStack.pop(); 
			float result = assembleval(num1, num2, opertor.front());
		        numStack.push(result); 	
		}
	       	else
		{ 
		throw std::invalid_argument("is an invalid expression");
		} 	
	} 	

	if(numStack.size() == 1) 
	{ 
		return numStack.top();
	} 
	else
	{ 
	throw std::invalid_argument("is an invalid expression");
	}
} 	
#endif //#ifndef FILE_RPNCALC_2_HPP_INCLUDED	
	
	
