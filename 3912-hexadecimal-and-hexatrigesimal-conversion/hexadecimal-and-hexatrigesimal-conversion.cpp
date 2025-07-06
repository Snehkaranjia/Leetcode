class Solution {

private:

    void reversestr(string &s)
    {
        int n = s.length();
        for(int i=0; i<n/2; i++)
            swap(s[i], s[n-1-i]);
    }

    string tohex(int n)
    {
        string str = "";
        while(n != 0)
        {
            int d = n % 16;
            str += (d <= 9) ? ('0' + d) : ('A' + (d - 10));
            n /= 16;
        }
        reversestr(str);
        return str; 
    }

    string to36(int n)
    {
        string str = "";
        while(n != 0)
        {
            int d = n % 36;
            str += (d <= 9) ? ('0' + d) : ('A' + (d - 10));
            n /= 36;
        }
        reversestr(str);
        return str; 
    }

public:
    string concatHex36(int n) {
        if(n == 0)
            return "0";
        string s1 = tohex(n*n);
        string s2 = to36(n*n*n);
        return s1+s2;
    }
};