//rpncalc.hpp
//Alexander E Johnson
//Started: 2023-11-12
//Updated: 2023-11-tbd
//
//For CS301 Fall 2023
//header file for rpncalc

#ifndef FILE_RPNCALC_HPP_INCLUDED
#define FILE_RPNCALC_HPP_INCLUDED


#include <iterator> 
//for std::advance
#include <vector>
//for std::vector
#include <string>
//for std::string
//for std::stof
#include <list>
//for std::list
#include <iostream>
//for std::cerr







	
//this function checks the type of the given string, by checking if std::stof throws,
//this will be done differently in the final program 
int evalstring(std::string & myString)
{

	try
	{ 
		std::stof(myString);
		return 1;   //this one represents a valid float value;
	} 
	catch(std::invalid_argument & e)
	{
	       	char token = myString.front();
		if(token == '+' || token == '-' || token == '*' || token == '/')
		{ 
			return 2; //in this context the two will represent a valid 
		} 	
		else
		{
			std::cerr << token << " is not a valid input" << std::endl;
			return 3; //indicates failure to find valid input
		} 
	}
       return 3; //this shouldn't happen 	
} 	





//dummy - this will be done in assembly in the near future, due to time constraints,
// aka calc2 exam tommorrow   
float assembleval(float op1, float op2, char op)
{ 
	if(op == '+')
	{ 
		return op1+op2;
	} 
	else if(op == '-')
	{ 
		return op1-op2;
	} 
	else if(op == '*')
	{
		return op1*op2;
	} 
	else if(op == '/')
	{ 
		return op1/op2;
	}
	return 0;
} 

//extern "C" float assembleval(float op1, float op2, char op); 




// this function searches a linked list of strings for a section of rpn notation that can be evaluated, num num operator,
// it then passes that section to function assembleval that returns the resulting number, it then replaces the three operands 
// with just the resultant number
//
//if an invalid operand is entered an appropriate error message will occur
//however if a invalid rpn expression is entered but with appropriate characters the program will crash
//i will fix this at some point
//
float rpnAssess(std::list<std::string> & inputstream) 
{
	
	
		std::vector<int> goalvec{1, 1, 2}; 	
		while(inputstream.size() != 1)
		{ 

			for(auto iter = inputstream.begin(); iter != inputstream.end(); iter++)	 
			{ 
		 		std::vector<int> typevec = {0, 0, 0}; 
				auto iter1 = iter;
				typevec[0] = evalstring(*iter);
				std::advance(iter, 1);
				auto iter2 = iter;
	       	 		typevec[1] = evalstring(*iter);
				std::advance(iter, 1);
				auto iter3 = iter; 
				typevec[2] = evalstring(*iter); 
				if (typevec[0] == goalvec[0] && typevec[1] == goalvec[1] && typevec[2] == goalvec[2]) 
				{ 
					float operand_1 = std::stof(*iter1);
					float operand_2 =  std::stof(*iter2); 
					char operato_r = iter3->front();
					float result = assembleval(operand_1,operand_2,operato_r);
					auto resultstring = std::to_string(result);
					inputstream.insert(iter1, resultstring);
					std::advance(iter3, 1);	
					inputstream.erase(iter1, iter3);
					if(inputstream.size() == 1) 
					{ 
						return std::stof(inputstream.front());
					}
				       break;	
				}
				else if(typevec[0] == 3 || typevec[1] == 3 || typevec[2] == 3)
				{ 
					std::cerr << "found invalid character" << std::endl;
					return 0; 
				} 

				else
				{ 
				iter = iter1; 
				} 	
			}

		}  

} 
	
	
	
#endif // #ifndef FILE_RPNCALC_HPP_INCLUDED
