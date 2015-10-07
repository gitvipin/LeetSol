/*
Solution for : https://leetcode.com/problems/minimum-path-sum/
*/

int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        if (!m)
            return 0;
        int n = grid[0].size();
        
        for ( int i = 0; i < m ; i++) {
            for (int j = 0; j <n; j++) {
                int minCost = 0;
                if (!i && j) {
                    minCost = grid[i][j-1];
                } else if (i && !j) {
                    minCost = grid[i-1][j];
                } else if (i && j) {
                    minCost = std::min(grid[i][j-1], grid[i-1][j]);
                }
                grid[i][j] += minCost;
            }
        }
        
        return grid[m-1][n-1];
    }
