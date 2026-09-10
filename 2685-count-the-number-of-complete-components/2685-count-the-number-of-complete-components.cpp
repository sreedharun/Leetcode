class Solution {
public:
    int ver,ed;
    vector<int> dfs(int s,vector<vector<int>>& aj,vector<bool>& vis){
            vis[s]=true;
            ver++;
            ed+=aj[s].size();
            for(int i=0;i<aj[s].size();i++){
                if(!vis[aj[s][i]]){
                    dfs(aj[s][i],aj,vis);
                }
            }
            return {ver,ed};
    }
    bool check(int v1,int v2){
        int t=(v1*(v1-1))/2;
        return t==v2/2;
    }
    int count(int n,vector<vector<int>>& aj,vector<bool> vis){
            int c=0;
            for(int i=0;i<n;i++){
                if(vis[i]==false){
                    ver=0;
                    ed=0;
                    vector<int> val=dfs(i,aj,vis);
                    if(check(val[0],val[1])){
                        c++;
                    }
                }
            }
            return c;
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> aj(n);
        vector<bool> vis(n,false);
        for(auto v:edges){
            aj[v[0]].push_back(v[1]);
            aj[v[1]].push_back(v[0]);
        }
        int c=count(n,aj,vis);
        return c;
    }
};