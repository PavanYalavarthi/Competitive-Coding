#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>>arr(n, vector<int>(m));
    vector<int>ans(n, 1);
    int x = 0;
    for(int i =0; i< n; i++) {
        for(int j = 0; j < m; j++){
            cin >> arr[i][j];
        }
        x ^= arr[i][0];
    }
    if(x == 0) {
        for(int i = 0; i< n; i++) {
            for(int j = 0; j < m; j++) {
                if(arr[i][j] != arr[i][0]) {
                    ans[i] = j +1;
                    i = n, x = 1;
                    break;
                }
            }
        }
    }
    if (x == 0) cout << "NIE";
    else {
        cout << "TAK\n";
        for(int i = 0; i< n; i++)
            cout << ans[i] << " ";
    }
    return 0;
}