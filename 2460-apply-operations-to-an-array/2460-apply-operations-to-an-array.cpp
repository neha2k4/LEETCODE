
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        // Step 1: Merge adjacent equal elements
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] == nums[i + 1]) {
                nums[i] *= 2; 
                nums[i + 1] = 0; 
            }
        }

        // Step 2: Shift non-zero elements to the front
        int index = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                nums[index++] = nums[i]; 
            }
        }

        // Step 3: Fill the rest of the array with zeros
        while (index < nums.size()) {
            nums[index++] = 0;
        }

        return nums;
    }
};