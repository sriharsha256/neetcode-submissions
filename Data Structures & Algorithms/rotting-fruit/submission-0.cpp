class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                { 
                    visited[i][j]=true;
                    q.push({i,j});
                }
            }
        }
       vector<int>  dr = {0,1,0,-1};
       vector<int>  dc = {1,0,-1,0};
        int time=0;
        while(!q.empty())
        {
            int size = q.size();
            bool rotten = false;
            for(int i=0;i<size;i++)
            {               
                int row = q.front().first;
                int col = q.front().second;
                q.pop();
                for(int j=0;j<4;j++)
                {
                   int  nrow = row+dr[j];
                   int  ncol = col+dc[j];
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && visited[nrow][ncol]==false)
                {
                    if(grid[nrow][ncol]==1)
                    {
                        grid[nrow][ncol] = 2;
                        visited[nrow][ncol] = true;
                        q.push({nrow,ncol});
                         rotten = true;
                    }
                }
                }
            }
            if(rotten) time++;
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1) return -1;
            }
        }
        return time;
    }
};
