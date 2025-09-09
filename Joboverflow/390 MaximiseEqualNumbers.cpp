/*
You are given the following:
An array a consisting of n elements and an integer k. For each (1 ≤ 1 ≤ n) , perform the following operation exactly one time:
Replace aj, by aj + x where x€|-K, K] which denotes, x should lie in the range of -k and k, both inclusive.
Determine the maximum length of the subsequence of array a, such that all numbers in that subsequence are equal after applying the 
given operation.
Task
A subsequence of array a is an array that can be derived from array a by removing some elements from it. (maybe none or all of them) Assume 1-based indexing
Example
n = 4
k= 1
Array a = [2,5,1,2]
Approach Applying one operation on indices 1, 2, and 4, with x = 0 to get array a as [2,5, 1, 2).
Applying one operation on index 3, with x = 1 to get array a as [2,5,2, 2]
Therefore, the maximum length of the subsequence with equal numbers is 3.
Input
The first line contains two integers, N (1 ≤ N ≤ 105) and K (0 ≤ K ≤ 109).
The second line contains an array of N integers, Al, Az... Av (1 ≤ Aj ≤ 10)
Output
The maximum length of the subsequence of the array a, such that all numbers in that subsequence are equal after applying the given operation.
Example
input
4 1
2 5 1 2
output
3

#GOOGLE
*/

#include<bits/stdc++.h>
using namespace std;
int main() {
    int n, k;
    cin >> n >> k;
    vector<int>v(n);
    for (int i = 0; i< n; i++) cin >> v[i];
    sort(v.begin(), v.end());
    int left = 0, ans = 1, right = 1;
    while(right < n) {
        if (v[left] + k < v[right] - k) {
            ans = max(ans, right - left);
            left++;
        }
        else right++;
    }
    ans = max(ans, right - left);
    cout << ans;
}