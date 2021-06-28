#include<bits/stdc++.h>
#define ll long long 
#define endl '\n'
#define rep(i,a,b)  for(ll i=a;i<=b;i++)
#define pll pair<ll,ll>
#define pii pair<ll,ll>
#define vpll vector<pll>
#define SZ(x) ((ll)x.size())
#define FIO  ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define watch(x)cout<<(#x)<<" is "<<(x)<<"\n"
#define watch2(x,y)cout<<(#x)<<" is "<<(x)<<" and "<<(#y)<<" is "<<(y)<<"\n"
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
const ll mxn=3e5;
vector<ll>adj[mxn];
ll vis[mxn];
ll cc=0;

void dfs(ll node){
    vis[node]=1;
    cc++;
    for(ll child:adj[node]){
        if(!vis[child])
            dfs(child);
    }
}
signed main() {
    FIO;
    ll T=1;//cin>>T;
    while (T--){
        ll n,m,x,u,v,w,k;cin>>n>>k;
        ll sum=power(n,k);
        rep(i,1,n-1){
            cin>>u>>v>>w;
            if(w==0){
                adj[u].pb(v);
                adj[v].pb(u);
            }
        }
        rep(i,1,n){
            cc=0;
            if(vis[i]==0 && !adj[i].empty()){
                dfs(i);
            }
            if(cc!=0)
                sum=(sum-power(cc,k)+mod)%mod;
        }
        ll cnt=0;
        rep(i,1,n){
            if(vis[i]==0){
                cnt++;
            }
        }
        sum=(sum-cnt+mod)%mod;
        cout<<sum<<endl;
    }
    return 0;   
}