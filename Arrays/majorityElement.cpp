#include<bits/stdc++.h>
using namespace std;

int findMajority2(vector<int>&nums){
    int maxi=nums[0];
    int count=1;
    for(int i=1; i<nums.size(); i++){
        if(nums[i]==maxi){
            count++;
        }
        else{
            count--;
        }
        if(count==0){
            maxi = nums[i];
            count=1;
        }
    }
    return maxi;
}

vector<int> findMajority3(vector<int>&nums){
    int count1=0, count2=0;
    int n = nums.size();
    int el1, el2;
    for(int i=0; i<n; i++){
        if(count1==0){
            count1=1;
            el1 = nums[i]; 
        }
        else if(count2==0){
            count2=1;
            el2 = nums[i];
        }
        else if(el1==nums[i]){
            count1++;
        }
        else if(el2==nums[i]){
            count2++;
        }else{
            count1--;
            count2--;
        }
    }
    return {el1, el2};
}
int main(){
    vector<int>nums = {1,2,2,2,1,1,6,2,1,0,12,2,2,2};
    vector<int> maj = findMajority3(nums);
    cout << maj[0] << " " << maj[1];
}