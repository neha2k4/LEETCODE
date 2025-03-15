class Solution {
public:
    int minElement(vector<int>& nums) {
        int mini = INT_MAX;  // Store the minimum value
        
        for (auto i : nums) {
            if (i > 9) {  // Compute digit sum if number > 9
                int sum = 0;
                while (i != 0) {
                    sum += i % 10;
                    i /= 10;
                }
                i = sum;
            }
            mini = min(i, mini);  // Track the minimum value
        }

        return mini;  // Return the smallest processed value
    }
};