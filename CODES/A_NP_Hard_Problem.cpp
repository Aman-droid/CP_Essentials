#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
#define vll vector< ll >
#define rep(i,a,b)  for(int i=a;i<=b;i++)
#define pii pair<int,int>
#define SZ(x) ((int)x.size())
#define FIO  ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define watch(x) cout << (#x) << " is " << (x) << "\n"
#define pb push_back
#define pf push_front
#define ff first
#define ss second
#define mod 1000000007
using namespace std;
ll power(ll a, ll b){//a^b
ll res=1;
a=a%mod;
while(b>0){
    if(b&1){res=(res*a)%mod;b--;}
    a=(a*a)%mod;
    b>>=1;
}
    return res;
}
ll gcd(ll a, ll b){return (b==0)?a:gcd(b,a%b);}
//--------------------------------------------------------------------------------------------------------//
/*//No of subtree of node
void dfs(ll s,ll par=0){
	sz[s]=1;
	for(pll child:adj[node]){
		if(child.ff==par)continue;
		dfs(child.ff,s);
		sz[s]+=sz[child.ff];
	}
}*/
const int mxn=2e5;
vector<int>adj[mxn];
int vis[mxn];
int col[mxn];
set<int>c1,c2;
//int fl=0;
/*bool dfs(int node,int par,int c){
    vis[node]=1;
    col[node]=c;
    if(c==1)
        c1.insert(node);
    else 
        c2.insert(node);
    for(int child:adj[node]){
        if(!vis[child]){
            if(dfs(child,node,c^1)==false)
                return false;
        }
        else {
            if(col[node]==col[child])
                return false;
        }
    }
    return true;
}*/
int fl=0;
void dfs(int node,int c)
{
    vis[node]=1;
    col[node]=c;
    if(c==1)
        c1.insert(node);
    else 
        c2.insert(node);
    for(int child:adj[node])
    {
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

int main() {
    FIO;
    int T=1;//cin>>T;
    while (T--)
    {
        int n,m,u,v;cin>>n>>m;
        for(int i=0;i<m;i++){
            cin>>u>>v;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        bool res=false;
        rep(i,1,n){
            if(vis[i]==0){
                if(adj[i].empty())
                    continue;
                dfs(i,1);
            }
        }
        if(fl==0){
            cout<<SZ(c2)<<endl;
            for(auto it:c2){
                cout<<it<<" ";
            }
            cout<<endl;
            cout<<SZ(c1)<<endl;
            for(auto it:c1){
                cout<<it<<" ";
            }
            cout<<endl;
        }
        else{
            cout<<"-1"<<endl;
        }
    }
}

