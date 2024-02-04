#include<bits/stdc++.h>

#define F first
#define S second
#define ll long long 
#define pb push_back
#define mp make_pair
#define veci vector<int> 
#define sort(v) sort(v.begin(), v.end())
#define reverse(v) reverse(v.begin(), v.end())
#define vecp vector< pair<int, int> >
#define seti set<int>
#define sets set<string>
#define fr(i,a,b) for(int i=a; i<b; i++)
#define frr(i,a,b) for(int i=a; i>=b; i--)
#define go(y) for(auto &x : y)

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

using namespace std;

int main(){

    freopen("input1.txt","r",stdin);
    freopen("output1.txt","w",stdout);

    int t; cin>>t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)cin >> a[i];
        set<int> s;
        int count = 0;
        for (int i = 0; i < n; i++) {
            auto p = s.lower_bound(a[i]);
            count += distance(p, s.end());
            s.insert(a[i]);
        }
        cout << count << endl;
    }

    return 0;
}