#include <bits/stdc++.h>
using namespace std;

struct Job {
    int id;
    int dead;
    int profit;
};

vector<int> JobScheduling(vector<Job>& jobs, int n) {
    sort(jobs.begin(), jobs.end(), [&](Job &a, Job &b) {
        return a.profit > b.profit;
    });
    
    int profit = 0;
    int jb = 0;
    int maxDead = 0;
    
    for (int i = 0; i < n; i++) {
        maxDead = max(maxDead, jobs[i].dead);
    }
    
    vector<int> days(maxDead + 1, -1);
    
    for (int j = 0; j < n; j++) {
        for (int i = jobs[j].dead; i > 0; i--) {
            if (days[i] == -1) {
                days[i] = jobs[j].id;
                profit += jobs[j].profit;
                jb++;
                break;
            }
        }
    }
    
    return {jb, profit};
}

int main() {
    vector<Job> jobs = {{1, 2, 100}, {2, 1, 19}, {3, 2, 27}, {4, 1, 25}, {5, 3, 15}};
    vector<int> result = JobScheduling(jobs, jobs.size());
    cout << result[0] << " " << result[1] << endl;
}
