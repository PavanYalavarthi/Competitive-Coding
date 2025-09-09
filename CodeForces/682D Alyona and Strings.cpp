#include<bits/stdc++.h>
using namespace std;
string s, t;
int dp[1000][1000][10][2];
int helper(int i, int j, int k, bool doContinue) {
    if (i == s.size() or j == t.size() or k == 0) return (k == 0) ? 0 : INT_MIN;
    if(dp[i][j][k -1][doContinue] != -1) return dp[i][j][k -1][doContinue];
    int ans = INT_MIN;
    if (s[i] == t[j]) ans = max({ans, 1 + helper(i +1, j +1, k, true), 1 + helper(i +1, j +1, k-1, false)});
    ans = max({ans, helper(i + 1, j, k - doContinue, false), helper(i, j+1, k- doContinue, false)});
    return dp[i][j][k -1][doContinue] = ans;
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int m, n, k;
    cin >> m >> n >> k;
    cin >> s >> t;
    memset(dp, -1,  sizeof(dp));
    cout << helper(0, 0, k, false);
    return 0;
}