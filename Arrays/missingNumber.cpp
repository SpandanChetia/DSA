#include <bits/stdc++.h>
using namespace std;

int missingNum(vector<int> &nums)
{
    int n = nums.size();
    int sum = accumulate(nums.begin(), nums.end(), 0);
    int sum1 = (n * (n + 1)) / 2;
    return sum1 - sum;
}

int shift(vector<int> &nums)
{
    int pv = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] > 0)
        {
            swap(nums[i], nums[pv]);
            pv++;
        }
    }
    return pv;
}
int firstMissingPositive(vector<int> &nums)
{
    int ix = shift(nums);
    for (int i = 0; i < ix; i++)
    {
        int v = abs(nums[i]);
        if (v <= ix && nums[v - 1] > 0)
        {
            nums[v - 1] = -nums[v - 1];
        }
    }

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] > 0)
        {
            return i + 1;
        }
    }
    return ix + 1;
}
int main()
{
    vector<int> nums = {1, 2, 3, 4};
    cout << missingNum(nums);
}