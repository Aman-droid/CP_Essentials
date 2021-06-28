/*bool dfs2(int  node,int c)
{
    vis[node]=1;
    col[node]=c; //maintain color of node 0 or 1
    for(int child:adj[node])
    {
        if(!vis[child])
        {
            if(dfs2(child,c^1)==false)       //c^1==to invert the color
                return false;
        }
        else
        {
            if(col[node]==col[child])
                return false;
        }
    }
    return true;
}*/

#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
#define vll vector< ll >
#define vpll vector<pair<ll,ll>>
#define SZ(x) ((int)x.size())
#define FIO  ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define watch(x) cout << (#x) << " is " << (x) << "\n"
#define watch2(x,y) cout <<(#x)<<" is "<<(x)<<" and "<<(#y)<<" is "<<(y)<<"\n"
#define pb push_back
#define pf push_front

using namespace std;
vector<int >adj[2001];
int vis[2001],col[2001];

//this one giving WA in testcase 12 in one problem
bool dfs(int node,int c){
    vis[node]=1;
    col[node]=c;
    for(int child:adj[node]){
        if(!vis[child]){
            if(dfs(child,c^1)==false)
                return false;
        }
        else{
            if(col[child]==col[node])
                return false;
        }
    }
    return true;
}

/*
//can also use this approach
void dfs(int node,int c)
{
    vis[node]=1;
    col[node]=c;
    
    if(c==1)
        c1.insert(node);
    else 
        c2.insert(node);


    for(int child:adj[node]){
        if(vis[child]==1){
            if(col[child]==col[node]){
                fl=1;
                return;
            }
        }
    }
    
    for(int child:adj[node]){
        if(vis[child]==0)
         dfs(child,c^1);
    }
}
*/

int main()
{
	int  T;cin>>T;
	for(int k=1;k<=T;k++)
    {
        int n,m,u,v;cin>>n>>m;
        for(int i=1;i<=n;i++){
            adj[i].clear();
            vis[i]=0;
            col[i]=0;
        }
        for(int i=1;i<=m;i++){
            cin>>u>>v;
            adj[u].pb(v);
            adj[v].pb(u);
        }

        bool ans =true;
        for(int i=1;i<=n;i++){
            if(!vis[i])
            {
                bool res=dfs(i,0);
                if(res==false)
                    ans=false;
            }
        }

        cout<<"Scenario #"<<k<<":"<<endl;
        if(ans==false)
            cout<<"Suspicious bugs found!"<<endl;
        else
            cout<<"No suspicious bugs found!"<<endl;

    }
	return 0;
}

