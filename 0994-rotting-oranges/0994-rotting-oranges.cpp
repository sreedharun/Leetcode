class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int t=0,fres=0;
        queue<vector<int>> q;
        int row=grid.size(),col=grid[0].size();
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }else if(grid[i][j]==1){
                    fres++;
                }
            }
        }
        vector<vector<int>> dir={{0,1},{1,0},{-1,0},{0,-1}};
        while(!q.empty() && fres>0){
            t++;
            int s=q.size();
            for(int m=0;m<s;m++){
                vector<int> v=q.front();
                q.pop();
                for(int i=0;i<4;i++){
                    int rr=v[0]+dir[i][0];
                    int rc=v[1]+dir[i][1];
                    if(rr>=0 && rc>=0 && rr<row && rc<col && grid[rr][rc]==1){
                        grid[rr][rc]=2;
                        q.push({rr,rc});
                        fres--;
                    }
                }
            }
        }
        return fres==0?t:-1;
    }
};