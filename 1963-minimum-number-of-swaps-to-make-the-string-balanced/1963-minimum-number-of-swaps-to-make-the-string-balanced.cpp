class Solution {
public:
    int minSwaps(string s) {
         int imbalance = 0, count = 0;

        for (int i=0; i<s.size(); i++) {
            if (s[i] == '['){
                count++;
            } else {
                count--;
            }
            if (count < 0) {
                imbalance++;
                count = 0;
            }
        }

        return (imbalance + 1) / 2;
    }
    
};