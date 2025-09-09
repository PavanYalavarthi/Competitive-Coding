#include<bits/stdc++.h>
using namespace std;

int cummulativeSum(vector<int> & prefixSum, int i, int j) {
    return (prefixSum[j] - prefixSum[i-1] + 100) % 100;
}
int helper(vector<int> & prefixSum, int i, int j, vector<vector<int>> &dp) {
    if (i == j) return 0;
    if (dp[i][j] != -1) return dp[i][j];
    int ans = INT_MAX;
    for(int k = i; k < j; k++) {
        ans = min(ans, helper(prefixSum, i, k, dp) + helper(prefixSum, k + 1, j, dp) + cummulativeSum(prefixSum, i, k) * cummulativeSum(prefixSum, k + 1, j));
    }
    return dp[i][j] = ans;
}
int main() {
    int t;
    cin.tie(nullptr)->sync_with_stdio(false);
    while(true) {
        int n;
        if(cin >> n) {
            vector<int>prefixSum(n +1);
            prefixSum[0] = 0;
            for(int i = 1; i<= n; i++) {
                cin >> prefixSum[i];
                prefixSum[i] = (prefixSum[i] +  prefixSum[i-1]) % 100;
            }
            vector<vector<int>> dp (n + 1, vector<int>(n+1, -1));
            cout << helper(prefixSum,1, n, dp) << endl;
        } else {
            break;
        }
    }
}