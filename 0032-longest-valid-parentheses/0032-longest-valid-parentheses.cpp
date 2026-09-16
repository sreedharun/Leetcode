class Solution {
public:
    int longestValidParentheses(string s) {
        long long mx=0;
        vector<long long> dp(s.size(),0);
        for(long long i=1;i<s.size();i++){
            if(s[i-1]=='(' && s[i]==')'){
                dp[i-1]=1;
                dp[i]=1;
                i++;
            }
        }
        stack<int> st;
        for(int i=0;i<s.size();i++){
            if(!st.empty()){
                long long t1=0;
                while(!st.empty() && i<s.size() && (s[st.top()]=='(' && s[i]==')')){
                    dp[i]=1;
                    dp[st.top()]=1;
                    st.pop();
                    i++;
                }
            }
            st.push(i);
        }
        for(long long i=0;i<dp.size();i++){
            long long t=0;
            while(i<dp.size() && dp[i]==1){
                t+=dp[i];
                i++;
            }
            mx=max(mx,t);
            t=0;
        }
        return mx;
    }
};