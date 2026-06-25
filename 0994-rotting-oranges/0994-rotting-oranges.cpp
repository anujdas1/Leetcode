class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<int, int>> q;

        const int r[]={-1, 0, 1, 0};
        const int c[]={0, 1, 0, -1};
        int freshcount=0;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==2){
                    q.push({i, j});
                }else if(grid[i][j]==1){
                    freshcount++;
                }
            }
        }

        if(freshcount==0) return 0;

        int count=0;
        while(!q.empty()){
            int sz=q.size();
            bool rotted=false;
            for(int j=0; j<sz; j++){
                auto [a,b]=q.front();
                q.pop();
                
                for(int i=0; i<4; i++){
                    int row=a + r[i];
                    int col= b + c[i];
                    if(row<n && row>=0 && col>=0 && col<m && grid[row][col]==1 && !vis[row][col]){
                        vis[row][col]=1;
                        grid[row][col]=2;
                        q.push({row, col});
                        rotted=true;
                        freshcount--;
                    }  
                }
            }

            if(rotted) count++;
        }

        if(freshcount>0) return -1;
        return count;
    }
};