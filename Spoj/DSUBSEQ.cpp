#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
int main() {
    int t;
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        int n = s.size();
        vector<int>dp(n + 1);
        vector<int>last(26, -1);
        dp[0] = 1;
        for(int i = 1; i<= n; i++) {
            dp[i] = (2 * dp[i - 1]) % MOD;
            int lastIndex = last[s[i-1] - 'A'];
            if(lastIndex != -1) dp[i] = (dp[i] - dp[lastIndex] + MOD)%MOD;
            last[s[i-1] - 'A'] = i - 1;
        }
        cout << dp[n] << '\n';
    }
    return 0;
}