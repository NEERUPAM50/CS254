#include <bits/stdc++.h>
using namespace std;

int partition(int arr[], int pos, int left, int right) {
    int i = left - 1, j = left;
    int pivot = arr[right];

    for (; j <= right - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[++i], arr[right]);
    return i;
}

float findMedian(int arr[], int size) {
    int mid1 = (size - 1) / 2;
    int mid2 = size / 2;

    int median1 = partition(arr, mid1, 0, size - 1);
    int median2 = (size % 2 == 0) ? partition(arr, mid2, 0, size - 1) : median1;

    return (float(median1) + float(median2)) / 2;
}

void solve() {
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    float medianValue = findMedian(arr, n);
    cout << medianValue << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input_4.txt", "r", stdin);
    freopen("output_4.txt", "w", stdout);
#endif

    int testCases;
    cin >> testCases;

    while (testCases--) {
        solve();
    }

    return 0;
}
