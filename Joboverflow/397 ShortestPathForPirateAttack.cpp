/*
There are N towns connected by M roads. Travelling any road takes half day, and thus for two towns X, Y connected directly by road 
if you start from X at day you will reach Y by night and vice versa.

Pirates will start from town-1 during the night and wish to reach town-N during night. They cannot halt at any town during the journey,
but they can visit same town multiple times.

Find minimum number of roads they need to travel to reach town-N during the night, or report its "IMPOSSIBLE".

Input

The first line contains two integers N and M - representing the number of towns and roads, respectively.
Each of the following M lines contains two integers a and b, indicating a road connecting towns a and b.

Output
Print a single integer - the minimum number of roads the pirates must travel to reach town-N by night.
If the journey cannot be completed as per the rules, print "IMPOSSIBLE".

Examples
input
5 5
3 2
1 3
3 4
2 1
5 4
output
4

input
4 3
1 2
2 3
3 4
output
IMPOSSIBLE

#GOOGLE
*/

#include <bits/stdc++.h>
using namespace std;
int bfs(vector<vector<int>> &adj, int n) {
  vector<vector<int>> dis(n+1, vector<int>(2, 1e9));
  queue<pair<int, int>> q;
  dis[1][0] = 0;
  q.push({1,0});
  while(!q.empty()) {
    auto [node, parity] = q.front();
    q.pop();
    int np = 1 - parity;
    for(int i : adj[node]) {
      if (dis[i][np] > 1 + dis[node][parity]) {
        dis[i][np] = 1 + dis[node][parity];
        q.push({i, np});
      }
    }
  }
  if (dis[n][0] != 1e9) return dis[n][0];
  return -1;
}
int main() {
  int m, n;
  cin >> n >> m;
  vector<vector<int>>adj(n + 1);
  for (int i = 0, a , b; i<m; i++) {
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  int ans = bfs(adj, n);
  if (ans != -1) cout << ans;
  else cout << "IMPOSSIBLE";
  return 0;
}