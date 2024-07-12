class Solution {
public:
    int numIslands(vector<vector<char>>& grid) 
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int cn = 0;
        for(int row = 0; row < n; row++)
        {
            for(int col = 0; col < m; col++)
            {
                if(!vis[row][col] && grid[row][col] == '1') {
                    cn++;
                    bfs(row, col, vis, grid);
                }
            }
        }
        return cn;
    }
    
    void bfs(int r, int c, vector<vector<int>>& vis, vector<vector<char>>& grid)
    {
        vis[r][c] = 1;
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;
        q.push({r, c});
        
        vector<int> dRow = {-1, 1, 0, 0};
        vector<int> dCol = {0, 0, -1, 1};
        
        while(!q.empty())
        {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for(int k = 0; k < 4; k++) {
                int nr = r + dRow[k];
                int nc = c + dCol[k];
                if(nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == '1' && !vis[nr][nc]) {
                    vis[nr][nc] = 1;
                    q.push({nr, nc});
                }
            }
        }
    }
};
