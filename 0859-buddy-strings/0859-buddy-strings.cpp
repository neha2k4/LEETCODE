class Solution {
public:
    bool buddyStrings(string s, string goal) {
        vector<int> cnt(26, 0);
        bool ok = false;
        for(char ch : s) {
            cnt[ch - 'a']++;
            if(cnt[ch - 'a'] > 1) {
                ok = true;
            }
        }
        if(s.size() != goal.size()) {
            return false;
        }
        if(s == goal) {
            return ok;
        }
        int difcnt = 0, f = -1, l = -1;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] != goal[i]) {
                ++difcnt;
                if(f == -1) {
                    f = i;
                } else {
                    l = i;
                }
            }
        }
        return (difcnt == 2 && s[f] == goal[l] && s[l] == goal[f]);
    }
};