#include<bits/stdc++.h>
using namespace std;

// DUTCH FLAG ALGO
void dutchNationalFlag(vector<int>&nums){
    int low=0, mid=0, high = nums.size()-1;

    while(mid<=high){
        if(nums[mid]==0){
            swap(nums[low++], nums[mid++]);
        }
        else if(nums[mid]==1){
            mid++;
        }else{
            swap(nums[mid], nums[high--]);
        }
    }
}
int main(){
    vector<int>nums = {0, 1,2,1,2,0,1,0};
    dutchNationalFlag(nums);
    for(auto& a : nums){
        cout << a << " ";
    }
}