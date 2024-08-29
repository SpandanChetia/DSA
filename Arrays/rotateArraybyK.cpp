#include<bits/stdc++.h>
using namespace std;

void reverse(int i, int j, vector<int>&nums){
    while(i<=j){
        swap(nums[i++], nums[j--]);
    }
}
vector<int>rotateArray(vector<int>&nums, int k){
    int n = nums.size();
    reverse(0, n-1, nums);
    reverse(0, k-1, nums);
    reverse(k, n-1, nums);
    return nums;
}
int main(){
    vector<int>nums = {1,2,3,4,5,6,7};
    rotateArray(nums, 4);
    for(auto& n : nums){
        cout << n << " ";
    }
}