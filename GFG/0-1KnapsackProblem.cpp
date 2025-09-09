class Solution {
  public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        vector<vector<int>>dp(val.size(), vector<int>(W + 1, -1));
        return helper(W, val, wt, 0, dp);
    }
    
    int helper(int W, vector<int> &val, vector<int> &wt, int index, vector<vector<int>>& dp) {
        if(index == val.size() || W == 0) return 0;
        if(dp[index][W] != -1) return dp[index][W];
        int ans = helper(W, val, wt, index +1, dp);
        if (wt[index] <= W) ans = max(ans, val[index] + helper(W - wt[index], val, wt, index + 1, dp));
        return dp[index][W]  = ans;
    }
    
};