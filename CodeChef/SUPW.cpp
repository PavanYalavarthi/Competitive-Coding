// https://www.codechef.com/practice/course/dynamic-programming/INTDP01/problems/ZCO14002?tab=statement

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int>dp(n);
    for(int & i: dp) {
        cin >> i;
    }
    dp.push_back(0);
    for(int i = 3; i <= n ; i++) {
        dp[i] += min(dp[i-1], min(dp[i-2], dp[i-3]));
    }
    cout << dp[n];
    return 0;
}