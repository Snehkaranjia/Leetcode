#include <string>

class Solution {
public:
    int longestSubsequence(string s, int k) {
        int n = s.length();
        long long sum = 0;
        int zeros = 0, ones = 0;
        for(char ch:s)
        {
            if(ch == '0')
                zeros++;
        }
        for(int i=n-1; i>=0; i--)
        {
            if(s[i] == '1')
            {
                if(sum + pow(2, (n-1)-(i)) > k)
                    continue;
                sum += pow(2, (n-1)-(i));
                ones++;
            }
            if(sum > k)
                break;
        }
        return zeros+ones;
    }
};