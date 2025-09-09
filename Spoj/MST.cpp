#include<bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<bool>visted(n + 1, false);
    vector<pair<int, int>> gr[n +1];
    for(int i = 0; i< m; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        gr[x].push_back({w, y});
        gr[y].push_back({w, x});
    }
    priority_queue<pair<int, int>> pq;
    int ans = 0;
    pq.push({0, 1});
    while(!pq.empty()) {
        auto& [weight, vertex] = pq.top();
        pq.pop();
        if(visited[vertex]) continue;
        visited[vertex] = true;
        for(auto &[w, y] : gr[vertex]) {
            if(!visited[y])
                pq.push({-w, y});
        }
        ans -= weight;
    }
    cout << ans;
    return 0;
}
