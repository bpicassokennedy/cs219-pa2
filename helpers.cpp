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

//updating the flags if the operation calls for it, if not just setting the flag values back to zero

void updateFlags(string operation, uint32_t result, bool isSigned){ 
    bool neg = 0;
    bool zero = (result == 0);
    if(operation.back() == 'S'){
        if(isSigned){
            neg = (static_cast<int32_t>(result) < 0); 
        }
        else{
            neg = (result & 0x80000000) != 0;
        }
        cout << "N: " << neg << " Z: " << zero << endl;
    }
    else{ //if not changing flags, go back to zero for both flag states
        cout << "N: 0 " << "Z: 0" << endl;
    }
}

//part of the output displayed to the terminal, operation, operand1, operand2 (depending), result, and the status flags

void displayOperations(string operation, uint32_t operand1, uint32_t operand2, uint32_t result){ //different formatting for some operations 
    if(operation == "ASR" || operation == "ASRS" || operation == "LSR" || operation == "LSRS" || operation == "LSL" || operation == "LSLS"){
        cout << operation << setw(6) << "0x" << hex << uppercase << operand1 << setw(3) << hex << uppercase << operand2 << ":" << setw(4);
        cout << "0x" << result << endl;
    }
    else if(operation == "NOT" || operation == "NOTS"){
        cout << operation << setw(6) << "0x" << hex << uppercase << operand1 << ":" << setw(4) << "0x" << result << endl; 
    }
    else{
        cout << operation << setw(6) << "0x" << hex << uppercase << operand1 << setw(6) << "0x" << hex << uppercase << operand2 << ":" << setw(4);
        cout << "0x" << hex << uppercase << result << " " << endl; //seperating operation and operands from results (just formatting preference)
    }
}

//performing the declared operation on the operands and storing the result in the results array incase these values need to be utilized later on! with that //being said this function allows for the implementation of (potentially) different operations in the future

void runOperations(string operations[], uint32_t operand1[], uint32_t operand2[], int count){
    for(int i = 0; i < count; i++){
        uint32_t num = 0; //initializing result
        bool isSigned = false;

        if(operations[i] == "ADD" || operations[i] == "ADDS"){ //performing all the operations 
            num = operand1[i] + operand2[i];
        }
        else if(operations[i] == "AND" || operations[i] == "ANDS"){
            num = operand1[i] & operand2[i];
        }
        else if(operations[i] == "ASR" || operations[i] == "ASRS"){
            int32_t signedOperand = static_cast<int32_t>(operand1[i]); 
            int32_t signedNum = signedOperand >> operand2[i]; 
            num = signedNum; 
            isSigned = true;
        }
        else if(operations[i] == "LSR" || operations[i] == "LSRS"){
            num = operand1[i] >> operand2[i];
        }
        else if(operations[i] == "LSL" || operations[i] == "LSLS"){
            num = operand1[i] << operand2[i];
        }
        else if(operations[i] == "NOT" || operations[i] == "NOTS"){
            num = ~operand1[i]; 
        }
        else if(operations[i] == "ORR" || operations[i] == "ORRS"){
            num = operand1[i] | operand2[i];
        }
        else if(operations[i] == "SUB" || operations[i] == "SUBS"){
            num = operand1[i] - operand2[i];
        }
        else if(operations[i] == "XOR" || operations[i] == "XORS"){
            num = operand1[i] ^ operand2[i];
        }
        else{ //operation not supported
            cout << "invalid operation!" << endl;
        }

        displayOperations(operations[i], operand1[i], operand2[i], num); //displaying operation, operands, and result
        updateFlags(operations[i], num, isSigned); //updating and displaying status flags

    }
}