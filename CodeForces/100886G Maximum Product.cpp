#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll max_prod = -1, ans;
string a, b;
pair<ll, string> dp[20][2][2][2];
pair<ll, string> helper(int pos, bool tightA, bool tightB, bool didStart) {
    if (pos == a.size()) return {1, "" };
    pair<ll, string>& ans = dp[pos][tightA][tightB][didStart];
    if (ans.first != -1) return ans;
    int start_digit = tightA ? a[pos] - '0' : 0;
    int end_digit = tightB ? b[pos] - '0' : 9;
    for(int i = start_digit; i <= end_digit; i++) {
        int val = (!didStart && i == 0)  ? 1 : i; // If not started, product should be 1, not 0 (shouldnt be effected by leading zeros)
        pair<ll, string> dp_ans = helper(pos + 1, tightA && i == start_digit, tightB && i == end_digit, didStart | (i > 0));
        if (ans.first < val * dp_ans.first) {
            ans = {val * dp_ans.first, to_string(i) + dp_ans.second};
        }
    }
    return dp[pos][tightA][tightB][didStart] = ans;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    ll l, r;
    cin >> l >> r;
    a = to_string(l), b = to_string(r);
    a = string(b.size() - a.size(), '0') + a;
    for(int i = 0; i< 20; i++) {
        for(int j = 0; j < 2; j++) {
            for(int k = 0; k < 2; k++) {
                for(int l = 0; l < 2; l++) {
                    dp[i][j][k][l] = {-1, ""};
                }
            }
        }
    }
    cout << stoll(helper(0, true, true, false).second);
}