//
//    Filename: helpers.h; compiled into helpers.o with helpers.cpp
//    Programmer: Bella Picasso-Kennedy
//    Purpose: To store all of the helper functions called by main in main.cpp
//  

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip> //hex formatting 
#include <cstdint> //uint32_t and int32_t

using namespace std;

int readData(ifstream& ifile, string operations[], uint32_t operand1[], uint32_t operand2[], int max);
void updateFlags(string operation, uint32_t result);
void displayOperations(string operation, uint32_t operand1, uint32_t operand2, uint32_t result);
void runOperations(string operations[], uint32_t operand1[], uint32_t operand2[], int count);