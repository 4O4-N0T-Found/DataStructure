// 将给定数字序列重新排列成字典序中下一个更大的排列，leetcode 31题。
#include <iostream>
#include <vector>
using namespace std;

//快速排序函数
void Quick(vector<int>& a, int start, int end)
{
    if (start >= end) return;
    int i = start;
    int j = end;
    int temp = a[i];
    while (i < j)
    {
        while (i < j && a[j] >= temp) j--;
        while (i < j && a[i] <= temp) i++;
        swap(a[i],a[j]);
    }
    swap(a[i],a[start]);
    Quick(a,start,i-1);
    Quick(a,i+1,end);
}

void nextPermutation(vector<int>& nums) {
    if(nums.size() < 2)     return;
    int len = nums.size(), i = len - 2, j = len - 1, k, temp;
    while(i >= 0) {
        if(nums[i] < nums[j])   break;
        else {
            i--;
            j--;
        }
    }
    if(i >= 0) {
        for(k = len - 1; k >= j; k--) {
            if(nums[k] > nums[i]) {
                temp = nums[k];
                nums[k] = nums[i];
                nums[i] = temp;
                break;
            }
        }
    }
    Quick(nums, j, len - 1);
}

void print(vector<int> list) {
    for(int i=0; i < list.size(); i++) {
        cout << list[i] << '\t';
    }
    cout << '\n';
}

int main() {
    vector<int> list = {1, 2, 3, 4, 5};
    print(list);
    nextPermutation(list);
    print(list);
}