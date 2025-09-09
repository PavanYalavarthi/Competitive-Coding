/*
Alex's Love for Letters :

Alex had written all the 26 letters from a to z on a board initially. Later, he rearranged those letters forming a new sequence. Alex gives you this new sequence of 26 letters, another string s of length n and a number k.
Your task is to find and return the lexicographically smallest subsequence of length k formed from string s, in accordance with the new sequence of letters provided to you.
Note: A subsequence of a string is formed by deleting a few (possibly 0) characters from string. Given two strings, a string will be lexicographically smaller than other string, if it comes first in the dictionary.
Input
The first line contais 2 integers n, k(1 ≤ k ≤ n ≤ 10^5).
The next line contains a string sp of length 26 - the new lexicographical order of alphabets. The next line contains a string s of length n.
Output
Output a single string - the lexicographically smallest subsequence of length k.
Example
input
4 2
rfov
abcdefghijklmnopqrstuvwxyz
output 
fo
*/

#include<bits/stdc++.h>
using namespace std;
int main() {
    int n,k;
    cin >> n >> k;
    unordered_map<char,int> mp;
    char c;
    for(int i = 0; i<26; i++) {
        cin >> c;
        mp[c] = i;
    }
    string s, t;
    cin >> t;
    for(int i = 0; i< n; i++) {
        while(!s.empty() && mp[s.back()] > mp[t[i]] && (s.size() + n - i) > k) s.pop_back();
        if(s.size() < k) s.push_back(t[i]);
    }
    cout << s;
}