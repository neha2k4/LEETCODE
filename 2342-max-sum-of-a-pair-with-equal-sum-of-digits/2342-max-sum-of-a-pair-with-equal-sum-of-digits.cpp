class Solution {
private:
    // Helper function to compute the sum of digits of a number
    int calculateDigitSum(int num) {
        int digitSum = 0;
        while (num > 0) {
            digitSum += num % 10;
            num /= 10;
        }
        return digitSum;
    }

public:
    int maximumSum(vector<int>& nums) {
        // Vector to store a min heap for each possible digit sum (0 to 81)
        vector<priority_queue<int, vector<int>, greater<int>>> digitSumGroups(
            82);

        int maxPairSum = -1;

        // Group numbers by their digit sums, maintaining heap size of 2
        for (int number : nums) {
            int digitSum = calculateDigitSum(number);
            digitSumGroups[digitSum].push(number);

            // Keep only the top 2 largest numbers in the heap
            if (digitSumGroups[digitSum].size() > 2) {
                digitSumGroups[digitSum].pop();  // Remove the smallest element
            }
        }

        // Traverse the vector to find the maximum pair sum for each group
        for (auto& minHeap : digitSumGroups) {
            if (minHeap.size() == 2) {
                int first = minHeap.top();
                minHeap.pop();
                int second = minHeap.top();
                maxPairSum = max(maxPairSum, first + second);
            }
        }

        return maxPairSum;
    }
};