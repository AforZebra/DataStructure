// https://leetcode.com/problems/unique-paths-iii/submissions/

class Solution {
public:
    int dfs(vector<vector<int>> grid, int i, int j, int count, int num0){
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == -1)return 0;
        if(grid[i][j] == 2){
            if (count + 1 == num0) return 1;
            return 0;
        }
        grid[i][j] = -1;
        int path = dfs(grid, i-1,j,count+1,num0) + dfs(grid, i+1,j,count+1,num0) + dfs(grid, i,j-1,count+1,num0) + dfs(grid, i,j+1,count+1,num0);
        grid[i][j] = 0;
        return path;
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        int count0 = 0, i1, j1;
        for(int i = 0;i < grid.size();i++){
            for(int j = 0;j < grid[i].size();j++){
                if(grid[i][j] == 1){
                    i1 = i;j1 = j;
                }
                if(grid[i][j] != -1)count0++;
            }
        }
        return dfs(grid, i1, j1, 0, count0);
    }
};
