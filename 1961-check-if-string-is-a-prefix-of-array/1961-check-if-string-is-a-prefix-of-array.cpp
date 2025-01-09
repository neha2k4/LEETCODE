class Solution {
public:
    bool isPrefixString(string s, vector<string>& words) {
        string ans = "";

        for(auto& word:words){
            ans += word;
            if(ans == s) return true;
            if(ans.length()>s.length()) return false;
        }
        return false;
    }
};