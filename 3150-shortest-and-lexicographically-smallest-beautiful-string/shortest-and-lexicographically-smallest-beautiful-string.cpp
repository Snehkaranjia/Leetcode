class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int i=0, j=0;
        int c1 = 0;
        int l=s.length();
        int minlen = INT_MAX;
        string ans="";
        while(j<l)
        {
            if(s[j] == '1')
                c1++;

            while(c1 > k)
            {
                if(s[i] == '1')
                    c1--;
                i++;
            }

            if(c1 == k)
            {
                while(s[i] == '0')
                    i++;
                string curr = s.substr(i, j-i+1);
                if(ans == "" || curr.size() < ans.size() || (curr.size() == ans.size()) && curr < ans)
                    ans = curr;
            }
            j++;
        }
        return ans;
    }
};