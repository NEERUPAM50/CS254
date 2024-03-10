#include<bits/stdc++.h>
using namespace std;

int timer = 0;

void findBridges(vector<int> adj[], int current, int parent, int visited[], int low[], int discovery_time[], vector<pair<int, int>>& bridges) {
    visited[current] = 1;
    discovery_time[current] = timer++;
    low[current] = discovery_time[current];

    for (auto neighbor : adj[current]) {
        if (neighbor == parent) continue;

        if (!visited[neighbor]) {
            findBridges(adj, neighbor, current, visited, low, discovery_time, bridges);
            low[current] = min(low[current], low[neighbor]);

            if (low[neighbor] > discovery_time[current]) {
                bridges.push_back({current, neighbor});
            }
        } else {
            low[current] = min(low[current], low[neighbor]);
        }
    }
}

void printBridges(vector<int> adj[], int V) {
    vector<pair<int, int>> bridges;
    int visited[V] = {0}, low[V], discovery_time[V];

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            findBridges(adj, i, -1, visited, low, discovery_time, bridges);
        }
    }

    cout << "Bridges in the graph:" << endl;
    for (auto bridge : bridges) {
        cout << bridge.first << ' ' << bridge.second << endl;
    }
}

int main() {
    freopen("input5_01.txt", "r", stdin);
    freopen("output5_01.txt", "w", stdout);

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
            adj[v].push_back(u);
        }

        printBridges(adj, V);
    }

    return 0;
}
