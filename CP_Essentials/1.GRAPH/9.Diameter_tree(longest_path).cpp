#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
#define vi vector< int >
#define vll vector< ll >
#define vpll vector<pair<ll,ll>>
#define SZ(x) ((int)x.size())
#define FIO  ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define watch(x) cout << (#x) << " is " << (x) << "\n"
#define watch2(x,y) cout <<(#x)<<" is "<<(x)<<" and "<<(#y)<<" is "<<(y)<<"\n"
#define pb push_back
#define pf push_front
#define mod 1000000007
//run dfs from any node
//find node at maxm distance
//run dfs from max node and dis will be answer

using namespace std;
vector<int> adj[100001];
int vis[100001];
int maxm,mnode;
void dfs(int node,int dis ){
    vis[node]=1;
    if(dis>maxm){
        maxm=dis;
        mnode=node;
    }
    for(int child:adj[node])
        if(!vis[child])
            dfs(child,dis+1);
}

int main()
{
    // FIO;
    int T=1;
    while(T--)
    {
        int n,u,v;cin>>n;
        for(int i=1;i<=n;i++)
        {
            vis[i]=0;
            adj[i].clear();
        }
        for(int i=1;i<=n-1;i++)
        {
            cin>>u>>v;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        maxm =-1;
        dfs(1,0);
        for(int i=1;i<=n;i++)
            vis[i]=0;
        maxm=-1;
        dfs(mnode,0);  //maxm=ans=diameter
        cout<<maxm<<endl;
    }
	return 0;
}






//USING DP
// for leaf ==> sub[node]=0 and others sub[node] = max(sub[node],sub[child]+1);
 
 
// const int mxn=2e5;
// vector<int>adj[105];
// vector<int>vis(105);
// int sub[105];
// int diameter;

// void dfs(int node,int par){

//     for(int child:adj[node]){
//         if(vis[child]==0){
//             if(child == par)continue;
//             dfs(child,node);
//             diameter=max(diameter,sub[node] + sub[child]+1);
//             sub[node] = max(sub[node],sub[child]+1);
//         }
//     }    
// }


// void solve(){
//     int n,N,u,v;cin>>n;
//     int ans=0;
//     rep(i,0,n-1){
//         cin>>N;
//         rep(i,1,N)adj[i].clear(),vis[i]=0,sub[i]=0;
//         rep(i,1,N-1){
//             cin>>u>>v;
//             adj[u].push_back(v);
//             adj[v].push_back(u);
//         }

//         diameter=0;
//         dfs(1,-1);
//         //cout<<diameter<<endl;
//         ans+=diameter;
//     }
//     cout<<ans<<endl;
// }

// signed main() {
//     //freopen("input.txt","r",stdin);
//     //freopen("output.txt","w",stdout);
//     FIO;
//     int T=1;//cin>>T;
//     while (T--){
//        solve();
//     }
//     return 0;   
// }
