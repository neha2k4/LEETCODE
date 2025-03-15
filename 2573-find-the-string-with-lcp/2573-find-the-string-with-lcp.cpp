class Solution {
public:
    string findTheString(vector<vector<int>>& lcp) {
        int n = lcp.size();
        // Check matrix structure
        // lcp[i][j] = lcp[j][i]
        // lcp[i][i] = n - i
        // lcp[i][j] > 0: lcp[i+1][j+1] =  lcp[i][j] - 1
        // lcp[i][j] < n - i, lcp[i][j] < n - j
        for (int i = 0; i < n; i++) {
            if (lcp[i][i] != n - i) return "";
            for (int j = 0; j < n; j++) {
                if (lcp[i][j] != lcp[j][i]) return "";
                if (lcp[i][j] > min(n - i, n - j)) return ""; 
                if (i + 1 < n && j + 1 < n && lcp[i][j] > 0) {
                    if (lcp[i+1][j+1] + 1 != lcp[i][j]) return "";
                }
            }
        }

        vector<int> result(n, -1);
        vector<vector<int>> isOK(n, vector<int>(26, 1));
        for (int i = 0; i < n; i++) {
            if (result[i] == -1) {
                for (int j = 0; j < 26; j++) {
                    if (isOK[i][j]) {
                        result[i] = j;
                        break;
                    }
                }
                if (result[i] == -1) return "";
            }
            // Check and populate
            for (int j = i+1; j < n; j++) {
                if (lcp[i][j] == 0) {
                    // conflict with existing letter
                    if (result[j] >= 0 && result[j] == result[i]) return "";
                    isOK[j][result[i]] = false;
                } else {
                    // conflict with existing letter
                    if (result[j] >= 0 && result[j] != result[i]) return "";
                    // conflict with can not fill
                    if (result[j] == -1 && !isOK[j][result[i]]) return "";
                    result[j] = result[i];
                }
            }
        }
        string s;
        for (int c: result) s += char(c+'a');
        return s;
    }
};