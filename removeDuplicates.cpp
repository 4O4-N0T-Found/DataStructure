// 删除排序数组中的重复项，leetcode 26题。
#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int>& nums) {
    if(nums.size() < 2) return nums.size();
    int i, curr = 0;
    for(i = 1; i < nums.size(); i++) {
        if(nums[i] == nums[curr])   continue;
        nums[++curr] = nums[i];
    }
    return curr + 1;
}

void print(vector<int> list) {
    for(auto item:list) {
        cout << item << '\t';
    }
    cout << '\n';
}

int main() {
    vector<int> list = {0,0,1,1,1,2,2,3,3,4};
    print(list);
    removeDuplicates(list);
    print(list);
}