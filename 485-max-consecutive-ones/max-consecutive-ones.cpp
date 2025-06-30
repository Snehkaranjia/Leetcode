class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int l=0;
        int cnt = 0, maxcnt = 0;
        for(int r=0; r<n; r++)
        {
            if(nums[r] == 1)
            {
                cnt++;
                maxcnt = max(cnt, maxcnt);
            }
            else
                cnt = 0;
        }
        return maxcnt;
    }
};