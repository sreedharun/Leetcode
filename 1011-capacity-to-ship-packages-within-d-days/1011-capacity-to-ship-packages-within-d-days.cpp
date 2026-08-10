class Solution {
public:
    bool check(vector<int>& weights,int days,int mid){
        long c=1,cur=0;
        for(int i=0;i<weights.size();i++){
            if(cur+weights[i]>mid){
                c+=1;
                cur=weights[i];
            }else{
                cur+=weights[i];
            }
        }
        return c <= days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int l=1,h=0,ans=-1;
        for(int w:weights){
            if(w>l){
                l=w;
            }
            h+=w;
        }
        while(l<=h){
            int m=l+((h-l)>>1);
            if(check(weights,days,m)){
                ans=m;
                h=m-1;
            }else{
                l=m+1;
            }
        }
        return ans;
    }
};