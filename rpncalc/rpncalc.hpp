//rpncalc.hpp
//Alexander E Johnson
//Started: 2023-11-12
//Updated: 2023-11-tbd
//
//For CS301 Fall 2023
//header file for rpncalc

#include <iterator> 
//for std::advance



float rpnAssess(std::list<std::string> & inputstream) 
{ 
	if(inputstream.size() == 1)     //base case 
	{ 
	return inputstream.front();
	} 
	
	
	else 				//recursive case
	{		
		std::vector<int> typevec{0, 0, 0}; 
		std::vector<int> goalvec{2, 2, 3};
		for (auto iter = inputstream.begin(); it != inputstream.end(); iter++)	 
		{ 
			iter1 = iter;
			typvec[0] = evalstring(*iter);
			std::advance(iter, 1);
			iter2 = iter;
	       	 	typvec[1] = evalstring(*iter);
			std::advance(iter, 1);
			iter3 = iter; 
			typvec[2] = evalstring(*iter); 
		
			if (typevec[0] == goalvec[0] && typevec[1] == goalvec[1] && typevec[2] == goalvec[2]) 
			{ 
				float operand_1 = *iter1;
				float operand_2 =  *iter2; 
				char operato_r = *iter3;
				float result = assembleval(operand_1,operand_2,operato_r);
				inputstream.inserter(iter1, result);
				inputstream.erase(iter1, iter3);
				rpnAssess(inputstream); //recursive call 
			} 
	
			}
			else 
			{ 
				typevec = {0, 0, 0}; 
			} 
		}
	}	
} 
	
	
	
	
	
int evalstring(std::string & myString)
{

	try
	{ 
		stof(inputstream);
		return 1;   //this one represents a valid float value;
	} 
	catch(std::invalid_argument & e)
	{ 
		if(token == '+' || token == '-' || token == '*' || token = '/')
		{ 
			return 2; //in this context the two will represent a valid 
		} 	
		else
		{ 
			throw; 
		} 
	}
       return 3; //this shouldn't happen 	
} 	












} 

