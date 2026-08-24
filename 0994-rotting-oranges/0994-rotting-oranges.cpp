class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int t=0,fresh=0;
        queue<vector<int>> q;
        int row=grid.size();
        int col=grid[0].size();
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }else if(grid[i][j]==1){
                    fresh++;
                }
            }
        }
        vector<vector<int>> dir={{0,-1},{-1,0},{0,1},{1,0}};
        while(!q.empty() && fresh>0){
            t++;
            int size=q.size();
            for(int m=0;m<size;m++){
                vector<int> v= q.front();
                for(int k=0;k<4;k++){
                    int rr=v[0]+dir[k][0];
                    int rc=v[1]+dir[k][1];
                    if(rr>=0 && rc>=0 && rr<row && rc<col && grid[rr][rc]==1){
                        grid[rr][rc]=2;
                        q.push({rr,rc});
                        fresh--;
                    }
                }
                q.pop();
            }
        }
        return fresh==0?t:-1;
    }
};