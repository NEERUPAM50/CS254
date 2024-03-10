#include <bits/stdc++.h>
using namespace std;

void DFS(vector<int> adj[], int node, int visited[], stack<int>& st) {
    if (visited[node]) return;
    visited[node] = 1;
    for (auto neighbor : adj[node]) {
        if (!visited[neighbor]) {
            DFS(adj, neighbor, visited, st);
        }
    }
    st.push(node);
}

void printDFS(vector<int> adj[], int node, int visited[]) {
    if (visited[node]) return;
    visited[node] = 1;
    cout << node << ' ';
    for (auto neighbor : adj[node]) {
        if (!visited[neighbor]) {
            printDFS(adj, neighbor, visited);
        }
    }
}

void stronglyConnectedComponent(vector<int> adj[], int V) {
    stack<int> st;
    int visited[V] = {0};
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            DFS(adj, i, visited, st);
        }
    }

    vector<int> reverseAdj[V];
    for (int i = 0; i < V; i++) {
        for (auto neighbor : adj[i]) {
            reverseAdj[neighbor].push_back(i);
        }
    }

    for (int i = 0; i < V; i++) {
        visited[i] = 0;
    }

    while (!st.empty()) {
        int u = st.top();
        st.pop();
        if (!visited[u]) {
            printDFS(reverseAdj, u, visited);
            cout << endl;
        }
    }
}

int main() {
    freopen("input3.txt", "r", stdin);
    freopen("output3.txt", "w", stdout);

    int t;
    cin >> t;

    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        while (E--) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        stronglyConnectedComponent(adj, V);
        cout << endl;
    }

    return 0;
}
