class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        sort(stones.begin(), stones.end());
        int replace = 0;
        int n=stones.size();
        for(int i=n-1; i>0; i--)
        {
            if(stones[i] != stones[i-1])
            {
                replace = abs(stones[i] - stones[i-1]);
                stones[i-1] = replace;
                stones.pop_back();
                sort(stones.begin(), stones.end());
            }
            else
            {
                stones.pop_back();
                stones.pop_back();
                i--;
            }
        }
        if(stones.size() == 0)
            return 0;
        return stones[0];
    }
};