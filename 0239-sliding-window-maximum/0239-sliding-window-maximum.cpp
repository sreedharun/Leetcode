class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> rs;
        priority_queue<pair<int,int>> pq;
        int n=nums.size();
        int l=0,r=k,i=1;
        while(l<r){
            pq.push({nums[l],l});
            l++;
        }
        rs.push_back(pq.top().first);
        while(r<n){
            pq.push({nums[l],l});
            while(pq.top().second < i){
                pq.pop();
            }
            rs.push_back(pq.top().first);
            l++;
            r++;
            i++;
        }
        return rs;
    }
};