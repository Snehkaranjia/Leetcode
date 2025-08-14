class Solution {
public:
    string largestGoodInteger(string num) {
        int n = num.length();
        char best = 'a'; 
        
        for (int i = 0; i <= n - 3; i++) {
            if (num[i] == num[i+1] && num[i] == num[i+2]) {
                if (best == 'a' || num[i] > best) {
                    best = num[i]; 
                }
            }
        }

        if (best == 'a') 
            return ""; 
        return string(3, best);
    }
};