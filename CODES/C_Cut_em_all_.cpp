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
int n;
int cnt[mxn],vis[mxn];
vector<int>adj[mxn];
ll ans=0;
void dfs(int node,int par){
    cnt[node]=1;
    vis[node]=1;
    //watch(node);
    for(int child:adj[node]){
        if(child==par)
            continue;
        if(!vis[child])
            dfs(child,node);
        cnt[node]+=cnt[child];
    }
    //watch(cnt[node]);
    if(cnt[node]%2==0 && node!=1)
       cnt[node]=0,ans++;
}

int main() {
    int T=1;//cin>>T;
    while (T--)
    {
        cin>>n;
        int u,v;
        rep(i,1,n-1)
        cin>>u>>v,adj[u].pb(v),adj[v].pb(u);
        dfs(1,-1);
        //rep(i,1,n)
            //watch(cnt[i]);
        if(cnt[1]%2==0)
            cout<<ans<<endl;
        else 
            cout<<"-1"<<endl;
    }
}

