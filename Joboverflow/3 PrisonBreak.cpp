/*
You and some monsters are in a prison. When taking a step in some direction in the prison, each monster may simultaneously take one as well. Your goal is to reach one of the boundary squares without ever sharing a square with a monster.
Your task is to find out if your goal is possible. Your plan has to work in any situation; even if the monsters know your path beforehand.
INPUT
The first input line has two integers n and m: the height and width of the map.
After this there are n lines of m characters describing the prison. Each character is. (floor), # (wall), A (start), or M (monster). There is exactly one A in the input
OUTPUT
First print "YES" if your goal is possible, and "NO" otherwise.
EXAMPLE
Sample 1 INPUT:
5 8
########
#M..A..#
#.#.M#.#
#M#..#..
#.######
Sample 1 OUTPUT:
YES
NOTE
You can break out of prison without being caught by any monster by taking a Right, Right, Down, Down, Right.
*/

#include <bits/stdc++.h>
  using namespace std;

  int dir[] = {1, 0, -1, 0, 1 };
  bool bfs(queue<pair<int, int>>& q, bool isPerson, vector<vector<int>> & matrix) {
    while(!q.empty()) {
      auto& [x, y] = q.front();
      q.pop();
      for (int i = 0 ; i<4;i++) {
        int X = x + dir[i], Y = y + dir[i + 1];
        if (X == -1 || X == matrix.size() || Y == -1 || Y == matrix[0].size()) {
          if (isPerson) return true;
          continue;
        } else if (matrix[X][Y] > matrix[x][y] + 1) {
          matrix[X][Y] = matrix[x][y] + 1;
          q.push({X,Y});
        }
      }
    }
    return false;
  }
  
  int main() {
    int m, n;
    cin >> m >> n;
    vector<vector<int>>matrix(m, vector<int>(n, 0));
    queue<pair<int, int>>q;
    pair<int, int> person;
    char c;
    for(int i = 0; i<m; i++) {
      for (int j = 0; j < n; j++) {
        cin >> c;
        if (c == 'M') q.push({i, j}); 
        else if (c == '.' || c == 'A') {
          matrix[i][j] = INT_MAX;
          if (c == 'A') person = {i,j };
        }
      }
    }
    bfs(q, false, matrix);
    q.push(person);
    matrix[person.first][person.second] = 0;
    if (bfs(q, true, matrix)) {
      cout << "YES";
    } else {
      cout << "NO";
    }
  }