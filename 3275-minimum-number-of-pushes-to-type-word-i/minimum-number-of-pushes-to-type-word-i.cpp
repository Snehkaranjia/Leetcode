class Solution {
public:
    int minimumPushes(string word) {
        int cnt = word.size();
        int curr = 1;
        int ans = 0;
        while(cnt > 0)
        {
            if(cnt <= 8)
            {
                ans += curr * cnt;
                break;
            }
            else
            {
                ans += curr * 8;
                curr++;
                cnt-=8; 
            }
        }
        return ans;
    }
};