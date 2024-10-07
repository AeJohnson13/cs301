# RPN Calc 

## Purpose
  RPN Calc implements a simple reverse polish notation calculator within a commmand line interface. It does this while also fullfilling the additional requirement of utilizing hand written x86 Assembly language. Numbers within the equation are stored as c++ floats, c++ std:string, and x86 QWORD, so some precission is lost in conversion, so the final `std::cout` will only display 6 digits of precision.
## Implementation 
* RPN Calc is implemented primarily in C++ with some additional x86 Assembly performing simple arithmetic operation. It operates in `white true` loop that will run until the user inputs an empty line. The specific logic that occurs within the loop is detailed in the below diagram. 


![RPN Calc](https://github.com/user-attachments/assets/9888b84c-9dc7-4c9d-b6ba-670d3af7c4f6)

* The majority of the work is done by the function RPN assess, which when given a string that contains a valid RPN notation equation will return the resulting number. The details of which are displayed in the diagram below. 

![RPN Assess](https://github.com/user-attachments/assets/274f4db0-29b4-4dce-b064-4c96f7f05295)

* The step "is element a number" takes place within `evalstring` which uses `std::stof()` to see if the given string can possibly be represented as a float.
* If `std::stof()` does throw an exception then that is fine, because it takes place within a try block and so a catch block will see if the string is one of the four basic arithmetic operators.
* Within the step "Pop two elements and apply given operator" the application of the two operators takes place within an X86 assembly file. The file uses the integer representation of the operator character in order to find which arithmetic operation to use within a table of functions. 

## How to Run
To run RPN calc, follow these steps: 
```shell
# Open a terminal on an X86 machine

# Ensure Git is installed
# Visit https://git-scm.com to download and install console Git if not already installed

# Clone the repository 
git clone https://github.com/AeJohnson13/cs301.git

# GO to the rpncalc directory
cd rpncalc

# compile and run using the included Makefile
Make run
```
