#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>threeSum(vector<int>&nums, const int& target){
    vector<vector<int>>ans;
    sort(nums.begin(), nums.end());
    int n = nums.size();
    for(int i=0; i<n; i++){
        if(i>0 && nums[i]==nums[i-1]){
            continue;
        }
        int j=i+1;
        int k=n-1;

        while(j<=k){
            int sum = nums[i]+nums[j]+nums[k];
            if(sum<target){
                j++;
            }else if(sum>target){
                k--;
            }else{
                vector<int>sub = {nums[i], nums[j], nums[k]};
                ans.push_back(sub);
                j++;
                k--;
                while(j<=k && nums[j]==nums[j-1]){
                    j++;
                }
                while(k>=j && nums[k]==nums[k+1]){
                    k--;
                }
            }
        }
    }
    return ans;
}
int main(){
    vector<int>nums = {-2, -2, -2, -1, -1, -1, 0, 0, 0, 2, 2, 2, 2};
    vector<vector<int>>sub = threeSum(nums, 0);
    for(auto&g : sub){
        for(auto& k : g){
            cout << k << " ";
        }
        cout << endl;
    }
}