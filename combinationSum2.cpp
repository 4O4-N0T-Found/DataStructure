// 39题的基础上，candidates 中的每个数字在每个组合中只能使用一次。leetcode 40题。
#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    vector<vector<int>> res;
    vector<int> candidates;
    vector<int> path;
    int len;

public:
    void DFS(int start, int target) {
        if(target < 0)  return;
        else if(target == 0) {
            res.push_back(path);
            return;
        }
        else {
            for(int i = start; i < len; i++) {
                if(i > start && candidates[i] == candidates[i-1])     continue;
                path.push_back(candidates[i]);
                DFS(i + 1, target - candidates[i]);
                path.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        this->candidates = candidates;
        len = candidates.size();
        DFS(0, target);
        return res;
    }
};

int main() {
    vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
    Solution s;
    vector<vector<int>> res = s.combinationSum2(candidates, 8);
    for(auto item:res) {
        for(auto i:item) {
            cout << i << '\t';
        }
        cout << '\n';
    }
}