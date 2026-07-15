class Solution {
public:

    void dfs(int row, int col, vector<vector<bool>>& visited, vector<vector<char>>& grid)
    {
        int rows = grid.size();
        int cols = grid[0].size();

        // Out of bounds
        if(row < 0 || row >= rows || col < 0 || col >= cols)
            return;

        // Already visited
        if(visited[row][col])
            return;

        // Water cell
        if(grid[row][col] == '0')
            return;

        // Mark as visited
        visited[row][col] = true;

        // Visit all 4 directions
        dfs(row - 1, col, visited, grid);
        dfs(row + 1, col, visited, grid);
        dfs(row, col - 1, visited, grid);
        dfs(row, col + 1, visited, grid);
    }

    int numIslands(vector<vector<char>>& grid) {

        int rows = grid.size();
        int cols = grid[0].size();

        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        int islands = 0;

        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                if(grid[i][j] == '1' && !visited[i][j])
                {
                    islands++;
                    dfs(i, j, visited, grid);
                }
            }
        }

        return islands;
    }
};
