bool dfs(int u,vector<vector<int>>&adj,vector<int>&vis){
    vis[u]=1;

    for(auto v:adj[u]){
        if(vis[v]==0){
            if(dfs(v,adj,vis)==true) 
                return true;
        }
        else if(vis[v]==1) 
            return true;
    }

    vis[u]=2;
    return false;
}

int Solution::solve(int A, vector<vector<int> > &B) {
    vector<int>vis(A+1,0);
    vector<vector<int>>adj(A+1);
    for(auto it:B)
        adj[it[0]].push_back(it[1]);
    
    for(int i=1;i<=A;i++){
        if(!vis[i]){
            if(dfs(i,adj,vis)) return true;
        }
    }
    return false;
}
