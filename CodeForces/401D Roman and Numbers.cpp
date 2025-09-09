#include<bits/stdc++.h>
using namespace std;
long long final_mask;
int m, n;
string s;
vector<vector<long long>>dp;
long long helper(int mask, int remainder) {
    if(mask == final_mask) return remainder == 0;
    if(dp[mask][remainder] != -1) return dp[mask][remainder];
    long long ans = 0;
    for(int i = ((mask == 0) ? 1 : 0); i<= 9; i++) {
        for(int j = 0; j <n; j++) {
            if(mask & (1 << j) || s[j] != i + '0') continue;
            ans += helper(mask | (1 << j), ((remainder * 10) % m + i) % m);
            break;
        }
    }
    return dp[mask][remainder] = ans;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> s >> m;
    n = s.size();
    dp.assign(1 << n, vector<long long>(m, -1));
    final_mask = (1 << n) - 1;
    cout << helper(0, 0);
    return 0 ;
}