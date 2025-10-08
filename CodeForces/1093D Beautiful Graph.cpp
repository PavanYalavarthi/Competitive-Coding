#include<bits/stdc++.h>
using namespace std;
#define MOD 998244353
int cnt1, cnt0;
vector<int> visited;

long long pow2 (int n) {
    long long ans = 1, base = 2;
    while (n > 0) {
        if (n & 1) ans = (ans * base) % MOD;
        base = (base * base) % MOD; 
        n >>= 1; 
    }
    return ans;
}
bool dfs(int node, vector<int> gr[], int parity) {
    visited[node] = parity;
    if (parity == 0) cnt0++;
    else cnt1++;
    for(int child: gr[node]) {
        if(visited[child] == parity || (visited[child] == -1 && !dfs(child, gr, 1 - parity)))
            return false;
    }
    return true;
}

long long solve() {
    int n, m;
    cin >> n >> m;
    vector<int> gr[n];
    while(m--) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        gr[u].push_back(v);
        gr[v].push_back(u);
    }
    visited.assign(n, -1);
    long long ans = 1;
    for(int i = 0; i< n; i++) {
        if (visited[i] != -1) continue;
        cnt0 = 0, cnt1 =0;
        if (dfs(i, gr, false) == false)
            return 0;
        (ans *= (pow2(cnt0) + pow2(cnt1))) %= MOD;
    }
    return ans;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        cout << solve() << endl;
    }
    return 0;
}