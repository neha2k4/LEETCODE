class Solution {
public:
    vector<vector<int>> substringXorQueries(string s, vector<vector<int>>& queries) {
        unordered_map<int, pair<int,int>> m;
        for(int i=0; i<s.size(); i++) {
            for(int j=i; j<min(i+32, (int)s.size()); j++) {
                long long int p = 1;
                long long int ans = 0;
                int k = j;
                while(k >= i) {
                    ans += p * (s[k] - '0');
                    p = p * 2;
                    k--;
                }

                if (m.find(ans) == m.end()) {
                    m[ans] = {i, j};
                } else {
                    int l = j - i;
                    if ((m[ans].second - m[ans].first) > l) {
                        m[ans] = {i, j};
                    }
                }
            }
        }
        vector<vector<int>> ans;
        for(auto i: queries) {
            int t = i[0] ^ i[1];
            if (m.find(t) != m.end()) {
                ans.push_back({m[t].first, m[t].second}); 
            } else {
                ans.push_back({-1, -1});
            }
        }
        return ans;
    }
};