// # recusion
// O(m + n) space and  O(2^(m+n)) time
class Solution {
public:
  	
  	int helper(vector<vector<int>>& grid, int i, int j , int n, int m){
        if(i == n-1 and j == m-1) return grid[i][j];
        if (i==n) return 1e9;
        if (j==m) return 1e9;
        int rightAns = helper(grid, i, j+1, n, m );
        int bottomAns = helper(grid, i+1, j, n, m );
        return grid[i][j] + min(bottomAns, rightAns);        
  	}

    int minPathSum(vector<vector<int>>& grid) {
        
        int n = grid.size();
        if(n == 0) return 0;
        int m = grid[0].size();
        return helper(grid, 0, 0, n, m);
    }
};


// # DP
// O(m*n) space and  O(m*n) time
class Solution {
public:
  	
    int minPathSum(vector<vector<int>>& grid) {
        
        int n = grid.size();
        if(n == 0) return 1e9;
        int m = grid[0].size();

        int** dp =  new int*[n];
        for (int i = 0; i < n; ++i){
        	dp[i] = new int[m];
        	for (int j = 0; j < m; ++j){
        		dp[i][j] = 0;
        	}
        }

        // filling last columns 
        dp[n-1][m-1] = grid[n-1][m-1];
        for (int j = m-2; j >=0; --j){
        	dp[n-1][j] = dp[n-1][j+1] + grid[n-1][j];
        }

        // & last row
        for (int i = n-2; i >=0; --i){
        	dp[i][m-1] = dp[i+1][m-1] + grid[i][m-1];
        }

        for (int i = n-2; i >= 0; --i){
        	for (int j = m-2; j >= 0; --j){
        		dp[i][j] = grid[i][j] + min(dp[i+1][j], dp[i][j+1]);
        	}
        }
        return dp[0][0];
    }
};