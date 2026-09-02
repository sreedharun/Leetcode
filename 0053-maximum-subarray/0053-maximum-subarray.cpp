class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int m1=nums[0],rm=nums[0];
        for(int i=1;i<nums.size();i++){
            m1=max(m1+nums[i],nums[i]);
            rm=max(rm,m1);
        }
        return rm;
    }
};