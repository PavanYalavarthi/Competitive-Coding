// https://www.codechef.com/practice/course/dynamic-programming/INTDP01/problems/ZCO14004

#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int n, sum =0;
    cin >> n;
    vector<int>dp(n+1);
    for(int i = 0; i < n; i++) {
        cin >> dp[i];
        sum += dp[i];
    }
    dp[n] = 0;
    for(int i = 3; i<=n;i++) {
        dp[i] += min({dp[i-1], dp[i-2], dp[i-3]});
    }
    cout << sum - dp[n];
    return 0;

}
