#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007

int n;
vector<int> arr;
ll dp[31][1 << 4][1 << 4];
ll helper(int bit, int bMask, int xorMask) {
    if (bit < 0) return 1;
    ll& ans = dp[bit][bMask][xorMask];
    if (ans != -1) return ans;
    ans = 0;
    // Try all combinations at bit
    for(int assign = 0; assign < (1 << n); assign++) {
        vector<int>bBit(n), xorBit(n);
        for(int i = 0; i<n; i++) {
            bBit[i] = (assign >> i) & 1;
            xorBit[i] = ((arr[i] >> bit) & 1) ^ bBit[i];
        }
        bool ok = true;
        int newBMask = bMask, newXorMask = xorMask;
        for(int i = 0; i < n -1; i++) {
            // If the order is not set in previous iteartion
            if ((bMask & (1 << i)) == 0) {
                if(bBit[i] > bBit[i +1]) {
                    // If i is bigger than i + 1, then its not proper order
                    ok = false;
                    break;
                }
                if (bBit[i] < bBit[ i + 1]) newBMask |= (1 << i); // if order is set, then setting respective bit
            }
            if ((xorMask & (1 << i)) == 0) {
                if(xorBit[i] > xorBit[i +1]) {
                    ok = false;
                    break;
                }
                if (xorBit[i] < xorBit[ i + 1]) newXorMask |= (1 << i);
            }
        }
        if(ok) {
            ans += helper(bit - 1, newBMask, newXorMask);
            if (ans >= MOD) ans -= MOD;
        }
    }
    return ans;
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        arr.resize(n);
        for(int i = 0; i < n; i++) cin >> arr[i];
        memset(dp, -1, sizeof(dp));
        cout << helper(30, 0, 0) << '\n';
    }
    return 0;
}