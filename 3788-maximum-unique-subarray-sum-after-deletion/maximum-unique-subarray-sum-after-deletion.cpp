class Solution {
public:
    int maxSum(vector<int>& nums) {
        bool allNegative = true;
        int maxVal = INT_MIN;
        for (auto &ele : nums) {
            if (ele >= 0) 
                allNegative = false;
            if (ele > maxVal) 
                maxVal = ele;
        }
        if (allNegative) 
            return maxVal;

        set<int> s;
        for(auto &ele:nums)
        {
            if(ele >= 0)
                s.insert(ele);
        }
        int ans = 0;
        for(auto &ele : s)
            ans += ele;
        return ans;
    }
};