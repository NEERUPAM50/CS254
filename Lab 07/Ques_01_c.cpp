#include <iostream>
#include <vector>

using namespace std;

int knapsackDP(vector<int>& values, vector<int>& weights, int capacity) {
    int n = values.size();
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int w = 1; w <= capacity; ++w) {
            if (weights[i - 1] <= w) {
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - weights[i - 1]] + values[i - 1]);
            } 
            else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][capacity];
}

int main() {
    freopen("input1_c.txt", "r", stdin);
    freopen("output1_c.txt", "w", stdout);

    int t; cin>>t;
    while(t--){
        int n; cin >> n;

        vector<int> weights(n);
        vector<int> values(n);

        for (int i = 0; i < n; ++i) {
            cin >> weights[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> values[i];
        }

        int capacity; cin >> capacity;

        int maxValue = knapsackDP(values, weights, capacity);
        cout << maxValue << endl;
    }
    
    return 0;
}
