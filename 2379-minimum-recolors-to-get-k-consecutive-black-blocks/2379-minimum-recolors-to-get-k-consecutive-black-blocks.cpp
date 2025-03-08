class Solution {
public:
    int minimumRecolors(std::string blocks, int k) {
        int n = blocks.length();
        int minOperations = INT_MAX;

        // Iterate through the string with a sliding window of size k
        for (int i = 0; i <= n - k; i++) {
            int whiteCount = 0;

            // Count the number of 'W's in the current window
            for (int j = i; j < i + k; j++) {
                if (blocks[j] == 'W') {
                    whiteCount++;
                }
            }

            // Update the minimum number of operations
            minOperations = std::min(minOperations, whiteCount);
        }
        return minOperations;
    }
};