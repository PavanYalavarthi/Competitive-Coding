#include<bits/stdc++.h>
using namespace std;
vector<bool>visited;
void dfs(int node, vector<int>gr[]) {
    visited[node] = true;
    for(int child: gr[node]) {
        if(!visited[child])
            dfs(child, gr);
    }
}
int main() {
    int n;
    cin >> n;
    vector<int>idx[26];
    for(int i = 0; i< n; i++) {
        string s;
        cin >> s;
        for(int j = 0; j< s.size(); j++)
            idx[s[j] - 'a'].push_back(i);
    }
    vector<int>gr[n];
    for(int i =0; i< 26; i++) {
        for(int j = 1; j < idx[i].size(); j++) {
            int u = idx[i][j -1], v = idx[i][j];
            gr[u].push_back(v);
            gr[v].push_back(u);
        }
    }
    visited.assign(n, false);
    int ans = 0;
    for(int i = 0; i< n; i++) {
        if(!visited[i]) {
            ans++;
            dfs(i, gr);
        }
    }
    cout << ans;
    return 0;
}