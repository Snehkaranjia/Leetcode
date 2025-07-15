class Solution {
public:
    bool isValid(string word) {
        if(word.size() < 3)
            return false;
        bool vowel = false, constant = false;
        for(auto ch : word)
        {
            if(!isalnum(ch))
                return false;

            if(isalpha(ch))
            {
                char small = tolower(ch);
                if(small == 'a' || small == 'e'|| small == 'i'|| small == 'o'|| small == 'u')
                    vowel = true;
                else
                    constant = true;
            }
        }
        return vowel && constant;
    }
};