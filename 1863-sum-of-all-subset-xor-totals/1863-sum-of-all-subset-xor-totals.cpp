class Solution {
public:
    int subsetXORSum(std::vector<int>& nums) {
        int xorSum = std::reduce(nums.begin(), nums.end(), 0, std::bit_or<>());
        return xorSum * (1 << (nums.size() - 1));
    }
};