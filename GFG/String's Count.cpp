long long dp[100001][2][3];
long long helper(long long n, int b, int c) {
    if(n == 0) return 1;
    if (dp[n][b][c] != -1) return dp[n][b][c];
    long long ans = helper(n-1, b, c);
    if (b) ans += helper(n-1, b-1, c);
    if (c) ans += helper(n-1, b, c-1);
    return dp[n][b][c] = ans;
}

long long int countStr(long long int n) {
    memset(dp, -1, sizeof(dp));
    return helper(n, 1, 2);
}

