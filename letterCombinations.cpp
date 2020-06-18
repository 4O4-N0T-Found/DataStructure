// 电话号码的字母组合，leetcode 17题
// 递归法，双100%。
// "看到题目首先想到循环遍历，把每一种组合都找出来输出，循环？问题来了，我不知题目会给几个数字，所以我不知道循环需要设置多少层，于是想到递归。"
// 如果输入为空，或只有一个数字，很好办。
// 如果输入n个数字，假设前(n-1)个已经排列组合完毕，再处理最后一个。
#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;


map<char, string> M = {
        {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"},
        {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}
};

vector<string> letterCombinations(string digits) {
    vector<string> res;
    string temp;
    if(digits.size()==0)    return {};
    else if(digits.size()==1) {
        for(int i=0; i<M[digits[0]].size(); i++) {
            temp = M[digits[0]].substr(i, 1);
            res.push_back(temp);
        }
    }
    else {
        vector<string> last = letterCombinations(digits.substr(0, digits.size()-1));
        for(int i=0; i<last.size(); i++) {
            for(int j=0; j<M[digits[digits.size()-1]].size(); j++) {
                temp = last[i] + M[digits[digits.size()-1]].substr(j, 1);
                res.push_back(temp);
            }
        }
    }
    return res;
}

int main() {
    for(auto item:letterCombinations("234")) {
        cout << item+'\n';
    }
}