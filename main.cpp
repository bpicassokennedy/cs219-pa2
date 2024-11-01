// 
//  Programmer: Bella Picasso-Kennedy 
//  Date Completed: October 31, 2024
//  Version: 1.0 (CS219 Project 2)
//  Brief Program Description: This program reads in a file of operations and operands, performs the operations, and outputs the results! The program is currently able to perform 
//                             several arithmetic and logical operations, while also updating the status flags when and if called for. 
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
    uint32_t operand1[maxCount]; //will need to cast to signed when and if needed
    uint32_t operand2[maxCount];
  
    int operationCount = readData(inFile, operations, operand1, operand2, maxCount);
  
    runOperations(operations, operand1, operand2, operationCount);
  
    return 0;
}