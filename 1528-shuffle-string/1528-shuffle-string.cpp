class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        vector<char> container(indices.size(), 0);
        for (int i = 0; i < indices.size(); i++) {
            container[indices[i]] = s[i];
        }
        string ans;
        for (int i = 0; i < container.size(); i++) {
            ans += container[i];
        }
        return ans;
    }
};