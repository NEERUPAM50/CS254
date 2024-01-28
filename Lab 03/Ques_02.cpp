#include <iostream>
#include <vector>
using namespace std;

const int MAX_N = 1e7;
vector<int> arr(MAX_N);

long long calcCrossSum(int l, int m, int r) {
    long long mxL = 0, mxR = 0;
    long long sum = 0;

    for (int i = m; i >= l; i--) {
        sum += arr[i];
        mxL = max(mxL, sum);
    }

    sum = 0;
    for (int i = m + 1; i <= r; i++) {
        sum += arr[i];
        mxR = max(mxR, sum);
    }

    return mxL + mxR;
}

long long maxSubarraySum(int l, int r) {
    if (l == r) {
        return arr[l];
    }

    int m = l + (r - l) / 2;
    long long left = maxSubarraySum(l, m);
    long long right = maxSubarraySum(m + 1, r);
    long long mid = calcCrossSum(l, m, r);

    return max(max(left, right), mid);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input2.txt", "r", stdin);
    freopen("output2.txt", "w", stdout);
    #endif

    int t; cin>>t;

    while(t--){
        int n;
        cin >> n;

        arr.resize(n);

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        long long ans = maxSubarraySum(0, n - 1);
        cout << ans << '\n';
    }

    return 0;
}
