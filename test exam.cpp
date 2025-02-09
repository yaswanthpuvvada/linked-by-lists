#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int getMinCost(vector<int>& pods, vector<int>& cost) {
    int n = pods.size(); // Get the length of pods list
    
    // Create a vector of tuples (pod count, cost, index)
    vector<pair<pair<int, int>, int>> pod_cost_pairs; // (pod count, cost), index

    for (int i = 1; i < n; ++i) {
        pod_cost_pairs.emplace_back(make_pair(pods[i], cost[i]), i);
    }

    // Sort based on pod count, then cost (in case of ties)
    sort(pod_cost_pairs.begin(), pod_cost_pairs.end(), [](const auto& a, const auto& b) {
        return a.first.first < b.first.first || (a.first.first == b.first.first && a.first.second > b.first.second);
    });

    int total_cost = 0;
    for (int i = 1; i < n - 1; ++i) {
        if (pod_cost_pairs[i].first.first <= pod_cost_pairs[i - 1].first.first) {
            // Calculate the minimum increment needed
            int increment = pod_cost_pairs[i - 1].first.first - pod_cost_pairs[i].first.first + 1;
            total_cost += increment * pod_cost_pairs[i].first.second;
            // Update the pod count
            int new_pod_count = pod_cost_pairs[i].first.first + increment;
            pod_cost_pairs[i].first.first = new_pod_count; // Update pod count
        }
    }
    return total_cost;
}

int main() {
    // Test with the given example
    vector<int> pods = {2, 3, 5};
    vector<int> cost = {2, 1, 7};
    int result = getMinCost(pods, cost);
    cout << result << endl; // Should print 0

    // Additional test
    pods = {5, 3, 4};
    cost = {2, 1, 7};
    result = getMinCost(pods, cost);
    cout << result << endl; // Adjusted test

    return 0;
}


