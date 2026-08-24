class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obs) {
        int r=obs.size();
        int c=obs[0].size();
        vector<vector<int>> dp(r+1,vector<int> (c+1));
        int s=1;
        for(int i=0;i<r;i++){
            if(obs[i][0]==1){
                s=0;
            }
            dp[i][0]=s;
        }
        int s1=1;
        for(int j=0;j<c;j++){
            if(obs[0][j]==1){
                s1=0;
            }
            dp[0][j]=s1;
        }
        for(int i=1;i<r;i++){
            for(int j=1;j<c;j++){
                if(obs[i][j]==1){
                    continue;
                }
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[r-1][c-1];
    }
};