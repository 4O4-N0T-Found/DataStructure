// 一个升序序列切成两端，交换位置后形成的序列。在其中搜索指定值的下标。leetcode 33题。
#include <iostream>
#include <vector>
using namespace std;

int search(vector<int>& nums, int target) {
    int len = nums.size(), left = 0, right = len - 1, mid;
    if(len == 0)    return -1;
    while(left <= right) {
        mid = (left + right) / 2;
        if(nums[mid] == target)  return mid;
        if(nums[left] <= nums[mid]) {
            if(target >= nums[left] && target<nums[mid]) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        else {
            if(target > nums[mid] && target <= nums[right]) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
    }
    return -1;
}

int main() {
    vector<int> list = {4, 5, 6, 7, 0, 1, 2};
    cout << search(list, 0);
}