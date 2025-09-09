#include<bits/stdc++.h>
using namespace std;
int dp[10][11][11][11];
int helper(int i, int x1, int x2, int x3) {
    if (x1 < 0 || x2 < 0 || x3 < 0) return INT_MIN;
    if (i == -1) return (x1 == 0 && x2 ==0 && x3 == 0) ? 0 : INT_MIN;
    if(dp[i][x1][x2][x3] != -1) return dp[i][x1][x2][x3];
    return dp[i][x1][x2][x3] = max({
        helper(i-1, x1, x2, x3),
        (1 << i) + helper(i-1, x1 -1, x2, x3),
        (1 << i) + helper(i-1, x1, x2 -1, x3),
        (1 << i) + helper(i-1, x1, x2, x3-1),
        helper(i-1, x1-1, x2 -1, x3),
        helper(i-1, x1-1, x2, x3 -1),
        helper(i-1, x1, x2 -1, x3-1),
        (1 << i) + helper(i-1, x1 - 1, x2 -1, x3 - 1)
    });
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--) {
        int cnt[3];
        string temp;
        for(int i = 0;i<3; i++) {
            cin >> temp;
            cnt[i] = count(temp.begin(), temp.end(), '1');
        }
        memset(dp, -1, sizeof(dp));
        cout << bitset<10>(helper(temp.size() - 1, cnt[0], cnt[1], cnt[2])) << endl;
    }
    return 0;
}