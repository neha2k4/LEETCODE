class Solution {

public:
    const vector<vector<int>> directions={{0,1},{0,-1},{1,0},{-1,0}};
    int dfs(int r,int c,vector<vector<int>>& grid,vector<vector<bool>>& visited)
    {
        if(r<0 || r>=grid.size() || c<0 || c>=grid[0].size() || grid[r][c]==0 || visited[r][c])
        {
            return 0;
        }
        visited[r][c]=true;
        int fishcount=grid[r][c];
        for(const auto& dir: directions)
        {
            fishcount+=dfs(r+dir[0],c+dir[1],grid,visited);
        }
        return fishcount;
    }
    int findMaxFish(vector<vector<int>>& grid) {
        int rows=grid.size();
        int cols=grid[0].size();
        int maxfish=0;
        vector<vector<bool>>visited(rows,vector<bool>(cols,false));
        for(int r=0;r<rows;r++){
            for(int c=0;c<cols;c++)
            {
                if(grid[r][c]>0 && !visited[r][c])
                {
                    maxfish=max(maxfish,dfs(r,c,grid,visited));
                }
            }
        }
        return maxfish;
        
    }
};