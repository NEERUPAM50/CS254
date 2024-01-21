#include <iostream>
#include <vector>
#define ll long long

using namespace std;

void findTwoMinElements(vector<ll> &v) {
    if (v.size() < 2) {
        // Return -1 when not possible
        cout << -1 << endl;
        return;
    }

    // Initialize the two min elements
    ll min1 = min(v[0], v[1]);
    ll min2 = max(v[0], v[1]);

    // Iterate through the array to find the two min elements
    for (ll i = 2; i < v.size(); ++i) {
        if (v[i] < min1) {
            min2 = min1;
            min1 = v[i];
        } else if (v[i] < min2) {
            min2 = v[i];
        }
    }

    cout << min1 << " " << min2 << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input_5.txt", "r", stdin);
    freopen("output_5.txt", "w", stdout);
#endif

    ll t;
    cin >> t;

    while (t--) {
        ll n;
        cin >> n;

        vector<ll> v;
        ll x;

        for (int i = 0; i < n; i++) {
            cin >> x;
            v.push_back(x);
        }

        findTwoMinElements(v);
    }

    return 0;
}
