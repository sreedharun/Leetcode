class Solution {
public:
    int vec,edge;
    vector<int> dfs(int s,vector<vector<int>>& adj,vector<bool>& vis){
        vis[s]=true;
        vec++;
        edge+=adj[s].size();
        for(int i=0;i<adj[s].size();i++){
            if(!vis[adj[s][i]]){
                dfs(adj[s][i],adj,vis);
            }
        }
        return {vec,edge};
    }
    bool check(int n1,int n2){
        int val=(n1*(n1-1))/2;
        return (n2/2)==val;
    }
    int count(int n,vector<vector<int>>& adj,vector<bool>& vis){
        int c=0;
        for(int i=0;i<n;i++){
            if(vis[i]==false){
                vec=0;
                edge=0;
                vector<int> val=dfs(i,adj,vis);
                if(check(val[0],val[1])){
                    c++;
                }
            }
        }
        return c;
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<bool> vis(n,false);
        vector<vector<int>> adj(n,vector<int>(0));
        for(auto& e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        int ans=count(n,adj,vis);
        return ans;
    }
};