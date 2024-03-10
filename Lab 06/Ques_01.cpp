#include<bits/stdc++.h>
using namespace std;

void topological_sort(vector<int> adj[], int V) {
    queue<int> q;
    vector<int> indegree(V, 0);

    for (int i = 0; i < V; i++) {
        for (auto x : adj[i]) {
            indegree[x]++;
        }
    }

    for (int i = 0; i < V; i++) {
        if (!indegree[i]) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int u = q.front();
        cout << u << ' ';
        q.pop();
        
        for (auto x : adj[u]) {
            indegree[x]--;
            if (!indegree[x]) {
                q.push(x);
            }
        }
    }

    cout << endl;
}

int main() {
    freopen("input1.txt", "r", stdin);
    freopen("output1.txt", "w", stdout);

    int t;
    cin >> t;

    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        topological_sort(adj, V);
    }

    return 0;
}
