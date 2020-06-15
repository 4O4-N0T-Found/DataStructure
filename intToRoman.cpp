//整数转罗马数字，难度中等，leetcode 12
#include <iostream>
#include <string>
using namespace std;

string intToRoman(int num) {
    int value[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    string roman[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    int i;
    string res;
    for(i=0;i<13;i++){
        while(value[i]<=num){
            res += roman[i];
            num -= value[i];
        }
    }
    return res;
}

int main(){
    std::cout << intToRoman(4999);
}