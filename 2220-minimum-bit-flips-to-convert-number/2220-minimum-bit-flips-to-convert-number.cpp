class Solution {
public:
    int minBitFlips(int start, int goal) {
        bitset<32> binary1(start);
        bitset<32> binary2(goal);

        string sx = binary1.to_string();
        string gy = binary2.to_string();

        if (sx == gy)
            return 0;

        int count = 0;
        for (int i = 31; i >= 0; i--) {

            if (sx[i] != gy[i]) {
                count += 1;
                if (sx[i] == '0') {
                    sx[i] = '1';
                } else if (sx[i] == '1') {
                    sx[i] = '0';
                }
            }

            if (sx == gy)
                return count;
        }
        return -1;
    }
};