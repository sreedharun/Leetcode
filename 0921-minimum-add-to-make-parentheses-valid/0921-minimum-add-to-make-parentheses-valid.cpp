class Solution {
public:
    int solve(string s){
        int c=0;
        stack<char> st;
        for(int i=0;i<s.size();i++){
            if(st.empty() && s[i]==')'){
                c++;
            }else if(!st.empty() && st.top()=='(' && s[i]==')'){
                st.pop();
            }else{
                st.push(s[i]);
            }
        }
        if(!st.empty()){
            c+=st.size();
        }
        return c;
    }
    int minAddToMakeValid(string s) {
        return solve(s);
    }
};