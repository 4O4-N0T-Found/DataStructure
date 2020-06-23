// 从数组中原地移除指定值的元素，leetcode 27题。
#include <iostream>
#include <vector>
using namespace std;

int removeElement(vector<int>& nums, int val) {
    int i, curr = 0;
    for(i = 0; i < nums.size(); i++) {
        if(nums[i] == val)  continue;
        nums[curr++] = nums[i];
    }
    return curr;
}

void print(vector<int> list) {
    for(auto item:list) {
        cout << item << '\t';
    }
    cout << '\n';
}

int main() {
    vector<int> list = {0,1,2,2,3,0,4,2};
    print(list);
    removeElement(list, 2);
    print(list);
}