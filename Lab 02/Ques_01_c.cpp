#include<bits/stdc++.h>
using namespace std;

vector<int> findIntersection(int a1[], int a2[], int n, int m) {
    vector<int> intersectionArray;
    int i = 0, j = 0;

    while (j < m && i < n) {
        if (a1[i] == a2[j]) {
            intersectionArray.push_back(a1[i]);
            i++;
            j++;
            while (i < n && a1[i] == a1[i - 1]) i++;
            while (j < m && a2[j] == a2[j - 1]) j++;
        } else if (a1[i] > a2[j]) {
            while (j < m && a2[j] < a1[i]) j++;
        } else {
            while (i < n && a1[i] < a2[j]) i++;
        }
    }

    return intersectionArray;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input_1a.txt", "r", stdin);
    freopen("output_1c.txt", "w", stdout);
#endif

    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        int a1[n];
        for (int i = 0; i < n; i++) cin >> a1[i];

        int a2[m];
        for (int j = 0; j < m; j++) cin >> a2[j];

        vector<int> intersectionArray = findIntersection(a1, a2, n, m);

        for (auto x : intersectionArray) cout << x << " ";
        cout << endl;
    }

    return 0;
}
