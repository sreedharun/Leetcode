class Solution {
public:
    int countCommas(int n) {
        int ans=1000-n;
        if(ans>0){
            return 0;
        }
        return abs(ans-1);
    }
};