# RPN Calc 

## Purpose
  RPN Calc implements a simple reverse polish notation calculator within a commmand line interface. It does this while also fullfilling the additional requirement of utilizing hand written x86 Assembly language. Numbers within the equation are stored as c++ floats, c++ std:string, and x86 QWORD, so some precission is lost in conversion, so the final `std::cout` will only display 6 digits of precision.
## Implementation 
* RPN Calc is implemented primarily in C++ with some additional x86 Assembly performing simple arithmetic operation. It operates in `white true` loop that will run until the user inputs an empty line, the specific logic is detailed in the below diagram. 
![RPN Assess](https://github.com/user-attachments/assets/539f1ba2-9445-47d7-b75d-1a81d49da89d)


* The majority of the work is done by the function RPN assess, which when given a string that contains a valid RPN notation equation will return the resulting number.
![RPN Calc](https://github.com/user-attachments/assets/5a7e4246-3623-4762-ba31-8515d9d9a011)

<p align="center">
  <a href="https://git.io/typing-svg"><img src="https://github.com/user-attachments/assets/5a7e4246-3623-4762-ba31-8515d9d9a011"/></a>
</p>
