class Solution {
public:
    int rob(vector<int>& nums) {
       int p1=0,p2=nums[0];
       for(int i=1;i<nums.size();i++){
            int cur=max(p2,p1+nums[i]);
            p1=p2;
            p2=cur;
       }
       return p2; 
    }
};