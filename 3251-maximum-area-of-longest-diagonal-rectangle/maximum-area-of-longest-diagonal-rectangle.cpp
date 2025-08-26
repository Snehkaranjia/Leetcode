class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int idx = 0;
        double maxDiag = 0;

        for (int i = 0; i < dimensions.size(); i++) {
            double diag = sqrt(dimensions[i][0] * dimensions[i][0] +
                               dimensions[i][1] * dimensions[i][1]);
            int area = dimensions[i][0] * dimensions[i][1];
            int bestArea = dimensions[idx][0] * dimensions[idx][1];

            if (diag > maxDiag || (abs(diag - maxDiag) < 1e-9 && area > bestArea)) {
                idx = i;
                maxDiag = diag;
            }
        }
        return dimensions[idx][0] * dimensions[idx][1];
    }
};