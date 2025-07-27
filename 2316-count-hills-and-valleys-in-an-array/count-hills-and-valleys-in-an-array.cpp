class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int ans = 0;
        int n=nums.size();
        for(int i=1; i< n-1; i++)
        {
            int prev = nums[i-1];
            while(prev == nums[i])
                i++;
            if(i>=n-1)
                break;
            int curr = nums[i];
            while(i < n-1 && curr == nums[i+1])
                i++;
            if(i>=n-1)
                break;
            int next = nums[i+1];
            cout << prev << curr << next << endl;
            if((prev < curr && next < curr) || (prev > curr && next > curr))
                ans++;

        }
        return ans;
    }
};