// 给定一个 没有重复 数字的序列，返回其所有可能的全排列。leetcode 46题。
#include <iostream>
#include <vector>
using namespace std;

void DFS(vector<vector<int>> &res, vector<int>& nums, int len, vector<bool>& used, vector<int> &path, int &depth) {
    if(depth == len) {
        res.push_back(path);
        return;
    }
    for(int i = 0; i < len; i++) {
        if(used[i] == false) {
            path.push_back(nums[i]);
            used[i] = true;
            depth++;
            DFS(res, nums, len ,used, path, depth);
            depth--;
            used[i] = false;
            path.pop_back();
        }
    }
    return;
}

vector<vector<int>> permute(vector<int>& nums) {
    int len = nums.size();
    vector<vector<int>> res;
    if(len == 0)    return res;

    vector<bool> used(len);
    vector<int> path;
    int depth = 0;

    DFS(res, nums, len, used, path, depth);
    return res;
}

int main() {
    vector<int> nums = {1, 2, 3};
    for(auto item:permute(nums)) {
        for(auto i:item) {
            cout << i;
        }
        cout << '\n';
    }
}