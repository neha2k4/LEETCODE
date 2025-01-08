class Solution {
public:
    int maxIncreasingCells(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        map<int, vector<pair<int, int>>> mp;
        for (int i = 0; i < m; ++i) 
            for (int j = 0; j < n; ++j) 
                mp[mat[i][j]].push_back(make_pair(i, j));
        vector<int> row(m, 0), col(n, 0), tmpR(m), tmpC(n);
        for (auto &[k, v]: mp) {
            for (auto &[x, y]: v) {
                int s = max(row[x], col[y]);
                tmpR[x] = max(tmpR[x], s + 1);
                tmpC[y] = max(tmpC[y], s + 1);
            }
            for (auto &[x, y]: v) {
                row[x] = tmpR[x];
                col[y] = tmpC[y];
            }
        }
        return *max_element(col.begin(), col.end());
    }
};