class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        vector<vector<int>> dir={{0,-1},{-1,0},{1,0},{0,1}};
        queue<vector<int>> q;
        int c=0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]=='1'){
                    c++;
                    grid[i][j]='0';
                    q.push({i,j});
                    while(!q.empty()){
                        vector<int> v=q.front();
                        for(int k=0;k<4;k++){
                            int rr=v[0]+dir[k][0];
                            int rc=v[1]+dir[k][1];
                            if(rr>=0 && rc>=0 && rr<row && rc<col && grid[rr][rc]=='1'){
                                grid[rr][rc]='0';
                                q.push({rr,rc});
                            }
                        }
                        q.pop();
                    }
                }
            }
        }
        return c;
        
    }
};