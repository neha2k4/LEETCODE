class Solution {
public:
    int countDigits(int num) {
        int ans = 0, temp = num;
        while (temp != 0) {
            int digit = temp % 10;
            if (num % digit == 0) {
                ans++;
            }
            temp = temp / 10;
        }
        return ans;
    }
};