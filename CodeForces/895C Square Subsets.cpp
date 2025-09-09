#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
vector<int>pow2(100001);
vector<int>primes({2, 3});
vector<int>msk(71);
unordered_map<int, int> freq;
vector<vector<int>> dp;
void isPrime(int i, vector<int>&primes){
    for(int prime: primes) {
        if (i % prime == 0)
            return;
    }
    primes.push_back(i);
}
 
 
long long helper(int index, int mask){
    if(index == 71) return (mask == 0);
    if(dp[index][mask] != -1) return dp[index][mask];
    int frequency = freq[index];
    if(frequency == 0) return helper(index + 1, mask);
    return dp[index][mask] = (pow2[frequency] * (helper(index + 1, mask) + helper(index + 1, mask ^ msk[index])) % MOD) % MOD;
}
 
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    pow2[1] = 1;
    for (int i = 2; i < 100001; ++i)
        pow2[i] = (pow2[i - 1] * 2LL) % MOD;
    for(int i = 5; i <= 70; i+=6) {
        isPrime(i, primes);
        isPrime(i+2, primes);
    }
    msk[1] = 0;
    for(int i = 2; i < 71; i++) {
        for(int j = 0; j < primes.size(); j++) {
            if(i % primes[j] == 0) {
                msk[i] = (1 << j) ^ msk[i / primes[j]];
                break;
            }
        }
    }
    int n;
    cin >> n;
    for(int i =0, temp; i< n; i++) {
        cin >> temp;
        freq[temp]++;
    }
    dp.assign(71, vector<long long>(1<<primes.size(), -1));
    cout << helper(1, 0) - 1;
    return 0;
}