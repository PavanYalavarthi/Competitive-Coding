#include <bits/stdc++.h>
using namespace std;
#define int long long

int helper(vector<int> & prefixSum, int i, int j, vector<vector<int>>& dp) {
    if (i == j) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    int  ans = 1e18, cost = prefixSum[j] - prefixSum[i-1];
    for(int k = i; k < j; k++) {
        ans = min(ans, helper(prefixSum, i, k, dp) + helper(prefixSum, k +1, j, dp) + cost);
    }
    return dp[i][j] = ans;
}
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while(T--) {
        int N;
        cin >> N;
        vector<int>v(N);
        vector<int>prefixSum(2*N + 1);
        prefixSum[0] = 0;
        for(int i = 0; i< N; i++) {
            cin >> v[i];
            prefixSum[i + 1] = prefixSum[i] + v[i]; 
        }
        for(int i = N; i < 2 * N; i++) {
            prefixSum[i + 1] = prefixSum[i] + v[i - N];
        }
        int ans = 1e18;
        vector<vector<int>>dp(prefixSum.size(), vector<int>(prefixSum.size(), -1));
        for(int i =1 ;i <= N; i++) {
            ans = min(ans, helper(prefixSum, i, i + N - 1, dp));
        }
        cout << ans << endl;
    }
    return 0;
}
