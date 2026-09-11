class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> tp(n+1);
        tp[0]=0;
        tp[1]=nums[0];
        for(int i=2;i<=n;i++){
            tp[i]=max(tp[i-1],tp[i-2]+nums[i-1]);
        }
        return tp[n];
    }
};