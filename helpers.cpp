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

void updateFlags(string operation, uint32_t result){ 
    bool neg = 0;
    bool zero = 0;
    if(operation.back() == 'S'){
        neg = (result & 0x80000000) != 0;
        zero = (result == 0);
        cout << "N: " << neg << " Z: " << zero << endl << endl;
    }
    else{
        cout << "N: " << neg << " Z: " << zero << endl << endl;
    }
}

//performing the declared operation on the operands and storing the result in the results array incase these values need to be utilized later on! with that //being said this function allows for the implementation of (potentially) different operations in the future

void runOperations(string operations[], uint32_t operand1[], uint32_t operand2[], int count){
    for(int i = 0; i < count; i++){
        uint32_t num = 0;
        bool isSigned = false;
        
        if(operations[i] == "ADD" || operations[i] == "ADDS"){
            num = operand1[i] + operand2[i];
        }
        else if(operations[i] == "AND" || operations[i] == "ANDS"){
            num = operand1[i] & operand2[i];
        }
        else if(operations[i] == "ASR" || operations[i] == "ASRS"){
            int32_t signedOperand = static_cast<int32_t>(operand1[i]); 
            int32_t signedNum = signedOperand >> operand2[i];
            cout << operations[i] << setw(6) << "0x" << hex << uppercase << operand1[i] << setw(6) << hex << uppercase << operand2[i] << ":" << setw(4);
            cout << "0x" << signedNum << endl;
            isSigned = true; 
        }
        else if(operations[i] == "LSR" || operations[i] == "LSRS"){
            num = operand1[i] >> operand2[i];
            cout << operations[i] << setw(6) << "0x" << hex << uppercase << operand1[i] << setw(6) << hex << uppercase << operand2[i] << ":" << setw(4);
            cout << "0x" << num << endl;
        }
        else if(operations[i] == "LSL" || operations[i] == "LSLS"){
            num = operand1[i] << operand[2];

        }
        else if(operations[i] == "NOT" || operations[i] == "NOTS"){
            num = ~operand1[i]; //need to fix output 
        }
        else if(operations[i] == "ORR" || operations[i] == "ORRS"){
            num = operand1[i] || operand2[i];
        }
        else if(operations[i] == "SUB" || operations[i] == "SUBS"){
            num = operand1[i] - operand2[i];
        }
        else if(operations[i] == "XOR" || operations[i] == "XORS"){
            num = operand1[i] ^ operand2[i];
        }
        else{
            cout << "invalid operation!" << endl;
        }
        // cout << operations[i] << setw(6) << "0x" << hex << uppercase << operand1[i] << setw(6) << "0x" << hex << uppercase << operand2[i] << ":" << setw(4);
        // cout << "0x" << hex << uppercase << num << " " << endl; //seperating operation and operands from results (just formatting preference)
        //updateFlags(operations[i], num);
    }
}