class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int mn=INT_MAX,mx=INT_MIN,mni=0,mxi=0;
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            if(nums[i]>mx){
                mx=nums[i];
                mxi=i;
            }
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]<mn){
                mn=nums[i];
                mni=i;
            }
        }
        int ans=INT_MAX;
        if(mni>mxi){
            int t=(mxi+1) + abs(mni-n);
            ans=min(ans,t);
            ans=min(ans,mni+1);
            ans=min(ans,abs(mxi-n));
        }
        if(mxi>mni){
            int t=(mni+1) + abs(mxi-n);
            ans=min(ans,t);
            ans=min(ans,mxi+1);
            ans=min(ans,abs(mni-n));
        }
        if(ans==INT_MAX){return 1;}
        return ans;
    }
};