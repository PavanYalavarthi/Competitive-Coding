#include<bits/stdc++.h>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    n++;
    vector<int>gr[n];
    while(m--) {
        int u, v;
        cin >> u >> v;
        gr[u].push_back(v);
        gr[v].push_back(u);
    }
    set<int>s;
    bool visited[n] = {false};
    vector<int>ans;
    ans.reserve(n - 1);
    s.insert(1);
    while(!s.empty()) {
        int node = *(s.begin());
        s.erase(s.begin());
        if (visited[node]) continue;
        ans.push_back(node);
        visited[node] = true;
        s.insert(gr[node].begin(), gr[node].end());
    }
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    return 0;
}