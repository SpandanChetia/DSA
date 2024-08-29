#include<bits/stdc++.h>
using namespace std;

class TaskScheduler {
public:
    int minimumTime(vector<char>& tasks, int n) {
        priority_queue<int>pq;
        queue<pair<int,int>>q;

        unordered_map<char,int>mp;
        for(auto& c : tasks){
            mp[c]++;
        }
        for(auto& c : mp){
            pq.push(c.second);
        }
        int time=0;
        while(!pq.empty() || !q.empty()){
            time++;
            if (!pq.empty()) {
                int task = pq.top();
                pq.pop();
                task--;
                if (task > 0) {
                    q.push({task, time+n});
                }
            }
            if (!q.empty() && q.front().second == time) {
                pq.push(q.front().first);
                q.pop();
            }
        }
        return time;
    }
};

int main(){
    TaskScheduler ts;
    vector<char>nums = {'A','A','A','B','B','B'};
    int n = 2;
    auto start = chrono::high_resolution_clock::now();
    cout << ts.minimumTime(nums, n);
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start).count();

    // Print the runtime in milliseconds
    cout << "Execution time: " << duration << " ms" << endl;
}