class Solution {
  public:
    int lcsOf3(string& s1, string& s2, string& s3) {
        int m = s1.size(), n = s2.size(), o = s3.size();
        int dp[m+1][n+1][o+1];
        memset(dp, 0, sizeof(dp));
        int ans = 0;
        for(int i = 0; i< m; i++) {
            for(int j = 0; j<n; j++) {
                for(int k = 0; k < o; k++) {
                    if (s1[i] == s2[j] and s2[j] == s3[k])
                        ans = max(ans, dp[i+1][j+1][k+1] = dp[i][j][k] + 1);
                    else 
                        dp[i+1][j+1][k+1] = max({dp[i][j+1][k+1], dp[i+1][j][k+1], dp[i+1][j+1][k]});
                }
            }
        }
        return ans;
    }
};
