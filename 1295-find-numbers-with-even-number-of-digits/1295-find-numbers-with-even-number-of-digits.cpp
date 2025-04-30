class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int count = 0;
        for (int i : nums) {
            if (countDigits(i) % 2 == 0) ++count;
        } 
        return count;
    }
    int countDigits(int x) {
        int cnt = 0;
        while (x > 0) {
            x /= 10;
            ++cnt;
        }
        return cnt;
    }
};