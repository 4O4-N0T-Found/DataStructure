// 字符串相乘,leetcode 43题。
#include <iostream>
#include <vector>
using namespace std;

string multiply(string num1, string num2) {
    int len1 = num1.size(), len2 = num2.size(), len3 = len1+len2-1, i, j, temp = 0;     //temp：进位
    vector<int> n1, n2, n3;
    n3.resize(len3);
    string res;
    for(i = len1 - 1; i >= 0; i--)  n1.push_back(num1[i] - '0');
    for(j = len2 - 1; j >= 0; j--)  n2.push_back(num2[j] - '0');
    for(i = 0; i < len1; i++) {
        for(j = 0; j < len2; j++) {
            n3[i + j] += n1[i] * n2[j];
        }
    }
    for(i = 0; i < len3; i++) {
        n3[i] = n3[i] + temp;
        temp = n3[i] / 10;
        n3[i] = n3[i] % 10;
        res = (char)(n3[i] + '0') + res;
    }
    if(temp > 0)    res = (char)(temp + '0') + res;
    while(res[0] == '0' && res.size() > 1)  res.erase(res.begin());     //去掉开头的0
    return res;
}

int main() {
    cout << multiply("123", "456");
}