class Solution {
public:
    int lis(int idx,int prev_idx,int n,vector<int> &nums,vector<vector<int>>& dp){
        if(idx==n){return 0;}
        if(dp[idx][prev_idx+1]!=-1){return dp[idx][prev_idx+1];}
        int len=0+lis(idx+1,prev_idx,n,nums,dp);
        if(prev_idx==-1 || nums[idx]>nums[prev_idx]){
            len=max(len,1+lis(idx+1,idx,n,nums,dp));
        }
        return dp[idx][prev_idx+1]=len;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n+1,vector<int> (n+1,-1));
        return lis(0,-1,n,nums,dp);
    }
};