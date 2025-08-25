class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        int curri = 0, currj = 0;
        vector<int> ans;
        bool up = true;

        while (curri < n && currj < m) {
            int i = curri, j = currj;

            if (up) {
                while (i >= 0 && j < m) {
                    ans.push_back(mat[i--][j++]);
                }
                if (j < m) {  
                    curri = i + 1;
                    currj = j;
                } else {         
                    curri = i + 2;
                    currj = m - 1;
                }
            } 
            else { 
                while (i < n && j >= 0) {
                    ans.push_back(mat[i++][j--]);
                }
                if (i < n) {     
                    curri = i;
                    currj = j + 1;
                } else {      
                    curri = n - 1;
                    currj = j + 2;
                }
            }

            up = !up; 
        }

        return ans;
    }
};
