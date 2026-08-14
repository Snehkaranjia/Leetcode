class Solution {
public:
    int maximumLengthSubstring(string s) {
        int i=0, j=0;
        unordered_map<char, int> freq;
        int ans = 0;
        while(j < s.length())
        {
            freq[s[j]]++;
            while(freq[s[j]] > 2)
                freq[s[i++]]--;
            ans = max(ans, j-i+1);
            j++;
        }
        return ans;
    }
};