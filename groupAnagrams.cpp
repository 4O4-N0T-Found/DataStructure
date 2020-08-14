// 将相同字母组合成的字符串归类，如abc和bca是一类。leetcode 49题。
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>> res;
    if(strs.size() == 0)    return res;

    unordered_map<string, int> m;
    string temp;
    int index = 0;
    for(auto str:strs) {
        temp = str;
        sort(temp.begin(), temp.end());
        if(m.count(temp) != 0) {
            res[m[temp]].push_back(str);
        }
        else {
            m[temp] = index++;
            res.push_back(vector<string> {str});
        }
    }
    return res;
}

int main() {
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    for(auto i:groupAnagrams(strs)) {
        for(auto j:i) {
            cout << j << ' ';
        }
        cout << '\n';
    }
}