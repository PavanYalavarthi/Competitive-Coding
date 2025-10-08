#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 2520
int k;
ll dp[20][2520][1 << 9][2]; //2520 as it is LCM of digits 1-9
ll helper(int pos, int modM, int mask, bool tight, const string & s) {
    if (dp[pos][modM][mask][tight] != -1) return dp[pos][modM][mask][tight];
    if(pos == s.size()) {
        int cnt = 0;
        for(int i = 1; i <= 9; i++) {
            if (mask & (1 << (i-1)) && modM % i == 0) 
                cnt++;
        }
        return dp[pos][modM][mask][tight] = (cnt >= k);
    } else {
        int last_digit = tight ? s[pos] - '0' : 9;
        int res = 0;
        for (int i = 0; i <= last_digit; i++) {
            if (i == 0)  //skipping zeros
                res += helper(pos + 1, (modM * 10) % MOD, mask, tight && (i == last_digit), s);
            else
                res += helper(pos+1, (modM * 10 + i) % MOD, mask | (1 << (i-1)), tight && (i == last_digit), s);
        }
        return dp[pos][modM][mask][tight] = res;
    }
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int Q;
    cin >> Q;
    while(Q--) {
        ll l, r;
        cin >> l >> r >> k;
        memset(dp, -1, sizeof(dp));
        ll ans = helper(0, 0, 0, true, to_string(r));
        memset(dp, -1, sizeof(dp));
        cout << ans - helper(0, 0, 0, true, to_string(l-1)) << endl;
    }
}
