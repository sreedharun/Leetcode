class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l=0,h=nums.size()-1,ans=-1;
        if(target<nums[0]){
            return 0;
        }
        if(target>nums[h]){
            return h+1;
        }
        while(l<=h){
            int m=l+((h-l)>>1);
            if(nums[m]>=target){
                ans=m;
                h=m-1;
            }else{
                l=m+1;
            }
        }
        return ans;
    }
};