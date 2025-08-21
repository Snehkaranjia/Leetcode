class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> nums(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            nums[i][0] = mat[i][0];
            for (int j = 1; j < n; j++) {
                if (mat[i][j])
                    nums[i][j] = nums[i][j - 1] + 1;
                else
                    nums[i][j] = 0;
            }
        }

        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int mini = nums[i][j];
                for (int k = i; k >= 0 && mini > 0; k--) {
                    mini = min(mini, nums[k][j]);
                    ans += mini;
                }
            }
        }
        return ans;
    }
};