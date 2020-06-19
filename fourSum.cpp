// 找四个数，使得和等于target，leetcode 18题
#include <iostream>
#include <vector>
using namespace std;


vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());
    int fst, scd, trd, fth, len = nums.size(), sum;
    for(fst = 0; fst < len; fst++) {
        if(fst > 0 && nums[fst] == nums[fst-1])
            continue;
        for(scd = fst + 1; scd < len; scd++) {
            if(scd > fst + 1 && nums[scd] == nums[scd-1])
                continue;
            fth = len - 1;
            for(trd = scd + 1; trd<len; trd++) {
                if(trd > scd + 1 && nums[trd] == nums[trd-1])
                    continue;
                if(trd < fth && nums[fst] + nums[scd] + nums[trd] + nums[fth] < target)     //如果sum比target小，就不用再执行下面的fth--，因为再减肯定更小
                    continue;                                                               //所以直接continue，让trd++，才能使得sum变大
                while(trd < fth && nums[fst] + nums[scd] + nums[trd] + nums[fth] > target)
                    fth--;
                if(trd == fth)  break;
                if(nums[fst] + nums[scd] + nums[trd] + nums[fth] == target)
                    res.push_back({nums[fst], nums[scd], nums[trd], nums[fth]});
            }
        }
    }
    return res;
}

int main() {
    vector<int> list = {1, 0, -1, 0, -2, 2};
    for (auto item:fourSum(list, 0)) {
        for(auto i:item){
            cout << i << '\t';
        }
        cout << '\n';
    }
}