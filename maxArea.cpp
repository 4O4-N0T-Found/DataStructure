#include <iostream>
#include <vector>
using namespace std;


// leetcode 第11题

int maxArea(vector<int>& height) {
    int i=0, j=height.size()-1, max=0, area;
    while(i<j){
        area = min(height[i], height[j]) * (j-i);
        if(area>max)    max = area;
        if(height[i]<height[j]) i++;
        else j--;
    }
    return max;
}

int main(){
	vector<int> obj = {1,8,6,2,5,4,8,3,7};
	cout << maxArea(obj);
	return 0;
}