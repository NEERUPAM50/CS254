#include<bits/stdc++.h>
using namespace std;

int knapsack(int values[], int weights[], int n, int maxWeight) {
    
    vector<vector<int>> dp(n + 1, vector<int>(maxWeight + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= maxWeight; w++) {
            if (weights[i - 1] <= w) {
                dp[i][w] = max(dp[i - 1][w], values[i - 1] + dp[i - 1][w - weights[i - 1]]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][maxWeight];
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input2.txt", "r", stdin);
    freopen("output2.txt", "w", stdout);
    #endif

    int t; cin>>t;
    while(t--){
        int n;
        cin >> n;

        int values[n], weights[n];
        for (int i = 0; i < n; i++)
            cin >> values[i];

        for (int i = 0; i < n; i++)
            cin >> weights[i];

        int maxWeight;
        cin >> maxWeight;

        int maxValue = knapsack(values, weights, n, maxWeight);

        cout << maxValue << endl;
    }

    return 0;
}
