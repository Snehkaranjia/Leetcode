class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();
        vector<int> diff;
        diff.push_back(startTime[0] - 0);
        for(int i=0; i<n-1; i++)
        {
            diff.push_back(startTime[i+1] - endTime[i]);
        }
        diff.push_back(eventTime - endTime[n-1]);
        
        int wndSize = k + 1;
        int totalDiff = diff.size();
        int sum = 0,maxsum = 0;

        for (int i = 0; i < wndSize && i < totalDiff; i++) {
            sum += diff[i];
        }
        maxsum = sum;

        for (int i = wndSize; i < totalDiff; i++) {
            sum += diff[i] - diff[i - wndSize];
            maxsum = max(maxsum, sum);
        }

        return maxsum;
    }
};