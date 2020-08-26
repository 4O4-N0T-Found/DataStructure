//最大子序和，leetcode 53题。
#include <iostream>
#include <vector>
using namespace std;

int maxSubArray(vector<int>& nums) {
    int res = nums[0], pre = 0;
    for(auto item:nums) {
        pre = max(pre+item, item);
        res = max(res, pre);
    }
    return res;
}

int main() {
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    cout << maxSubArray(nums);
}