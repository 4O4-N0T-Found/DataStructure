// 找出candidates中所有可以使数字和为target的组合。leetcode 39题。
#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    vector<int> candidates;
    vector<int> path;
    vector<vector<int>> res;

public:
    void DFS(int start, int target) {
        if(target < 0)  return;
        else if(target == 0) {
            res.push_back(path);
            return;
        }
        else {
            for(int i = start; i < candidates.size(); i++) {
                path.push_back(candidates[i]);
                DFS(i, target - candidates[i]);
                path.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        this->candidates = candidates;
        DFS(0, target);
        return res;
    }
};

int main() {
    vector<int> candidates = {7, 2, 6, 3};
    Solution s;
    vector<vector<int>> res = s.combinationSum(candidates, 7);
    for(auto item:res) {
        for(auto i:item) {
            cout << i << '\t';
        }
        cout << '\n';
    }
}