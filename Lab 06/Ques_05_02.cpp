#include<bits/stdc++.h>
using namespace std;

int timer = 0;

void dfs(int node, int parent, vector<int>& visited, int discovery_time[], int low[], vector<int>& articulationPoints, vector<int> adj[]) {
    visited[node] = 1;
    discovery_time[node] = low[node] = timer++;
    int childCount = 0;

    for (auto neighbor : adj[node]) {
        if (neighbor == parent) continue;

        if (!visited[neighbor]) {
            dfs(neighbor, node, visited, discovery_time, low, articulationPoints, adj);
            low[node] = min(low[node], low[neighbor]);

            if (low[neighbor] >= discovery_time[node] && parent != -1) {
                articulationPoints[node] = 1;
            }

            childCount++;
        } else {
            low[node] = min(low[node], discovery_time[neighbor]);
        }
    }

    if (childCount > 1 && parent == -1) {
        articulationPoints[node] = 1;
    }
}

void findArticulationPoints(int vertices, vector<int> adj[]) {
    vector<int> visited(vertices, 0);
    int discovery_time[vertices], low[vertices];
    vector<int> articulationPoints(vertices, 0);

    for (int i = 0; i < vertices; i++) {
        if (!visited[i]) {
            dfs(i, -1, visited, discovery_time, low, articulationPoints, adj);
        }
    }

    vector<int> result;
    bool noArticulationPoints = true;

    for (int i = 0; i < vertices; i++) {
        if (articulationPoints[i]) {
            cout << i << ' ';
            noArticulationPoints = false;
        }
    }

    if (noArticulationPoints) {
        cout << "no articulation point";
    }

    cout << endl;
}

int main() {
    freopen("input5_02.txt", "r", stdin);
    freopen("output5_02.txt", "w", stdout);

    int t;
    cin >> t;

    while (t--) {
        int vertices, edges;
        cin >> vertices >> edges;
        vector<int> adj[vertices];

        for (int i = 0; i < edges; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        findArticulationPoints(vertices, adj);
    }

    return 0;
}
