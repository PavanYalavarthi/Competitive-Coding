vector<int> bfs(int n, int m, vector<vector<int>> edges, int s) {
    vector<int> gr[n];
    for(int i = 0; i < m; i++) {
        int u = edges[i][0] - 1, v = edges[i][1] - 1;
        gr[u].push_back(v);
        gr[v].push_back(u);
    }
    s--;
    vector<int> res(n, -1);
    res[s] = 0;
    queue<int> que;
    que.push(s);
    while(!que.empty()) {
        int node = que.front();
        que.pop();
        for(int child: gr[node]) {
            if(res[child] == -1) {
                res[child] = res[node] + 6;
                que.push(child);
            }
        }
    }
    res.erase(res.begin() + s);
    return res;
}