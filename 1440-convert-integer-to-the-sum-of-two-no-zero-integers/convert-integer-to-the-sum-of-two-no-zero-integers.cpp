class Solution {
private:
    bool checkNZ(int n1, int n2)
    {
        string num1 = to_string(n1);
        string num2 = to_string(n2);

        for(auto &ch1 : num1)
        {
            if(ch1 == '0')
                return false;
        }

        for(auto &ch2 : num2)
        {
            if(ch2 == '0')
                return false;
        }
        return true;
    }

public:
    vector<int> getNoZeroIntegers(int n) {
        vector<int> ans(2);
        for(int i=1; i<n; i++)
        {
            if(checkNZ(i, n-i))
            {
                ans[0] = i;
                ans[1] = n-i;
                break;
            }
        }
        return ans;
    }
};