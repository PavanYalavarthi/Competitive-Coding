#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[20][11][11][2][2][2][2];
ll helper(int pos, int last_ele, int sec_last_ele, bool tight, bool even, bool odd, bool doesStart, string& s) {
    if (pos == s.size()) return odd && even;
    if (dp[pos][last_ele][sec_last_ele][tight][even][odd][doesStart] != -1) return dp[pos][last_ele][sec_last_ele][tight][even][odd][doesStart];
    int last_digit = tight ? s[pos] - '0' : 9;
    ll result = 0;
    for(int i = 0; i <= last_digit; i++) {
        if(!doesStart && i == 0) // skipping the leading zeros
                result += helper(pos + 1, last_ele, sec_last_ele, tight && (i == last_digit), even, odd,false , s);
        else
            result += helper(pos + 1, i, last_ele, tight && (i == last_digit), even || (i == last_ele), odd || (i == sec_last_ele), true, s);
    }
    return dp[pos][last_ele][sec_last_ele][tight][even][odd][doesStart] = result;
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--) {
        string a, b;
        cin >> a >> b;
        memset(dp, -1, sizeof(dp));
        ll ans = helper(0, 10, 10, true, false, false, false, b);
        memset(dp, -1, sizeof(dp));
        cout << ans - helper(0, 10, 10, true, false, false, false, a) << endl;
    }
    return 0;
}