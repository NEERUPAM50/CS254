#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Job {
    int deadline;
    int profit;
};

bool compare(Job a, Job b) {
    return a.profit > b.profit;
}

int maxProfitGreedy(vector<Job>& jobs) {
    sort(jobs.begin(), jobs.end(), compare);

    int maxDeadline = 0;
    for (const auto& job : jobs) {
        maxDeadline = max(maxDeadline, job.deadline);
    }

    vector<int> schedule(maxDeadline, -1);

    int totalProfit = 0;
    for (const auto& job : jobs) {
        for (int i = job.deadline - 1; i >= 0; --i) {
            if (schedule[i] == -1) {
                schedule[i] = job.profit;
                totalProfit += job.profit;
                break;
            }
        }
    }

    return totalProfit;
}

int main() {
    freopen("input2.txt", "r", stdin);
    freopen("output2.txt", "w", stdout);

    int t; cin>>t;
    while(t--){
        int n; cin >> n;

        vector<Job> jobs(n);
        for (int i = 0; i < n; ++i) {
            cin >> jobs[i].deadline;
            cin >> jobs[i].profit;
        }

        int maxProfitValGreedy = maxProfitGreedy(jobs);
        cout << maxProfitValGreedy << endl;
    }

    return 0;
}
