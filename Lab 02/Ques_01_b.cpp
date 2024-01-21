#include<bits/stdc++.h>
using namespace std;

vector<int> unionOfArrays(int a1[], int a2[], int n, int m) {
    int i = 0, j = 0;
    vector<int> unionArray;

    while (i < n && j < m) {
        if (a1[i] < a2[j]) {
            unionArray.push_back(a1[i]);
            i++;
            while (i < n && a1[i] == a1[i - 1]) i++;
        } else if (a1[i] > a2[j]) {
            unionArray.push_back(a2[j]);
            j++;
            while (j < m && a2[j] == a2[j - 1]) j++;
        } else {
            // If both elements are equal, include only one and move both indices
            unionArray.push_back(a1[i]);
            i++;
            j++;
            while (i < n && a1[i] == a1[i - 1]) i++;
            while (j < m && a2[j] == a2[j - 1]) j++;
        }
    }

    // Include remaining elements of both arrays
    while (i < n) {
        unionArray.push_back(a1[i]);
        i++;
        while (i < n && a1[i] == a1[i - 1]) i++;
    }

    while (j < m) {
        unionArray.push_back(a2[j]);
        j++;
        while (j < m && a2[j] == a2[j - 1]) j++;
    }

    return unionArray;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input_1a.txt", "r", stdin);
    freopen("output_1b.txt", "w", stdout);
#endif

    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        int a1[n], a2[m];

        for (int i = 0; i < n; i++) cin >> a1[i];
        for (int i = 0; i < m; i++) cin >> a2[i];

        vector<int> unionArray = unionOfArrays(a1, a2, n, m);

        for (auto x : unionArray) cout << x << " ";
        cout << endl;
    }

    return 0;
}
