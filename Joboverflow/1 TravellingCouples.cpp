/*
Travelling Couples
AlgoLand has N cities. There are M pairs of cities connected by bidirectional trains. For travelling between any of the M pairs of 
cities, one can buy any of 3 types of train tickets which have the same cost irrespective of cities you are travelling between.
• Ticket Type I : It costs Cy but only males can buy and travel using it.
• Ticket Type II: It costs C2 but only females can buy and travel using it.
• Ticket Type III : It costs C3 but only couples in the same city travelling together can buy and travel using it.
A man is currently in city 1 while his wife is at city 2. Find the minimum cost they both need to collectively spend to reach their home which is in city N.
They can both reach at different times or together, but they both have to reach home.
Input
The first line contains five space-separated integers in this order: C1 C2 C3 N M.
The next M lines describe pairs of cities connected by a bidirectional train route.
Constraints:
1≤ C, C2, C3 ≤ 4•104
3 ≤ N ≤4.104
Every city is reachable from every other city through some combination of train routes.
Initially, the man is at city 1 while his wife is at city 2; and they both have to reach city N.
Output
A single integer - the minimum collective cost of tickets they both will need to buy to reach their home city.
Example
input
4 4 5 8 8
1 4
2 3
3 4
4 7
2 5
5 6
6 8
7 8
output
22
Note
Here is the explanation of an optimal solution for this sample test case:
• Husband buys a male-only ticket and travels from city 1 to city 4 and waits for his wife. [ Cost 4 ]
• Wife buys two female-only tickets travelling from city 2 to city 3 and then from city 3 to city 4. [ Cost 4 + 4 ]
• Now that they both are in same city, they can now choose to buy a couple's ticket (costing 5) or buy a male and female ticket 
separately (4 + 4) to travel to next city.
• Clearly it is optimal to buy two couple's tickets and travel from city
4 to city 7 and then from city 7 to city 8. [ Cost 5 + 5 ]
This is how they can reach their home with the total cost of tickets =
4+ (4+4)+(5+5) =22.
*/

#include<bits/stdc++.h>
using namespace std;
vector<int> bfs(vector<vector<int>> & adj, int src) {
    vector<int> dis(adj.size(), -1);
    queue<int> q;
    q.push(src);
    dis[src] = 0;
    while(!q.empty()) {
        int node =  q.front();
        q.pop();
        for(int child: adj[node]) {
            if (dis[child] == -1) {
                dis[child] = dis[node] + 1;
                q.push(child);
            }
        }
    }
    return dis;
}
int main() {
    int c1, c2, c3, n, m;
    cin >> c1 >> c2 >> c3 >> n >> m;
    vector<vector<int>>adj(n + 1);
    int x, y;
    while (m--) {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<int> dis1 = bfs(adj, 1);
    vector<int> dis2 = bfs(adj, 2);
    vector<int> dis = bfs(adj, n);
    int cost = INT_MAX;
    for (int i = 1; i<=n ;i++){
        cost = min(cost, dis1[i] * c1 + dis2[i] * c2 + dis[i] * c3);
    }
    cout << cost;
    return 0;
}