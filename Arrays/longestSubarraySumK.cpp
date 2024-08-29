#include<bits/stdc++.h>
using namespace std;

#define ll long long

int longestSubarray(vector<int>& nums, int k) {     // Better Solution
    int n = nums.size();
    unordered_map<ll, int> mp;
    int ans = 0;
    ll sum = 0;

    for (int i = 0; i < n; i++) {
        sum += nums[i];
        if (sum == k) {
            ans = max(ans, i + 1);
        }
        if (mp.count(sum - k)) {
            ans = max(ans, i - mp[sum - k]);
        }
        if (!mp.count(sum)) {
            mp[sum] = i;
        }
    }

    return ans;
}

int longestSub(vector<int>&nums, int k){           // Optimal Solution
    
}

int main() {
    vector<int> nums = {1, 2, 3, 1, 1, 1, 1, 4, 2, 3};
    cout << longestSubarray(nums, 3);
}
