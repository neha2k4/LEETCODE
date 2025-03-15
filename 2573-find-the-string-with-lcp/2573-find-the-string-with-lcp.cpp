class Solution {
public:
    string findTheString(vector<vector<int>>& lcp) {
        int n = lcp.size();
        int c = 0;
        vector<int> letter(n);
        for (int i = 0; i < n; ++i) {
            if (letter[i]) continue;
            if (++c > 26) return "";
            for (int j = i; j < n; ++j) {
                if (lcp[i][j] > 0) {
                    letter[j] = c;
                }
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int v = 0;
                if (i+1 < n && j+1 < n) {
                    v = lcp[i+1][j+1];
                }
                if (letter[i] == letter[j]) {
                    v += 1;
                } else {
                    v = 0;
                }
                if (lcp[i][j] != v) return "";
            }
        }

        string rst = "";
        for (int c : letter) {
            rst += 'a' + c - 1;
        }
        return rst;
    }
};