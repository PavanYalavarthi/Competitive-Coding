/*
Circular Kadane :
Difficulty Level : Easy
Submissions: 194
Asked In:
Marks :10
13:415:0
Challenge W
There are N kids sitting in a circle. Each kid owns an Integer. You can select any contagious sequence of kids in your team. Strength of your team is simply the sum of all integers kids in your team own.
Ofcourse, since you need a team to participate in championship you will need to select atleast one kid.
NOTE: In this problem, we have kept maximum possible sum (= {Max size of array} * {Max value of an element in Array}) fit within Integer type. But in coding rounds, it may not be a case, so always take care of it.
Input
• The first line will contain an integer N, the number of kids
• The second line will contain N integers owned by all the kids seperated by space
Constraints
• 1 = d ≤ 10^5
• -10^4 ≤ Each Integer owned by a kid ≤ 10^4
Output
Output a single integer: Maximum possible strength of your team.
Example
Input
5
1 2 3 4 5
Output
15
*/

#include <bits/stdc++.h>
using namespace std;

  int main() {
    int n, i, sum = 0, maxStraightSum = INT_MIN, maxCurrSum = 0,minStraightSum = INT_MAX, minCurrSum = 0 ;
    cin >> n;
    while(n--) {
      cin >> i;
      sum += i;
      maxCurrSum += i;
      maxStraightSum = max(maxStraightSum, maxCurrSum);
      maxCurrSum = max(0, maxCurrSum);
      minCurrSum += i;
      minStraightSum = min(minStraightSum, minCurrSum);
      minCurrSum = min(0, minCurrSum);
    }
    if (minStraightSum == sum) {
      //If all are negative numbers
      cout << maxStraightSum;
    } else {
      cout << max(maxStraightSum, sum - minStraightSum);
    }
  }