#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
ll dp[51][33][33][2][2];
ll helper(int pos, int cnt63, int cnt93, bool is3Present, bool tight, string& s) {
    if (pos == s.size()) return is3Present && cnt63 == 16 && cnt93 == 16;
    if(cnt63 == 33 || cnt93 == 33 || cnt93 < 0 || cnt63 < 0) return 0;
    ll& ans = dp[pos][cnt63][cnt93][is3Present][tight];
    if(ans != -1) return ans;
    ans = 0;
    int up_bound = tight ? s[pos] - '0' : 9;
    for(int i = 0; i <= up_bound; i++) {
        bool is3 = (i == 3), is6 = (i ==6), is9 = (i == 9);
        (ans += helper(pos + 1, cnt63 + (is6 - is3), cnt93 + (is9 - is3), is3Present | is3, tight & (i == up_bound), s)) %= MOD;
    }
    return ans;
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--) {
        string l, r;
        cin >> l >> r;
        memset(dp, -1, sizeof(dp));
        ll ans = helper(0, 16, 16, false, true, r);
        memset(dp, -1, sizeof(dp));
        int i = l.size() - 1;
        while(l[i] == '0') l[i--] = '9';
        l[i]--;
        cout << (ans - helper(0, 16, 16, false, true, l) + MOD) % MOD << endl;
    }
    return 0;
}