vector<vector<int>>adj;
vector<int>vis;
bool check(int node,int par){
    vis[node]=1;
    for(int child:adj[node]){
        if(child==par)continue;
        if(vis[child]==0){
            if(check(child,node)==true)return true;
        }
        else{
            if(child!=par)return true;
        }
    }
    return false;
}
int Solution::solve(int n, vector<vector<int> > &B) {
    adj=vector<vector<int>>(n+1);
    vis=vector<int>(n+1);

    for(int i=0;i<B.size();i++){
        adj[B[i][0]].push_back(B[i][1]);
        adj[B[i][1]].push_back(B[i][0]);
    }

    for(int i=1;i<=n;i++){
        if(vis[i]==0){
            bool res=check(i,-1);
            if(res)return true;
        }
    }
    return false;
}

