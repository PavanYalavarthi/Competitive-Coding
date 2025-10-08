#include<bits/stdc++.h>
using namespace std;
#define ll long long

struct DSU {
    vector<int> par, sz;

    DSU(int n) {
        par.resize(n);
        iota(par.begin(), par.end(), 0);
        sz.assign(n, 1);
    }

    int find(int x) {
        if (par[x] == x) return x;
        return par[x] = find(par[x]);
    }

    ll unite(int x, int y) {
        int u = find(x), v = find(y);
        ll ret_val = 1LL * sz[u] * sz[v];
        if (sz[u] > sz[v]) swap(u, v);
        par[u] = v;
        sz[v] += sz[u];
        return ret_val; 
    }

};

int main() {
    int n, m;
    cin >> n >> m;
    DSU dsu(n+1);
    vector<vector<int>> edges;
    for(int i = 1; i < n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({w, u, v});
    }
    sort(edges.begin(), edges.end());
    map<int, ll> mp;
    for(auto& edge: edges) {
        int w = edge[0], u = edge[1], v = edge[2];
        mp[w] += dsu.unite(u, v);
    }
    ll prev_val = 0;
    for(auto& entry: mp) {
        entry.second += prev_val;
        prev_val = entry.second;
    }
    while(m--) {
        int w;
        cin >> w;
        auto it = mp.upper_bound(w);
        cout << (it != mp.begin() ? (--it)->second : 0) << ' ';
    }
    return 0;
}