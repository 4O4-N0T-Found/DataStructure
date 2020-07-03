// 给定排序数组和目标值，搜索插入位置。leetcode 35题。
#include <iostream>
#include <vector>
using namespace std;

int searchInsert(vector<int>& nums, int target) {
    int len = nums.size(), i;
    if(len == 0) return 0;
    for(i = 0; i < len; i++) {
        if(nums[i] == target)   return i;
        else if(nums[i] < target)   continue;
        else if(nums[i] > target)   break;
    }
    return i;
}

int main() {
    vector<int> list = {1, 3, 5, 6};
    cout << searchInsert(list, 7);
}