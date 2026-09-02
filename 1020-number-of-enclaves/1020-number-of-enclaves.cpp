class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        queue<vector<int>> q;
        vector<vector<int>> dir={{0,1},{1,0},{0,-1},{-1,0}};
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(i==0||j==0||i==row-1||j==col-1){
                    if(grid[i][j]==1){
                        grid[i][j]=0;
                        q.push({i,j});
                    }
                }
            }
        }
        while(!q.empty()){
            vector<int> v=q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int rr=v[0]+dir[i][0];
                int rc=v[1]+dir[i][1];
                if(rr>=0 && rc>=0 && rr<row && rc<col && grid[rr][rc]==1){
                    grid[rr][rc]=0;
                    q.push({rr,rc});
                }
            }
        }
        int c=0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]==1){
                    c++;
                }
            }
        }
        return c;
    }
};