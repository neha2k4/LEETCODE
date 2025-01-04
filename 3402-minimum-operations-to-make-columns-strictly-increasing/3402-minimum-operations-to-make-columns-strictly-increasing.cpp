class Solution {
public:
    int minimumOperations(vector<vector<int>>& grid) {
        int i=0,j=0;
        int m=grid.size(); //col size
        int n=grid[0].size(); // row size
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                if(grid[j][i]<grid[j-1][i])
                {
                    cnt+=grid[j-1][i]-grid[j][i]+1;
                    grid[j][i]=grid[j-1][i]+1;
                    
                    
                }
                else if(grid[j][i]==grid[j-1][i])
                {
                    cnt++;
                    grid[j][i]=grid[j][i]+1;
                }
            }
        }
        return cnt;
    }
};