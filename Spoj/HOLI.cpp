#include<bits/stdc++.h>
using namespace std;
long long cnt;
int n;
int dfs(int i, vector<vector<pair<int, int>>> & gr, vector<bool>& visited) {
    visited[i] = true;
    int nodes = 1;
    for(auto& [vertex, weight] : gr[i]) {
        if (!visited[vertex]) {
            int nodeCount = dfs(vertex, gr, visited);
            nodes += nodeCount;
            cnt += 2 * weight * min(nodeCount, n - nodeCount);
        }
    }
    return nodes;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        cin >> n;
        vector<vector<pair<int, int>>> gr(n+1);
        for(int j = 1; j < n; j++) {
            int u, v, cost;
            cin >> u >> v >> cost;
            gr[u].push_back({v, cost});
            gr[v].push_back({u, cost});
        }
        vector<bool>visited(n+1, false);
        cnt = 0;
        dfs(1, gr, visited);
        cout << "Case #" << i << ": " << cnt <<'\n';
    }
    return 0;
}