class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        if(k==0)
            return 1;
            
        vector<double> dp(n+1, 0);
        dp[0] = 1;
        double prev_prob = 1;
        for(int i=1; i<=n; i++)
        {
            dp[i] = prev_prob / maxPts;
            if(i < k)
                prev_prob += dp[i];
            if(i >= maxPts &&  i-maxPts < k)
                prev_prob -= dp[i-maxPts];
        }
        
        double ans = 0;
        for(int i=k; i<=n; i++)
            ans += dp[i];
        
        return ans;
    }
};