#include<bits/stdc++.h>
using namespace std;

bool hasLoop(vector<int> adjacency[], int vertices) {
    queue<int> q;
    vector<int> visited(vertices, 0);
    vector<int> inDegree(vertices, 0);

    for (int i = 0; i < vertices; i++) {
        for (auto x : adjacency[i]) {
            inDegree[x]++;
        }
    }

    for (int i = 0; i < vertices; i++) {
        if (!inDegree[i]) {
            q.push(i);
        }
    }

    int count = 0;
    while (!q.empty()) {
        int u = q.front();
        count++;
        q.pop();

        for (auto x : adjacency[u]) {
            inDegree[x]--;

            if (!inDegree[x]) {
                q.push(x);
            }
        }
    }

    return count != vertices;
}

int main() {
    freopen("input4.txt", "r", stdin);
    freopen("output4.txt", "w", stdout);

    int t;
    cin >> t;

    while (t--) {
        int N, E;
        cin >> N >> E;
        vector<int> adjacency[N];

        while (E--) {
            int u, v;
            cin >> u >> v;
            adjacency[u].push_back(v);
        }

        cout << (hasLoop(adjacency, N) ? "YES" : "NO") << endl;
    }

    return 0;
}
