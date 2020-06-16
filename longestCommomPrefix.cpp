// 字符串数组的最长公共前缀，leetcode 14题
#include<iostream>
#include<string>
#include<vector>
using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    if(strs.size()==0)  return "";
    string res = "";
    int i, j;
    char temp;
    for(i=0; i<strs[0].size(); i++){
        temp = strs[0][i];
        for(j=1; j<strs.size(); j++){
            if(strs[j][i]!=temp)    return res;
        }
        res = strs[0].substr(0, i+1);
    }
    return res;
}

int main(){
    vector<string> strs = {"flower", "flow", "flight"};
    cout << longestCommonPrefix(strs);
}
