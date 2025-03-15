class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;
        bool isNegative = (dividend < 0) != (divisor < 0);
        long long dvd = abs((long long)dividend), dvs = abs((long long)divisor), result = 0;
        while (dvd >= dvs) {
            long long temp = dvs, multiple = 1;
            while (dvd >= temp << 1) {
                temp <<= 1;
                multiple <<= 1;
            }
            dvd -= temp;
            result += multiple;
        }
        return isNegative ? -result : result;
    }
};