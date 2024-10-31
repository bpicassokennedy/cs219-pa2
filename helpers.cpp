#include "helpers.h"

//reading and parsing input from file, storing the operation, operand1, and operand2 into designated arrays while also keeping track of the number of lines //in the file (value being returned)

int readData(ifstream& ifile, string operations[], uint32_t operand1[], uint32_t operand2[], int max){
  string line;
  int count = 0;
  while(ifile.good() && count < max){
    getline(ifile, line);
    stringstream ss(line);
    ss >> operations[count];
    ss >> hex >> operand1[count] >> operand2[count];   
    count++;
  }  
  ifile.close();
  return count;
}

//detecting unsigned overflow by passing through the operands and checking if either of the operands are less than the result. returning true if there is an //overflow (an operand is less than the result), false otherwise

bool detectOverflow(uint32_t num1, uint32_t num2){
  bool overflow = 0;
  uint32_t result = num1 + num2;
  if(result < num1 || result < num2){ // again, result should never be less than one of the operands!
    overflow = 1;
  }
  return overflow;
}

//performing the declared operation on the operands and storing the result in the results array incase these values need to be utilized later on! with that //being said this function allows for the implementation of (potentially) different operations in the future

void runOperations(string operations[], uint32_t operand1[], uint32_t operand2[], uint32_t results[], int count){
  for(int i = 0; i < count; i++){
    uint32_t num = 0;
    bool overflow = 0;
    
    if(operations[i] == "ADD"){
      num = operand1[i] + operand2[i];
      results[i] = num;
      overflow = detectOverflow(operand1[i], operand2[i]);
    
      cout << "ADD" << setw(6) << "0x" << hex << uppercase << operand1[i] << setw(6) << "0x" << hex << uppercase << operand2[i] << ":" << setw(4);
      cout << "0x" << hex << uppercase << num << " " << endl; //seperating operation and operands from results (just formatting preference)
      cout << "Overflow: " << (overflow ? "Yes" : "No") << endl << endl;
    }
    else if(operations[i] == "SUB"){
      //again, demonstrating incase program calls for further implementation
    }
    else{
      cout << "invalid operation!" << endl;
    }
  }
}