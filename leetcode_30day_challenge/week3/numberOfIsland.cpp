class Solution {
public:
   	void dfs(vector<vector<char>>& grid, int i, int j, int n, int m) {
   		if(grid[i][j] == '2' || grid[i][j] == '0') return ;
   		// mark this cell as visited
		grid[i][j] = '2';
		// call to right
		if(j+1 < m)
			dfs(grid, i, j+1, n, m);
		// call to bottom
		if(i+1 <n)
			dfs(grid, i+1, j, n, m);
        if(j-1 >=0)
			dfs(grid, i, j-1, n, m);
		// call to bottom
		if(i-1 >=0)
			dfs(grid, i-1, j, n, m);
        return;
   	}

    int numIslands(vector<vector<char>>& grid) {
    	int no_of_island = 0;
    	int n = grid.size();
        if(n >= 1) {
            int m = grid[0].size();
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < m; ++j)
                    if(grid[i][j] == '1'){
                        dfs(grid, i, j, n, m);
                        no_of_island += 1;
                    }	
        }else{
            return 0;
        }
        return no_of_island;
    }
};