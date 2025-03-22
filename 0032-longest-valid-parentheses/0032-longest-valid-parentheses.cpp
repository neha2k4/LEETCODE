class Solution {
public:
    int longestValidParentheses(string str) {
        stack<int> s;
        int n = str.size();
        vector<int> dp(n, 0);

        for (int i = 0; i < n; i++) {
            if (str[i] == '(') {
                s.push(i);
            } else {
                if (!s.empty()) {
                    int index = s.top();
                    s.pop();

                    int length = i - index + 1; 
                    dp[i] = (index > 0 ? dp[index - 1] : 0) + length;
                }
            }
        }

        int mx = 0;
        for (const auto& v : dp) {
            mx = max(mx, v);
        }
        return mx;
    }
};
