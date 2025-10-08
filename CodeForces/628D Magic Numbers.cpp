#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
ll dp[2001][2000][2];
string l, r;
int m, d;
ll helper(int pos, int modM, bool tight, string& s) {
    if (pos == s.size()) return modM == 0;
    if (dp[pos][modM][tight] != -1) return dp[pos][modM][tight];
    int end_digit = tight ? s[pos] - '0' : 9;
    int ans = 0;
    for(int i = 0 ; i <= end_digit; i++) {
        if ((pos & 1) != 0 && i == d) {
            // If position is even (here its odd as pos started from 0), accepting only d
            (ans += helper(pos + 1, (modM*10 + i) % m, tight & (i == end_digit), s)) %= MOD;
            break;
        } else if ((pos & 1)  == 0 && i != d) {
            // in odd positions, accepting all other than d
            (ans += helper(pos + 1, (modM*10 + i) % m, tight & (i == end_digit), s)) %= MOD;
        }
    }
    return dp[pos][modM][tight] = ans;
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> m >> d;
    cin >> l >> r;
    int i = l.size() -1;
    while (i >= 0 && l[i] == '0') {
        l[i] = '9';
        i--;
    }
    l[i]--;
    memset(dp, -1, sizeof(dp));
    ll ans = helper(0, 0, true, r);
    memset(dp, -1, sizeof(dp));
    cout << (ans - helper(0, 0, true, l) + MOD) %MOD;
    return 0;
}