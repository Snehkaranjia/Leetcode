class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        int size = banned.size();

        vector<bool> check(pow(10, 4), false);
        for(int num : banned)
            check[num] = true;
        
        long long sum = 0;
        int ans = 0;
        for(int i=1; i<=n; i++)
        {
            if(!check[i])
            {
                sum += i;
                if(sum <= maxSum)
                {
                    ans++;
                }
            }
        }
        
        return ans;
    }
};