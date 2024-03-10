#include<bits/stdc++.h>
using namespace std;

int DFS(vector<int> graph[], int node, vector<int> &memo, vector<int> &visited) {
    if (visited[node])
        return memo[node];

    visited[node] = 1;
    int maxPath = 0;

    for (auto neighbor : graph[node])
        maxPath = max(maxPath, DFS(graph, neighbor, memo, visited));

    return memo[node] = 1 + maxPath;
}

int longestPath(vector<int> graph[], int N, int M) {
    vector<int> visited(N, 0);
    vector<int> memo(N, -1);

    for (int i = 0; i < N; i++) {
        if (!visited[i]) {
            DFS(graph, i, memo, visited);
        }
    }

    int answer = 0;
    for (auto pathLength : memo)
        answer = max(answer, pathLength);

    return answer;
}

int main() {
    freopen("input2.txt", "r", stdin);
    freopen("output2.txt", "w", stdout);

    int t;
    cin >> t;

    while (t--) {
        int N, M;
        cin >> N >> M;

        vector<int> graph[N];

        for (int i = 0; i < M; i++) {
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
        }

        cout << longestPath(graph, N, M) << endl;
    }

    return 0;
}
