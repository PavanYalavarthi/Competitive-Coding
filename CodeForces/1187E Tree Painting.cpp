#include<bits/stdc++.h>
using namespace std;

#define ll long long

int n;
ll ans = 0;
vector<ll>sz, dp;
void dfs1(int node, int par, vector<int> gr[]) {
    for(int child : gr[node]) {
        if (child != par) {
            dfs1(child, node, gr);
            sz[node] += sz[child];
            dp[node] += dp[child];
        }
    }
    dp[node] += sz[node];
}

void dfs2(int node, int par, ll par_res, vector<int> gr[]) {
    ans = max(ans, dp[node] + par_res + n - sz[node]);
    for(int child: gr[node]) {
        if (child != par) {
            dfs2(child, node, par_res + n - sz[node] + dp[node] - dp[child] - sz[child], gr);
        }
    }
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n;
    vector<int>gr[n];
    for(int i = 1, u, v; i <n ;i++) {
        cin >> u >> v;
        u--, v--;
        gr[u].push_back(v);
        gr[v].push_back(u);
    }
    sz.assign(n, 1);
    dp.assign(n, 0);
    dfs1(0, -1, gr);
    dfs2(0, -1, 0, gr);
    cout << ans;
}