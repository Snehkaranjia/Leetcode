class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int fr=m-1, lr=0, fc=n-1, lc=0;
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j] == 1)
                {
                    fr = min(fr, i);
                    lr = max(lr, i);
                    fc = min(fc, j);
                    lc = max(lc, j);
                }
            }
        }
        return (lr-fr+1) * (lc-fc+1);
    }
};