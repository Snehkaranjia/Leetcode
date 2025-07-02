class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxHeap;
        for (int num : stones) {
            maxHeap.push(num);
        }

        while (maxHeap.size() > 1) {
            int val1 = maxHeap.top(); 
            maxHeap.pop();
            int val2 = maxHeap.top(); 
            maxHeap.pop();
            if (val1 != val2) {
                maxHeap.push(abs(val1 - val2));
            }
        }

        return maxHeap.empty() ? 0 : maxHeap.top();
    }
};