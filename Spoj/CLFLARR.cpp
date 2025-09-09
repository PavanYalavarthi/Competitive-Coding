#include<bits/stdc++.h>
using namespace std;
class DSU {
    vector<int>par;
    public:
        DSU(int n) {
            par.resize(n);
            iota(par.begin(), par.end(), 0);
        }

        int find(int x) {
            return (x == par[x] ? x : par[x] = find(par[x]));
        }


        int unite(int i, int j) {
            i = find(i), j= find(j);
            if (i != j) {
                return par[i] = par[j] = max(i, j);
            }
            return i;
        }
};

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, q;
    cin >> n >> q;
    vector<vector<int>>queries(q, vector<int>(3));
    for(int i =0; i< q; i++) {
        cin >> queries[i][0] >>  queries[i][1] >>  queries[i][2];
    }
    DSU dsu(n + 2);
    vector<int>res(n + 1, 0);
    for(int i = q - 1; i >= 0; i--) {
        int index = dsu.find(queries[i][0]), r = queries[i][1], col = queries[i][2];
        while(index <= r) {
            res[index] = col;
            index = dsu.unite(index, index + 1);
        }
    }
    for(int i =1; i<= n; i++) 
        cout << res[i] << endl;
    return 0;
}