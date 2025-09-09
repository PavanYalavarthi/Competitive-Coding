class Solution {
  public:
    int kadane(vector<int> row_sum) {
        int max_sum = INT_MIN, curr_sum = 0;
        for(int i =0; i< row_sum.size(); i++) {
            curr_sum = max(row_sum[i], curr_sum + row_sum[i]);
            max_sum = max(max_sum, curr_sum);
        }
        return max_sum;
    }
    int maxRectSum(vector<vector<int>> &mat) {
        int m = mat.size(), n= mat[0].size();
        vector<int>row_sum(m);
        int ans = -1000;
        for(int left = 0; left < n; left++) {
            memset(row_sum.data(), 0, m * sizeof(int));
            for(int right = left; right < n; right++) {
                for(int row = 0; row < m; row++) {
                    row_sum[row] += mat[row][right];
                }
                ans = max(ans, kadane(row_sum));
            }
        }
        return ans;
    }
};
