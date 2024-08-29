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