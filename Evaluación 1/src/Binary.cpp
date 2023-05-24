#include <iostream>
#include <cmath>
#include "Binary.h"

Binary::Binary(){
    
}

string Binary::toBinary(int number){
    string binary = "";
    while (number > 0) {
        binary = to_string(number % 2) + binary;
        number = number / 2;
    }
    return binary;
}

int Binary::toDecimal(string binary){
    int decimal = 0;
    int power = 0;
    for(int i = binary.size() - 1; i >= 0; i--){
        if(binary[i] == '1'){
            decimal += pow(2, power);
        }
        ++power;
    }
    return decimal;
}