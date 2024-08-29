#include<bits/stdc++.h>
using namespace std;

int longestConsecutiveSeq(vector<int>&nums){
    unordered_set<int>tb(nums.begin(), nums.end());
    int ans=1;
    for(int i=0; i<nums.size(); i++){
        if(!tb.count(nums[i]-1)){
            int count=1;
            int num = nums[i];
            while (tb.count(num+ 1)) { 
                num++;
                count++;
            }
            ans = max(ans, count);
        }
    }
    return ans;
}
int main(){
    vector<int>nums = {100, 4, 200, 1, 10, 3, 2, 8, 9, 12, 11};
    cout << longestConsecutiveSeq(nums);
}