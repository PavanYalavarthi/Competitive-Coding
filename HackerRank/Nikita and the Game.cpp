int helper(vector<long long>& prefixSum, int i, int j) {
    if(i == j) return 0;
    long long totalSum = prefixSum[j] - prefixSum[i-1];
    if (totalSum & 1) return 0;
    long long requiredSum = (prefixSum[j] + prefixSum[i-1]) / 2;
    int index = lower_bound(prefixSum.begin() + i, prefixSum.begin() + j + 1, requiredSum) - prefixSum.begin();
    if(prefixSum[index] != requiredSum) return 0;
    return 1 + max(helper(prefixSum, i, index), helper(prefixSum, index + 1, j)); 
}

int arraySplitting(vector<int> arr) {
    int n = arr.size();
    vector<long long>prefixSum(n +1);
    prefixSum[0] = 0;
    for(int i =0 ;i < n; i++) {
        prefixSum[i + 1] = prefixSum[i] + arr[i];
    }
    return helper(prefixSum, 1, n);
}