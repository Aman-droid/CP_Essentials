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
const int mxn=2e5;
vector<int>adj[mxn];
int vis[mxn];
//int col[mxn];
//map<int,int>cnt;
//map<pair<int,int>,int> mp;

/*void dfs(int u,int par)
{
    vis[u]=1;
    for(int v:adj[u]){
        if(v==par)
            continue;
        else if(vis[v] && mp[{u,v}]==0 && mp[{v,u}]==0 ){    //back edge but increasing count multiple times
            pii x1={u,v};
            pii x2={v,u};
            mp[x1]++;
            mp[x2]++;
            if(col[u]!=col[v]){
                cnt[col[u]]++;
                cnt[col[v]]++;
            }
        }
        else if(!vis[v]){
            if(col[u]!=col[v]){
                cnt[col[u]]++;
                cnt[col[v]]++;
            }
            dfs(v,u);
        }
    }
}*/
map<int,int> col;
map<int,set<int>> res;
void dfs(int node)
{
    vis[node]=1;
    for(auto u:adj[node])
    {
        if(col[node]!=col[u]){
            res[col[node]].insert(col[u]);
        }
    }
    for(auto u:adj[node]){
        if(vis[u]==0)
            dfs(u);
    }
}

int main() {
    FIO;
    int T=1;//cin>>T;
    while (T--){
        int n,m,u,v,x;cin>>n>>m;
        rep(i,1,n){
            cin>>x;
            col[i]=x;
            res[x].insert(-1);
        }
        rep(i,1,m){
            cin>>u>>v;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        rep(i,1,n){
            if(vis[i]==0)
                dfs(i);
        }
        int mxm=-1,ans=1;
        for(auto it:res){           //res==>sorted order //map ==>sorted order 
            if(SZ(it.ss)-1>mxm){
                mxm=it.ss.size()-1;
                ans=it.ff;
            }
        }
        cout<<ans<<endl;
    }
}

