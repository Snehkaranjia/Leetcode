class Solution {
private:
    double calcfrac(int pass, int total) { 
        return (double)pass / total; 
    }

public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int n = classes.size();

        using P = pair<double, int>;
        priority_queue<P> maxheap;

        for (int i = 0; i < n; i++) {
            double gain = calcfrac(classes[i][0] + 1, classes[i][1] + 1) - 
                          calcfrac(classes[i][0], classes[i][1]);
            maxheap.push({gain, i});
        }

        while (extraStudents--) {
            auto [gain, idx] = maxheap.top();
            maxheap.pop();

            classes[idx][0]++; 
            classes[idx][1]++;

            double newgain = calcfrac(classes[idx][0] + 1, classes[idx][1] + 1) - 
                             calcfrac(classes[idx][0], classes[idx][1]);
            maxheap.push({newgain, idx});
        }

        double ans = 0;
        for (int i = 0; i < n; i++)
            ans += calcfrac(classes[i][0], classes[i][1]);

        return ans / n;
    }
};
