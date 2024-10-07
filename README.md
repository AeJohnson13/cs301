# RPN Calc 

## Purpose
  RPN Calc implements a simple reverse polish notation calculator within a commmand line interface. It does this while also fullfilling the additional requirement of utilizing hand written x86 Assembly language. Numbers within the equation are stored as c++ floats, c++ std:string, and x86 QWORD, so some precission is lost in conversion, so the final `std::cout` will only display 6 digits of precision.
## Implementation 
* RPN Calc is implemented primarily in C++ with some additional x86 Assembly performing simple arithmetic operation. It operates in `white true` loop that will run until the user inputs an empty line, the specific logic is detailed in the below diagram. 
![Test](assets/RPN Assess.pdf)


* The majority of the work is done by the function RPN assess, which when given a string that contains a valid RPN notation equation will return the resulting number.

