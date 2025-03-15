class Solution {
public:
    int minFlips(int a, int b, int c) {
        int ans = 0;
        for (int i = 0; i < 32; i++) {
            if ((c & (1 << i)) == 0) { 
                // If c has 0 at this bit, check a and b
                if ((a & (1 << i)) && (b & (1 << i))) 
                    ans += 2;  // If both a and b have 1, we need to flip both
                else if ((a & (1 << i)) || (b & (1 << i))) 
                    ans += 1;  // If either a or b has 1, we need to flip one
            } else { 
                // If c has 1 at this bit, at least one of a or b should be 1
                if (!(a & (1 << i)) && !(b & (1 << i))) 
                    ans += 1;  // If both are 0, we need one flip
            }
        }
        return ans;
    }
};