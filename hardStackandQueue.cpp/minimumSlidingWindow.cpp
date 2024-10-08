#include<bits/stdc++.h>
using namespace std;

vector<int> minimumSlidingWindow(vector<int>nums, int k){
    vector<int>ans;
    deque<int>dq;

    for(int i=0; i<nums.size(); i++){
        if(!dq.empty() && dq.front()<i-k+1){
            dq.pop_front();
        }
        while(!dq.empty() && nums[dq.back()]>nums[i]){
            dq.pop_back();
        }
        dq.push_back(i);
        if(i>=k-1){
            ans.push_back(nums[dq.front()]);
        }
    }
    return ans;
}

int main(){
    vector<int>nums = {1,3,-1,-3,5,3,6,7};
    int k=3;
    vector<int>ans = minimumSlidingWindow(nums, k);
    for(auto& n : ans){
        cout << n << " ";
    }
}