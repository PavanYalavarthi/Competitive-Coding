#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[20][4][2];
int helper (int pos, int cnt, bool tight, string s) {
    if(pos == s.size()) return 1;
    if (dp[pos][cnt][tight] != -1) return dp[pos][cnt][tight];
    int last_digit = tight ? s[pos] - '0' : 9;
    int res = 0;
    for(int i = 0; i <= last_digit; i++) {
        int cur_cnt = cnt + (i > 0);
        if (cur_cnt <= 3) {
            res += helper(pos+1, cur_cnt, tight && (i == last_digit), s);
        }
    }
    return dp[pos][cnt][tight] = res;
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--) {
        ll l, r, right_ans;
        cin >> l >> r;
        memset(dp, -1, sizeof(dp));
        right_ans = helper(0, 0, true,to_string(r));
        memset(dp, -1, sizeof(dp));
        cout <<  right_ans - helper(0, 0, true, to_string(l-1)) << endl;
    }
}