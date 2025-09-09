class Solution {
    int final_mask;
    vector<vector<int>> dp;
  public:
    int helper(vector<vector<int>>& cost, int mask, int prevCity) {
        if (mask == final_mask) return cost[prevCity][0];
        if (dp[mask][prevCity] != -1) return dp[mask][prevCity];
        int ans = INT_MAX;
        for(int i = 1; i< cost.size(); i++) {
            if ((mask & 1 << i) == 0) {
                ans = min(ans, cost[prevCity][i] + helper(cost, mask | (1 << i), i));
            }
        }
        return dp[mask][prevCity] = ans;
    } 
    int tsp(vector<vector<int>>& cost) {
        int n = cost.size();
        dp.assign(1 << n, vector<int>(n, -1));
        final_mask = (1 << n) - 1;
        return helper(cost, 1, 0);
    }
    
    
};