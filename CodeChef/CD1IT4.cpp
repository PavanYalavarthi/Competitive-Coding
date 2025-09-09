#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

int main() {
    int M, N, P;
    cin >> M >> N >> P;
    vector<vector<int>>dp(M + 1, vector<int>(N + 1, 0));
    while(P--) {
        int i, j;
        cin >> i >> j;
        dp[i][j] = -1;
    }
    if(dp[1][1] == -1 || dp[M][N] == -1) {
        dp[M][N] = 0;
    } else {
        dp[1][1] = 1;
        for(int i =1; i <= M; i++) {
            for(int j =1; j<= N;j++) {
                if (i ==1 and j ==1) continue;
                if (dp[i][j] == -1) dp[i][j] = 0;
                else if (j == 1) dp[i][1] = dp[i-1][1];
                else if(i == 1) dp[1][j] = dp[1][j-1];
                else dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % MOD;
            }
        }
    }
    cout << dp[M][N];
    return 0;
}
