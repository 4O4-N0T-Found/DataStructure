// 括号是否匹配，双100，leetcode 20题。
#include <iostream>
#include <stack>
#include <string>
using namespace std;


bool isValid(string s) {
    stack<char> stk;
    bool match = true;
    for(auto item:s) {
        if (item == '(' || item == '[' || item=='{')
            stk.push(item);
        else if(item == ')') {
            match = !stk.empty() && (stk.top() == '(');
            if(!stk.empty())  stk.pop();
        }
        else if(item == ']') {
            match = !stk.empty() && (stk.top() == '[');
            if(!stk.empty())  stk.pop();
        }
        else if(item == '}') {
            match = !stk.empty() && (stk.top() == '{');
            if(!stk.empty())  stk.pop();
        }
        if(match == false)  break;
    }
    return match && stk.empty();
}

int main() {
    if(isValid("){")) {
        cout << "true";
    }
    else {
        cout << "false";
    }
}