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


// evalstring
// Given string, returns 1 if string can be converted into a float, 
// else returns 2 if the character is + - * or /, otherwise throws 
// std::invalid_argument
// Basic Guarantee	
int evalstring(const std::string & myString)
{

	try
	{ 
		std::stof(myString);
		return 1;   //this 1 represents a valid float value;
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
			return 2; // in this context the two will represent a valid operator
		} 	
		else
		{ 
			throw std::invalid_argument("contains invalid char"); 
		} 
	}
} 	


// assembleval declaration
// 
// implemented in rpn.asm
//
// Given two floats and an operator char
// return the result of the two floats
// Pre: 
// 	char is + - * or / 
// Strong Guarantee 
extern "C" float assembleval(float op1, 
			     float op2, 
			     char op); 



// rpnAssess 
// given a string that contains a valid reverse polish notation 
// expression returns the result of the expression, will throw 
// std::invalid argument if an invalid expression is given
// Basic Guarantee
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
	
	
