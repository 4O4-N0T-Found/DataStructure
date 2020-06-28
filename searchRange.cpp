// 在排序数组中查找指定元素的第一个和最后一个位置，leetcode 34题。
#include <iostream>
#include <vector>
using namespace std;

// 二分查找
int search(vector<int> &nums, int left, int right, int target) {
    while(left <= right) {
        int mid = (left + right) / 2;
        if(nums[mid] == target)     return mid;
        else if(nums[mid] > target)     right = mid - 1;
        else    left = mid + 1;
    }
    return -1;
}

vector<int> searchRange(vector<int>& nums, int target) {
    int len = nums.size();
    // 先随便找到任何一个target
    int index = search(nums, 0, len - 1, target);
    if(index == -1)     return {-1, -1};
    // left和right默认是index
    int left = index, right = index, temp;
    // 在[0..index]找到第一个target
    while(true) {
        temp = search(nums, 0, left - 1, target);
        if(temp == -1)  break;
        else    left = temp;
    }
    while(true) {
        temp = search(nums, right + 1, len - 1, target);
        if(temp == -1)  break;
        else    right = temp;
    }
    return {left, right};
}

int main() {
    vector<int> list = {5, 7, 7, 8, 8, 10};
    for(auto item:searchRange(list, 8)) {
        cout << item << '\t';
    }
}