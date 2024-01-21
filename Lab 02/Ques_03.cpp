#include<bits/stdc++.h>
using namespace std;

void inplaceMerge(int arr[], int n, int m) {
    int gap = n / 2;

    while (gap > 0) {
        for (int i = 0; i + gap < n; i++) {
            int j = i + gap;

            if (arr[i] > arr[j]) {
                swap(arr[i], arr[j]);
            }
        }

        gap /= 2;
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input_3.txt", "r", stdin);
    freopen("output_3.txt", "w", stdout);
#endif

    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        inplaceMerge(arr, n, m);

        for (int i = 0; i < n; i++) {
            cout << arr[i] << ' ';
        }
        cout << endl;
    }

    return 0;
}
