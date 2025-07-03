class Solution {
public:
    char kthCharacter(int k) {
        string word = "a";
        while (word.length() < k) {
            string newword = "";
            for (char c: word) {
                if (c == 'z')
                    newword += 'a';
                else
                    newword += c + 1;
            }
            word += newword;
        }
        return word[k - 1];
    }
};