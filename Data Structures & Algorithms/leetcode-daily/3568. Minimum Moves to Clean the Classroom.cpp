/*
Bitmasking:
- Each litter cell is assigned a unique bit position from 0 to litterCount - 1.
- The mask represents which litter cells have already been collected.
- If litter with id = x is collected, we set its bit using:
      mask |= (1 << x)
- Example:
      mask = 0101
  means litter 0 and litter 2 have been collected.
- fullMask = (1 << litterCount) - 1 creates a mask where every litter bit is 1.
  Example: litterCount = 3
      1 << 3  = 1000
      1000 - 1 = 0111
  So mask == fullMask means all litter has been collected.

Why BFS instead of DFS:
- Every movement costs exactly 1 step.
- BFS explores states level-by-level:
      step 0 -> step 1 -> step 2 -> ...
- Therefore, the first time we reach a state where mask == fullMask,
  we are guaranteed to have used the minimum number of moves.
- DFS does not provide this guarantee because it may explore a much longer
  path before exploring a shorter one.

Visited state:
- Position alone is not enough to describe a state.
  Reaching the same (i, j) with different collected litter gives different states.
- Therefore our logical state is:
      (i, j, mask, remainingEnergy)

- Instead of explicitly storing energy as another visited dimension,
  visited[i][j][mask] stores the maximum energy with which we have reached
  that (i, j, mask) state.

- If we reach the same (i, j, mask) again with energy <= previously stored energy,
  we skip it because it cannot be better.
  The previous state is at the same position, has collected the same litter,
  and has at least as much energy available.

- However, if we reach the same state with MORE energy, we must explore it,
  because that additional energy may allow us to reach places that were
  impossible from the previous visit.
*/

class Solution {
    public:
        vector<int> dx = {-1, 0, 1, 0};
        vector<int> dy = {0, 1, 0, -1};
    
        int minMoves(vector<string>& classroom, int energy) {
            int n = classroom.size();
            int m = classroom[0].size();
    
            int sx = -1, sy = -1;
            int litterCount = 0;
    
            vector<vector<int>> litterId(n, vector<int>(m, -1));
    
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (classroom[i][j] == 'S') {
                        sx = i;
                        sy = j;
                    }
    
                    if (classroom[i][j] == 'L') {
                        litterId[i][j] = litterCount++;
                    }
                }
            }
    
            int fullMask = (1 << litterCount) - 1;
    
            vector<vector<vector<int>>> visited(
                n,
                vector<vector<int>>(
                    m,
                    vector<int>(
                        1 << litterCount, -1
                    )
                )
            );
    
            queue<array<int, 4>> q;
            q.push({sx, sy, energy, 0});
    
            int steps = 0;
    
            while (!q.empty()) {
                int size = q.size();
    
                while (size--) {
                    auto [i, j, currEnergy, mask] = q.front();
                    q.pop();
    
                    if (visited[i][j][mask] >= currEnergy)
                        continue;
    
                    visited[i][j][mask] = currEnergy;
    
                    if (mask == fullMask)
                        return steps;
    
                    if (classroom[i][j] == 'R')
                        currEnergy = energy;
    
                    if (currEnergy == 0)
                        continue;
    
                    for (int k = 0; k < 4; k++) {
                        int ni = i + dx[k];
                        int nj = j + dy[k];
    
                        if (ni < 0 || nj < 0 || ni >= n || nj >= m)
                            continue;
    
                        if (classroom[ni][nj] == 'X')
                            continue;
    
                        int newEnergy = currEnergy - 1;
                        int newMask = mask;
    
                        if (classroom[ni][nj] == 'L') {
                            int id = litterId[ni][nj];
                            newMask |= (1 << id);
                        }
    
                        if (classroom[ni][nj] == 'R') {
                            newEnergy = energy;
                        }
    
                        q.push({
                            ni,
                            nj,
                            newEnergy,
                            newMask
                        });
                    }
                }
    
                steps++;
            }
    
            return -1;
        }
    };