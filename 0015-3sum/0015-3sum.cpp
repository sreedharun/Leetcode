class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        for(int x=0;x<nums.size()-2;x++){
            if(x!=0 && nums[x]==nums[x-1]){continue;}
            int i=x+1,j=nums.size()-1;
            while(i<j){
                int sum=nums[x]+nums[i]+nums[j];
                if(sum==0){
                    res.push_back({nums[x],nums[i],nums[j]});
                    i++;j--;
                    while(i<nums.size() && nums[i]==nums[i-1]){i++;}
                    while(j>0 && nums[j]==nums[j+1]){j--;}
                    cout<<x<<i<<j<<" ";
                }else if(sum<0){
                    i++;
                }else{
                    j--;
                }
            }
        }
        return res;
    }
};