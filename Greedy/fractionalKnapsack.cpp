#include<bits/stdc++.h>
using namespace std;

struct Item {
    int value;
    int weight;
};

class fKnapsack {
public:
    double fractionalKnapsack(int w, vector<Item>& items) {
        vector<pair<double, Item>> itemRatios;
    
        for (const auto& item : items) {
            double ratio = (double)item.value / item.weight;
            itemRatios.push_back({ratio, item});
        }
        
        sort(itemRatios.begin(), itemRatios.end(), [](const pair<double, Item>& a, const pair<double, Item>& b) {
            return a.first > b.first;
        });
    
        double ans = 0.0;
        
        for (const auto& item : itemRatios) {
            int weight = item.second.weight;
            int value = item.second.value;
            
            if (weight <= w) {
                ans += value;
                w -= weight;
            } else {
                ans += item.first * w;
                break;
            }
        }
        
        return ans;
    }
};


int main() {
    fKnapsack fk;
    int W = 50;
    vector<Item> items = {{60, 10}, {100, 20}, {120, 30}};
    double maxValue = fk.fractionalKnapsack(W, items);
    cout << "Maximum value in Knapsack = " << maxValue << endl;
    return 0;
}