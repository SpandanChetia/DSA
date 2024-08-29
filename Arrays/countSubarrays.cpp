#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll countSubarraysSumZero(vector<int>&nums){
    int n = nums.size();
    unordered_map<ll, ll>mp;
    ll sum=0;
    ll count=0;

    mp[0]=1;
    for(int i=0; i<n; i++){
        sum +=nums[i];
        if(mp.count(sum)){
            count += mp[sum];
        }       
        mp[sum]++; 
    }
}

ll countSubswithKones(string& s, int k){
    int n=s.size();
    unordered_map<ll,ll>mp;
    mp[0]=1;
    ll sum=0;
    ll ans=0;
    for(int i=0; i<n; i++){
        if(s[i]=='1'){
            sum++;
        }
        if(mp.count(sum-k)){
            ans+= mp[sum-k];
        }
        mp[sum]++;
    }
    return ans;
}

ll countSubarraysSumK(vector<int>&nums, int k){
    int n=nums.size();
    unordered_map<ll,ll>mp;
    mp[0]=1;
    ll sum=0;
    ll ans=0;
    for(int i=0; i<n; i++){
        sum +=nums[i];
        if(mp.count(sum-k)){
            ans+= mp[sum-k];
        }
        mp[sum]++;
    }
    return ans;
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