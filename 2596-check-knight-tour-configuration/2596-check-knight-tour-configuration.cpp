class Solution {
public:
    vector<int> dx = {2, 2, -2, -2, 1, 1, -1, -1};
    vector<int> dy = {1, -1, 1, -1, 2, -2, 2, -2};
    int p1=0,p2=0;
    bool check(pair<int,int>& v){
        int n1=v.first,n2=v.second;
        for(int i=0;i<8;i++){
            int rr=p1+dx[i];
            int rc=p2+dy[i];
            if(rr==n1 && rc==n2){
                p1=n1;
                p2=n2;
                return true;
            }
        }
        return false;
    }
    bool checkValidGrid(vector<vector<int>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        vector<pair<int,int>> dp(row * col);
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                int n=grid[i][j];
                dp[n]={i,j};
            }
        }
        if(dp[0].first !=0 || dp[0].second !=0){
            return false;
        }
        for(int i=1;i<dp.size();i++){
            if(!check(dp[i])){
                return false;
            }
        }
        return true;
    }
};