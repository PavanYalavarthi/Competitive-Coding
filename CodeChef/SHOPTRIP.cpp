#include <bits/stdc++.h>
using namespace std;
int final_mask;

double distance(pair<int, int>& p1, pair<int, int>& p2) {
    int dx = p1.first - p2.first, dy = p1.second - p2.second;
    return sqrt(dx * dx + dy * dy);
}

double helper(vector<vector<double>>& dist, vector<int>& ingredients, int mask, int index, vector<vector<double>>& dp) {
    if(mask == final_mask) return dist[index][0];
    if (dp[mask][index] != -1) return dp[mask][index];
    double ans = numeric_limits<double>::max();
    for(int i = 1; i < dist.size(); i++) {
        if ((mask | ingredients[i]) != mask) {
            ans = min(ans, dist[index][i] + helper(dist, ingredients, mask | ingredients[i], i, dp));
        }   
    }
    return dp[mask][index] = ans;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        final_mask =  (1 << k) -1;
        vector<pair<int, int>>v(n + 1);
        vector<int>ingredients(n + 1);
        v[0].first = v[0].second = 0;
        for(int i = 1; i <= n; i++) 
            cin >> v[i].first >> v[i].second;
        int temp = 0;
        ingredients[0] = 0;
        for(int i = 1; i <= n; i++) {
            string tmp;
            cin >> tmp;
            int ans = 0;
            for(int j = 0; j < k; j++) {
                if (tmp[j] == '1')
                    ans |= (1<<(k - j -1));
            }
            temp |= ingredients[i] = ans;
        }
        if (temp != final_mask ){
           cout << -1 << endl; 
        } else {
            vector<vector<double>>dist(n+1, vector<double>(n+1));
            for(int i = 0; i <= n ;i++) {
                for(int j = i; j <= n; j++) {
                    if (i == j) dist[i][j] = 0;
                    else dist[i][j] = dist[j][i] = distance(v[i], v[j]);
                }
            }
            vector<vector<double>> dp (1 << k, vector<double>(n + 1, -1));
            printf("%.10f\n", helper(dist, ingredients, 0, 0, dp));
        }
    }
}
