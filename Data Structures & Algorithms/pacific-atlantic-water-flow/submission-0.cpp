class Solution {
private:
    void dfs(int row, int col, vector<vector<int>>& heights, vector<vector<int>>& vis) {
        vis[row][col] = 1;
        int n = heights.size();
        int m = heights[0].size();
        int delRow[] = {-1, 0, +1, 0};
        int delCol[] = {0, +1, 0, -1};
        for(int i = 0; i < 4; i++)
        {
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && heights[nrow][ncol] >= heights[row][col])
            {
                dfs(nrow, ncol, heights, vis);
            }
        }
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> pacific(n, vector<int>(m, 0));
        vector<vector<int>> atlantic(n, vector<int>(m, 0));
        for(int j = 0; j < m; j++){
            dfs(0, j, heights, pacific);
        }
        for(int i = 0; i < n; i++){
            dfs(i, 0, heights, pacific);
        }
        for(int j = 0; j < m; j++){
            dfs(n - 1, j, heights, atlantic);
        }
        for(int i = 0; i < n; i++){
            dfs(i, m - 1, heights, atlantic);
        }
        vector<vector<int>> ans;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(pacific[i][j] && atlantic[i][j]){
                    ans.push_back({i, j});
                }
            }
        }
        return ans;
    }
};