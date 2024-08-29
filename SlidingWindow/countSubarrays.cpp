#include<bits/stdc++.h>
using namespace std;

int countSubsSumK(vector<int>& nums, int k){
    unordered_map<int,int>sumCount;
    int count=0, sum=0;
    sumCount[0] = 1;

    for(int num : nums){
        sum += num;
        if(sumCount.count(sum-k)){
            count += sumCount[sum-k];
        }
        sumCount[sum]++;
    }
    return count;
}

vector<pair<int,int>>SubarraysSumK(vector<int>&nums, int k){
    vector<pair<int,int>>ans;
    unordered_map<int,vector<int>>mp;
    mp[0].push_back(-1);
    int sum=0;
    for(int i=0; i<nums.size(); i++){
        sum += nums[i];
        if(mp.count(sum-k)){
            for(auto& s : mp[sum-k]){
                ans.push_back({s+1, i});
            }
        }
        mp[sum].push_back(i);
    }
    return ans;
}

int longestSubarraySumK(vector<int>&nums, int k){
    int maxi=0;
    int sum=0;
    unordered_map<int, int>mp;
    mp[0] = -1;
    for(int i=0; i<nums.size(); i++){
        sum += nums[i];
        if(mp.count(sum-k)){
            maxi = max(maxi, i-mp[sum-k]);
        }
        if(!mp.count(sum-k)){
            mp[sum-k] = i;
        }
    }
    return maxi;
}

int main(){
    vector<int>nums = {1,2,3,1,2,3};
    int k = 6;
    cout << countSubsSumK(nums, k) << " " << longestSubarraySumK(nums, k) << endl;
    vector<pair<int, int>> ans = SubarraysSumK(nums, k);
    cout << "Subarrays with sum " << k << " are:" << endl;
    for (auto& a : ans) {
        cout << "From index " << a.first << " to " << a.second << endl;
    }
}