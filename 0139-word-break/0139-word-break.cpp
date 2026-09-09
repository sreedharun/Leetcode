class Solution {
public:
    class Trie{
    public:    
        Trie* children[26];
        bool isEnd;
        Trie(){
            isEnd=false;
            for(int i=0;i<26;i++){
                children[i]=nullptr;
            }
        }
    };
    Trie* root=new Trie();
    void insert(string s){
        Trie* n=root;
        for(char C:s){
            int i=C-'a';
            if(!n->children[i]){
                n->children[i]=new Trie();
            }
            n=n->children[i];
        }
        n->isEnd=true;
    }
    bool find(string& s,int i,vector<int>& dp){
        Trie* n=root;
        if(i==s.size()){
            return true;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        for(int j=i;j<s.size();j++){
            int in=s[j]-'a';
            if(!n->children[in]){
                break;
            }
            n=n->children[in];
            if(n->isEnd){
                if(find(s,j+1,dp)){
                    return dp[i]=true;
                }
            }
        }
        return dp[i]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int res=s.size();
        vector<int> dp(res,-1);
        int n=wordDict.size();
        for(int i=0;i<n;i++){
            insert(wordDict[i]);
        }
        return find(s,0,dp);
    }
};