class Solution {
public:
    int minBitFlips(int s, int g) {
        return __builtin_popcount(s ^ g);
    }
};