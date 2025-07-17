class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        vector<vector<int>> dp(k, vector<int>(k, 0));
        int res = 0;
        for (int no : nums) {
            int a = no % k;
            for (int b = 0; b < k; ++b) {
                dp[a][b] = dp[b][a] + 1;
                if (dp[a][b] > res) 
                    res = dp[a][b];
            }
        }
        return res;
    }
};