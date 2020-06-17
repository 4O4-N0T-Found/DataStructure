// 找三数，使和等于0。leetcode 15题
#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> res;
    sort(nums.begin(),nums.end());
    int first, second, third, count=nums.size();
    for(first=0; first<count; first++) {
        if(first>0 && nums[first]==nums[first-1])
            continue;
        third = count-1;
        for(second=first+1; second<count; second++) {
            if(second>first+1 && nums[second]==nums[second-1])
                continue;
            while(second < third && nums[first]+nums[second]+nums[third] > 0)
                third--;
            if(second == third) break;
            if(nums[first]+nums[second]+nums[third] == 0)
                res.push_back({nums[first], nums[second], nums[third]});
        }
    }
    return res;
}

int main() {
    vector<int> list = {-1, 0, 1, 2, -1, -4};
    for (auto item:threeSum(list)) {
        for(auto i:item){
            cout << i << '\t';
        }
        cout << '\n';
    }
}