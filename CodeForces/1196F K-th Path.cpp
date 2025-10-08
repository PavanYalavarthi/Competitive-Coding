#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll INF64 = 1e15;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;

    vector<array<int,3>> edges(m); // {w, u, v}
    for (int i = 0; i < m; i++) {
        cin >> edges[i][1] >> edges[i][2] >> edges[i][0];
    }
    sort(edges.begin(), edges.end());

    vector<int> vertices;
    int minEdges = min(k, m);
    for (int i = 0; i < minEdges; i++) {
        vertices.push_back(edges[i][1]);
        vertices.push_back(edges[i][2]);
    }
    sort(vertices.begin(), vertices.end());
    vertices.erase(unique(vertices.begin(), vertices.end()), vertices.end());

    int noOfVertices = vertices.size();
    vector<vector<ll>> dist(noOfVertices, vector<ll>(noOfVertices, INF64));
    for (int i = 0; i < noOfVertices; i++) dist[i][i] = 0;

    for (int i = 0; i < minEdges; i++) {
        int x = lower_bound(vertices.begin(), vertices.end(), edges[i][1]) - vertices.begin();
        int y = lower_bound(vertices.begin(), vertices.end(), edges[i][2]) - vertices.begin();
        dist[x][y] = dist[y][x] = edges[i][0];
    }

    // full Floyd–Warshall
    for (int k = 0; k < noOfVertices; k++) {
        for (int i = 0; i < noOfVertices; i++) {
            for (int j = 0; j < noOfVertices; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    vector<ll> res;
    for (int i = 0; i < noOfVertices; i++) {
        for (int j = i + 1; j < noOfVertices; j++) {
            if (dist[i][j] < INF64) res.push_back(dist[i][j]);
        }
    }

    sort(res.begin(), res.end());
    cout << res[k - 1] << "\n";
}
