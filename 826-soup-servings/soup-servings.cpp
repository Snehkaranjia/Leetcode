class Solution {

private:
    double helper(int a, int b, vector<vector<double>>& dp) {
        if (a <= 0 && b <= 0)
            return 0.5;
        if (b <= 0)
            return 0;
        if (a <= 0)
            return 1;
        if (dp[a][b] != -1)
            return dp[a][b];
        double prob = 0;
        prob += helper(a - 100, b, dp);
        prob += helper(a - 75, b - 25, dp);
        prob += helper(a - 50, b - 50, dp);
        prob += helper(a - 25, b - 75, dp);
        return dp[a][b] = prob * 0.25;
    }

public:
    double soupServings(int n) {
        if (n >= 4800)
            return 1;
        vector<vector<double>> dp(n + 1, vector<double>(n + 1, -1));
        return helper(n, n, dp);
    }
};