class Solution {

private:
    void solve(vector<int>& piles, int pa, int pb, bool &ans, int i, int j)
    {
        if(ans)
            return;
            
        if(i >= j)
        {
            if(pa >= pb)
            {
                ans = true;
            }
            return;
        }

        solve(piles, pa+piles[i], pb, ans, i+1, j);
        solve(piles, pa+piles[j], pb, ans, i, j-1);
        solve(piles, pa, pb+piles[i], ans, i+1, j);
        solve(piles, pa, pb+piles[j], ans, i, j-1);
    }

public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        bool ans = false;
        solve(piles, 0, 0, ans, 0, n-1);
        return ans;
    }
};