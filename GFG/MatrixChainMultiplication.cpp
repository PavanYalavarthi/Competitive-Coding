class Solution {
    vector<vector<int>>dp;
  public:
    int matrixMultiplication(vector<int> &arr) {
        // code here
        int n = arr.size();
        dp = vector<vector<int>>(n, vector<int>(n, -1));
        return helper(arr, 0, arr.size() -1);
    }
    
    int helper(vector<int> &arr, int i, int j) {
        if(i + 1 == j) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        int ans = INT_MAX;
        for(int k = i + 1; k < j ; k++) {
            ans = min(ans, helper(arr, i,k) + helper(arr,k, j) + arr[i] * arr[j] * arr[k]);
        }
        return dp[i][j] = ans;
    }
};