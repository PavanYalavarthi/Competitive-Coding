#include<bits/stdc++.h>
using namespace std;
#define MOD 100000000
int n1, n2, k1, k2;
int dp[101][101][11][11];
int helper(int n1, int n2, int continuous_n1, int continuous_n2) {
    if (n1 ==0 || n2 == 0) return (n1 <= k1 && n2 <= k2);
    if (dp[n1][n2][continuous_n1][continuous_n2] != -1) return dp[n1][n2][continuous_n1][continuous_n2];
    int ans = 0;
    if (n1 != 0 && continuous_n1 < k1) (ans += helper(n1 -1, n2, continuous_n1 + 1, 0)) %= MOD;
    if (n2 != 0 && continuous_n2 < k2) (ans +=helper(n1, n2 -1, 0, continuous_n2 +1)) %= MOD;
    return dp[n1][n2][continuous_n1][continuous_n2] = ans; 
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n1 >> n2 >> k1 >> k2;
    memset(dp, -1, sizeof(dp));
    cout << helper(n1, n2, 0, 0);
    return 0;
}