class Solution {
  public:
    int maximumAmount(vector<int> &arr) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return helper(arr, 0, n -1, dp);
    }
    
    int helper(vector<int> &arr, int i, int j, vector<vector<int>>& dp) {
        if (i > j) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        int left = arr[i] + min(helper(arr, i + 2, j, dp) , helper(arr, i+1, j-1, dp));
        int right = arr[j] + min(helper(arr, i, j -2, dp), helper(arr, i +1, j-1, dp));
        return dp[i][j] = max(left, right);
    }
};