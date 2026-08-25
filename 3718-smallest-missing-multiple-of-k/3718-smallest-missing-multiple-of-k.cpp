class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int m=0;
        for(int x:nums){
            if(x>m){
                m=x;
            }
        }
        sort(nums.begin(),nums.end());
        int i,ans;
        for(i=1;i<=nums.size();i++){
            ans=k*i;
            cout<<ans;
            if(ans>nums[nums.size()-1] && nums.size()-1!=0){
                return ans;
            }
            cout<<ans;
            int fl=0;
            for(int j=0;j<nums.size();j++){
                if(ans==nums[j]){
                    cout<<"yes";
                    fl=-1;
                    break;
                }
            }
            if(fl!=-1){
                return ans;
            }
        }
        return k*i;
    }
};