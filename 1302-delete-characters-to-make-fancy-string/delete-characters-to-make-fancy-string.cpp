class Solution {
public:
    string makeFancyString(string s) {
        if (s.length() < 3)
            return s;
        char a, b, c;
        string ans = "";
        ans += s[0];
        ans += s[1];
        for (int i = 2; i < s.length(); i++) {
            a = s[i - 2];
            b = s[i - 1];
            c = s[i];
            if (!(a == b && b == c)) {
                ans += c;
            }
        }
        return ans;
    }
};