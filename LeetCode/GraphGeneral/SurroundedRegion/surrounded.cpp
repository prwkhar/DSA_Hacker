class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i==0||j==0||i==n-1||j==m-1)
                {
                if(board[i][j]=='O'&&!visited[i][j])
                {
                    dfs(board,visited,i,j);
                }
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!visited[i][j])
                {
                    board[i][j]='X';
                }
            }
        }
    }
    void dfs(vector<vector<char>>& b,vector<vector<bool>>& visited,int row,int col)
    {
        int n=b.size();
        int m=b[0].size();
        stack<pair<int,int>> st;
        visited[row][col]=1;
        st.push({row,col});
        while(!st.empty())
        {
            pair<int,int> node=st.top();
            st.pop();
            int r=node.first;
            int c=node.second;
                int nr=r-1;
                int nc=c;
                if(nr>=0&&nr<n&&nc>=0&&nc<m&&b[nr][nc]=='O'&&!visited[nr][nc])
                {
                    visited[nr][nc]=true;
                    st.push({nr,nc});
                }
                nr=r;
                nc=c-1;
                if(nr>=0&&nr<n&&nc>=0&&nc<m&&b[nr][nc]=='O'&&!visited[nr][nc])
                {
                    visited[nr][nc]=true;
                    st.push({nr,nc});
                }
                nr=r;
                nc=c+1;
                if(nr>=0&&nr<n&&nc>=0&&nc<m&&b[nr][nc]=='O'&&!visited[nr][nc])
                {
                    visited[nr][nc]=true;
                    st.push({nr,nc});
                }
                nr=r+1;
                nc=c;
                if(nr>=0&&nr<n&&nc>=0&&nc<m&&b[nr][nc]=='O'&&!visited[nr][nc])
                {
                    visited[nr][nc]=true;
                    st.push({nr,nc});
                }
    }
    }
};