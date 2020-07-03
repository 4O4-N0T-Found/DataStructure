// 给定一个正整数 n，输出外观数列的第 n 项。leetcode 38题。
#include <iostream>
using namespace std;

string countAndSay(int n) {
    if(n == 1)  return "1";
    string pre = countAndSay(n - 1), res;
    int len = pre.size(), i = 0, j = 0;
    for( ; i < len; i++) {
        while(i < len - 1 && pre[i] == pre[i+1])    i++;
        res += to_string(i-j+1) + pre[j];
        j = i + 1;
    }
    return res;
}

int main() {
    cout << countAndSay(5);
}