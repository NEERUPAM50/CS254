#include <bits/stdc++.h>
using namespace std;

int main(){
#ifndef ONLINE_JUDGE
    freopen("input1.txt", "r", stdin);
    freopen("output1.txt", "w", stdout);
#endif

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
            cin >> a[i];

        int mx = INT_MIN;
        int smx = INT_MIN;

        for(int i = 0; i < n; i++) {
            if(a[i] >= mx) {
                smx = max(smx, mx);
                mx = a[i];
            }
            else {
                if(a[i] > smx)
                    smx = a[i];
            }
        }

        cout << mx + smx << endl;
    }

    return 0;
}
