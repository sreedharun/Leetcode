class Solution {
public:
    int minDistance(string word1, string word2) {
        int s1=word1.size();
        int s2=word2.size();
        if(word1.size()==0 && word2.size()!=0){
            return word2.size();
        }else if(word2.size()==0 && word1.size()!=0){
            return word1.size();
        }
        vector<vector<int>> dp(s1+1,vector<int> (s2+1));
        for(int i=1;i<=s1;i++){
            dp[i][0]=i;
        }
        for(int j=1;j<=s2;j++){
            dp[0][j]=j;
        }
        for(int i=1;i<=s1;i++){
            for(int j=1;j<=s2;j++){
                if(word1[i-1]==word2[j-1]){
                    dp[i][j]=dp[i-1][j-1];
                }else{
                    dp[i][j]=min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]))+1;
                }
            }
        }
        return dp[s1][s2];
    }
};