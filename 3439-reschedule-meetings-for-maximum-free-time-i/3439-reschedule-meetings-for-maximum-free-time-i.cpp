class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();

        // Step 1: Build the gaps array
        vector<int> gaps;
        gaps.push_back(startTime[0]);
        for (int i = 1; i < n; ++i) {
            gaps.push_back(startTime[i] - endTime[i - 1]); 
        }
        gaps.push_back(eventTime - endTime.back()); 

        // Step 2: Sliding window of size k+1 to get maximum sum of gaps
        int windowSize = k + 1;
        int maxSum = 0, currentSum = 0;

        for (int i = 0; i < gaps.size(); i++) {
            currentSum += gaps[i];
            if (i >= windowSize) {
                currentSum -= gaps[i - windowSize];
            }
            if (i >= windowSize - 1) {
                maxSum = max(maxSum, currentSum);
            }
        }

        return maxSum;
    }
};