class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n=s.length();
        int start=0,end=0,last=n-1;
        vector<int> ans;
        int cnt = 0;
        while(start < n)
        {
            while(s[last] != s[start])
                last--;
            end = max(end, last);
            last=n-1;
            if(end-start == 0)
            {
                ans.push_back(cnt+1);
                cnt = 0;
                start++;
                end++;
            }
            else
            {
                cnt++;
                start++;
            }
        }
        return ans;
    }
};