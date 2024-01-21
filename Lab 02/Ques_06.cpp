#include <iostream>
#include <algorithm>
using namespace std;

void medianQuickSort(int arr[], int left, int right) {
    if (right <= left) {
        return;
    }

    if (right - left == 1) {
        if (arr[left] > arr[right]) {
            swap(arr[left], arr[right]);
        }
        return;
    }

    int mid = left + (right - left) / 2;

    int minElement = min({arr[left], arr[right], arr[mid]});
    int maxElement = max({arr[left], arr[right], arr[mid]});
    int sum = arr[left] + arr[right] + arr[mid];

    arr[left] = minElement;
    arr[right] = maxElement;
    arr[mid] = sum - minElement - maxElement;

    int pivot = arr[mid];
    int i = left;
    int j = i + 1;

    swap(arr[mid], arr[right - 1]);

    for (; j <= right - 2; j++) {
        if (arr[j] < pivot) {
            swap(arr[++i], arr[j]);
        }
    }

    swap(arr[++i], arr[right - 1]);

    medianQuickSort(arr, left, i - 1);
    medianQuickSort(arr, i + 1, right);
}

void solve() {
    int n;
    cin >> n;
    int arrayToSort[n];

    for (int i = 0; i < n; i++) {
        cin >> arrayToSort[i];
    }

    medianQuickSort(arrayToSort, 0, n - 1);

    for (int i = 0; i < n; i++) {
        cout << arrayToSort[i] << ' ';
    }

    cout << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input_6.txt", "r", stdin);
    freopen("output_6.txt", "w", stdout);
#endif

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
