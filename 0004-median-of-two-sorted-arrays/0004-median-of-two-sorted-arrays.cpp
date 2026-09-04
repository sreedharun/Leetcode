class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size(),n2=nums2.size();
        vector<int> res;
        for(int i=0;i<n1;i++){
            res.push_back(nums1[i]);
        }
        for(int i=0;i<n2;i++){
            res.push_back(nums2[i]);
        }
        sort(res.begin(),res.end());
        int m=res.size()/2;
        double med;
        if(res.size()%2==0){
            med=abs(res[m]+res[m-1])/2.00000;
        }else{
            return (double) res[m];
        }
        return med;
    }
};