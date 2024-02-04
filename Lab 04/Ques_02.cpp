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

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int totalSize = nums1.size() + nums2.size();
    int n = nums1.size();
    int m = nums2.size();

    int ans = 0, prev = 0;
    int i = 0, j = 0;
    int targetIndex = totalSize / 2;
    int count = -1;

    bool isEven = (totalSize % 2 == 0);

    while (count != targetIndex && i < n && j < m) {
        if (nums1[i] <= nums2[j]) {
            prev = ans;
            ans = nums1[i];
            i++;
            count++;
        } else {
            prev = ans;
            ans = nums2[j];
            j++;
            count++;
        }
    }

    while (i < n && count != targetIndex) {
        prev = ans;
        ans = nums1[i];
        i++;
        count++;
    }

    while (j < m && count != targetIndex) {
        prev = ans;
        ans = nums2[j];
        j++;
        count++;
    }

    return (isEven) ? (double)(ans + prev) / 2 : ans;
}

int main(){
    freopen("input2.txt","r",stdin);
    freopen("output2.txt","w",stdout);

    int t; cin>>t;
    while(t--){
        int n, m;
        cin >> n >> m;
        
        vector<int> a(n), b(m);
        
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < m; i++) cin >> b[i];
        
        cout << findMedianSortedArrays(a, b) << endl;
    }

    return 0;
}