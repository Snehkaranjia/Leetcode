class Solution {

private:
    void solve(int &k, int n, vector<int> &mid, vector<vector<int>> &ans, int i)
    {
        if(mid.size() == k)
        {
            if(n==0)
                ans.push_back(mid);
            return;
        }

        if(n<0) 
            return;

        if(i > 9)
            return;

        mid.push_back(i);
        solve(k,n-i,mid,ans,i+1);
        mid.pop_back();

        solve(k,n,mid,ans,i+1);
    }

public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> mid;
        vector<vector<int>> ans;
        solve(k,n,mid,ans,1);
        return ans;
    }
};