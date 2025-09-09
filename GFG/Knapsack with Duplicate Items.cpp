// User function Template for C++

class Solution {
  public:
    int helper(vector<int>& val, vector<int>& wt, int capacity, int i, vector<vector<int>> & dp) {
        if (i < 0 || capacity == 0) return 0;
        if (dp[i][capacity] != -1) return dp[i][capacity];
        int ans = helper(val, wt, capacity, i - 1, dp);
        if (wt[i] <= capacity) ans = max(ans, val[i] + helper(val, wt, capacity - wt[i], i, dp));
        return dp[i][capacity] = ans;
    }
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        int n = val.size();
        vector<vector<int>>dp(n, vector<int>(capacity + 1, -1));
        return helper(val, wt, capacity, n - 1, dp);
    }
};