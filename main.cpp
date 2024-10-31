// 
//  Programmer: Bella Picasso-Kennedy 
//  Date Completed: October 30, 2024
//  Version: 1.0 (CS219 Project 2)
//  Brief Program Description: This program reads in a file of operations and operands, performs the operations, and outputs the results! However, the 
//                             program can currently only perform unsigned addition, and detect if there is an unsigned overflow. Program has been written   //                             in consideration of future extension (implementation of additional operations).
//

#include "helpers.h"

int main(){
    ifstream inFile("programming-project-2.txt");
    if(!inFile){
        cout << "error opening file!" << endl;
        return 1;
    }
  
    static const int maxCount = 50;
    string operations[maxCount];
    uint32_t operand1[maxCount]; //will need to case to signed when and if needed
    uint32_t operand2[maxCount];
  
    int operationCount = readData(inFile, operations, operand1, operand2, maxCount);
  
    runOperations(operations, operand1, operand2, operationCount);
  
    return 0;
}