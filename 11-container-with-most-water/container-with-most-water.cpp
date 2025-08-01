class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int water = 0;
        int l = 0, r=n-1;
        while(l<r)
        {
            int new_water = min(height[r], height[l]) * (r-l);
            water = max(water, new_water);
            if(height[l] < height[r])
                l++;
            else
                r--;
        }
        return water;
    }
};