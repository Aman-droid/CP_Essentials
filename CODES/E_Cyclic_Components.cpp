#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
#define vll vector< ll >
#define rep(i,a,b)  for(int i=a;i<=b;i++)
#define pii pair<int,int>
#define SZ(x) ((int)x.size())
#define FIO  ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define watch(x) cout << (#x) << " is " << (x) << "\n"
#define mp make_pair
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
const int mxn=3e5;
vector<int> adj[mxn];
vector<int> vis(mxn);
int cnt[mxn];
int par[mxn];
vector<int> cc;

int ans,fl;
void dfs(int v,int p){
    vis[v]=1;
    par[v]=p;
    cc.pb(v);

    for(int u:adj[v]){
        if(!vis[u])
            dfs(u,v);
    }
}
int main() {
    int T=1;//cin>>T;
    while (T--){
        int n,u,v,m;cin>>n>>m;
        rep(i,1,n)
            adj[i].clear(),vis[i]=0;
        rep(i,1,m)
            cin>>u>>v,adj[u].pb(v),adj[v].pb(u),cnt[u]++,cnt[v]++;
        ans=0;
        rep(i,1,n){
            if(!vis[i]){
                cc.clear();
                fl=0;
                dfs(i,-1);
                //watch(fl);
                for(auto it:cc)
                    if(cnt[it]!=2)
                        fl=1;
                if(fl==0)
                    ans++;
            }
        }
        cout<<ans<<endl;
    }
}

