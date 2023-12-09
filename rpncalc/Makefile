run: calc
	./calc
calc: rpncalc_2.cpp rpn.o rpncalc_2.hpp
	g++ -std=c++17 -no-pie -o calc rpncalc_2.cpp rpn.o
rpn.o: rpn.asm
	nasm -f elf64 -w+all -w+error rpn.asm
