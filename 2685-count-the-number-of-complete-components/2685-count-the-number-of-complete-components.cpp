class Solution {
public:
    int c=-1;    
    void dfs(int s,vector<bool>& vis,vector<vector<int>>& adj,vector<vector<int>>& com){
        vis[s]=true;
        com[c].push_back(s);
        for(int i = 0;i < adj[s].size() ;i++){
            if(!vis[adj[s][i]]){
                dfs(adj[s][i],vis,adj,com);
            }
        }
    }
    int count(int n,vector<bool>& vis,vector<vector<int>>& adj,vector<vector<int>>& com){
        for(int i=0;i<n;i++){
            if(vis[i]==false){
                c++;
                dfs(i,vis,adj,com);
            }
        }
        return c;
    }
    bool las(int p1,int p2,vector<vector<int>>& edges){
        for(int i=0;i<edges.size();i++){
            if(p1==edges[i][0] && p2==edges[i][1] || 
            p2==edges[i][0] && p1==edges[i][1]){
                return true;
            }
        }
        return false;
    }
    bool find(vector<int> com,vector<vector<int>>& edges){
        int n=com.size();
        if(n==1){return true;}
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(!las(com[i],com[j],edges)){
                    return false;
                }
            }
        }
        return true;
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<bool> vis(n,false);
        vector<vector<int>> adj(n);
        vector<vector<int>> com(n);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        count(n,vis,adj,com);
        int res=0;
        for(int i=0;i<com.size();i++){
            if(com[i].empty()){continue;}
            if(find(com[i],edges)){
                res++;
            }
        }
        return res;
    }
};