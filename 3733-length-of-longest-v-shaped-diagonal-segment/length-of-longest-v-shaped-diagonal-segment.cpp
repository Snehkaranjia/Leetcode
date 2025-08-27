class Solution {
    int n, m;

private:
    int find(vector<vector<int>>& grid, int i, int j, int d, int val, bool turn,
             pair<int, int> dir[]) {
        if (grid[i][j] != val)
            return 0;

        if (val == 0)
            val = 2;
        else
            val = 0;

        int _i = i + dir[d].first;
        int _j = j + dir[d].second;

        int straight = 1;
        if (_i < n && _i >= 0 && _j < m && _j >= 0) {
            straight = 1 + find(grid, _i, _j, d, val, turn, dir);
        }
        int clockwise = 1;
        if (turn) {
            d = (d + 1) % 4;
            _i = i + dir[d].first;
            _j = j + dir[d].second;
            if (_i < n && _i >= 0 && _j < m && _j >= 0) {
                clockwise = 1 + find(grid, _i, _j, d, val, false, dir);
            }
        }

        return max(straight, clockwise);
    }

public:
    int lenOfVDiagonal(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        pair<int, int> dir[] = {{-1, -1}, {-1, 1}, {1, 1}, {1, -1}};

        int len = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    len = max(1, len);
                    for (int d = 0; d < 4; d++) {
                        int _i = i + dir[d].first;
                        int _j = j + dir[d].second;
                        if (_i < n && _i >= 0 && _j < m && _j >= 0) {
                            len = max(len,
                                      1 + find(grid, _i, _j, d, 2, true, dir));
                        }
                    }
                }
            }
        }

        return len;
    }
};