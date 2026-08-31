class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int i=0,c=0;
        string ans="";
        for(int j=0;j<s.size();j++){
            if(s[j]=='1'){
                c++;
            }
            while(c==k){
                if(ans.empty()){
                    ans=s.substr(i,j-i+1);
                }
                if(j-i+1 < ans.size()){
                    ans=s.substr(i,j-i+1);
                }
                if(j-i+1 == ans.size()){
                    if(ans > s.substr(i,j-i+1)){
                        ans=s.substr(i,j-i+1);
                    }
                }
                if(s[i]=='1'){
                    c--;
                }
                i++;
            }
        }
        return ans;
    }
};