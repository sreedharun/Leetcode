class Solution {
public:
    int findMin(vector<int>& nums) {
        int l=0,h=nums.size()-1;
        while(l<h){
            int m=l+((h-l)>>1);
            if(nums[m]==nums[l] && nums[m]==nums[h]){
                l++;
                h--;
            }else if(nums[m]>nums[h]){
                l=m+1;
            }else{
                h=m;
            }
        }
        return nums[l];
    }
};