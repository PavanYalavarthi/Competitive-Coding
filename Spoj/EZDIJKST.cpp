#include<bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--) {
        int n, e;
        cin >> n >> e;
        vector<int>dist(n+1, INT_MAX);
        vector<pair<int, int>>gr[n + 1];
        for(int i = 0; i< e; i++) {
            int x, y, w;
            cin >> x >> y >> w;
            gr[x].push_back({w, y});
        }
        set<pair<int,int>> s;
        int src, target;
        cin >> src >> target;
        dist[src] = 0;
        s.insert({0, src});
        while (!s.empty()) {
            auto [weight, vertex] = *s.begin();
            if (vertex == target) break;
            s.erase(s.begin());
            for(auto &[w, y] : gr[vertex]) {
                if (weight + w < dist[y]) {
                    s.erase({dist[y], y});
                    dist[y] = weight + w;
                    s.insert({dist[y], y});
                }
            }
        }
        if (dist[target] == INT_MAX)
            cout << "NO\n";
        else
            cout << dist[target] << '\n';
    }
    return 0;
}
