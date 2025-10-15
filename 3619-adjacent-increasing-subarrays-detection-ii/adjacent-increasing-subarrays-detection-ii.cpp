class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        pair<int, int> prevcurr;
        int ans = 1;
        prevcurr = {0, 1};
        
        for(int i=1; i< nums.size(); i++)
        {
            if(nums[i] > nums[i-1])
                prevcurr.second++;

            else{
                ans = max({ans, prevcurr.second/2, min(prevcurr.first, prevcurr.second)}); 
                prevcurr.first = prevcurr.second;
                prevcurr.second = 1;
            }
        }

        return max({ans, prevcurr.second/2, min(prevcurr.first, prevcurr.second)});
    }
};