// 找三数，使得和与目标数最接近。leetcode15题
#include<iostream>
#include<vector>
using namespace std;

int threeSumClosest(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    int first, second, third, length=nums.size(), res=nums[0]+nums[1]+nums[length-1], sum;
    for(first=0; first<length; first++) {
        second=first+1;
        third=length-1;
        while(second < third) {
            sum = nums[first] + nums[second] + nums[third];
            if(abs(sum-target) < abs(res-target))
                res = sum;
            if(sum>target)
                third--;
            else if(sum<target)
                second++;
            else
                break;
        }
    }
    return res;
}

int main() {
    vector<int> list = {-1, 0, 1, 2, -1, -4};
    cout << threeSumClosest(list, 1);
}