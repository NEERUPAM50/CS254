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

int findKthLargest(const vector<int>& nums, int k) {
    priority_queue<int, vector<int>, greater<int>> minHeap;

    for (int i = 0; i < k; ++i) {
        minHeap.push(nums[i]);
    }

    for (int i = k; i < nums.size(); ++i) {
        if (nums[i] > minHeap.top()) {
            minHeap.pop();
            minHeap.push(nums[i]);
        }
    }

    return minHeap.top();
}

int main(){
    freopen("input3.txt","r",stdin);
    freopen("output3.txt","w",stdout);

    int t; cin>>t;
    while(t--){
        int n, k;
    
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < n; i++)cin >> nums[i];

        int result = findKthLargest(nums, k);

        cout << result << endl;
    }

    return 0;
}