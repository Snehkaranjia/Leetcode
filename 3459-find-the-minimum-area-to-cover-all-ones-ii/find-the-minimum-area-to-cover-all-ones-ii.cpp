class Solution {

private:
    int minimumArea(vector<vector<int>>& grid, int ri, int rj, int ci, int cj) {
        int x1 = INT_MAX;
        int y1 = INT_MAX;
        int x2 = 0;
        int y2 = 0;
        for (int i = ri; i <= rj; i++) {
            for (int j = ci; j <= cj; j++) {
                if (grid[i][j] == 1) {
                    x1 = min(x1, i);
                    y1 = min(y1, j);
                    x2 = max(x2, i);
                    y2 = max(y2, j);
                }
            }
        }
        return x1 == INT_MAX ? 0 : (x2 - x1 + 1) * (y2 - y1 + 1);
    }

public:
    int minimumSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = m * n;

        // different cases of R1,R2,R3;
        // case 1&2&3 -> horizontal
        // case 1
        for (int i = 0; i < m; i++) {
            int R1 = minimumArea(grid, 0, i, 0, n - 1);
            for (int j = 0; j < n; j++)
                ans =
                    min(ans, R1 + minimumArea(grid, i + 1, m - 1, 0, j) +
                                 minimumArea(grid, i + 1, m - 1, j + 1, n - 1));
        }
        // case 2
        for (int i = 0; i < m; i++) {
            int R1 = minimumArea(grid, i, m - 1, 0, n - 1);
            for (int j = 0; j < n; j++)
                ans = min(ans, R1 + minimumArea(grid, 0, i - 1, 0, j) +
                                   minimumArea(grid, 0, i - 1, j + 1, n - 1));
        }
        // case 3
        for (int i1 = 0; i1 < m; i1++) {
            for (int i2 = i1 + 1; i2 < m; i2++)
                ans = min(ans, minimumArea(grid, 0, i1, 0, n - 1) +
                                   minimumArea(grid, i1 + 1, i2, 0, n - 1) +
                                   minimumArea(grid, i2 + 1, m - 1, 0, n - 1));
        }

        // case 4&5&6 -> vertical
        // case 4
        for (int j = 0; j < n; j++) {
            int R1 = minimumArea(grid, 0, m - 1, 0, j);
            for (int i = 0; i < m; i++)
                ans =
                    min(ans, R1 + minimumArea(grid, 0, i, j + 1, n - 1) +
                                 minimumArea(grid, i + 1, m - 1, j + 1, n - 1));
        }
        // case 5
        for (int j = 0; j < n; j++) {
            int R1 = minimumArea(grid, 0, m - 1, j, n - 1);
            for (int i = 0; i < m; i++)
                ans = min(ans, R1 + minimumArea(grid, 0, i, 0, j - 1) +
                                   minimumArea(grid, i + 1, m - 1, 0, j - 1));
        }
        // case 6
        for (int j1 = 0; j1 < n; j1++) {
            for (int j2 = j1 + 1; j2 < n; j2++)
                ans = min(ans, minimumArea(grid, 0, m - 1, 0, j1) +
                                   minimumArea(grid, 0, m - 1, j1 + 1, j2) +
                                   minimumArea(grid, 0, m - 1, j2 + 1, n - 1));
        }

        return ans;
    }
};