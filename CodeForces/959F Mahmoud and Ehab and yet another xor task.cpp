#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, q;
    cin >> n >> q;
    vector<int>arr(n+1), queries(q);
    for(int i =1; i<= n; i++) cin >> arr[i];
    unordered_map<int, vector<pair<int, int>>> mp;
    for(int i =0; i< q; i++) {
        int l, x;
        cin >> l >> x;
        mp[l].push_back({i, x});
    }
    
    int ans = 1;
    unordered_set<int> s;
    s.insert(0);
    for(int i = 1; i<= n; i++) {
        if(s.find(arr[i]) != s.end()) ans = (2 * ans) % MOD;
        else {
            vector<int> temp;
            for(int x : s) {
                temp.push_back(x ^ arr[i]);
            }
            s.insert(temp.begin(), temp.end());
        }
        for(auto &[index, x] : mp[i]) {
            queries[index] = s.find(x) != s.end() ? ans : 0;
        }
        mp.erase(i);
    }

    for(int i = 0; i< q; i++) {
        cout << queries[i] << '\n';
    }
    return 0;
}