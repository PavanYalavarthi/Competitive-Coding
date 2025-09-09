class DSU {
    private:
        vector<int> parent, cost;
    public:
        DSU(int n) {
            parent.resize(n);
            iota(parent.begin(), parent.end(), 0);
            cost.resize(n, 1);
        }
        
        int find(int x) {
            if (parent[x] != x)
                parent[x] = find(parent[x]);
            return parent[x];
        }
        
        void unite(int x, int y) {
            int parX = find(x), parY = find(y);
            if(parX == parY) return;
            if(cost[parX] < cost[parY]) swap(parX, parY);
            parent[parY] = parX;
            cost[parX] += cost[parY];
        }
        
        long long total_cost() {
            long long count = 0;
            for(int i =0 ;i < parent.size(); i++) {
                if(parent[i] == i) {
                     count += (1LL * cost[i] * (cost[i] - 1)) / 2;   
                }
            }
            return count;
        }
 };
 
long long journeyToMoon(int n, vector<vector<int>> astronaut) {
    DSU dsu(n);
    for(auto v : astronaut) {
        dsu.unite(v[0], v[1]);
    }
    return 1LL * n * (n - 1) / 2 - dsu.total_cost();
}
