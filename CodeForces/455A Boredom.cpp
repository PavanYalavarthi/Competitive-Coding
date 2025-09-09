#include<bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n;
    map<uint64_t, uint64_t> mp;
    uint64_t temp;
    for(int i=0; i< n; i++) {
        cin >> temp;
        mp[temp]++;
    }
    uint64_t ans = 0, prev1 =0, prev2 =0;
    for(auto &[key, freq] : mp) {
        if (mp.count(key -1) != 0)
            temp = max(key * freq + prev2, prev1);
        else
            temp = key * freq + prev1;
        prev2 = prev1;
        prev1 = temp;
    }
    cout << prev1;
    return 0;
}