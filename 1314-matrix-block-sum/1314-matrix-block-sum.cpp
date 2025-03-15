class Solution
{
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>> &mat, int k)
    {
        int r = mat.size();
        int c = mat[0].size();
        vector<vector<int>> ans(r, vector<int>(c, 0));
        for (int i = 0; i < r; ++i)
        {
            for (int j = 0; j < c; ++j)
            {
                int val = 0;
                int minrow = i - k;
                int maxrow = i + k;
                int mincol = j - k;
                int maxcol = j + k;
                while (minrow < 0) ++minrow;
                while (maxrow > (r - 1)) --maxrow;
                while (mincol < 0) ++mincol;
                while (maxcol > (c - 1)) --maxcol;
                for (int p = minrow; p <= maxrow; ++p)
                {
                    for (int q = mincol; q <= maxcol; ++q)
                    {
                        val += mat[p][q];
                    }
                }
                ans[i][j] = val;
            }
        }
        return ans;
    }
};