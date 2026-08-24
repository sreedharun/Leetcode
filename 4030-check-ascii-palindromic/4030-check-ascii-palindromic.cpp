class Solution {
public:
    string ascitobin(char a){
        string bin="";
        for(int i=7;i>=0;i--){
            bin+=((a>>i) & 1)? 1 : 0 ;
        }
        return bin;
    }
    bool isPalindromic(string s) {
        string res="";
        for(int i=0;i<s.size();i++){
            res+=ascitobin(s[i]);
        }
        int i=0,j=res.size()-1;
        while(i<j){
            if(res[i]!=res[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};