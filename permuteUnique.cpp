// 给定一个可包含重复数字的序列，返回所有不重复的全排列。leetcode 47题。
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void DFS(vector<vector<int>> &res, vector<int> &path, vector<bool> &uesd, vector<int>& nums, int &len, int &depth) {
    if(depth == len) {
        res.push_back(path);
        return;
    }
    for(int i = 0; i < len; i++) {
        if(uesd[i] == true)     continue;
        if(i > 0 && nums[i] == nums[i - 1] && uesd[i - 1] == false)     continue;
        path.push_back(nums[i]);
        uesd[i] = true;
        depth++;
        DFS(res, path, uesd, nums, len, depth);
        depth--;
        uesd[i] = false;
        path.pop_back();
    }
    return;
}

vector<vector<int>> permuteUnique(vector<int>& nums) {
    vector<vector<int>> res;
    int len = nums.size();
    if(len == 0)    return res;

    sort(nums.begin(), nums.end());

    vector<bool> uesd(len);
    vector<int> path;
    int depth = 0;
    DFS(res, path, uesd, nums, len, depth);
    return res;
}

int main() {
    vector<int> nums = {1, 2, 1};
    for(auto item:permuteUnique(nums)) {
        for(auto i:item) {
            cout << i << '\t';
        }
        cout << '\n';
    }
}