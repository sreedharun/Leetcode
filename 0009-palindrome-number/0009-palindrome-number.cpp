class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0){
            return false;
        }
        long rev=0;
        int t=x;
        while(t !=0){
            int n=t % 10;
            rev= rev * 10 + n;
            t/=10;
        }
        return x==rev;
    }
};