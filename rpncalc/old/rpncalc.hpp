//rpncalc.hpp
//Alexander E Johnson
//Started: 2023-11-12
//Updated: 2023-11-tbd
//
//For CS301 Fall 2023
//header file for rpncalc

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
inline
int evalstring(std::string & myString)
{

	try
	{
		std::stof(myString);
	//	std::cerr << "found float" << std::endl;
		return 1;   //this one represents a valid float value;
	}
	catch(std::invalid_argument & e)
	{
	       	char token = myString.front();
		if(token == '+' || token == '-' || token == '*' || token == '/')
		{
	//	std::cerr << "found char" << std::endl;
			return 2; //in this context the two will represent a valid
		}
		else
		{
			throw;
		}
	}
       return 3; //this shouldn't happen
}





// extern "C" float assembleval(float op1, float op2, int op); 
//dummy
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


float rpnAssess(std::list<std::string> & inputstream)
{


		std::vector<int> goalvec{1, 1, 2};
		while(inputstream.size() != 1)
		{
			for(auto iter = inputstream.begin(); iter != inputstream.end(); iter++)
			{
				if(inputstream.size() == 1) { break;}
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
					break;
				}
				else
				{
				iter = iter1;
				}
			}
		}

	if(inputstream.size() == 1)     //base case
	{
	return std::stof(inputstream.front());
	}
}



