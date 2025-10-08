#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007

int n;
vector<vector<ll>> dp;
ll dfs(int node, int par, vector<int> gr[]) {
    ll ans = 0;
    for(int child: gr[node]) {
        if (child != par) {
            ans += dfs(child, node, gr);
        }
    }
    return ans == 0 ? 1 : ans;
}

long long pow4(long long exp) {
    long long result = 1, base = 4;
    base %= MOD;
    while (exp > 0) {
        if (exp & 1) 
            result = (result * base) % MOD;
        base = (base * base) % MOD;
        exp >>= 1;
    }
    return result;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--) {
        cin >> n;
        vector<int>gr[n];
        for(int i = 0; i < n - 2; i++) {
            int u, v;
            cin >> u >> v;
            gr[u].push_back(v);
            gr[v].push_back(u);
        }
        // Leaves can take Val_of_N ^ (xor of all the node on the top)
        // So, leaf nodes has 1 option and rest of nodes can have any of 4 options.
        int ans = n - dfs(1, 0, gr);
        cout << pow4(ans) << endl;
    }
}
