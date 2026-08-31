class Solution {
public:
    int findMin(vector<int>& nums) {
        int mn=INT_MAX;
        for(int x:nums){
            if(x<mn){
                mn=x;
            }
        }
        return mn;
    }
};