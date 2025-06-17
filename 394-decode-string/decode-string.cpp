class Solution {

private:
    void solve(string s, int n, int& index, string& final) {
        while (index < n && s[index] != ']') {
            if (isdigit(s[index])) {
                //extract number
                string num = "";
                while (index < n && isdigit(s[index])) {
                    num += s[index];
                    index++;
                }

                //skip '['
                index++;

                //fetch string in '[]'
                string encode = "";
                solve(s, n, index, encode);

                //skip ']'
                index++;

                //encode fetched string
                int freq = stoi(num);
                while (freq != 0) {
                    final += encode;
                    freq--;
                }
            } else {
                final += s[index];
                index++;
            }
        }
    }
    public:
        string decodeString(string s) {
            int n = s.length();
            string ans = "";
            int index = 0;
            solve(s, n, index, ans);
            return ans;
        }
    };