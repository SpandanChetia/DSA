#include<bits/stdc++.h>
using namespace std;

// GREEDY SOLUTION ONLY

bool canJump(vector<int>&nums){
    int maxi=0;
    for(int i=0; i<nums.size(); i++){
        if(maxi<i){
            return false;
        }
        int sum = i+nums[i];
        maxi = max(maxi, sum);
    }
    return true;
}

int minJump(vector<int>&nums){
    int ans=0;
    int l=0,r=0;

    while(r<nums.size()-1){
        int farthest=0;
        for(int i=l; i<=r; i++){
            farthest = max(farthest, nums[i]+i);
        }
        l = r+1;
        r=farthest;
        ans++;
    }
    return ans;
}

int main(){
    vector<int>nums = {2,3,1,1,4};

    cout << canJump(nums) << " " << minJump(nums);
}