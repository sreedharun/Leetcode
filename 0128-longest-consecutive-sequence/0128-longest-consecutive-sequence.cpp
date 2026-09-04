class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> oc(nums.begin(),nums.end());
        int ans=0;
        for(auto& v:oc){
            if(oc.contains(v-1)){
                continue;
            }
            int num=v;
            int cur=1;
            while(oc.contains(num+1)){
                num++;
                cur++;
            }
            ans=max(ans,cur);
        }
        return ans;
    }
};