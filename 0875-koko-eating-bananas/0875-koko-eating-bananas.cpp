class Solution {
public:
    bool check(vector<int>& piles,long long mid,int h){
        long count=0;
        for(int i:piles){
            if(i % mid==0){
                count+=i/mid;
            }else if(i/mid==0){
                count+=1;
            }else{
                count+=(i/mid)+1;
            }
        }
        return count <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        long long low=1,high=0;
        for(int i:piles){
            if(i>high){
                high=i;
            }
        }
        long long ans;
        while(low<=high){
            long long mid=(high+low)/2;
            if(check(piles,mid,h)){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
};