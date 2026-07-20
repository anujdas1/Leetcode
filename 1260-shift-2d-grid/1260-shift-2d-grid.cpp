class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n=grid[0].size();
        int m=grid.size();

        
        int total=m*n;
        k=k%total;

        vector<vector<int>> result(m, vector<int>(n));

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                int pos1D=(i*n + j + k)%total;

                int x=pos1D/n;
                int y=pos1D%n;

                result[x][y]=grid[i][j];
                
            }
        }

        return result;
    }
};