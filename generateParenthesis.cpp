// 生成所有可能的并且有效的括号组合,leetcode 22题。
#include <iostream>
#include <vector>
using namespace std;

void Next(vector<string> & res, int left, int right, string str) {
    if(left == 0 && right == 0) {
        res.push_back(str);
        return;
    }
    if(left > 0)    Next(res, left - 1, right + 1, str + '(');
    if(right > 0)   Next(res, left, right - 1, str + ')');
}

vector<string> generateParenthesis(int n) {
    vector<string> res;
    Next(res, n, 0, "");
    return res;
}

int main() {
    for(auto item:generateParenthesis(3)) {
        cout << item << '\n';
    }
}