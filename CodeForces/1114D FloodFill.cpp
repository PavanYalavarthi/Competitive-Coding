#include<bits/stdc++.h>
using namespace std;

int helper(vector<int>& arr, int i, int j, vector<vector<int>>& dp) {
    if(i == j) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    if(arr[i] == arr[j]) return dp[i][j] = 1 + helper(arr, i+1, j-1, dp);
    return dp[i][j] = 1 + min(helper(arr, i+1, j, dp), helper(arr, i, j-1, dp)); 
} 
int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    arr.resize(unique(arr.begin(), arr.end()) - arr.begin());
    vector<vector<int>>dp(arr.size(), vector<int>(arr.size(), -1));
    cout << helper(arr, 0, arr.size() -1, dp);
    return 0;
}