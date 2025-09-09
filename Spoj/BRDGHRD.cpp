#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<pair<int,int>> v(n);
        for(int i=0; i <n; i++) cin >> v[i].first;
        for(int i=0; i <n; i++) cin >> v[i].second;
        sort(v.begin(), v.end());
        vector<int> dp;
        dp.push_back(v[0].second);
        for(int i =1 ;i < n; i++) {
            int index = lower_bound(dp.begin(), dp.end(), v[i].second + 1) - dp.begin();
            if (index == dp.size()) dp.push_back(v[i].second);
            else dp[index] = v[i].second;
        }
        cout << dp.size() << '\n';
    }
}