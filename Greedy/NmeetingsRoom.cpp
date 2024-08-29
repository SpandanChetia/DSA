#include<bits/stdc++.h>
#include <chrono>
using namespace std;

struct Meet{
    int start;
    int end;
};

int meetings(vector<Meet>&m){
    sort(m.begin(), m.end(), [&](const Meet& a, const Meet& b){
        return a.end < b.end;
    });
    int ans=1;
    int prev = m[0].end;

    for(int i=1; i<m.size(); i++){
        if(m[i].start > prev){
            ans++;
            prev = m[i].end;
        }
    }
    return ans;
}

int main(){
    vector<Meet> nums = {{1,2}, {3,4}, {0,6}, {5,7}, {8,9}, {5,9}};
    auto start = chrono::high_resolution_clock::now();
    cout << "Maximum number of meetings: " << meetings(nums) << endl;
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start).count();

    // Print the runtime in milliseconds
    cout << "Execution time: " << duration << " ms" << endl;
}