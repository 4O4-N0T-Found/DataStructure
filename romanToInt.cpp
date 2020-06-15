// 罗马数字转整数，leetcode 13题
#include <iostream>
#include <string>
#include <map>
using namespace std;

int romanToInt(string s) {
    map<char, int> table= {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
    int i, res=0;
    for(i=0; i<s.size(); i++){
        if(table[s[i]]<table[s[i+1]]) res-=table[s[i]];
        else res+=table[s[i]];
    }
    return res;
}

int main(){
    cout << romanToInt("MCMXCIV");
}