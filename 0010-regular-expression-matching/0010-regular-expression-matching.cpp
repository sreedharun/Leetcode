class Solution {
public:
    bool check(string &s,string &p,int n1,int n2,int i,int j){
        if(i >= n1 && j >= n2){
            return true;
        }
        if(j>=n2){
            return false;
        }
        bool fir= (s[i]==p[j] || p[j]=='.') && i<n1;
        bool ans;
        if(j+1 < n2 && p[j+1]=='*'){
            ans = check(s,p,n1,n2,i,j+2);
            if(fir){
                ans=ans|| check(s,p,n1,n2,i+1,j);
            }
        }else{
            ans= fir && check(s,p,n1,n2,i+1,j+1);
        }
        return ans;
    }
    bool isMatch(string s, string p) {
        int n1=s.size();
        int n2=p.size();
        return check(s,p,n1,n2,0,0);
    }
};