class NeighborSum {
public:
    unordered_map<int, pair<int, int>> dict;
    vector<vector<int>> m_grid;
    int n;

    NeighborSum(vector<vector<int>>& grid) {
        m_grid = grid;
        n = grid.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dict[grid[i][j]] = {i, j};
            }
        }
    }
    
    int adjacentSum(int value) {
        int i = dict[value].first, j = dict[value].second, res = 0;
        if (i > 0) res += m_grid[i-1][j];
        if (i+1 < n) res += m_grid[i+1][j];
        if (j > 0) res += m_grid[i][j-1];
        if (j+1 < n) res += m_grid[i][j+1];
        return res;
    }
    
    int diagonalSum(int value) {
        int i = dict[value].first, j = dict[value].second, res = 0;
        if (i > 0 && j > 0) res += m_grid[i-1][j-1];
        if (i+1 < n && j > 0) res += m_grid[i+1][j-1];
        if (i > 0 && j+1 < n) res += m_grid[i-1][j+1];
        if (i+1 < n && j+1 < n) res += m_grid[i+1][j+1];
        return res;
    }
};