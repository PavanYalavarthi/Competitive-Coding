#include<bits/stdc++.h>
using namespace std;
#define LG 20
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n ,q;
    cin >> n >> q;
    vector<int> arr(n);
    for(int i =0 ; i< n; i++) cin >> arr[i];
    // go[i][k] = minimal index >= i that can be reached from i and has bit k set
    // use n as sentinel (out of bounds)
    vector<vector<int>>go(n+1, vector<int>(LG, n)); 
    // last[j] Store last index with jth bit set
    vector<int> last(LG, n);
    for(int i = n-1; i >= 0; i--) {
        for(int j = 0; j < LG; j++) {
            if(arr[i] & (1 << j)) {
                if(last[j] != n) {
                    // from i we can reach whatever last[j] could reach
                    for(int k = 0; k< LG; k++) {
                        go[i][k] = min(go[i][k], go[last[j]][k]);
                    }
                }
                go[i][j] = last[j] = i;
            }
        }
    }
    for(int i = 0; i<q; i++) {
        int l, r;
        cin >> l >> r;
        --l, --r;
        bool ok = arr[l] & arr[r];
        for(int j =0; j < LG; j++) {
            if(arr[r] & (1 << j) && go[l][j] <= r)
                ok = true; 
        }
        cout << (ok ? "Shi\n" : "Fou\n");
    }
    return 0;
}