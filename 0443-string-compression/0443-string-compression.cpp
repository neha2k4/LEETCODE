class Solution {
public:
    int compress(vector<char>& c) {
        int n = c.size();
        if (n == 0) return 0;
        int w = 0,r = 0;
        while (r < n) {
            char x = c[r];
            int cnt = 0;
            while (r < n && c[r] == x) {
                r++,cnt++;
            }
            c[w++] = x;
            if (cnt > 1) {
                for (char d : to_string(cnt)) {
                    c[w++] = d;
                }
            }
        }
        return w;
    }
};