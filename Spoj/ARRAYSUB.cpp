#include<bits/stdc++.h>
using namespace std;
int main() {
    int n, k;
    cin >> n;
    vector<int>v(n);
    for(int i = 0; i< n; i++) cin >> v[i];
    cin >> k;
    deque<int>q;
    for(int i = 0; i < k; i++) {
        while(!q.empty() && v[q.back()] <= v[i]) q.pop_back();
        q.push_back(i);
    }
    for(int i = k; i < n; i++) {
        cout << v[q.front()] << " ";
        while(!q.empty() && q.front() <= i - k) q.pop_front();
        while(!q.empty() && v[q.back()] <= v[i]) q.pop_back();
        q.push_back(i);
    }
    cout << v[q.front()];
    return 0;
}