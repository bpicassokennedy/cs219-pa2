# Machine Learning Simulator - Project 2 
## Program Description 
This project is a **machine learning simulator** that can perform various arithmetic *and* logical operations. It reads from an input file (*programming-project-2.txt*) and performs the specified operation on the given hexadecimal operands (operand1, operand2) or just sole operand depending on the type of operation specified (ex. NOT). Following, the program then displays the requested operation, given operand(s), and result of the operation to the terminal. Additionally, this program also checks if the operation includes an (S) suffic to determine if the flags (N and Z) should be updated. If no update is required, the flags default to zero. 
## How to Compile the Program 
In order to compile the program, first make sure that the makefile and source files (main.cpp, helpers.cpp, helpers.h) are all in the same directory. Then run the make command in your terminal. This command will compile and create an executable named proj2. After successfull compilation you can run the program using **./proj2** where the requested operations will be presented in the terminal.
## Code's Working Process 
- **Read and Parse Input:** First, the program needs to read and parse the input given from the programming-project-2.txt file. To do so we check if the requested file is present in the directory and attempt to open the file from there. If there is no file, the program returns 1 to demonstrate an error. If there is no error returned, then the readData function is called. In readData, the file is parsed and split into operation, operand1, and operand2 then each stored respectively into their own arrays. The function then returns the number of lines in the file to be used in performing operations and loops later on.
- **Performing Operations:** Following, we then need to run the specified operation on the given operands. To do so, this program calls runOperations which determines which operation will be carried out checking the string stored in the operations array (looping through the entire array using the integer value returned from readData). 
- **Updating Flags:** The updateFlags function is responsible for setting two flags, N (negative) and Z (zero) after an operation has been performed. updateFlags is called in runOperations, and are passed the operation, result of the operation, and a boolean indicator whether the result is signed (ASR) or not. In the function, if the operation string ends in an 'S' then the flags are updated respectively. If there is no 'S' indicating that we are to update the flags, the flags return to their default state (N = 0, Z = 0).  
- **Displaying Output:** After the result of the operation has been stored, and the flags have been updated; the terminal displays to the user the operation, operands, and results of the operation. As well as the flag states! Again, defaulting back to 0 if there is no 'S' suffix. Displaying these results takes place in the displayOperations function, which is called in runOperations!
## Result
The output for the given operations in the *programming-project-2.txt* file are all correct, and the flags are updated how and when expected (again returning to 0 when status flags are not being updated)! 

### Command Operations: 
**ADD(S):** Adds operand1 and operand2 together. The result is stored, and if the (S) suffix is present the flags (N and Z) are updated based on the result. 

**AND(S):** Performs a bitwise AND operation between operand1 and operand2. The result has bits set only where *both* operands have corresponding bits set to 1. If the (S) suffix is present the flags (N and Z) are updated based on the result. 

**ASR(S):** Performs an arithmetic shift right on operand1 by a specified number of bits, given to us by operand2. Preserving the sign of the original number, as opposed to filling the left most bit with zeroes. If (S) suffix is present the flags (N and Z) are updated based on the result.

**LSR(S):** Performs a logical shift right on operand1 by a specified number of bits, given to us by operand2. Filling the most significant bit (MSB) with zeros as shifted. If the (S) suffix is present the flags (N and Z) are updated based on the result.

**LSL(S):** Performs a logical shift left on operand1, moving bits to the left and filling the MSB with zeros a set amount of times based on operand2. If the (S) suffix is present the flags (N and Z) are updated based on the result. 

**NOT(S):** Performs a bitwise NOT operation to operand1, inverting each bit in the given operand. If a bit is 0 -> 1, 1 -> 0. If the (S) suffix is present the flags (N and Z) are updated based on the result. 

**ORR(S):** Performs a bitwise OR operation between operand1 and operand2. If either operand has a corresponding bit set to 1, the corresponding result bit is set to 1 as well. If the (S) suffix is present the flags (N and Z) are updated based on the result. 

**SUB(S):** Subtracts operand2 from operand1 and stores the result. If the (S) suffix is present the flags (N and Z) are updated based on the result. 

**XOR(S):** Performs a bitwise XOR operation between operand1 and operand2, setting bits to 1 where the operands have differing bits. If the (S) suffix is present the flags (N and Z) are updated based on the result. 

### Change in Status Flag Values:
**Negative Flag:** Set to 1 (true) if the result of the operation is negative in the case of signed numbers, or if the MSB is 1 in the case for unsigned numbers. Otherwise set to 0 (false).

**Zero Flag:** Set to 1 (true) if the result of the operation (signed or unsigned) is equal to zero. Otherwise set to 0 (false).