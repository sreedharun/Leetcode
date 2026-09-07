class Solution {
public:
    int mx1(vector<int>& nums,int i){
        int mx=INT_MIN;
        for(int j=0;j<=i;j++){
            mx=max(mx,nums[j]);
        }
        return mx;
    }
    int mn1(vector<int>& nums,int i){
        int mn=INT_MAX;
        for(int j=i;j<nums.size();j++){
            mn=min(mn,nums[j]);
        }
        return mn;
    }
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        int ans=-1;
        for(int i=0;i<n;i++){
            int mx=mx1(nums,i);
            int mn=mn1(nums,i);
            if(mx-mn<=k){
                ans=i;
                break;
            }
        }
        return ans;
    }
};