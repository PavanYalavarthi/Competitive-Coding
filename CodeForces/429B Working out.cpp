#include<bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int m, n;
    cin >> m >> n;
    vector<vector<int>>grid(m, vector<int>(n));
    for(int i = 0; i < m; i++) {
        for(int j =0; j <n; j++) {
            cin >> grid[i][j];
        }
    }
    vector<vector<int>>boy_start, boy_end, girl_start, girl_end;
    boy_start = boy_end = girl_start = girl_end = vector<vector<int>>(m+2, vector<int>(n+2, 0));
    for(int i = 1; i<=m; i++) {
        for(int j = 1; j <= n; j++) {
            boy_start[i][j] = max(boy_start[i-1][j], boy_start[i][j-1]) + grid[i-1][j-1];
        }
    }
    for(int i = m; i>0; i--) {
        for(int j = n; j > 0; j--) {
            boy_end[i][j] = max(boy_end[i+1][j], boy_end[i][j+1]) + grid[i-1][j-1];
        }
    }
    for(int i = m; i>0; i--) {
        for(int j = 1; j <= n; j++) {
            girl_start[i][j] = max(girl_start[i+1][j], girl_start[i][j-1]) + grid[i-1][j-1];
        }
    }
    for(int i = 1; i<=m; i++) {
        for(int j = n; j > 0; j--) {
            girl_end[i][j] = max(girl_end[i][j +1], girl_end[i-1][j]) + grid[i-1][j-1];
        }
    }

    int ans = 0;
    for(int i =2; i< m; i++){
        for(int j = 2; j < n; j++) {
            ans = max({ans, 
                boy_start[i][j-1] + boy_end[i][j+1] + girl_start[i+1][j] + girl_end[i-1][j],
                boy_start[i-1][j] + boy_end[i+1][j] + girl_start[i][j-1] + girl_end[i][j+1]
            });
        }
    }
    cout << ans;
    return 0;
}