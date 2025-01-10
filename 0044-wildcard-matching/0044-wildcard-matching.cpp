class Solution {
public:
    bool solve(int index1, int index2, string &text, string &pattern) {
        if (index1 < 0 && index2 < 0) return true;
        if (index2 < 0 && index1 >= 0) return false;
        if (index1 < 0 && index2 >= 0) {
            for (int i = 0; i <= index2; i++) {
                if (pattern[i] != '*') return false;
            }
            return true;
        }

        if (text[index1] == pattern[index2] || pattern[index2] == '?') {
            return solve(index1 - 1, index2 - 1, text, pattern);
        }

        if (pattern[index2] == '*') {
            return solve(index1 - 1, index2, text, pattern) || solve(index1, index2 - 1, text, pattern);
        }

        return false;
    }

    bool isMatch(string s, string p) {
        int n1 = s.size();
        int n2 = p.size();
        return solve(n1-1, n2-1, s, p);
    }
};