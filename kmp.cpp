// KMP
#include <iostream>
#include <vector>
using namespace std;

vector<int> getnext(string str) {
    int len = str.size();
    vector<int> next;
    next.push_back(-1);
    int j = 0, k = -1;
    while(j < len - 1) {
        if(k == -1 || str[j] == str[k]) {
            k++;
            j++;
            next.push_back(k);
        }
        else    k = next[k];
    }
    return next;
}

int strStr(string haystack, string needle) {
    if(needle.empty())  return 0;
    int i = 0, j = 0, len1 = haystack.size(), len2 = needle.size();
    vector<int> next;
    next = getnext(needle);
    while((i < len1) && (j < len2)) {
        if(j == -1 || haystack[i] == needle[j]) {
            i++;
            j++;
        }
        else    j = next[j];
    }
    if(j == len2)  return i - j;
    return -1;
}

int main() {
    cout << strStr("hello", "ll");
}