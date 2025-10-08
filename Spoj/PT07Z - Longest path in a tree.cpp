#include<bits/stdc++.h>
using namespace std;
int ans = 0;
int dfs(int node, int par, vector<int>gr[]) {
    int max1 = 0, max2 = 0;
    for(int child: gr[node]) {
        if (child != par) {
            int len = dfs(child, node, gr) + 1;
            if(len > max1) {
                max2 = max1;
                max1 = len;
            } else if(len > max2) {
                max2 = len;
            }
        }
    }
    ans = max(ans, max1 + max2);
    return max1;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int>gr[n + 1];
    for(int i = 1; i<n;i++) {
        int a, b;
        cin >> a >> b;
        gr[a].push_back(b);
        gr[b].push_back(a);
    }
    dfs(1, 0, gr);
    cout << ans;
}