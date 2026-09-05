class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(),nums.end());
        int ans=0;
        for(int x:s){
            if(s.contains(x-1)){
                continue;
            }
            int val=x;
            int count=1;
            while(s.contains(val+1)){
                val=val+1;
                count++;
            }
            ans=max(ans,count);
        }
        return ans;
    }
};