#include<bits/stdc++.h>
using namespace std;
vector<int> tin, tout, parent, depth;
int timer = 0;
void dfs(int node, int par, vector<int> gr[]) {
    parent[node] = par;
    depth[node] = depth[par] + 1;
    tin[node] = timer++;
    for(int child: gr[node]) {
        if (parent[child] == -1)
            dfs(child, node, gr);
    }
    tout[node] = timer++;
}
int main() {
    int n, m;
    cin >> n >> m;
    n++;
    vector<int> gr[n];
    for(int i = 2; i< n; i++) {
        int u, v;
        cin >> u >> v;
        gr[u].push_back(v);
        gr[v].push_back(u);
    }
    tin = tout = parent = depth = vector<int>(n, -1);
    dfs(1, 0, gr);
    tout[0] = INT_MAX;
    while(m--) {
        int k;
        cin >> k;
        vector<int>v(k);
        int farthestNode = 0;
        for(int& i: v) {
            cin >> i;
            if(depth[farthestNode] < depth[i]) {
                farthestNode = i;
            }
            i = parent[i];
        }
        string ans = "YES";
        for(int i: v) {
            if(tin[i] > tin[farthestNode] || tout[i] < tout[farthestNode]) {
                ans = "NO";
                break;
            }
        }
        cout << ans << endl;
    }
}