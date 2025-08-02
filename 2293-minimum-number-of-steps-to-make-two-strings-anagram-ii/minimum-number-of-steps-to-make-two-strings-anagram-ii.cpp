class Solution {
public:
    int minSteps(string s, string t) {
        int ans = 0;
        vector<int> v1(26, 0);
        vector<int> v2(26, 0);

        for (char& ch : s)
            v1[ch - 'a']++;
        for (char& ch : t)
            v2[ch - 'a']++;

        for (int i = 0; i < 26; i++) {
            ans += abs(v1[i] - v2[i]);
        }
        return ans;
    }
};