class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (n <= 1)
            return grid;

        vector<pair<int, int>> starts;

        for (int i = n - 1; i >= 0; --i)
            starts.push_back({i, 0}); 
        for (int j = 1; j < n; ++j)
            starts.push_back({0, j}); 

        for (auto [r, c] : starts) {
            vector<int> diag;
            int i = r, j = c;

            while (i < n && j < n) {
                diag.push_back(grid[i][j]);
                ++i, ++j;
            }

            if (c == 0)
                sort(diag.begin(), diag.end(), greater<int>()); 
            else
                sort(diag.begin(), diag.end()); 
                
            i = r, j = c;
            int k = 0;
            while (i < n && j < n) {
                grid[i][j] = diag[k++];
                ++i, ++j;
            }
        }
        return grid;
    }
};
