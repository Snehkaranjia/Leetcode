class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n =  nums.size();
        if(n == k)
        {
            int maxi = 0;
            for(int i=0; i<n; i++)
                maxi = max(maxi, nums[i]);
            return maxi;
        }
        
        int freq[51]={0};
        for(int x: nums)
            freq[x]++;

        if (k==1){
            for(int x=50; x>=0; x--)
                if (freq[x]==1) return x;
            return -1;
        }

        int f = nums[0], l = nums[n-1];
        bool repf = freq[f] > 1, repl = freq[l] > 1;
        
        if((repf && repl) || (l==f))
            return -1;
        if(repf)
            return l;
        if(repl)
            return f;
        return max(l, f);
    }
};