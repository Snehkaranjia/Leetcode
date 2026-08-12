class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        map<int, int> freq;
        int i=0, j=1;
        int n = nums.size();
        freq[nums[0]]++;
        if(nums.size()==1)
            return 1;
        int maxlen = 1;
        while(i<n && j<n)
        {
            freq[nums[j]]++;
            if(freq[nums[j]] > k)
            {
                while(nums[i] != nums[j])
                {
                    freq[nums[i++]]--;
                }
                freq[nums[i++]]--;
            }
            else
                maxlen = max(maxlen, j-i+1);
            j++;
        }
        return maxlen;
    }
};