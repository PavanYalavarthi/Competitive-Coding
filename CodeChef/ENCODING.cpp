#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define ll long long

ll dp[100001][11][2];
ll contrib_dp[100001];
ll pow10[100001];

ll contribution(int n, bool tight, string& s) {
    if (tight == false) return pow10[n];
    if (n == 0) return 1;

    if (contrib_dp[n] != -1) return contrib_dp[n];
    ll cnt = 0;
    int last_digit = s[s.size() - n] - '0';
    for(int digit = 0; digit <= last_digit; digit++) {
        cnt = (cnt + contribution(n - 1, digit == last_digit, s)) % MOD;
    }
    return contrib_dp[n] = cnt;
}

ll helper(int n, int last_ele, bool tight, string& s) {
    if(n == 0) return 0;
    if (dp[n][last_ele][tight] != -1) return dp[n][last_ele][tight];
    ll ans = 0;
    int last_digit = tight ? s[s.size() - n] - '0' : 9;
    for(int i = 0; i <= last_digit; i++) {
        bool new_tight = tight && (i == last_digit);
        if (i != last_ele) {
            ll contribtn = i * pow10[n-1] * contribution(n -1, new_tight, s);
            ans = (ans + contribtn)  % MOD;
        }
        ans = (ans + helper(n - 1, i, new_tight, s)) % MOD;
       
    }
    return dp[n][last_ele][tight] = ans;
}

int main() {
    pow10[0] = 1;
    for(int i = 1; i < 100001; i++)
        pow10[i] = pow10[i-1] * 10 % MOD;
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
	    int nl, nr;
	    string l, r;
	    cin >> nl >> l >> nr >> r;
	    memset(dp, -1, sizeof(dp));
	    memset(contrib_dp, -1, sizeof(contrib_dp));
	    ll ans = helper(nr, 10, true, r);
	    int i = l.size() - 1;
	    while(l[i] == '0') {
            l[i] = '9';
            i--;
        }
	    l[i]--;
	    memset(dp, -1, sizeof(dp));
	    memset(contrib_dp, -1, sizeof(contrib_dp));
	    cout << (ans - helper(nl, 10, true, l) + MOD) % MOD << endl;
	}
}